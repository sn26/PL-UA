/*------------------------------ ejemplo.l -------------------------------*/
NUM    [0-9]
AZS    [a-zA-Z]
AZSNUM   [a-zA-Z0-9]

%{
  
#include <string.h> 
#include <string>
#include <iostream>

using namespace std;

#include "comun.h"
#include "ejemplo.tab.h"

int col = 1,
    fila = 1;

int findefichero = 0;

int ret(int token);  
// función que actualiza 'nlin' y 'ncol' y devuelve el token

void msgError(int nerror, int nlin,int ncol,const char *s);
// función para producir mensajes de error

%}

%x COMENTARIO

%%
%{
/* codigo local */
%}

" "                {ncol++;}
[\t]               {ncol++;}
[\n]               {nlin++;ncol=1;}
"//"(.)*           {; /* comentarios de una linea, no hacer nada */} 
"/*"                    {ncol += strlen(yytext);BEGIN(COMENTARIO);}
<COMENTARIO>[^/*\n]+    {ncol += strlen(yytext);}
<COMENTARIO>\n          {nlin++;ncol=1;}
<COMENTARIO><<EOF>>     {msgError(ERRLEXEOF,-1,-1,"");}
<COMENTARIO>"*/"        {ncol+=strlen(yytext); BEGIN(INITIAL);}
<COMENTARIO>[*/]        {ncol += strlen(yytext);}
"("                 {return ret(pari , PARI);}
")"                 {return ret(pard , PARD);}
":"                 {return ret(dosp , DOSP); }
"="                 {return ret(asig ,ASIG); }
";"                 {return ret(pyc , pyc );}
""
"" 


.                  {msgError(ERRLEXICO,nlin,ncol,yytext);}

%%

int yywrap(void) {findefichero=1; return 1;} /* para no tener que linkar con la
                                libreria del lex */


int ret(int token , int tipo)
{
   yylval.lexema=strdup(yytext);
   yylval.fila=nlin;
   yylval.col=ncol;
   yyval.tipo= tipo;
   ncol+=(strlen(yytext));
   return(token);
}
