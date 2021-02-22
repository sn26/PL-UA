import java.util.ArrayList;

public class Token {

	public int fila;
	public int columna;
	public String lexema;
	public int tipo;		// tipo es: ID, ENTERO, REAL ...
	
	//Cadenas que vamos a mostrar como resultad, en la funcin to string 
	private String[] cad_results = {"(" , ")" , 
			":"  , "->" , "=" , ";" , "+ -" , "* /" , 
			"'fn'" ,"'endfn'" , "'int'" , "'real'" , "'let'" , "'if'" , "'else'", "'fi'" ,
			"'print'" , "'blq'" , "'fblq'" , "identificador" , "numero entero" , "numero real" , ""}; 
	
	public static final int
		PARI 		= 0, //(
		PARD		= 1, //) 
		DOSP            = 2, //:
		RET             = 3, //->
		ASIG		= 4, //=
		PYC		= 5, //;
		OPAS		= 6, //+ - 
		OPMD		= 7, // * /
		FN		= 8, //'fn'
		ENDFN		= 9, //'endfn'
		INT		= 10, //'int'
		REAL		= 11, //'real'
		LET		= 12, // 'let'
		IF              = 13, //'if'
		ELSE            = 14, //'else'
		FI              = 15, //'fi'
		PRINT           = 16, //'print' 
		BLQ		= 17, //'blq'
		FBLQ		= 18, //'fblq'
		ID		= 19, //identificador 
		NUMINT		= 20, //numero entero
		NUMREAL		= 21, //numero real
		EOF		= 22; //""

	
	public Token() {
		this.columna = 0;
		this.fila= 0; 
		this.lexema = "";
		this.tipo = 0;
		
		
	}
	
	/**
	 * Funcin que devuelve, para cada Token, la cadena de la tercera columna de la tabla del enunciado
	 * 
	 */
	public String toString(){
		//Dependiendo del tipo, devolveremos uno u otro
		return this.cad_results[this.tipo]; 
	}
}
