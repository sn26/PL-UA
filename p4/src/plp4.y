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
using namespace std;

extern int ncol, nlin, findefichero;


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

}