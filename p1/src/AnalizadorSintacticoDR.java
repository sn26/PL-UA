
import java.util.ArrayList;
import java.util.Arrays;


public class AnalizadorSintacticoDR {

    private AnalizadorLexico lex; 
    //private ArrayList<Integer> buffer_rules; //Donde vamos a guardar las reglas por las que vayamos pasando 
    private StringBuilder buffer_rules;
    private Token actual_tok;
    public boolean print_rules_flag = true ;  
    
    public AnalizadorSintacticoDR(AnalizadorLexico al) {
        this.lex = al;  
        buffer_rules= new StringBuilder(); 
        this.actual_tok = al.siguienteToken(); 
    }
    
    public final void emparejar(int tokEsperado ){
        if(this.actual_tok.tipo != tokEsperado) errorSintaxis(tokEsperado);
        else this.actual_tok = this.lex.siguienteToken(); 
    }
    
    private String get_errorString(String err , int ... errores_args){
        for(int arg : errores_args ){
            this.actual_tok.tipo= arg;
            err = err + " " + this.actual_tok.toString();
        } 
        return err + " \n";
    }
    
    public final void errorSintaxis(int ... errores_args){
        buffer_rules.setLength(0); //LIMPIO EL STRING BUILDER (NO ESTOY SEGURO DE QUE HAGA FALTA)
        if(this.actual_tok.tipo != Token.EOF){
            System.err.print(get_errorString("Error sintactico (" 
                  + this.actual_tok.fila +"," + this.actual_tok.columna + 
                  "): encontrado '" + this.actual_tok.lexema + "', esperaba" , errores_args));
            System.exit(-1);
        }
        System.err.print(get_errorString("Error sintactico: encontrado fin de fichero, esperaba" , errores_args));
        System.exit(-1);
    }
    
    /**
     * Imprime los num de las reglas por las que hemos pasado
     */
    public final void comprobarFinFichero(){
        if(this.actual_tok.tipo == Token.EOF) System.out.println(this.buffer_rules); //Solo imprimiremos cuando termina con exito
    }
    
    /////************************REGLAS***************************************** 
    /**
     * 
     * S -> Sp
     * 
     */
    public final void S(){
        if(actual_tok.tipo == Token.FN ){
            buffer_rules.append( " " +1); 
            this.Sp();
            return;
        }
        this.errorSintaxis(Token.FN);    
    } 
    
    /**
     * 
     * Sp -> Fun Spp
     * 
     */
    public final void Sp( ){
        if(this.actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +2);
            this.Fun();
            this.Spp();
            return; 
        }
        this.errorSintaxis(Token.FN);
    }
    
    /**
     * 
     * Fun -> fn id A RT  Spp Cod endfn 
     * 
     */
    public final void Fun( ){
        if(this.actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +5);
            this.emparejar(Token.FN); //Emparejamos, hemos llegado al final de la escalera 
            this.emparejar(Token.ID);
            this.A();
            this.Rt();
            this.Spp();
            this.Cod();
            this.emparejar(Token.ENDFN); 
            return; 
        }
        this.errorSintaxis(Token.FN); 
    }
    
    /**
     * 
     * Spp  -> Fun Spp 
     * Spp -> epsilon
     * 
     */
    public final void Spp(){
        if(actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +3);
            this.Fun(); 
            this.Spp();
            return; 
        }
        if(actual_tok.tipo == Token.EOF ||
                actual_tok.tipo == Token.BLQ ||
                actual_tok.tipo == Token.LET ||
                actual_tok.tipo == Token.PRINT || 
                actual_tok.tipo == Token.IF){
            //NO HACEMOS NADA MAS PORQUE ESTAMOS EN EPSILON!!
            buffer_rules.append( " " +4);
            return; 
        }
        this.errorSintaxis(Token.FN , Token.LET , Token.PRINT , Token.IF, Token.BLQ , Token.EOF); 
                
    }
    
    /**
     * A -> pari Arg pard
     * 
     */
    public final void  A(){
        if(this.actual_tok.tipo == Token.PARI){
            buffer_rules.append( " " +6);
            emparejar(this.actual_tok.tipo); 
            Arg();
            this.emparejar(Token.PARD); 
            return; 
        }
        this.errorSintaxis(Token.PARI); 
    }
        
    /**
     * Arg -> id dosp Type Arg
     * Arg -> epsilon
     * 
     */
    public final void Arg(){
        if(this.actual_tok.tipo == Token.ID){
            buffer_rules.append( " " +7);
            emparejar(Token.ID);
            emparejar(Token.DOSP); 
            Type();
            Arg(); 
            return; 
        }
        if(this.actual_tok.tipo == Token.PARD){
            //EPSILON
            buffer_rules.append( " " +8);
            return; 
        }
        this.errorSintaxis(Token.ID , Token.PARD);
    }
    
    /***
     * 
     * Rt -> ret Type
     * Rt -> epsilon
     * 
     */
    public final void Rt(){
        if(this.actual_tok.tipo == Token.RET){
            buffer_rules.append( " " +9);
            emparejar(Token.RET);
            Type();
            return; 
        }
        if(this.actual_tok.tipo == Token.FN 
                || this.actual_tok.tipo == Token.BLQ 
                || this.actual_tok.tipo == Token.LET 
                ||this.actual_tok.tipo == Token.PRINT 
                || this.actual_tok.tipo == Token.IF){
            //EPSILON
            buffer_rules.append( " " +10);
            return; 
        }
        this.errorSintaxis(Token.FN ,Token.RET,  Token.LET , Token.PRINT , Token.IF, Token.BLQ ); 
    }
    
    /**
     * 
     * Type -> Int  
     * Type -> Real
     */
    public final void Type(){
        if(this.actual_tok.tipo == Token.INT){
            buffer_rules.append( " " +11);
            emparejar(Token.INT); 
            return; 
        }
        if(this.actual_tok.tipo == Token.REAL){
            buffer_rules.append( " " +12);
            emparejar(Token.REAL);
            return; 
        }
        this.errorSintaxis(Token.INT , Token.REAL);
    }
    
    /**
     * Cod -> I Codp
     * 
     */
    public final void Cod(){
        if(this.actual_tok.tipo == Token.BLQ || 
                this.actual_tok.tipo == Token.LET ||
                this.actual_tok.tipo == Token.PRINT||
                this.actual_tok.tipo == Token.IF){
            buffer_rules.append( " " +13);
            I();
            Codp();
            return; 
        }
        this.errorSintaxis(Token.LET , Token.PRINT , Token.IF, Token.BLQ );
        
    }
    
    /**
     * Codp -> pyc I Codp 
     * Codp -> epsilon
     * 
     */
    public final void Codp(){
        if(this.actual_tok.tipo == Token.PYC) {
           buffer_rules.append( " " +14);
           emparejar(Token.PYC);
           I();
           Codp();
           return; 
           
        }if(this.actual_tok.tipo == Token.ENDFN ||
                this.actual_tok.tipo == Token.FBLQ){
            
            //EPSILON
            buffer_rules.append( " " +15);
            return;
        }
        this.errorSintaxis(Token.ENDFN , Token.PYC , Token.FBLQ);
    }
    
    /**
     * I -> Blq
     * I -> let id IT
     * I -> print E
     * I -> if E I Ip
     */
    public final void I(){
        if(this.actual_tok.tipo == Token.BLQ){
            buffer_rules.append( " " +16);
            Blq();
            return;
        }
        if(this.actual_tok.tipo == Token.LET){
            buffer_rules.append( " " +17);
            emparejar(Token.LET);
            emparejar(Token.ID);
            It();
            return;
            
        }
        if(this.actual_tok.tipo == Token.PRINT){
            buffer_rules.append( " " +18);
            emparejar(Token.PRINT);
            E();
            return; 
        }
        if(this.actual_tok.tipo  == Token.IF){
            buffer_rules.append( " " +19);
            emparejar(Token.IF);
            E();
            I(); 
            Ip();
            return;
        }
        this.errorSintaxis(Token.LET , Token.PRINT , Token.IF, Token.BLQ );
    }
    
    /**
     * Ip -> else I fi
     * Ip -> fi
     * 
     */
    public final void Ip(){
        if(this.actual_tok.tipo == Token.ELSE){
            buffer_rules.append( " " +20);
            emparejar(Token.ELSE);
            I();
            emparejar(Token.FI);
            return;
        }
        if(this.actual_tok.tipo == Token.FI){
            buffer_rules.append( " " +21);
            emparejar(Token.FI);
            return ;
        }
        this.errorSintaxis(Token.ELSE , Token.FI );    
    }
    
    /**
     * 
     * Blq -> blq Cod fblq 
     * 
     */
    public final void Blq(){
        if(this.actual_tok.tipo == Token.BLQ){
            buffer_rules.append( " " +22);
            emparejar(Token.BLQ);
            Cod(); 
            emparejar(Token.FBLQ); 
            return;
        }
        this.errorSintaxis(Token.BLQ);
    }
    
    /**
     * IT -> dosp Type
     * IT -> asig E Ifa
     * IT -> epsilon
     */
    public final void It(){
        if(actual_tok.tipo == Token.DOSP){
            buffer_rules.append( " " +23);
            emparejar(Token.DOSP);
            Type(); 
            return; 
        }
        if(actual_tok.tipo == Token.ASIG){
            buffer_rules.append( " " +24);
            emparejar(Token.ASIG);
            E(); 
            Ifa();
            return;
        }
        if(actual_tok.tipo == Token.ELSE ||
                actual_tok.tipo == Token.FI || 
                actual_tok.tipo == Token.PYC || 
                actual_tok.tipo == Token.FBLQ || 
                actual_tok.tipo == Token.ENDFN){
            //EPSILON
            buffer_rules.append( " " +25);
            return;
        }
        
        this.errorSintaxis(Token.ENDFN , Token.DOSP , Token.PYC , Token.ELSE, Token.FI,  Token.FBLQ , Token.ASIG );
    }
    
    /**
     * Ifa -> if E
     * Ifa -> epsilon
     * 
    */
    public final void Ifa(){
        if(actual_tok.tipo == Token.IF){
            buffer_rules.append( " " +26);
            emparejar(Token.IF);
            E();
            return;
        }
        if(actual_tok.tipo == Token.ELSE ||
                actual_tok.tipo == Token.FI ||
                actual_tok.tipo == Token.PYC ||
                actual_tok.tipo == Token.FBLQ ||
                actual_tok.tipo == Token.ENDFN){
            //EPSILON
            buffer_rules.append( " " +27);
            return;
        }
        errorSintaxis(Token.ENDFN , Token.PYC , Token.IF , Token.ELSE , Token.FI, Token.FBLQ);
    }
    
    /**
     * E -> T Ep
     * 
     */
    public final void E(){
        if(actual_tok.tipo == Token.ID  ||actual_tok.tipo == Token.NUMINT 
                ||actual_tok.tipo == Token.NUMREAL ||  
                actual_tok.tipo == Token.PARI) {
            buffer_rules.append( " " +28);
            T();
            Ep(); 
            return; 
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
    }
    
    /**
     * 
     * Ep -> opas T Ep
     * Ep -> epsilon
     * 
     */
    public final void Ep(){
        if(actual_tok.tipo == Token.OPAS ){
            buffer_rules.append( " " +29);
            emparejar(Token.OPAS );
            T();
            Ep();
            return;
        }
        if(actual_tok.tipo == Token.BLQ||
                actual_tok.tipo == Token.LET ||
                actual_tok.tipo == Token.PRINT ||
                actual_tok.tipo == Token.IF ||
                actual_tok.tipo == Token.ELSE ||
                actual_tok.tipo == Token.FI || 
                actual_tok.tipo == Token.PYC ||
                actual_tok.tipo == Token.FBLQ || 
                actual_tok.tipo == Token.ENDFN || 
                actual_tok.tipo == Token.PARD  ){
            //EPSILON
            buffer_rules.append( " " +30);
            return;
        }
        errorSintaxis(Token.ENDFN, Token.PARD , Token.PYC , Token.LET , Token.PRINT , Token.IF , 
                        Token.ELSE , Token.FI, Token.BLQ,   Token.FBLQ , Token.OPAS);
    }
    
    /**
     * T -> F Tp
    */
    public final void T(){
        if(actual_tok.tipo== Token.ID ||
                actual_tok.tipo == Token.NUMINT  || 
                actual_tok.tipo == Token.NUMREAL ||
                actual_tok.tipo == Token.PARI){
            buffer_rules.append( " " +31);
            F(); 
            Tp();
            return;
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
    }
    
    /**
     * Tp -> opmd F Tp
     * Tp -> epsilon
     */
    public final void Tp(){
        if(actual_tok.tipo == Token.OPMD){
            buffer_rules.append( " " +32);
            emparejar(Token.OPMD);
            F();
            Tp();
            return; 
        }
        if(actual_tok.tipo == Token.OPAS||
                actual_tok.tipo == Token.BLQ ||
                actual_tok.tipo == Token.LET ||
                actual_tok.tipo == Token.PRINT||
                actual_tok.tipo == Token.IF ||
                actual_tok.tipo == Token.ELSE || 
                actual_tok.tipo == Token.FI ||
                actual_tok.tipo == Token.PYC || 
                actual_tok.tipo == Token.FBLQ || 
                actual_tok.tipo == Token.ENDFN ||
                actual_tok.tipo == Token.PARD){
            //EPSILON
            buffer_rules.append( " " +33);
            return;
        }
        errorSintaxis(Token.ENDFN, Token.PARD , Token.PYC , Token.PRINT , Token.LET, Token.IF , 
                        Token.ELSE , Token.FI,  Token.BLQ,  Token.FBLQ , Token.OPAS , Token.OPMD);
    }
    
    /**
     * F -> id 
     * F -> numint 
     * F -> numreal 
     * F -> pari E pard
     */
    public final void F(){
        if(actual_tok.tipo == Token.NUMINT){
            buffer_rules.append( " " +34);
            emparejar(Token.NUMINT); 
            return;
        }
        if(actual_tok.tipo == Token.NUMREAL){
            buffer_rules.append( " " +35);
            emparejar(Token.NUMREAL);
            return;
        }
        if(actual_tok.tipo == Token.ID){
            buffer_rules.append( " " +36);
            emparejar(Token.ID); 
            return;  
        }
        
        
        if( actual_tok.tipo == Token.PARI ){
            buffer_rules.append( " " +37);
            emparejar(Token.PARI);
            E();
            emparejar(Token.PARD);
            return; 
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
    }
}
