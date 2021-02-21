import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;
/*
 * Sirvent Navarro, Alvaro
 * 
 */
/*
 * A TENER EN CUENTA  
 * 	Principio de la subcadena más larga: siempre se intenta obtener
	el token más largo	
	Con algunos tokens (números, identificadores) nos tenemos que
	“pasar” leyendo la entrada (hay que leer uno o más caracteres
	que no pertenecen al token)
	El analizador léxico ignora los espacios en blanco, comentarios,
	saltos de línea,. . . pero sigue contando líneas y columnas
	Política de elección de palabra reservada sobre identificador: si
	una cadena puede ser palabra reservada y a la vez identificador,
	se elige la palabra reservada (p.ej. while)
	Errores léxicos: caracteres no permitidos en el lenguaje (p.ej. “$”)	
	o no permitidos en un contexto determinado (p.ej. “12.3” vs “.” o“.23”)
 * 
 */
import java.util.ArrayList;
import java.util.Arrays;

public class AnalizadorLexico {
	
	private static char EOF = (char)-1; //Para cuando lanzamos un error
	private RandomAccessFile fichero; //Fichero que vamos a usar
	private ArrayList<Character> buffer = new ArrayList<>(); 
	private Token actual_tok; //Token que vamos a ir devolviendo
	Integer[] final_states = {2,3,4,5,6,8,9,10,11,13,16,17,19,21,24,25};
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
			currentChar = (char)fichero.readByte();
			buffer.add(currentChar); // Por si tenemos que volver a alguno anterior (Lo iremos limpiando)
			return currentChar;
		}catch (EOFException e) {
			return EOF; // constante estática de la clase
		}catch (IOException e) {
			return ' '; // error lectura
		}
	}
	
	/**
	 * Método para devolver el token actual
	 * @return
	 */
	public Token siguienteToken() {
		Integer estado = 1; //Estado inicial
		char c = leerCaracter();  //Leemos ;
		Integer nuevo = 0;
		do
		{
			nuevo = delta(estado,c); // función de transición del DT
			if (nuevo == 17 || nuevo==26) errorLexico(nuevo);
			
			if (Arrays.asList(this.final_states).contains(nuevo)){ //ESTADO FINAL 
				devolverCaracteres(nuevo);
				return tokenAsociado(nuevo); //Devolvemos el tojen de lo anterior
				
			}
			else{
				estado = nuevo;
				c = leer();
			}
		} while (true);

	}
	
	/**
	 * Función que utilizamos cunaod tenemos un error en la lectura de la cadena (error de delta)
	 * 
	 */
	private void errorLexico(int nuevo) {
		
		return;
	}
	/**
	 * Función para sacar el estado en el que nos encontramos 
	 * @param estado 
	 * @param c
	 * @return
	 */
	private int delta(int estado, char c ) {
		switch(estado ) {
			case 1: 
				if(c=='(') return 2; //PARI	 
				if(c == ')') return 3; //PARD
				if(c==':') return 4; //DOSP
				if(c=='=') return 5; //ASSIGN
				if(c==';') return 6; //PYC
				if(c=='-') return 7;  //OPAS (-) O RETURN
				if(c=='+') return 10; //OPAS (+)
				if(c=='*') return 11; //OPMD (*)
				if(c=='/') return 12; //OPMD (/) o Comment
				if(Character.isLetter(c)) return 18; //ID o Palabra reservada
				if(Character.isDigit(c)) return 20; //NINT O NENTERO O NREAL
				return 26; //ERROR
			case 7: //-> O - 
				if(c=='>') return 8; //RETURN
				return 9; //OPAS (-)
			case 12: //OPMD (/) O (/*)
				if(c=='*') return 14; //Comment
				return 13;
			case 14: //(/*)
				if(c=='*') return 15;  
				if(c==(char)-1) return 17; //Error eof
				return 14; 
			case 15: //(/*) 
				if(c=='*') return 15;
				if(c=='/') return 16; //Terminamos el comentario 
				if(c==(char)-1 ) return 17; //Error LÉXICO
				return 14;
			case 18: //id
				if(Character.isLetter(c) || Character.isDigit(c)) return 18; 
				return 19; 
			case 20: //NINT NENTERO NREAL
				if(Character.isDigit(c)) return 20; 
				if(c=='.') return 22; //NENTERO NREAL
				return 21; //NINT
			case 22: //NENTERO NREAL
				if(Character.isDigit(c)) return 23; //NREAL
				return 25; //Nentero
			case 23://NREAL
				if(Character.isDigit(c)) return 23; 
				return 24; 
			default: 
				return 26; //Error
		}
	}
	
}
