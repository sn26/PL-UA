/**
* Sirvent Navarro, Álvaro
*/ 
//DEFINIMOS LOS TOKEN
%token pari pard
%token dosp
%token rettok 
%token asig 
%token pyc 
%token opas opmd
%token fn endfn 
%token inttok real
%token let 
%token iftok elsetok fi
%token print
%token blq fblq 
%token id
%token numint numreal
%token eof

%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
#include "comun.h"
#include "TablaSimbolos.h"


extern int col, fila, findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);
const int ERRYADECL=1,ERRNODECL=2,ERRVOID=3,ERRNOSIMPLE=4,ERRNOENTERO=5;
void errorSemantico(int nerror,char *lexema,int fila,int columna);

TablaSimbolos *tsActual = new TablaSimbolos(NULL); 

string tipoMayus(string tipo);
int tipoShake(int type1,  int type2);
int parserTipo(string tipo , char * lexema, int fila, int columna  );
%}

%% 

S : Sp { 
    /* Primero, comprobaremos que después del programa no hay ningún token más*/
    int tk = yylex(); 
    if(tk!= 0) yyerror(""); 
    $$.trad = $1.trad; 
    cout<<$$.trad; 
}
; 
Sp : Fun Spp {
    $$.trad = $1.trad + $2.trad; 
    $$.atributos.asig = "";
}
;

Spp : Fun Spp { 
                $$.trad = $1.trad + $2.trad; 
                $$.atributos.asig = $1.atributos.asig; }
    |{}{} {$$.trad = ""; }
    ;

Fun : fn id {  
            struct Simbolo simb1; 
            simb1.nombre = $2.lexema; 
            simb1.tipo =FUNCIONT; 
            simb1.nomtrad = $0.atributos.asig + $2.lexema;  
            if(!tsActual->newSymb(simb1)){
                errorSemantico(ERRYADECL,$2.lexema,$2.fila,$2.col);
            } 
            tsActual= new TablaSimbolos(tsActual); 
            } 
            A Rt 
            {$$.atributos.asig = $0.atributos.asig + $2.trad + "_"; } 
            Spp {$$.trad = "_" +$0.atributos.asig + $2.trad; 
            $$.atributos.tipo = $5.trad; } Cod endfn 
            {
                $$.trad = $7.trad + $5.trad + " " + $0.atributos.asig + $2.trad + " "+ "\n{\n" + $8.trad + " }\n " ;
            }
        ;

A : pari {$$.atributos.asig = ""; } Arg pard {} { $$.trad = "(" + $2.trad + ")";  }; 

Arg : id dosp Type {$$.atributos.asig = ",";} Arg {
    struct Simbolo simb1; simb1.nombre = $1.lexema; simb1.tipo = parserTipo($3.trad , $1.lexema , $1.fila, $1.col ); simb1.nomtrad = $1.lexema;  
    if(!tsActual->newSymb(simb1))  errorSemantico(ERRYADECL,$1.lexema,$1.fila,$1.col);
    $$.trad = $0.trad + $3.trad + " " + $1.lexema + $5.trad;     }
    | {$$.trad = "";  }; 

Rt : rettok Type { $$.trad = $2.trad;}
    | {$$.trad = "void"; };

Type : inttok { $$.trad = "int"; }
    | real {$$.trad = "float";};


Cod : Cod pyc {$$.trad =$0.trad; $$.atributos.tipo= $0.atributos.tipo;  } I {$$.trad = $1.trad + $4.trad;  }
    | {} {} {$$.trad = $0.trad; $$.atributos.tipo= $0.atributos.tipo; } I         {$$.trad = $4.trad; }; 

I : Blq {$$.trad = $1.trad + "\n"; }
   | let id {$$.trad = $0.trad + "_" + $2.trad; $$.atributos.tipo = $0.atributos.tipo;    } It {$$.trad = $4.trad; }
   | print E {$$.trad = "print" + tipoMayus($2.atributos.tipo) + "(" + $2.trad + ");\n";   }
   | iftok E { tsActual = new TablaSimbolos(tsActual); } I {tsActual = tsActual->getPadre();} Ip {$$.trad = "if(" + $2.trad + "){\n" + $4.trad + "\n}\n" + $6.trad;   }; 

Blq : blq {tsActual = new TablaSimbolos(tsActual); } Cod {tsActual = tsActual->getPadre();} fblq { $$.trad = "{\n" + $3.trad + "\n}\n"; }; 

Ip : elsetok {tsActual = new TablaSimbolos(tsActual);} I {tsActual = tsActual->getPadre(); } fi {$$.trad = "else{ \n" + $3.trad + "\n}\n"; }

    | fi {$$.trad = ""; }
    ; 

It : dosp Type {  struct Simbolo simb1; 
            simb1.nombre = $-1.lexema; 
            simb1.tipo = parserTipo($2.trad , $-1.lexema , $-1.fila , $-1.col);  
            simb1.nomtrad = $-1.lexema + $0.trad;  
            if(!tsActual->newSymb(simb1))errorSemantico(ERRYADECL,$-1.lexema,$-1.fila,$-1.col);
            $$.trad = $2.trad + " " + $-1.lexema + $0.trad + "; ";
             }
    | asig E {$$.trad = $-1.lexema; } Ifa {
        if(tsActual->searchSymb($-1.lexema)!= NULL){
            if(tsActual->searchSymb($-1.lexema)->tipo == ENTEROT && parserTipo($2.atributos.tipo , $-1.lexema , $-1.fila , $-1.col) == REAL ) errorSemantico(ERRNOENTERO,$-1.lexema,$-1.fila,$-1.col);
            $$.tipo = $2.tipo;
            $$.trad =  $4.trad +  tsActual->searchSymb($-1.lexema)->nomtrad + " = " + $2.trad + ";" ;
        }
        struct Simbolo simb1; 
        simb1.nombre = $-1.lexema; 
        simb1.tipo = parserTipo($2.atributos.tipo , $-1.lexema , $-1.fila , $-1.col);  
        simb1.nomtrad = $-1.lexema + $0.trad;  
        if( !tsActual->newSymb(simb1)){
            if(tsActual->searchSymb($-1.lexema)->tipo == ENTEROT &&  parserTipo($2.atributos.tipo , $-1.lexema , $-1.fila , $-1.col) == REAL ) errorSemantico(ERRNOENTERO,$-1.lexema,$-1.fila,$-1.col);
            $$.tipo = $2.tipo;
            $$.trad =  $4.trad +  tsActual->searchSymb($-1.lexema)->nomtrad + " = " + $2.trad + ";" ;
            
        }else{
            if($3.trad.length() > 1 ) errorSemantico(ERRVOID,$-1.lexema,$-1.fila,$-1.col);
        }
        if($3.trad.length() > 1){
            $$.tipo = $2.tipo; 
            $$.trad = $4.trad + $-1.lexema + $0.trad + " = " + $2.trad + ";" ;

        }else{ 
            $$.tipo = $2.tipo; 
            $$.trad =   $2.atributos.tipo + " " + $-1.lexema + $0.trad + "; " +  $-1.lexema + $0.trad  + " = " + $2.trad + ";" ;
        }
    }
    | {
        struct Simbolo simb1; 
        simb1.nombre = $-1.lexema; 
        simb1.tipo = parserTipo($0.atributos.tipo , $-1.lexema , $-1.fila , $-1.col);  
        simb1.nomtrad = $-1.lexema + $0.trad;  
        if( !tsActual->newSymb(simb1) )  errorSemantico(ERRYADECL,$-1.lexema,$-1.fila,$-1.col);
        $$.tipo = $0.tipo;
        $$.trad = $0.atributos.tipo + " " + $-1.lexema + $0.trad + ";";
    }; 

Ifa : iftok {if(tsActual->searchSymb($0.trad) == NULL ) errorSemantico(ERRVOID,$0.lexema,$0.fila,$0.col); } E { $$.tipo = $3.tipo; $$.trad = "if(" + $3.trad + ")";  }
    | {$$.trad = ""; };

E : E opas T {  $$.tipo = tipoShake($1.tipo , $3.tipo); 
                $$.trad = $1.trad + $2.lexema + $3.trad; }
    | T     { $$.tipo = $1.tipo; 
            $$.trad = $1.trad; };

T : T opmd F {  $$.tipo = tipoShake($1.tipo , $3.tipo);
                $$.trad = $1.trad + " " + $2.lexema + " " + $3.trad; 
    }
    | F { $$.tipo = $1.tipo; 
        $$.trad = $1.trad; 
        };

F : numint {$$.tipo =ENTEROT; 
            $$.atributos.tipo = "int";
            $$.trad = $1.lexema; }
    | numreal {
        $$.atributos.tipo = "float";
        $$.tipo = REALT; 
                $$.trad = $1.lexema;}
    | pari E pard {
        $$.tipo = $1.tipo; 
        $$.atributos.tipo = $1.atributos.tipo;
        $$.trad = "(" + $1.trad + ")"; }
    | id {
        if( tsActual->searchSymb($1.lexema) == NULL) errorSemantico(ERRNODECL,$1.lexema,$1.fila,$1.col);
        if(tsActual->searchSymb($1.lexema)->tipo != ENTEROT && tsActual->searchSymb($1.lexema)->tipo != REALT ) errorSemantico(ERRNOSIMPLE,$1.lexema,$1.fila,$1.col);
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo; 
        $$.trad =  tsActual->searchSymb($1.lexema)->nomtrad;
    }

%%

string tipoMayus(string tipo){
    if(tipo == "int") return "Int"; 
    return "Float"; 
}

int parserTipo(string tipo , char * lexema, int fila, int columna  ){
    if (tipo =="int"  ) return ENTEROT; 
    if (tipo == "float"  ) return REALT; 
    if(tipo == "void" )errorSemantico(ERRVOID,lexema,fila,columna);
    return -1; 
}

int tipoShake(int type1,  int type2){
    if(type1 == REAL || type2 == REAL ) return REAL; 
    return INT;
}

/// ---------- Errores semánticos ---------------------------------

void errorSemantico(int nerror,char *lexema,int fila,int columna)
{
    fprintf(stderr,"Error semantico (%d,%d): en '%s', ",fila,columna,lexema);
    switch (nerror) {
      case ERRYADECL: fprintf(stderr,"ya existe en este ambito\n");
         break;
      case ERRNODECL: fprintf(stderr,"no ha sido declarado\n");
         break;
      case ERRNOSIMPLE: fprintf(stderr,"debe ser de tipo entero o real\n");
         break;
      case ERRVOID: fprintf(stderr,"debe declararse con tipo entero o real\n");
         break;
      case ERRNOENTERO: fprintf(stderr,"la expresión debe ser de tipo entero\n");
         break;
    }
    exit(-1);
}



/// ---------- Errores léxicos y sintácticos ----------------------
void msgError(int nerror,int fila,int col,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",fila,col,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",fila,col,s);
            break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
            break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
            break;
     }
        
     exit(1);
}

int yyerror(char *s)
{
    if (findefichero) 
    {
       msgError(ERREOF,-1,-1,"");
    }
    else
    {  
       msgError(ERRSINT,fila,col-strlen(yytext),yytext);
    }
    return 0;
}


int main(int argc,char *argv[])
{
    FILE *fent;

    if (argc==2)
    {
        fent = fopen(argv[1],"rt");
        if (fent)
        {
            yyin = fent;
            yyparse();
            fclose(fent);
        }
        else
            fprintf(stderr,"No puedo abrir el fichero\n");
    }
    else
        fprintf(stderr,"Uso: ejemplo <nombre de fichero>\n");
}
