
import java.util.ArrayList;
import java.util.Arrays;


public class TraductorDR {

    private AnalizadorLexico lex; 
    //private ArrayList<Integer> buffer_rules; //Donde vamos a guardar las reglas por las que vayamos pasando 
    private StringBuilder buffer_rules;
    private Token actual_tok;
    public boolean print_rules_flag = true ; 
    private TablaSimbolos tsActual = null; 
    private String[] erroresSemanticos = {
        " , ya existe en este ambito" , 
        " , no ha sido declarado" , 
        " , la expresión debe ser de tipo entero", 
        " debe ser de tipo entero o real" , 
        " debe declararse con tipo entero o real"
    }; 
    public TraductorDR(AnalizadorLexico al) {
        this.lex = al;  
        buffer_rules= new StringBuilder(); 
        this.actual_tok = al.siguienteToken();
        this.tsActual = new TablaSimbolos(null); //No hemos entrado en ningún ámbito 
    }
    
    /**
     * Función que usaremos para pasar del tipo traducido, al tipo (int) del símbolo
     * @param typetrad
     * @return 
     */
    private int parserTipo(String typetrad){
        if(typetrad.equals("int")) return 1;
        if ( typetrad.equals("float")) return 2; 
        //SI ES VOID, LANZAMOS ERROR 
        if(typetrad.equals("void")) this.errorSemantico(4);
        return -1;
    }
    
    /**
     * Función que usaremos para devolver el tipo de una variable que se está declarando, cuando hacemos por ejemplo let a = 1.5(float) + 1(int)
     * @param type1
     * @param type2
     * @return 
     */
    private String tiposhake(String type1 , String type2){
        if(type1.equals("float") || type1.equals("float")) return "float";
        return "int"; 
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
    
    /***
     * Función que vamos a utilizar para sacar los errores semánticos
     * @param errores_args 
     */
    private final void errorSemantico(int tipoerr){
        buffer_rules.setLength(0); //LIMPIO EL STRING BUILDER (NO ESTOY SEGURO DE QUE HAGA FALTA)
        
        System.err.print("Error semántico (" 
              + this.actual_tok.fila +"," + this.actual_tok.columna + 
              "): '" + this.actual_tok.lexema + this.erroresSemanticos[tipoerr] );
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
    public String S(){
        if(actual_tok.tipo == Token.FN ){
            buffer_rules.append( " " +1); 
            return this.Sp(); //Devolvemos la traduccion de Sp
        }
        this.errorSintaxis(Token.FN);  
        return ""; 
    } 
    
    /**
     * 
     * Sp -> Fun Spp
     * 
     */
    public String Sp( ){
        if(this.actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +2);
            return this.Fun("", "" ) + "" + this.Spp("" , ""); 
        }
        this.errorSintaxis(Token.FN);
        return ""; 
             
    }
    
    /**
     * 
     * Fun -> fn id A RT  Spp Cod endfn 
     * 
     */
    public String Fun(String funth , String tipoh){ //funth1 -> Sufijo , fumth2 -> tipo padre (void , int , float)
        if(this.actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +5);
            this.emparejar(Token.FN); //Emparejamos, hemos llegado al final de la escalera 
            this.emparejar(Token.ID);
            String idlexema = actual_tok.lexema;
            //Añadimos la func al ámbito actual
            if( !this.tsActual.newSymb(new Simbolo(idlexema , 3 , funth + idlexema ))) this.errorSemantico(0);  
            //Añadimos el simbolo de la funcion
            //Cogemos las traducciones 
            this.tsActual = new TablaSimbolos(this.tsActual); //Añadimos un nuevo ámbito
            String attrad = this.A(); //Argumentos
            String rttrad = this.Rt(tipoh) ;
            String spptrad = this.Spp(funth + idlexema + "_" , rttrad); // Prefijo, tipo_padre 
            String codtrad = this.Cod(rttrad ,"_" + funth + idlexema ); //Tipo si no hay para declaracion de variables, sufijo para variables
            this.emparejar(Token.ENDFN);
            //Una vez que tenemos las traducciones, generamos el string final
            //Cerramos el ámbito
            this.tsActual = tsActual.getPadre();
            return  rttrad + " " + funth + idlexema + " " + attrad + " {" + codtrad + " } " + spptrad; 
        }
        this.errorSintaxis(Token.FN); 
        return "";
    }
    
    /**
     * 
     * Spp  -> Fun Spp 
     * Spp -> epsilon
     * Spp.trad = Fun.trad || Spp.trad
     * Spp.trad = "" //Si epsilon 
     */
    public String Spp(String cadfunc , String tipoh){
        if(actual_tok.tipo == Token.FN){
            buffer_rules.append( " " +3);
            String funtrad = this.Fun(cadfunc , tipoh); 
            String spptrad = this.Spp(cadfunc, tipoh);
            return funtrad + spptrad; 
        }
        if(actual_tok.tipo == Token.EOF ||
                actual_tok.tipo == Token.BLQ ||
                actual_tok.tipo == Token.LET ||
                actual_tok.tipo == Token.PRINT || 
                actual_tok.tipo == Token.IF){
            //NO HACEMOS NADA MAS PORQUE ESTAMOS EN EPSILON!!
            buffer_rules.append( " " +4);
            return ""; 
        }
        this.errorSintaxis(Token.FN , Token.LET , Token.PRINT , Token.IF, Token.BLQ , Token.EOF); 
        return ""; 
    }
    
    /**
     * A -> pari Arg pard
     * A.trad := "(" || Arg.trad || ")"
     */
    public String  A(){
        if(this.actual_tok.tipo == Token.PARI){
            buffer_rules.append( " " +6);
            emparejar(this.actual_tok.tipo); 
            String argtrad = Arg("");
            this.emparejar(Token.PARD); 
            return "(" + argtrad + ")";  
        }
        this.errorSintaxis(Token.PARI); 
        return ""; 
    }
        
    /**
     * Arg -> id dosp Type Arg
     * Arg -> epsilon
     * Arg.trad := Type.trad ||" " ||id.lexema 
     */
    public String Arg(String coma){
        if(this.actual_tok.tipo == Token.ID){
            buffer_rules.append( " " +7);
            emparejar(Token.ID);           
            String idlexema = actual_tok.lexema; 
            emparejar(Token.DOSP); 
            String ttypetrad = Type();
            if( !this.tsActual.newSymb(new Simbolo(this.actual_tok.lexema , this.parserTipo(ttypetrad) , idlexema ))) this.errorSemantico(0);
            String argtrad = Arg(","); 
            return coma + ttypetrad + " " + idlexema ; 
        }
        if(this.actual_tok.tipo == Token.PARD){
            //EPSILON
            buffer_rules.append( " " +8);
            return ""; 
        }
        this.errorSintaxis(Token.ID , Token.PARD);
        return "";
    }
    
    /***
     * 
     * Rt -> ret Type
     * Rt -> epsilon
     * 
     */
    public String Rt(String tipoh){
        if(this.actual_tok.tipo == Token.RET){
            buffer_rules.append( " " +9);
            emparejar(Token.RET);
            String ttypetrad = Type();
            return ttypetrad; 
        }
        if(this.actual_tok.tipo == Token.FN 
                || this.actual_tok.tipo == Token.BLQ 
                || this.actual_tok.tipo == Token.LET 
                ||this.actual_tok.tipo == Token.PRINT 
                || this.actual_tok.tipo == Token.IF){
            //EPSILON
            buffer_rules.append( " " +10);
            if (!tipoh.equals("")) return tipoh; //Devolvemos el tipo del padre
            return "void"; //Cuando no hay tipo, la func será un void  
        }
        this.errorSintaxis(Token.FN ,Token.RET,  Token.LET , Token.PRINT , Token.IF, Token.BLQ ); 
        return ""; 
    }
    
    /**
     * 
     * Type -> Int  
     * Type -> Real
     * Type.trad := int
     * Type.trad :=float
     */
    public String Type(){
        if(this.actual_tok.tipo == Token.INT){
            buffer_rules.append( " " +11);
            emparejar(Token.INT); 
            return "int"; 
        }
        if(this.actual_tok.tipo == Token.REAL){
            buffer_rules.append( " " +12);
            emparejar(Token.REAL);
            return "float"; 
        }
        this.errorSintaxis(Token.INT , Token.REAL);
        return ""; 
    }
    
    /**
     * Cod -> I Codp
     * Cod.trad = I.trad || Codp.trad
     */
    public String Cod(String codth1, String codth2 ){
        if(this.actual_tok.tipo == Token.BLQ || 
                this.actual_tok.tipo == Token.LET ||
                this.actual_tok.tipo == Token.PRINT||
                this.actual_tok.tipo == Token.IF){
            buffer_rules.append( " " +13);
            String itrad = I(codth1, codth2 );
            String codptrad = Codp(codth1 , codth2);
            return itrad + codptrad; 
        }
        this.errorSintaxis(Token.LET , Token.PRINT , Token.IF, Token.BLQ );
        return ""; 
    }
    
    /**
     * Codp -> pyc I Codp 
     * Codp -> epsilon
     * 
     */
    public String Codp(String codpth1 , String codpth2){
        if(this.actual_tok.tipo == Token.PYC) {
           buffer_rules.append( " " +14);
           emparejar(Token.PYC);
           String itrad = I(codpth1 , codpth2 );
           String codptrad = Codp(codpth1 , codpth2 );
           return itrad + codptrad; 
           
        }if(this.actual_tok.tipo == Token.ENDFN ||
                this.actual_tok.tipo == Token.FBLQ){
            
            //EPSILON
            buffer_rules.append( " " +15);
            return "";
        }
        this.errorSintaxis(Token.ENDFN , Token.PYC , Token.FBLQ);
        return ""; 
    }
    
    /**
     * I -> Blq I.trad = Blq.trad 
     * I -> let id IT
     * I -> print E
     * I -> if E I Ip
     */
    public String I(String ith1 , String ith2 ){
        if(this.actual_tok.tipo == Token.BLQ){ //I.trad = Blq.trad  + "\n"
            buffer_rules.append( " " +16);
            String blqtrad = Blq(ith1, "_" + ith2);
            return blqtrad + "\n";
        }
        if(this.actual_tok.tipo == Token.LET){ //I.trad = I1.th ||" " || id.lexema || I2.th || It.trad ||";\n"  
            buffer_rules.append( " " +17);
            emparejar(Token.LET);
            emparejar(Token.ID);
            String idlexema = this.actual_tok.lexema; 
            
            Atributos ittrad = It(ith1 , ith2 , idlexema);
           
            return ittrad.getTipo() + " " + idlexema + ith2 + "; " + ittrad.getAsig() + ";\n"; //Devolvemos la traduccion con el tipo del ret  
        }
        if(this.actual_tok.tipo == Token.PRINT){ //I.trad := "print" || tipo_tabla_simb || "(" || e.trad || it2.th ||");\n"  
            buffer_rules.append( " " +18);
            emparejar(Token.PRINT);
            Atributos etrad = E();
            return "print" + etrad.getTipo() + "(" + etrad.getAsig() + ith2 + ");\n"; 
        }
        if(this.actual_tok.tipo  == Token.IF){//I.trad := "if(" || E.trad || I.trad || Ip.trad || "{"
            buffer_rules.append( " " +19);
            emparejar(Token.IF);
            Atributos etrad = E();
            //Creamos un nuevo ámbito para lo interno del if 
            this.tsActual = new TablaSimbolos(this.tsActual);
            String itrad= I(ith1 , ith2 ); 
            //Cerramos antes del else 
            this.tsActual = this.tsActual.getPadre();
            String iptrad = Ip(ith1 , ith2 );
            return "if(" + etrad.getAsig() + "){\n" + itrad + "}" + iptrad ;
        }
        this.errorSintaxis(Token.LET , Token.PRINT , Token.IF, Token.BLQ );
        return ""; 
    }
    
    /**
     * Ip -> else I fi
     * Ip -> fi
     * 
     */
    public String Ip(String ith1 , String ith2 ){
        if(this.actual_tok.tipo == Token.ELSE){
            buffer_rules.append( " " +20);
            emparejar(Token.ELSE);
            //Creamos un nuevo ámbito
            this.tsActual = new TablaSimbolos(this.tsActual); 
            String itrad = I(ith1 , "_" + ith2); //Entramos dentro de otro bloque, por lo que añadimos un "_"+
            emparejar(Token.FI);
            this.tsActual = this.tsActual.getPadre(); 
            return "else{\n" + itrad + "}\n";
        }
        if(this.actual_tok.tipo == Token.FI){
            buffer_rules.append( " " +21);
            emparejar(Token.FI);
            return "";
        }
        this.errorSintaxis(Token.ELSE , Token.FI );    
        return ""; 
    }
    
    /**
     * 
     * Blq -> blq Cod fblq 
     * Blq.trad := "{" || Cod.trad || "}"
     */
    public String Blq(String blqth1 , String blqth2){
        if(this.actual_tok.tipo == Token.BLQ){
            buffer_rules.append( " " +22);
            emparejar(Token.BLQ);
            //Creamos un nuevo ámbito
            this.tsActual = new TablaSimbolos(this.tsActual); 
            String codtrad = Cod(blqth1 , blqth2); 
            emparejar(Token.FBLQ);
            //Cerramos el ámbito
            this.tsActual = this.tsActual.getPadre();
            return "{" + codtrad + "}";
        }
        this.errorSintaxis(Token.BLQ);
        return "";
    }
    
    /**
     * IT -> dosp Type It.trad:= Type.trad 
     * IT -> asig E Ifa
     * IT -> epsilon
     */
    public Atributos It(String ith1 , String ith2 , String idlexemah){
        if(actual_tok.tipo == Token.DOSP){ //It.trad := Type.trad
            buffer_rules.append( " " +23);
            emparejar(Token.DOSP);
            String typetrad = Type(); 
            //Añadimos a la tabla 
            
            if( !this.tsActual.newSymb(new Simbolo(idlexemah , this.parserTipo(typetrad), idlexemah + ith2  ))) this.errorSemantico(0);
            return new Atributos(new String[] {typetrad , ""}); //Devolvemos la clase atributo con el tipo
           
        }
        if(actual_tok.tipo == Token.ASIG){ //It.trad:= ith2 ||  Ifa.trad ||" = " || E.trad
            buffer_rules.append( " " +24);
            emparejar(Token.ASIG);
            Atributos etrad = E(); 
            Atributos ifatrad = Ifa();
            //Añadimos a la tabla (Si no se había creado anterioremente)
            if( !this.tsActual.newSymb(new Simbolo(idlexemah , this.parserTipo(etrad.getTipo()), idlexemah + ith2  ))){
                //Comprobamos los timpos
                if(this.tsActual.searchSymb(idlexemah).tipo == 1 &&  this.parserTipo( etrad.getTipo()) == 2 ) this.errorSemantico(2);
                
            }
            
            return new Atributos(new String [] {etrad.getTipo() , ifatrad.getAsig() + ith2 + " = " + etrad.getAsig() });
           
        }
        if(actual_tok.tipo == Token.ELSE ||
                actual_tok.tipo == Token.FI || 
                actual_tok.tipo == Token.PYC || 
                actual_tok.tipo == Token.FBLQ || 
                actual_tok.tipo == Token.ENDFN){
            //EPSILON
            buffer_rules.append( " " +25);
            return new Atributos(new String[] {ith1 , ""}); //Devolvemos el heredado
        }
        
        this.errorSintaxis(Token.ENDFN , Token.DOSP , Token.PYC , Token.ELSE, Token.FI,  Token.FBLQ , Token.ASIG );
        return new Atributos(new String[]{}); 
    }
    
    /**
     * Ifa -> if E
     * Ifa -> epsilon
     * 
    */
    public Atributos Ifa(){
        if(actual_tok.tipo == Token.IF){ //Ifa.trad = "if(" || E.trad || ")"
            buffer_rules.append( " " +26);
            emparejar(Token.IF);
            Atributos etrad = E();
            return new Atributos(new String [] {etrad.getTipo() , "if(" + etrad.getAsig() + ")"}); //NO ESTOY SEGURO 
        }
        if(actual_tok.tipo == Token.ELSE ||
                actual_tok.tipo == Token.FI ||
                actual_tok.tipo == Token.PYC ||
                actual_tok.tipo == Token.FBLQ ||
                actual_tok.tipo == Token.ENDFN){
            //EPSILON
            buffer_rules.append( " " +27);
            return new Atributos(new String[] {"" , ""});
        }
        errorSintaxis(Token.ENDFN , Token.PYC , Token.IF , Token.ELSE , Token.FI, Token.FBLQ);
        return new Atributos(new String[]{}); 
    }
    
    /**
     * E -> T Ep
     * 
     */
    public Atributos E(){
        if(actual_tok.tipo == Token.ID  ||actual_tok.tipo == Token.NUMINT 
                ||actual_tok.tipo == Token.NUMREAL ||  
                actual_tok.tipo == Token.PARI) { //E.trad := " = " || T.trad || Ep.trad
            buffer_rules.append( " " +28);
            Atributos ttrad = T();
            Atributos eptrad = Ep(); 
            return new Atributos( new String[] { this.tiposhake(ttrad.getTipo(), eptrad.getTipo()), ttrad.getAsig() + eptrad.getAsig()}); 
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
        return new Atributos(new String[]{});
    }
    
    /**
     * 
     * Ep -> opas T Ep
     * Ep -> epsilon
     * 
     */
    public Atributos Ep(){
        if(actual_tok.tipo == Token.OPAS ){ //Ep.trad = opas.lexema || " "  || T.trad || Ep.trad
            buffer_rules.append( " " +29);
            emparejar(Token.OPAS );
            String opaslexema = this.actual_tok.lexema;
            Atributos ttrad = T();
            Atributos eptrad = Ep();
            return new Atributos(new String[] {this.tiposhake(ttrad.getTipo(), eptrad.getTipo()), opaslexema + " " + ttrad.getAsig() + eptrad.getAsig()});
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
            return new Atributos(new String[] {"" , ""});
        }
        errorSintaxis(Token.ENDFN, Token.PARD , Token.PYC , Token.LET , Token.PRINT , Token.IF , 
                        Token.ELSE , Token.FI, Token.BLQ,   Token.FBLQ , Token.OPAS);
        return new Atributos(new String[] {});
    }
    
    /**
     * T -> F Tp
    */
    public Atributos T(){
        if(actual_tok.tipo== Token.ID ||
                actual_tok.tipo == Token.NUMINT  || 
                actual_tok.tipo == Token.NUMREAL ||
                actual_tok.tipo == Token.PARI){ //T.trad := F.trad || Tp.trad
            buffer_rules.append( " " +31);
            Atributos ftrad= F(); 
            Atributos tptrad = Tp();
            //Tenemos que comprobar los tipos
            return new Atributos( new String[]{ this.tiposhake(ftrad.getTipo(), tptrad.getTipo()) , ftrad.getAsig() + tptrad.getAsig()}) ;
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
        return new Atributos(new String[] {});
    }
    
    /**
     * Tp -> opmd F Tp
     * Tp -> epsilon
     */
    public Atributos Tp(){
        if(actual_tok.tipo == Token.OPMD){
            buffer_rules.append( " " +32);
            emparejar(Token.OPMD);
            String opmdlexema = this.actual_tok.lexema; 
            Atributos ftrad = F();
            Atributos tptrad  = Tp();
            //TENEMOS QUE COMPROBAR LOS TIPOS
            
            return new Atributos(new String [] {this.tiposhake(ftrad.getTipo(), tptrad.getTipo()) , opmdlexema + ftrad.getAsig() + tptrad.getAsig() }); 
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
            return new Atributos(new String[] {"" , ""});
        }
        errorSintaxis(Token.ENDFN, Token.PARD , Token.PYC , Token.PRINT , Token.LET, Token.IF , 
                        Token.ELSE , Token.FI,  Token.BLQ,  Token.FBLQ , Token.OPAS , Token.OPMD);
        return new Atributos(new String[] {"" , ""});
    }
    
    /**
     * F -> id 
     * F -> numint 
     * F -> numreal 
     * F -> pari E pard
     */
    public Atributos F(){
        if(actual_tok.tipo == Token.NUMINT){
            buffer_rules.append( " " +34);
            emparejar(Token.NUMINT); 
            return new Atributos(new String[] {"int" , this.actual_tok.lexema});
        }
        if(actual_tok.tipo == Token.NUMREAL){
            buffer_rules.append( " " +35);
            emparejar(Token.NUMREAL);
            return new Atributos(new String[] {"float" , this.actual_tok.lexema});
        }
        if(actual_tok.tipo == Token.ID){
            buffer_rules.append( " " +36);
            emparejar(Token.ID); 
            //Comprobamos que exista
            if(this.tsActual.searchSymb(this.actual_tok.lexema) == null ) this.errorSemantico(1); 
            //Comprobamos que no sea func
            if(this.tsActual.searchSymb(this.actual_tok.lexema).tipo >= 3 ) this.errorSemantico(3);
            return new Atributos(new String[] {"id" , this.actual_tok.lexema});  
        }
        
        
        if( actual_tok.tipo == Token.PARI ){
            buffer_rules.append( " " +37);
            emparejar(Token.PARI);
            Atributos etrad = E();
            emparejar(Token.PARD);
            return new Atributos(new String[] {"()" , etrad.getAsig()} ); 
        }
        errorSintaxis(Token.ID, Token.PARI , Token.NUMINT , Token.NUMREAL );
        return new Atributos(new String[]{}); 
    }
}
