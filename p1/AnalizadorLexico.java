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

public class AnalizadorLexico {
	
	private static char EOF = (char)-1; //Para cuando lanzamos un error
	private RandomAccessFile fichero; //Fichero que vamos a usar
	private ArrayList<Character> buffer = new ArrayList<>(); 
	
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
			if(currentChar != ' ' ) { 
				buffer.add(currentChar); // Por si tenemos que volver a alguno anterior
			}else buffer.clear(); //Cuando hemos terminado la palabra, borramos lo que teníamos en el buffer
			return currentChar;
		}catch (EOFException e) {
			return EOF; // constante estática de la clase
		}catch (IOException e) {
			return ' '; // error lectura
		}
	}
	
	public analizadorLex() {
		Integer estado = 1; //Estado inicial
		char c = leerCaracter();  //Leemos ;
		Integer nuevo = 0;
		do
		{
			nuevo = delta(estado,c); // función de transición del DT
			if (nuevo == EOF) errorLexico(...);
			if (esFinal(nuevo)){
				devolverCaracteres(nuevo);
				return tokenAsociado(nuevo); //Devolvemos el tojen de lo anterior
				
			}
			else{
				estado = nuevo;
				c = leer();
			}
		} while (true);

	}

	private int delta(int estado, char c ) {
		
		switch(estado ) {
			case 1: if(c=='(') return 2; //PARI	 
			case 2: if(c==')') return 3; //PARD
			case 3: if(c==':') return 4; //DOSP
			case 4: if(c== '=') return 5; //Asign
			case 5: if(c==';') return 6; //PyC
			case 6: if(c=='-') {
				//Tendremos que leer el siguiente, para saber de qué tipo es
				if(c=='>') return 7; //Return
				else return 8; //opas
			}
			case 7: if(c == '+') {
				
			}
		}
		
		return 1; 
	}
	
}
