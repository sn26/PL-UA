/**
* Sirvent Navarro, Álvaro
*/ 
//DEFINIMOS LOS TOKEN
//NUEVOS TOKEN DE P5
%token cori cord
%token fortok whiletok
%token coma 
%token readtok
%token var
%token arraytok
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
#include "TablaTipos.h"

extern int col, fila, findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);
void errorSemantico(int nerror,char *lexema,int fila,int columna);
int mietiquetaact = 0;
int nuevaEtiqueta();
TablaSimbolos *tsActual = new TablaSimbolos(NULL); 
TablaTipos *ttActual = new TablaTipos(); 
string tipoMayus(string tipo);
string tipoShake(string  type1,  string type2);
//  int parserTipo(string tipo , char * lexema, int fila, int columna  );
int ctemp = 16000;
int cvar = 0;  
int nuevaTemp(char *lexema, int fila, int columna);
int nuevaVar(unsigned tam ,char *lexema, int fila, int columna);
bool esArray(unsigned tipo); 

//int devuelveDim(unsigned tipo);
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
    int etiqact = nuevaEtiqueta(); 
    $$.trad = "L" + to_string(etiqact) + ":\n"
    + $5.trad; 
}; 
Stype: inttok {
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
    | arraytok Stype Dim {
        $$.tam =  $3.tam; 
        $$.tipo = $3.tipo;
        
    };

Dim: numint coma {if($1.numint == 0 ) errorSemantico(ERR_DIM, $1.lexema, $1.fila, $1.col ); $$.tipo = $0.tipo; } Dim {
        $$.tam= $1.numint * $4.tam;
        $$.tipo = ttActual->nuevoTipoArray($$.tam , $4.tipo); 
    }
    | numint{
        if($1.numint == 0 ) errorSemantico(ERR_DIM, $1.lexema, $1.fila, $1.col); 
        $$.tam = $1.numint;
        $$.tipo = ttActual->nuevoTipoArray($$.tam , $0.tipo); 
    }; 

Cod: Cod pyc I {
    $$.trad = $1.trad + $3.trad;
    }
    | I {
        $$.trad = $1.trad;
    };

I: Blq {
    $$.trad = $1.trad; 
    $$.atributos.tipo = $1.atributos.tipo; 
    $$.tipo = $1.tipo;
    }
    | let Ref asig E Ifa {
        
        int temp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.trad = 
        $5.trad +   
        "mov " + to_string($5.dir) + " " + to_string(temp) + "\n" +
        "mov" + to_string(temp) + " " + to_string($1.dir) + "\n" +  
        $5.atributos.etiqueta;
        
    }
    | var id It {
        struct Simbolo simb1; 
        simb1.nombre = $2.lexema;
        simb1.tipo = $3.tipo;
        simb1.dir = $2.dir;
        simb1.tam = $3.tam;
        if(!tsActual->newSymb(simb1))  errorSemantico(ERR_YADECL,$2.lexema,$2.fila,$2.col);
        $$.dir = nuevaVar($3.tam , $2.lexema, $2.fila, $2.col); 
        $$.trad = ""; 
        $$.tipo = $3.tipo; 
        $$.dir = $2.dir; 
        $$.tam = $$.tam;
    }
    | print E {if($2.tipo == REAL ) $$.trad = "wri "; 
                if($2.tipo == ENTERO ) $$.trad = "wrr ";   } {
        $$.trad = $3.trad  + to_string( $2.dir) + " wrl\n";   
    }
    | readtok Ref {if($2.tipo == ENTERO ) $$.trad = "rdi "; 
                if($2.tipo == REAL) $$.trad = "rdr ";  } {
        $$.trad = $3.trad + to_string($2.dir); 
    }
    | whiletok E I {
        int etiqact1 = nuevaEtiqueta();
        int etiqact2 = nuevaEtiqueta(); 
        $$.trad = "L" + to_string(etiqact1)+ ":\n"+
        $2.trad + "mov " + to_string($2.dir) + " A\n" 
        + "jz " + "L" + to_string(etiqact2) + "\n" + 
        $3.trad + "jmp L" + to_string(etiqact1) + "\n" + 
        "L" + to_string(etiqact2) + ":\n";   
    }
    | fortok {tsActual = new TablaSimbolos(tsActual); } id asig numint dosp numint {
         if($4.numint > $6.numint) $$.trad = "subi "; 
        if($4.numint < $6.numint) $$.trad = "addi "; } 
        I {  
            int etiqact1 = nuevaEtiqueta(); 
            int var1 = nuevaVar(1,$3.lexema , $3.fila , $3.col ); 
            $$.trad = "L" + to_string(etiqact1) + ":\n mov " + $5.lexema + " " + to_string(var1) + "\n" +  "mov " + to_string(var1) + " A\n" + $8.trad + " #1\n" + "mov A" + to_string(var1) + "\n subi" + " #"+$7.lexema + "\n"+ "jmpz L" + to_string(etiqact1) + "\n"; 
            tsActual = tsActual->padre;
    }
    | iftok E {if($2.tipo!=ENTERO) errorSemantico(ERR_IFWHILE, $1.lexema, $1.fila, $1.col);} I Ip {
        int etiqact1 = nuevaEtiqueta(); 
        int etiqact2 = nuevaEtiqueta();
        $$.trad = $2.trad + 
        "mov " + to_string($2.dir) + " A\n" +
         "jz L" + to_string(etiqact1) + "\n" 
         + $3.trad 
         + "jmpL" + to_string(etiqact2) + "\n" +
         + 
         "L" + to_string(etiqact1)+":\n"
         +$4.trad +
         "L" + to_string(etiqact2) + ":\n";
}; 

Ip: elsetok I fi {
    $$.trad = $2.trad; 
    }
    | fi {
        $$.trad = ""; 
    }; 

Blq: blq {tsActual = new TablaSimbolos(tsActual); } Cod {tsActual = tsActual->getPadre();}fblq {
    
    $$.trad = $2.trad;

    
}; 


It: dosp Type {
    $$.tipo = $2.tipo; 
    $$.trad = ""; 
    $$.tam  = $2.tam; 
    }
    | {
        $$.trad =""; 
        $$.tipo = ENTERO;
        $$.tam = 1;

    }

Ifa: iftok E{
    int etiq = nuevaEtiqueta();
    $$.trad = "mov " + to_string($2.dir) + " A\n" + "jz" + "L" + to_string(etiq) + "\n";
    $$.dir = $2.dir;
    $$.atributos.etiqueta = "L" + to_string(etiq) + ":\n";

    }
    | {
        $$.trad ="";
        $$.atributos.etiqueta = ""; 

    }


E: E opas {if(strcmp($2.lexema, "+") ){$$.trad = "add"; }
            if(strcmp($2.lexema ,"-")) {$$.trad == "sub";}} T {
    int tmp;
    tmp = nuevaTemp($1.lexema, $1.fila, $1.col);
    $$.dir = tmp; 
    if($1.tipo == ENTERO && $4.tipo == ENTERO ){
        $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A" + $3.trad +"i " + to_string($4.dir) + "mov A " + to_string(tmp); 
        $$.tipo = ENTERO;
        $$.atributos.tipo = "int"; 
    }
    else if($1.tipo == REAL && $4.tipo == ENTERO){
        int tmpcp; 
        tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
        $$.trad = $1.trad + $4.trad + "mov " + to_string($4.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
        + "mov " + to_string($1.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp); 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float"; 
    }else if ($1.tipo == REAL && $4.tipo == REAL){
        $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n" + $3.trad + "r " + to_string($4.dir) + "\nmov A " + to_string(tmp); 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float";  
    }
    }
    | opas {if( strcmp($1.lexema,"+") ){$$.trad = "add"; }
            if(strcmp( $1.lexema ,"-")) {$$.trad == "sub";}} T {

        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col); 
        if($3.tipo == ENTERO){
            $$.trad = $2.trad + "i " + to_string($3.dir)+ "mov A "  + to_string(tmp); 
            $$.tipo = ENTERO; 
            $$.atributos.tipo == "int";  
        }else if($3.tipo == REAL ){
            $$.trad = $2.trad + "r " + to_string($3.dir)+ "mov A "  + to_string(tmp);  
            $$.tipo = REAL; 
            $$.atributos.tipo = "float"; 
        }
    }
    | T {
        $$.atributos.tipo = $1.atributos.tipo; 
        $$.tipo = $1.tipo; 
        $$.trad = $1.trad; 
    };

T: T opmd {if(strcmp($2.lexema,"*")){$$.trad = "mul"; }
           if(strcmp($2.lexema ,"/")){$$.trad = "div";}} F 
            {
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col);
        $$.dir = tmp; 
        if($1.tipo == ENTERO && $4.tipo == ENTERO ){
            $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A" + $3.trad +"i " + to_string($4.dir) + "mov A " + to_string(tmp); 
            $$.tipo = ENTERO;
            $$.atributos.tipo = "int"; 
        }
        else if($1.tipo == REAL && $4.tipo == ENTERO){
            
            int tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
            $$.trad = $1.trad + $4.trad + "mov " + to_string($4.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
            + "mov " + to_string($1.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp); 
            $$.tipo = REAL; 
            $$.atributos.tipo = "float"; 
        }else if ($1.tipo == REAL && $4.tipo == REAL){
            $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n" + $3.trad + "r " + to_string($4.dir) + "\nmov A " + to_string(tmp); 
            $$.tipo = REAL; 
            $$.atributos.tipo = "float";  
        }
    }
    | F {
        $$.tipo = $1.tipo;
        $$.trad = $1.trad;
    }


F: numint {$$.tipo = ENTERO; 
        $$.atributos.tipo = "int"; 
        int temp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.trad = "mov #" + string($1.lexema) +  to_string(temp) + "\n"; 
        $$.dir = temp; 
        }

    | numreal {
        $$.tipo = REAL; 
        $$.atributos.tipo = "real"; 
        int temp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.trad = "mov $" + string($1.lexema) +  to_string(temp) + "\n";
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
       
        if( tsActual->searchSymb($1.lexema) == NULL) {
            //cout<<$1.lexema<<endl;
            errorSemantico(ERR_NODECL,$1.lexema,$1.fila,$1.col);
        }
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo;
        if($$.tipo == ENTERO) $$.atributos.tipo = "int";
        if($$.tipo == REAL) $$.atributos.tipo = "float"; 
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col );
        $$.dir = tmp;
        $$.trad = "mov " + to_string(tsActual->searchSymb($1.lexema)->dir) + " " + to_string(tmp) + "\n";
        
    }

    | id {if(tsActual->searchSymb($1.lexema) == NULL) errorSemantico(ERR_NODECL,$1.lexema,$1.fila,$1.col); 
        if(!esArray(tsActual->searchSymb($1.lexema)->tipo)) errorSemantico(ERR_SOBRAN,$1.lexema,$1.fila,$1.col);
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo; 
     } cori {$$.tam = ttActual->tipos[$2.tipo].tamano; 
    $$.tipo = ttActual->tipos[$2.tipo].tipoBase;
      $$.atributos.dbase = $1.dir; int tmp= nuevaTemp($1.lexema, $1.fila, $1.col); $$.trad= "mov #0 " + to_string(tmp) + "\n"; $$.dir= tmp;} LExpr  cord {if(esArray($6.tipo)) errorSemantico(ERR_FALTAN, $6.lexema, $6.fila, $6.col); }{
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col); 
        $$.dir = tmp; 
        $$.trad = $5.trad + "mov" + to_string($5.dir) + " A\n" + "muli" + "#" + to_string($5.tam) + "\naddi #" + to_string($5.atributos.dbase) + "\n" + "mov @A" + to_string(tmp); 
        $$.tipo = $5.tipo; 
   }; 

LExpr: LExpr coma {$$.tipo = $1.tipo; if(!esArray($1.tipo))errorSemantico(ERR_SOBRAN, $2.lexema, $2.fila, $2.col );} E{
        
        if($4.tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,$3.lexema,$3.fila,$3.col);
        
        $$.tipo = ttActual->tipos[$1.tipo].tipoBase;
        
        $$.atributos.dbase = $0.atributos.dbase; 
        int tmp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.dir = tmp;
        $$.trad = $0.trad + $3.trad + "mov " + to_string($0.dir) + " A\n" + "muli" + "#" + to_string($0.tam) + "\naddi " + to_string( $3.dir)  + "\n" + "mov A " + to_string(tmp); 
    }
    | E {
        if($1.tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,$1.lexema,$1.fila,$1.col);
        $$.trad = $1.trad; 
        $$.tipo = $0.tipo; 
         
        $$.dir = $1.dir; 
    };

%%

bool esArray(unsigned tipo ){
    if(tipo != ENTERO  && tipo != REAL ) return true; 
    return false;
}

/*
//Funcion para ir bajando en la tabla de tipos hasta conseguir el total de dimensiones
int devuelveDim(unsigned tipo){
    int contador =0;
    //int tipo == ttActual->tipos[tipo].tipoBase; 
    return 0; 
}*/




string tipoMayus(string tipo){
    
    if(tipo == "int") return "Int"; 
    return "Float"; 
}
/*
int parserTipo(string tipo , char * lexema, int fila, int columna  ){
    if (tipo =="int"  ) return ENTERO; 
    if (tipo == "float"  ) return REAL; 
    
    if(tipo == "void" )errorSemantico(ERRVOID,lexema,fila,columna);
    return -1; 
}*/

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
int nuevaVar(unsigned tam , char *lexema, int fila, int columna ){
    cvar +=tam; 
    if(cvar > 16000) errorSemantico(ERR_NOCABE, lexema, fila, columna ); 
    return cvar; 
}
//Manejar etiquetas 
int nuevaEtiqueta(){
    mietiquetaact += 1;
    return mietiquetaact; 
}

/// ---------- Errores semánticos ---------------------------------
void errorSemantico(int nerror,char *s,int fila,int columna)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    //cout<<ERR_NODECL<<endl;
    //cout<<nerror<<endl;
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
