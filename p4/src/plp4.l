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
""

"print"            {return ret(print);}
        /* Las palabras reservadas deben aparecer antes de la regla que
          reconoce los identificadores, para evitar que sean reconocidas
          como identificadores en lugar de como palabras reservadas */            
{L}({LD})*         {return ret(id);}
{D}+               {return ret(numentero);}
{D}+(\.){D}+       {return ret(numreal);}
"+"                {return ret(opas);}
"-"                {return ret(opas);}
"("                {return ret(pari);}
")"                {return ret(pard);}
";"                {return ret(pyc);}
","                {return ret(coma);}
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
