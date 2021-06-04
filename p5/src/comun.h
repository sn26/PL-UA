/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */

struct Atributos{
	string tipo; 
	string asig;
	
};
typedef struct {
   char *lexema;
   int fila,col;
   int tipo;
   string trad;
   int numint; 
   Atributos atributos; 
   unsigned dir; 
   unsigned tam; 
} MITIPO;

#define YYSTYPE MITIPO
const int
		INT		= 0, //'int'
		REALT		= 1, //'real'
		
		PARI 		= 10,
      	PARD		= 11, //) 
		DOSP            = 2, //:
		
		//RET             = 3, //->
		ASIG		= 4, //=
		PYC		= 5, //;
		OPAS		= 6, //+ - 
		OPMD		= 7, // * /
		FN		= 8, //'fn'
		ENDFN		= 9, //'endfn'
		
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
		//NUEVOS
		ARRAYT 		= 3, 
		VAR = 22, 
		READ = 23,
		WHILE = 24,
		FOR = 25, 
		COMA = 26,
		CORI = 27, 
		CORD = 28;
		


//***-------------------- en comun.h -------------------------------
const int ERRLEXICO=1,
          ERRSINT=2,
          ERREOF=3,
          ERRLEXEOF=4,
          
          ERR_YADECL=5,
          ERR_NODECL=6,
          ERR_NOCABE=7,

          ERR_IFWHILE=8,
          
          ERR_DIM=9,
          ERR_FALTAN=10,
          ERR_SOBRAN=11,
          ERR_INDICE_ENTERO=12,
          
          ERR_ASIG=13,
          ERR_MAXTEMP=14;


void errorSemantico(int nerror,int fila,int columna,const char *s);
void msgError(int nerror,int nlin,int ncol,const char *s);

/*
#define ERRLEXICO    1
#define ERRSINT      2
#define ERREOF       3
#define ERRLEXEOF    4
*/
void msgError(int nerror,int nlin,int ncol,const char *s);