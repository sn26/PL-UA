/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */
#include<string>
typedef struct {
   char *lexema;
   int nlin,ncol;
   int tipo;
   string trad;
} MITIPO;

#define YYSTYPE MITIPO


#define ERRLEXICO    1
#define ERRSINT      2
#define ERREOF       3
#define ERRLEXEOF    4

void msgError(int nerror,int nlin,int ncol,const char *s);
