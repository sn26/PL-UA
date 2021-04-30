/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */
#include<string.h>
#include<string>
struct Atributos{
	char* tipo; 
	char* asig; 
};
typedef struct {
   char *lexema;
   int fila,col;
   int tipo;
   string trad;
   Atributos atributos; 
} MITIPO;

#define YYSTYPE MITIPO

const int
		PARI 		= 0,
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
		EOF		= 22; //"fin de fichero"

#define ERRLEXICO    1
#define ERRSINT      2
#define ERREOF       3
#define ERRLEXEOF    4

void msgError(int nerror,int nlin,int ncol,const char *s);
