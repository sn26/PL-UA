import java.util.ArrayList;

public class Token {

	public int fila;
	public int columna;

	public String lexema;

	public int tipo;		// tipo es: ID, ENTERO, REAL ...

	public static final int
		PARI 		= 0,
		PARD		= 1,
		DOSP            = 2,
		RET             = 3,
		ASIG		= 4,
		PYC		= 5,
		OPAS		= 6,
		OPMD		= 7,
		FN		= 8,
		ENDFN		= 9,
		INT		= 10,
		REAL		= 11,
		LET		= 12,
		IF              = 13,
		ELSE            = 14,
		FI              = 15,
		PRINT           = 16,
		BLQ		= 17,
		FBLQ		= 18,
		ID		= 19,
		NUMINT		= 20,
		NUMREAL		= 21,
		EOF		= 22;

	
	public Token() {
		this.columna = 0;
		this.fila= 0; 
		this.lexema = "";
		this.tipo = 0;
	}
	/**
	 * Funci�n que devuelve, para cada Token, la cadena de la tercera columna de la tabla del enunciado
	 * 
	 */
	public String toString(){
	        
	}
}
