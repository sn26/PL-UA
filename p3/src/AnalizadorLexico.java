import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Arrays;

public class AnalizadorLexico {
	
	private static char EOF = (char)-1; //Para cuando lanzamos un error
	
	private RandomAccessFile fichero; //Fichero que vamos a usar
	
	private ArrayList<Character> buffer = new ArrayList<>(); 
	
	private Token actual_tok = new Token(); //Token que vamos a ir devolviendo
	
	private Integer[] final_states = {2,3,4,5,6,8,9,10,11,13,19,21,24,25}; //NO SE INCLUYEN LOS ESTADOS FINALES POR ERROR EN LA LECTURA (17, 26) NI EL ESTADO DE FINAL DE COMENTARIO (16) 
	
	private int rollback = 0; //Contador de los caracteres que tenemos que ir hacia atras (En el caso de que haya que hacerlo)
	//FILA Y COL DEL FICHERO	
	private int fila = 1; 
	private int col =0; 
	
	public AnalizadorLexico(RandomAccessFile ra ){
		this.fichero = ra; 
	}
	
	/*
	 * Leer fichero caracter a caracter
	 */
	public char leerCaracter()
	{
            char currentChar;
            try {
                if(rollback > 0){

                    currentChar = this.buffer.get(0);
                    //System.out.println("Estamos entrando con " + this.buffer.get(0));
                    rollback --;
                    //System.out.println("Mi char es " + currentChar + " Y mi fila es " + this.fila);  
                    //this.file_position_manager(currentChar);
                    this.col ++; 
                    //System.out.println(" Y mi nueva fila es " + this.fila);  
                    return currentChar; 
                }
                currentChar = (char)fichero.readByte();	
                
                buffer.add(currentChar); // Por si tenemos que volver a alguno anterior (Lo iremos limpiando)
                //this.file_position_manager(currentChar); 
                this.col ++; 
                //if(currentChar == '\n') fila--; // (Lo sumaremos más adelante)
                return currentChar;
            }catch (EOFException e) {
                
                buffer.add(EOF);
                this.col ++; 
                return EOF; // constante estatica de la clase
            }catch (IOException e) {
                buffer.add(' ');
                this.col ++; 
                return ' '; // error lectura
            }
	}
	
	/**
	 * Funcion para actualizar la fila y la columna por la que vamos actualmente 
	 * @param currentChar
	 */
	/*private void file_position_manager(char currentChar  ) {
		if(currentChar == '\n') {
			this.col = 0; 
			//System.out.println("Estamos por la fila " + this.fila ); 
			this.fila ++; 
			//System.out.println("Estamos por la fila " + this.fila );  
			return; 
		}else this.col++; 
	}*/
	/**
	 * Metodo para devolver el token actual
	 * @return
	 */
	public Token siguienteToken() {
            Integer estado = 1; //Estado inicial
            char c = leerCaracter();  //Leemos ;
            Integer nuevo = 0;
            do
            {
                nuevo = delta(estado,c); // funcin de transicin del DT
                if (nuevo == 17 || nuevo==26 ) {
                    estado = 1; //Reseteamos el estado, por si ha saltado el error por un salto de lnea, o por un espacio
                    errorLexico(nuevo , c); //CUando encontamos un error, salimos de la ejecucicin con System.exit(-1) 
                    if(c == (char)-1 ) return this.actual_tok; //Devolvemos el token, porque hemos llegado al final del archivo      
                    nuevo = 1;
                }
                if (Arrays.asList(this.final_states).contains(nuevo)){ //ESTADO FINAL 
                    //if(c == '\n' ) this.fila --; 
                    devolverCaracteres(nuevo);
                    //Seteamos las filas finales del token que vamos a devolver
                    this.actual_tok.fila  = this.fila;
                    //if(c == '\n') this.fila ++;  
                    return this.actual_tok; //Devolvemos el token de lo anterior
                }
                else{
                    estado = nuevo;
                    c = leerCaracter();  //Leemos el siguiente caracter que compone nuestra cadena;
                }
            } while (true);

	}
	
	/**
	 * Mtodo para sacar el lexema actual
	 * @param actual_rollback
	 * @return
	 */
	private String get_lexema(int actual_rollback) {
            String final_cad = ""; 
            for(int i =0; i<buffer.size() -actual_rollback ; i++) { 
                final_cad = final_cad + buffer.get(i);
            }
            return final_cad; 
	}
	
	/**
	 * Donde haremos el "rollback"
	 * @param nuevo
	 */
	private void devolverCaracteres(Integer nuevo) {
            int actual_rollback =1;
            if(nuevo == 19 ) { //Miraremos todos los id
                //Cogemos la cadena del buffer, y miramos si coincide con alguna de las palabras reservadas
                //ES IMPORTANTE TENER EN CUENTA EL ROLLBACK!
                String final_cad = this.get_lexema(actual_rollback);
                this.actual_tok.lexema = final_cad; 
                //System.out.println("La cad final es " + final_cad ); 
                this.actual_tok.columna = this.col - (buffer.size() -1);  
                //System.out.println("Estamos en la col " + this.col + "Con un buffer de " + buffer.size());
                while(buffer.size() > actual_rollback ) buffer.remove(0);
                //System.out.println("Lo que nos queda es " + buffer.get(0)); 
                this.rollback = actual_rollback; 
                this.col = col - actual_rollback; 
                //System.out.println("Estamos en la col " + this.actual_tok.columna);
                //System.out.println("ESTAMOS ENTRANDO CON EL LEXEMA " + final_cad + " buffer.size " + buffer.size() );
                switch(final_cad) {
                    case "fn":
                        this.actual_tok.tipo = actual_tok.FN;
                        return; 
                    case "endfn": 
                        this.actual_tok.tipo = actual_tok.ENDFN;
                        return; 
                    case "int": 
                        this.actual_tok.tipo = actual_tok.INT;
                        return; 
                    case "real":
                        this.actual_tok.tipo = actual_tok.REAL;
                        return;
                    case "blq":
                        this.actual_tok.tipo = actual_tok.BLQ;
                        return;
                    case "fblq": 
                        this.actual_tok.tipo = actual_tok.FBLQ;
                        return; 
                    case "let":
                        this.actual_tok.tipo = actual_tok.LET; 
                        return; 
                    case "if": 
                        this.actual_tok.tipo = actual_tok.IF; 
                        return; 
                    case "else": 
                        this.actual_tok.tipo = actual_tok.ELSE; 
                        return; 
                    case "fi": 
                        this.actual_tok.tipo = actual_tok.FI; 
                        return; 
                    case "print": 
                        this.actual_tok.tipo = actual_tok.PRINT;
                        return; 
                    default: 
                        this.actual_tok.tipo = actual_tok.ID; 
                        return; 
                }
                    
            }
            if(nuevo == 9 || nuevo == 13 || nuevo == 21 || nuevo == 24 || nuevo == 25) {
                if(nuevo == 25) actual_rollback= 2; 
                String final_cad = this.get_lexema(actual_rollback);
                this.actual_tok.lexema = final_cad; 
                this.actual_tok.columna = this.col - (buffer.size() -1)  ;  
                while(buffer.size() > actual_rollback ) buffer.remove(0);
                this.rollback = actual_rollback; 
                this.col = col - actual_rollback; 
                return; 
            }
            //Cuando no es ningn estado final con rollback
            String final_cad = this.get_lexema(0);
            this.actual_tok.lexema = final_cad;
            //System.out.println("Estamos en la col " + this.col);
            //System.out.println("ESTAMOS ENTRANDO CON EL LEXEMA " + final_cad + " buffer.size " + buffer.size() );
            this.actual_tok.columna = this.col - (buffer.size() -1) ;  
            this.rollback = 0; 
            this.buffer.clear();
            return; 
	}
	
	
	/**
	 * Funcin que utilizamos cunaod tenemos un error en la lectura de la cadena (error de delta)
	 * 
	 */
	private void errorLexico(int nuevo , char last_char ) {
           
            if(nuevo == 17) {
                buffer.clear( ); 
                System.err.println("Error lexico: fin de fichero inesperado");
                System.exit(-1);
            }
		
            if(last_char == '\n' || last_char == '\t' || last_char == ' '   ) {
                //System.out.println("ESTAMOS ENTRANDO CON " + buffer.size() + " Y CON EL CHAR " + last_char );
                //buffer.remove(buffer.size() - 1 ); 
                //System.out.println("Estamos entrando con " + last_char ); 
                
                if(last_char == '\n') {
                    this.fila ++; 
                    this.col = 0; 
                }
                buffer.clear(); 
                return ;
            }
            if(last_char == (char)-1 ) {
                this.actual_tok.tipo = this.actual_tok.EOF;
                this.actual_tok.fila = this.fila; 
                this.actual_tok.columna = this.col;
                buffer.clear( ); 
                return; 
            }
           
            
            System.err.println("Error lexico ("
                            + this.fila + "," + this.col + "): "
                            + "caracter '" + last_char + "' incorrecto"); 
            System.exit(-1); 
	}
	
	/**
	 * Funcin para sacar el estado en el que nos encontramos 
	 * @param estado 
	 * @param c
	 * @return
	 */
	private int delta(int estado, char c ) {
    	//System.out.println("ESTAMOS ENTRANDO CON " + c  + " Y con el estado " + estado); 
        switch(estado ) {
            case 1: 
                if(c=='(') {
                    this.actual_tok.tipo = actual_tok.PARI;
                    return 2; //PARI	 
                }
                if(c == ')') {
                    this.actual_tok.tipo = actual_tok.PARD; 
                    return 3; //PARD
                }
                if(c==':') {
                    this.actual_tok.tipo = actual_tok.DOSP; 
                    return 4; //DOSP
                }
                if(c=='=') {
                    this.actual_tok.tipo = actual_tok.ASIG; 
                    return 5; //ASSIGN
                }
                if(c==';') {
                    this.actual_tok.tipo = actual_tok.PYC; 
                    return 6; //PYC
                }
                if(c=='-') return 7;  //OPAS (-) O RETURN
                if(c=='+') {
                    this.actual_tok.tipo = actual_tok.OPAS; 
                    return 10; //OPAS (+)
                }
                if(c=='*') {
                    this.actual_tok.tipo = actual_tok.OPMD; 
                    return 11; //OPMD (*)
                }
                if(c=='/') return 12; //OPMD (/) o Comment

                if(Character.isLetter(c)) return 18; //ID o Palabra reservada
                if(Character.isDigit(c)) return 20; //NINT O NENTERO O NREAL
                
                
                return 26; //ERROR
            case 7: //-> O - 
                if(c=='>') {
                    this.actual_tok.tipo = actual_tok.RET; 
                    return 8; //RETURN
                }
                this.actual_tok.tipo = actual_tok.OPAS; 
                return 9; //OPAS (-)
            case 12: //OPMD (/) O (/*)
                if(c=='*') return 14; //Comment
                this.actual_tok.tipo = this.actual_tok.OPMD; 
                return 13;
            case 14: //(/*)
                if(c == '\n') {
                    this.col = 0; 
                    this.fila++; 
                }
                if(c=='*') return 15;  
                if(c==(char)-1) return 17; //Error eof
                return 14; 
            case 15: //(/*) 
                if(c == '\n') {
                    this.col = 0; 
                    this.fila++; 
                }
                if(c=='*')return 15;
                if(c=='/'){
                    buffer.clear();
                    return 1; 	
                }
                if(c==(char)-1 ) return 17; //Error eof

                return 14;
            case 18: //id
                if(Character.isLetter(c) || Character.isDigit(c)){
                    //System.out.println("Sigo en id con " + c ); 

                    return 18; //Continuamos leyendo el identificador
                }
                this.actual_tok.tipo = this.actual_tok.ID; 
                //System.out.println("Estamos saliendo con " + c ); 
                return 19; 
            case 20: //NINT NENTERO NREAL
                if(Character.isDigit(c)) return 20; 
                if(c=='.') return 22; //NENTERO NREAL
                this.actual_tok.tipo = this.actual_tok.NUMINT; 
                return 21; //NINT
            case 22: //NENTERO NREAL
                if(Character.isDigit(c)) return 23; //NREAL
                this.actual_tok.tipo = this.actual_tok.NUMINT; 
                return 25; //Nentero
            case 23://NREAL
                if(Character.isDigit(c)) return 23; 
                this.actual_tok.tipo = actual_tok.NUMREAL; 
                return 24; 
            default: 
                return 26; //Error
            }
	}
	
}
