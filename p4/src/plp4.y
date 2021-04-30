/**
* Sirvent Navarro, Álvaro
*/ 
//DEFINIMOS LOS TOKEN
%token pari pard
%token dosp
%token ret 
%token asig 
%token pyc 
%token opas opmd
%token fn endfn 
%token int real
%token let 
%token if else fi
%token print
%token blq fblq 
%token id
%token numint numreal
%token eof

%{

#include <string.h>
#include <stdio.h>
#include "comu.h"
#include "TablaSimbolos.h"
using namespace std;

extern int ncol, nlin, findefichero;

TablaSimbolos *tsActual = new TablaSimbolos(NULL); 

%}

%% 

S : Sp { 
    /* Primero, comprobaremos que después del programa no hay ningún token más*/
    int tk = yylex(); 
    if(tk!= 0) yyerror(""); 
    $$.trad = $1.trad; //Sp.trad 
    cout<<$$.trad; //Imprimimos la traducción
}; 

Sp : Fun Spp {
    $$.trad = $1.trad + $2.trad; 
    $$.atributos.asig = "";
};

Spp : Fun Spp { 
                $$.trad = $1.trad + $2.trad; 
                $$.atributos.asig = $1.atributos.asig; //Cogemos el valor (nombre ) de la traducción}
    |{}{} {$$.trad = ""; };

Fun : fn id {  
            struct Simbolo simb1; 
            simb1.nombre = $2.lexema; 
            simb1.tipo =$2.tipo; 
            simb1.nomtrad = $2.lexema;  
            if(!tsActual->newSymb(simb1)){
                yerror("");
            } 
            tsActual= new TablaSimbolos(tsActual); //Abrimos una nueva tabla de simbolos
            )} 
            A Rt 
            {$$.atributos.asig = $0.atributos.asig + $2.trad + "_"; } 
            Spp {$$.trad = "_" +$0.atributos.asig + $2.trad; 
            $$.atributos.tipo = $5.trad} Cod endfn 
            {
                $$.trad = $7.trad + $5.trad + " " + $0.atributos.asig + $2.trad + " "+ "\n{\n" + $8.trad + " }\n " ;
            };

A : pari {$$.atributos.asig = ""} Arg pard {} { $$.trad = "(" + $2.trad + ")";  }; 

Arg : id dosp Type {$$.atributos.asig = ","} Arg {
    //Añadimos el nuevo símbolo
    struct Simbolo simb1; simb1.nombre = $1.lexema; simb1.tipo =$1.tipo; simb1.nomtrad = $1.lexema;  
    if(!tsActual->newSymb(simb1)) yerror("");
    $$.trad = $0.trad + $3.trad + " " + $1.lexema + $5.trad;     }
    | {$$.trad = "";  }; 

Rt : ret Type { $$.trad = $2.trad;}
    | {$$.trad = "void"; };

Type : int { $$.trad = "int"; }
    | real {$$.trad = "float";};


Cod : Cod pyc {$$.trad =$0.trad; //Heredamos el sufijo } I {$$.trad = $1.trad + $4.trad;  }
    | {} {} {$$.trad = $0.trad;} I         {$$.trad = $4.trad; }; 

I : Blq {$$.trad = $1.trad + "\n"; }
   | let id {$$.trad = $0.trad + "_" + $2.trad; //Para la herencia  } IT {$$.trad = $4.trad; }
   | print E {$$.trad = "print" + tipoMayus($2.atributos.tipo) + "(" + $2.trad + ");\n";   }
   | if E { tsActual = new TablaSimbolos(tsActual); } I {tsActual = tsActual->getPadre();} Ip {$$.trad = "if(" + $2.trad "){\n" + $4.trad + "\n}\n" + $6.trad;   }; 

Blq : blq {tsActual = new TablaSimbolos(tsActual); } Cod {tsActual = tsActual->getPadre();} fblq { $$.trad = "{\n" + $3.trad + "\n}\n"; }; 

Ip : else {tsActual = new TablaSimbolos(tsActual);} I {tsActual = tsActual->getPadre(); } fi {$$.trad = "else{ \n" + $3.trad + "\n}\n"; }

    | fi {$$.trad = ""; }
    ; 

It : dosp Type {  struct Simbolo simb1; 
            simb1.nombre = $-1.lexema; //Cogemos el lexema del id 
            simb1.tipo = checkTipo($2.tipo);  
            simb1.nomtrad = $-1.lexema + $0.trad;  
            if(!tsActual->newSymb(simb1))yerror("");
            $$.trad = $2.trad + " " + $-1.lexema + $0.trad + "; ";
             }
    | asig E {$$.trad = $-1.lexema; } Ifa {
        struct Simbolo simb1; 
        simb1.nombre = $-1.lexema; //Cogemos el lexema del id 
        simb1.tipo = checkTipo($2.tipo);  
        simb1.nomtrad = $-1.lexema + $0.trad;  
        //Añadimos a la tabla (Si no se había creado anterioremente)
        if(tsActual->searchSymb($-1.lexema)!= NULL){//Ya la tenemos declarada en un ámbito (Padre o el actual)
            //Comprobamos los tipos
            if(tsActual->searchSymb($-1.lexema).tipo == INT &&  checkTipo($2.tipo) == REAL ) yerror("");
            $$.tipo = $2.tipo;
            $$.trad =  $4.trad +  tsActual->searchSymb($-1.lexema).nomtrad + " = " + $2.trad + ";" ;
        }
        if( !tsActual->newSymb(simb1)){
            //Comprobamos los tipos
            if(tsActual->searchSymb($-1.lexema).tipo == INT &&  checkTipo( $2.tipo) == REAL ) yerror("");
            $$.tipo = $2.tipo;
            $$.trad =  $4.trad +  tsActual->searchSymb($-1.lexema).nomtrad + " = " + $2.trad + ";" });
            
        }else{
            if($3.trad.length() > 1 ) yerror("");
        }
        if($3.trad.length() > 1){
            $$.tipo = $2.tipo; 
            $$.trad = $4.trad + $-1.lexema + $0.trad + " = " + $2.trad + ";" });

        }else{ 
            $$.tipo = $2.tipo; 
            $$.trad =   $2.atributos.tipo + " " + $-1.lexema + $0.trad + "; " +  $-1.lexema + $0.trad  + " = " + $2.trad + ";" });
        }
    }
    | {
        struct Simbolo simb1; 
        simb1.nombre = $-1.lexema; //Cogemos el lexema del id 
        simb1.tipo = checkTipo($2.tipo);  
        simb1.nomtrad = $-1.lexema + $0.trad;  
        if( !tsActual->newSymb(simb1) )  yerror("");
        $$.tipo = $0.atributos.tipo;
        $$.trad = $0.atributos.tipo + " " + $-1.lexema + $0.trad + ";"}); //Devolvemos el heredado
    }; 

Ifa : if {if(tsActual->searchSymb($0.trad) == NULL ) yerror(""); } E { $$.tipo = $3.tipo; $$.trad = "if(" + $3.trad + ")";  }
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

F : numint {$$.tipo =INT; 
            $$.trad = $1.lexema; }
    | numreal {$$.tipo = REAL; 
                $$.trad = $1.lexema;}
    | pari E pard {
        $$.tipo = $1.tipo; 
        $$.trad = "(" + $1.trad + ")"; }
    | id {
        if( tsActual->searchSymb($1.lexema) == NULL) yerror(""); 
        if(tsActual->searchSymb($1.lexema).tipo != INT && tsActual->searchSymb($1.lexema).tipo != REAL ) yerror(""); 
        $$.tipo = tsActual->searchSymb($1.lexema).tipo; 
        $$.trad =  tsActual->searchSymb($1.lexema).nomtrad;
    }

%%

string tipoMayus(string tipo){
    if(tipo == "int") return "Int"; 
    return "Float"; 
}

int checkTipo(int tipo ){
    if (tipo == INT ) return INT; 
    if (tipo == REAL ) return REAL; 
    yerror("");
    return -1; 
}

int tipoShake(int type1,  int type2){
    if(type1 == REAL || type2 == REAL ) return REAL; 
    return INT;
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
       msgError(ERREOF,0,0,"");
    }
    else
    {  
       msgError(ERRSINT,nlin,ncol-strlen(yytext),yytext);
    }
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
