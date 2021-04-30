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
#include "plp4.tab.h"

int col = 1,
    fila = 1;

int findefichero = 0;

int ret(int token , int tipo);  
// función que actualiza 'nlin' y 'ncol' y devuelve el token

void msgError(int nerror, int nlin,int ncol,const char *s);
// función para producir mensajes de error

%}

%x COMENTARIO

%%
%{
/* codigo local */
%}

" "                {col++;}
[\t]               {col++;}
[\n]               {fila++;col=1;}
"//"(.)*           {; /* comentarios de una linea, no hacer nada */} 
"/*"                    {col += strlen(yytext);BEGIN(COMENTARIO);}
<COMENTARIO>[^/*\n]+    {col += strlen(yytext);}
<COMENTARIO>\n          {fila++;col=1;}
<COMENTARIO><<EOF>>     {msgError(ERRLEXEOF,-1,-1,"");}
<COMENTARIO>"*/"        {col+=strlen(yytext); BEGIN(INITIAL);}
<COMENTARIO>[*/]        {col += strlen(yytext);}
"("                 {return ret(pari , PARI);}
")"                 {return ret(pard , PARD);}
":"                 {return ret(dosp , DOSP); }
"="                 {return ret(asig ,ASIG); }
";"                 {return ret(pyc , PYC);}
"->"                {return ret(rettok , RET ); }
"-"                 {return ret(opas , OPAS); }
"+"                 {return ret(opas , OPAS ); }
"*"                 {return ret(opmd , OPMD); }
"/"                 {return ret(opmd , OPMD ); }
"fn"                {return ret(fn ,FN ); }
"endfn"             {return ret(endfn , ENDFN); }
"int"               {return ret(inttok , INT ); }
"real"              {return ret(real , REAL ); }
"blq"               {return ret(blq, BLQ); }
"fblq"              {return ret(fblq , FBLQ); }
"let"               {return ret(let , LET); }
"if"                {return ret(iftok , IF ); }
"else"              {return ret(elsetok , ELSE ); }
"fi"                {return ret(fi, FI); }
"print"             {return ret(print , PRINT); }
{AZS}({AZSNUM})*    {return ret(id , ID);}
{NUM}+              {return ret(numint , NUMINT); }
{NUM}+(\.){NUM}+    {return ret(numreal , NUMREAL); }
.                  {msgError(ERRLEXICO,fila,col,yytext);}

%%

int yywrap(void) {findefichero=1; return 1;} /* para no tener que linkar con la
                                libreria del lex */


int ret(int token , int tipo)
{
   yylval.lexema=strdup(yytext);
   yylval.fila=fila;
   yylval.col=col;
   yylval.tipo= tipo;
   yylval.atributos.tipo = ""; 
   yylval.atributos.asig = ""; 
   col+=(strlen(yytext));
   return(token);
}
