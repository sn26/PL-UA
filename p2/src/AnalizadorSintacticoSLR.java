import java.io.*; 
import java.util.*; 
import java.util.HashMap;
/**
 *
 * @author Alvar
 */
public class AnalizadorSintacticoSLR {
    private AnalizadorLexico lex; 
    private String buffer_rules;
    private Token actual_tok;
    public boolean print_rules_flag = true ;  
    private Stack<Integer> estados; //Donde iremos metiendo los estados por los que pasamos 
    
    private Map ir_a;
    public AnalizadorSintacticoSLR(AnalizadorLexico al){
        this.lex = al;
        this.buffer_rules = new String();
        estados= new  Stack<>();
        this.ir_a = new HashMap();
        this.init_map();
    }
    
    //Tabla 
    private final String[][] accion = {
        // 0,    1 , 2 ,   3 ,  4 ,     5 ,  6 ,  7  ,  8  , 9 , 10 ,    11 , 12  ,  13 , 14 ,  15 ,    16     , 17 
        // fn , id, pari, pard, endfn, ret, int, real, pyc, let, print, dosp, asig, opas, opmd, numint, numreal , $
        {"d4" , "" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //0
        {"" , "" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", "aceptar"} , //1
        {"" , "" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", "r1"}, //2
        {"d4" , "" , "", "", "", "" , "" , "" , "" , "r4", "r4" , "" , "" , "" , "" , "" , "", "r4"}, //3
        {"" , "d7" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, // 4
        {"" , "" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", "r2"}, //5
        {"d4" , "" , "", "", "", "" , "" , "" , "" , "r4", "r4" , "" , "" , "" , "" , "" , "", "r4"}, // 6
        {"" , "" , "d9", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //7
        {"" , "" , "", "", "", "" , "" , "" , "" , "r3", "r3" , "" , "" , "" , "" , "" , "", "r3"}, //8
        {"" , "" , "", "d10", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //9 
        {"r7" , "" , "", "", "", "d12" , "" , "" , "" , "r7", "r7" , "" , "" , "" , "" , "" , "", ""}, //10
        {"d4" , "" , "", "", "", "" , "" , "" , "" , "r4", "r4" , "" , "" , "" , "" , "" , "", "r4"}, //11
        {"" , "" , "", "", "", "" , "d15" , "d16" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //12
        {"" , "" , "", "", "", "" , "" , "" , "" , "d19", "d20" , "" , "" , "" , "" , "" , "", ""}, //13
        {"r6" , "" , "", "", "", "" , "" , "" , "" , "r6", "r6" , "" , "" , "" , "" , "" , "", ""}, //14
        {"r8" , "" , "", "", "r8", "" , "" , "" , "r8" , "r8", "r8" , "" , "" , "" , "" , "" , "", ""}, //15
        {"r9" , "" , "", "", "r9", "" , "" , "" , "r9" , "r9", "r9" , "" , "" , "" , "" , "" , "", ""},  //16
        {"" , "" , "", "", "d21", "" , "" , "" , "d22" , "", "" , "" , "" , "" , "" , "" , "", ""}, //17
        {"" , "" , "", "", "r11", "" , "" , "" , "r11" , "", "" , "" , "" , "" , "" , "" , "", ""}, //18
        {"" , "d23" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //19
        {"" , "d29" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "d27" , "d28", ""}, //20
        {"r5" , "" , "", "", "", "" , "" , "" , "" , "r5", "r5" , "" , "" , "" , "" , "" , "", "r5"}, //21
        {"" , "" , "", "", "", "" , "" , "" , "" , "d19", "d20" , "" , "" , "" , "" , "" , "", ""}, //22
        {"" , "" , "", "", "r16", "" , "" , "" , "r16" , "", "" , "d32" , "d33" , "" , "" , "" , "", ""}, //23
        {"" , "" , "", "", "r13", "" , "" , "" , "r13" , "", "" , "" , "" , "d34" , "" , "" , "", ""}, //24
        {"" , "" , "", "", "r18", "" , "" , "" , "r18" , "", "" , "" , "" , "r18" , "d35" , "" , "", ""} , //25
        {"" , "" , "", "", "r20", "" , "" , "" , "r20" , "", "" , "" , "" , "r20" , "r20" , "" , "", ""}, //26
        {"" , "" , "", "", "r21", "" , "" , "" , "r21" , "", "" , "" , "" , "r21" , "r21" , "" , "", ""}, //27
        {"" , "" , "", "", "r22", "" , "" , "" , "r22" , "", "" , "" , "" , "r22" , "r22" , "" , "", ""}, //28
        {"" , "" , "", "", "r23", "" , "" , "" , "r23" , "", "" , "" , "" , "r23" , "r23" , "" , "", ""}, // 29
        {"" , "" , "", "", "r10", "" , "" , "" , "r10" , "", "" , "" , "" , "" , "" , "" , "", ""}, //30 
        {"" , "" , "", "", "r12", "" , "" , "" , "r12" , "", "" , "" , "" , "" , "" , "" , "", ""}, //31
        {"" , "" , "", "", "", "" , "d15" , "d16" , "" , "", "" , "" , "" , "" , "" , "" , "", ""}, //32
        {"" , "d29" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "d27" , "d28", ""}, //33
        {"" , "d29" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "d27" , "d28", ""} , //34 
        {"" , "d29" , "", "", "", "" , "" , "" , "" , "", "" , "" , "" , "" , "" , "d27" , "d28", ""} , //35
        {"" , "" , "", "", "r14", "" , "" , "" , "r14" , "", "" , "" , "" , "" , "" , "" , "", ""}, //36 
        {"" , "" , "", "", "r15", "" , "" , "" , "r15" , "", "" , "" , "" , "d34" , "" , "" , "", ""}, //37
        {"" , "" , "", "", "r17", "" , "" , "" , "r17" , "", "" , "" , "" , "r17" , "d35" , "" , "", ""}, //38
        {"" , "" , "", "", "r19", "" , "" , "" , "r19" , "", "" , "" , "" , "r19" , "r19" , "" , "", ""}//39
        }; 
        
    private final int longitud_parte_derecha[] = {0 , 1, 2 , 2, 0 ,8, 2 , 0 ,1 ,1 , 3 , 1 , 3 , 2, 2 , 2 , 0 , 3 , 1 , 3 , 1, 1 ,1 ,1 }; 
    private final Integer[] translator = { 2, 3, 11 , 5 , 12 , 8 , 13 , 14, 0 , 4, 6 , 7 , 9 , 10 , 1, 15 , 16 , 17}; // Pasar del tipo que tenemos en el token, al que tenemos en las tablas TOKEN.tipo -> TablasOrden
    private final Integer[] translator_inverted = {8 , 14 , 0 , 1 , 9 ,3, 10, 11, 5 , 12, 13, 2 , 4, 6 , 7 , 15, 16, 17}; //TABLASORDEN -> Token.tipo 
    private final Integer[]parte_izq = {0, 0 ,1, 2 ,2 ,3, 4 ,4 , 5 , 5 , 6 , 6 , 7 , 7 , 8 , 8 , 8 , 9,9 ,10, 10, 11, 11, 11};                        // S, SP , SPP, FUN, RT, TYPE, COD, I , IT, E , T ,F 
    
    private void init_map(){
        ir_a.put(0 , new Integer[] {1, 2, null , 3});
        ir_a.put(3 , new Integer[] {null, null, 5 , 6});
        ir_a.put(6 , new Integer[] {null, null, 8, 6 });
        ir_a.put(10 , new Integer[] {null, null, null , null, 11});
        ir_a.put(11 , new Integer[] {null, null, 13 , 6});
        ir_a.put(12 , new Integer[] {null, null, null , null, null, 14});
        ir_a.put(13 , new Integer[] {null, null, null , null, null, null, 17, 18});
        ir_a.put(20 , new Integer[] {null, null, null , null, null, null, null, null, null , 24, 25, 26 });
        ir_a.put(22 , new Integer[] {null, null, null , null, null, null, null, 30 });
        ir_a.put(23 , new Integer[] {null, null, null , null, null, null, null, null, 31 });
        ir_a.put(32 , new Integer[] {null, null, null , null, null, 36});
        ir_a.put(33 , new Integer[] {null, null, null , null, null, null, null, null, null , 37, 25, 26 });
        ir_a.put(34 , new Integer[] {null, null, null , null, null, null, null, null, null , null, 38, 26 });
        ir_a.put(35 , new Integer[] {null, null, null , null, null, null, null, null, null , null, null , 39 });
    }        
    /**
     * Función para analizar los tokens de manera ascendente (TABLAS)
     */
    public void analizar(){
        this.estados = new Stack();
        estados.push(0);
        this.actual_tok = this.lex.siguienteToken();
        boolean finished = false;
        do{
            if(accion[estados.peek()][this.translator[this.actual_tok.tipo]].contains("d")){
                estados.push(Integer.parseInt((accion[estados.peek()] [this.translator[this.actual_tok.tipo]]).split("d")[1]));
                this.actual_tok = this.lex.siguienteToken();
            }else if( accion[this.estados.peek()] [this.translator[this.actual_tok.tipo]].contains("r") && !accion[estados.peek()] [this.translator[this.actual_tok.tipo]].equals("aceptar")  ){
                Integer regla = Integer.parseInt(accion[this.estados.peek()] [this.translator[this.actual_tok.tipo]].split("r")[1]); 
                //System.out.println("Estamos entrando con la long derecha de " +longitud_parte_derecha[Integer.parseInt((accion[estados.peek()] [this.translator[this.actual_tok.tipo]]).split("r")[1])] );
                //System.out.println("La regla es la " +Integer.parseInt(accion[estados.peek()] [this.translator[this.actual_tok.tipo]].split("r")[1]) ); 
                Integer actual_long = longitud_parte_derecha[Integer.parseInt( (accion[estados.peek()] [this.translator[this.actual_tok.tipo]]).split("r")[1])];
                for( int i = 0; i< actual_long; i++){
                    
                    this.estados.pop();
                    //System.out.println("Estamos entrando y nos queda un tam de " + estados.size() );
                }   
                //sea p el estado en la cima de la pila
                //sea A la parte izquierda de la regla k
                //System.out.println("Estamos en el estado " + estados.peek());
                //System.out.println("Estamos en el arr " + Arrays.toString(((Integer[]) ir_a.get(estados.peek())))); 
                //System.out.println("EL VALOR QUE VAMOS A METER ES EL " + ((Integer[]) ir_a.get(estados.peek()))[this.parte_izq[regla]]);
                //System.out.println("LA REGLA ES LA " +this.parte_izq[regla] );
                estados.push(((Integer[]) ir_a.get(estados.peek()))[this.parte_izq[regla]]);
                this.buffer_rules = Integer.toString(regla) + " " + this.buffer_rules;
            }else if( accion[estados.peek()] [this.translator[this.actual_tok.tipo]].equals("aceptar")) {
                finished = true;
            } 
            else{   
                this.error(); 
            }
        
        }while(finished != true);
       if(this.print_rules_flag) System.out.println(this.buffer_rules);
       
    }
    
    /**
     * Función que recorre la pila de los estados, y los saca en orden
     */
    private void error(){
        ArrayList<Integer> posibles = new ArrayList<>();
        for(int i = 0; i<this.translator.length ; i++ ){ //RECORREMOS EN EL ORDEN DEL TOKEN.TIPO
            if(accion[this.estados.peek()][translator[i]].contains("r") || accion[this.estados.peek()][translator[i]].contains("d") ){
                posibles.add(translator_inverted[translator[i]]); //Añadimos como TOKEN.TIPO
            }
        }
        
        this.errorSintaxis( posibles.stream().mapToInt(i -> i).toArray() ); 
    }
    
    private String get_errorString(String err , int ... errores_args){
        for(int arg : errores_args ){
            this.actual_tok.tipo= arg;
            err = err + "" + this.actual_tok.toString();
        } 
        return err + " \n";
    }
    
    public final void errorSintaxis(int ... errores_args){
        
        if(this.actual_tok.tipo != Token.EOF){
            System.err.print(get_errorString("Error sintactico (" 
                  + this.actual_tok.fila +"," + this.actual_tok.columna + 
                  "): encontrado '" + this.actual_tok.lexema + "', esperaba" , errores_args));
            System.exit(-1);
        }
        System.err.print(get_errorString("Error sintactico: encontrado fin de fichero, esperaba" , errores_args));
        System.exit(-1);
    }
}
