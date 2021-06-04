/**
* Sirvent Navarro, Álvaro
*/ 
//DEFINIMOS LOS TOKEN
//NUEVOS TOKEN DE P5
%token cori cord
%token for while
%token coma 
%token read 
%token var
%token array
//ANTERIORES
%token pari pard
%token dosp
//%token rettok 
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
etiquetaact = 0;
int nuevaEtiqueta();
TablaSimbolos *tsActual = new TablaSimbolos(NULL); 
TablaTipos *ttactual = new TablaTipos(); 
string tipoMayus(string tipo);
string tipoShake(string  type1,  string type2);
int parserTipo(string tipo , char * lexema, int fila, int columna  );
int ctemp = 16000;
int cvar = 0;  
int nuevaTemp(char *lexema, int fila, int columna);


%}

%% 

S: Fun { 
    /* Primero, comprobaremos que después del programa no hay ningún token más*/
    int tk = yylex(); 
    if(tk!= 0) yyerror(""); 
    $$.trad = $1.trad; 
    cout<<$$.trad; 
}; 

Fun: fn id pari pard Cod endfn{
    
}; 
Stype: int {
        $$.tipo = ENTERO; 
        $$.atributos.tipo= "int"; 
        $$.tam = 1; 
    } 
    | real {
        $$.tipo = REAL; 
        $$.atributos.tipo = "float"; 
        $$.tam = 1; 
    }; 

Type: Stype {
    $$.tipo = $1.tipo; 
    $$.atributos.tipo = $1.atributos.tipo; 
    $$.tam = $1.tam; 
    }
    | array Stype Dim {
        $$.tipo = ttactual->nuevoTipoArray($3.tam , $3.tipo);
        $$.tam = $3.tam; 
    };

Dim: numint coma Dim {

    }
    | numint{

    }; 

I: Blq {
    tsActual = new TablaSimbolos(tsActual); 
    $$.trad = $1.trad; 
    $$.atributos.trad = $1.atributos.trad; 
    $$.tipo = $1.tipo;
    }
    | let Ref asig E Ifa {


    }
    | if E I Ip {
        int etiqact = nuevaEtiqueta(); 
        $$.trad = "mov " + $2.trad + " A\n" + "jz L" + etiqact + "\n" + $4.trad + "L" + etiqact+":\n"+$3.trad ; 

    }

Ifa: if E{
    $$.trad = "mov " + $2.trad + " A\n" + "jz" + "L" + nuevaEtiqueta() + "\n";
    $$.dir = $2.dir;
    }
    | {
        $$.trad ="";
    }


E: E opas {if($2.lexema == "+" ){$$.trad = "add"; }
            if($2.lexema == "-") {$$.trad == "sub";}} T {
    tmp = nuevaTemp($1.lexema, $1.fila, $1.columna);
    $$.dir = tmp; 
    if($1.tipo == ENTERO && $4.tipo == ENTERO ){
        $$.trad = $1.trad + $4.trad + "mov " + $1.dir + " A" + $3.trad +"i " + $4.dir + "mov A " + tmp; 
        $$.tipo = ENTERO;
        $$.atributos.tipo = "int"; 
    }
    else if($1.tipo == REAL && &4.tipo == ENTERO){
        tmpcp = nuevaTemp($1.lexema, $1.fila, $1.columna);
        $$.trad = $1.trad + $4.trad + "mov " + $4.dir + " A\n"+"itor\n" + "mov A " + tmpcp + "\n" 
        + "mov " + $1.dir + " A" + "\n" + $3.trad + "r " + tmpcp + "\nmov A " + tmp; 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float"; 
    }else if ($1.tipo == REAL && &4.tipo == REAL){
        $$.trad = $1.trad + $4.trad + "mov " + $1.dir + " A\n" + $3.trad + "r " + $4.dir + "\nmov A " + tmp; 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float";  
    }
    }
    | opas {if($2.lexema == "+" ){$$.trad = "add"; }
            if($2.lexema == "-") {$$.trad == "sub";}} T {

        tmp = nuevaTemp($1.lexema, $1.fila, $1.columna); 
        if($3.tipo == ENTERO){
            $$.trad = $2.trad + "i " + $3.dir+ "mov A "  + tmp; 
            $$.tipo = ENTERO; 
            $$.atributos.tipo == "int";  
        }else if($3.tipo == REAL ){
            $$.trad = $2.trad + "r " + $3.dir+ "mov A "  + tmp;  
            $$.tipo = REAL; 
            $$.atributos.tipo = "float"; 
        }
    }
    | T {
        $$.atributos.tipo = $1.atributos.tipo; 
        $$.tipo = $1.tipo; 
        $$.trad = $1.trad; 
    };


F: numint {$$.tipo = ENTERO; 
        $$.atributos.tipo = "int"; 
        temp = nuevaTemp($1.lexema , $1.fila, $1.columna); 
        $$.trad = "mov #" + $1.lexema +  temp + "\n"; 
        $$.dir = temp; 
        }

    | numreal {
        $$.tipo = REAL; 
        $$.atributos.tipo = "real"; 
        $$.trad = "mov $" + $1.lexema +  temp + "\n";
        $$.dir = temp; 

    }
    | pari E pard {
        $$.tipo = $2.tipo; 
        $$.atributos.tipo = $2.atributos.tipo; 
        $$.trad = $2.trad; 
        $$.dir = $2.dir; 
    }
    | Ref {
        $$.tipo = $1.tipo; 
        $$.atributos = $1.atributos; 
        $$.trad = $1.trad;
        $$.dir = $1.dir; 
    }; 

Ref: id{ 
        if( tsActual->searchSymb($1.lexema) == NULL) errorSemantico(ERRNODECL,$1.lexema,$1.fila,$1.col);
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo;
        if($$.tipo == ENTERO) $$.atributos.tipo = "int";
        if($$.tipo == REAL) $$.atributos.tipo = "float"; 
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.columna );
        $$.dir = tmp;
        $$.trad = "mov " + tsActual->searchSymb($1.lexema)->dir + " " + tmp;
        
    }

    | id {if(tsActual->searchSymb($1.lexema) == NULL) errorSemantico(ERRNODECL,$1.lexema,$1.fila,$1.col); 
        if(tsActual->searchSymb($1.lexema)->tipo != ARRAY) errorSemantico(ERR_SOBRAN,$1.lexema,$1.fila,$1.col); 
     } cori LExpr cord{

    }; 

LExpr: LExpr coma E{

    }
    | E {

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

string tipoShake(string type1,  string type2){
    if(type1 == "float" || type2 == "float" ) return "float"; 
    return "int";
}

///Manejar temporales (16000 - 16383)
int nuevaTemp(char *lexema, int fila, int columna ){
    ctemp +=1; 
    if(ctemp > 16383) errorSemantico(ERR_MAXTEMP, lexema, fila, columna ); 
    return ctemp; 
}
///Manejar variables 
int nuevaVar(char *lexema, int fila, int columna ){
    cvar +=1; 
    if(cvar > 16000) errorSemantico(ERR_NOCABE, lexema, fila, columna ); 
    return ctemp; 
}
//Manejar etiquetas 
int nuevaEtiqueta(){
    etiquetaact += 1;
    return etiquetaact; 
}


/// ---------- Errores semánticos ---------------------------------
void errorSemantico(int nerror,int fila,int columna,const char *s)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    switch (nerror) {
        case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s);
               // fila,columna de la variable
               break;
        case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s);
               // fila,columna de la variable
               break;
        case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);  
               // fila,columna de la variable
               break;

        case ERR_IFWHILE:fprintf(stderr,"la expresion del '%s' debe ser de tipo entero",s);
               // fila,columna del 'if' o 'while'
               break;
             
        case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que 0\n");
               // fila,columna de la dimension (numint)
               break;
        case ERR_FALTAN: fprintf(stderr,"faltan indices\n");
               // fila,columna del id (si no hay ningún índice) o del último ']'
               break;
        case ERR_SOBRAN: fprintf(stderr,"sobran indices\n");
               // fila,columna del '[' si no es array, o de la ',' que sobra
               break;
        case ERR_INDICE_ENTERO: fprintf(stderr,"el indice de un array debe ser de tipo entero\n");
               // fila,columna del '[' si es el primero, o de la ',' inmediatamente anterior
               break;

        case ERR_ASIG: fprintf(stderr,"tipos incompatibles en la asignacion\n");
               // fila,columna del '='
               break;
        case ERR_MAXTEMP:fprintf(stderr,"no hay espacio para variables temporales\n");
               // fila,columna da igual
               break;
    }
    exit(-1);
}




void msgError(int nerror,int nlin,int ncol,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
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
