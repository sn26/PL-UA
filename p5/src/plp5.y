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
    cout<<$$.trad + "\nhalt";
    
}; 

Fun: fn id pari pard Cod endfn{
    int etiqact = nuevaEtiqueta(); 
    $$.trad = "L" + to_string(etiqact) + "\n"
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

Dim: numint coma {if($1.numint <= 0 ) errorSemantico(ERR_DIM, $1.lexema, $1.fila, $1.col ); $$.tipo = $0.tipo; } Dim {
        $$.tam= $1.numint * ttActual->tipos[$4.tipo].tamano;
        
        $$.tipo = ttActual->nuevoTipoArray($$.tam , $4.tipo); 
    }
    | numint{
        if($1.numint <= 0 ) errorSemantico(ERR_DIM, $1.lexema, $1.fila, $1.col); 
        
        $$.tam = $1.numint * ttActual->tipos[$0.tipo].tamano;
        $$.tipo = ttActual->nuevoTipoArray($$.tam , $0.tipo); 
    }; 

Cod: Cod {$$.tam = ctemp;  } pyc I {ctemp = $2.tam;}  {
    $$.trad = $1.trad  + $4.trad;
    }
    | {$$.tam= ctemp;} I {ctemp = $1.tam;} {
        $$.trad = $2.trad;
    };
/*
Cod: Cod { } pyc I  {
    $$.trad = $1.trad  + $4.trad;
    
    }
    | {} I {} {
        $$.trad = $2.trad;
    };
*/
I: Blq {
    $$.trad = $1.trad; 
    }
    | let Ref asig E Ifa {
       
        $$.trad =  $2.trad + $4.trad;
        //
        int temp = nuevaTemp($1.lexema, $1.fila, $1.col); 
        //cout<<"LA DIR ES " <<$4.dir<<endl;
        $$.trad = $$.trad + "mov " + to_string($4.dir) + " A" + "\n";
        //cout<<"EL LEX ES "<<$4.dir<<endl; 
        $$.trad = $$.trad + "mov " + "A " + to_string(temp ) + "\n";
        //cout<<"TRAD ANTERIOR"<<$4.trad<<endl; 
        //cout<<"*******TERMINADO******"<<endl;
        if($2.tipo != $4.tipo && $2.tipo == ENTERO  ) errorSemantico(ERR_ASIG, $3.lexema ,$3.fila, $3.col);
        if($2.tipo != $4.tipo && $2.tipo == REAL) { //CORRECTO
            
            $$.trad = $$.trad +  "mov " + to_string($4.dir) + " A\n" + "itor\n" + "mov A " + to_string($4.dir) + "\n";
            //tsActual->searchSymb($2.lexema )->tipo = ;
            
            //a
        }//if(!esArray($2.tipo)){ //CORRECTO
            //cout<<"LA DIR DESDE LET PARA "<<$2.lexema<<" es "<<$2.atributos.dbase<<endl;
            //cout<<"EL VALOR PARA "<<$2.lexema<<" es "<<$4.trad<<endl;
            $$.trad = 
            $5.trad +  $$.trad +
            "mov #" + to_string($2.atributos.dbase) + " A" + "\n" +
            "mov " + to_string($4.dir) + " @A" +  "\n"  +
            $5.atributos.etiqueta + "\n";
            $$.dir = $2.dir;
        /*}else{ //ESTAMOS VIENDO UN ARRAY
            $$.trad 
            = $5.trad + $$.trad + "mov " +
             to_string($4.dir) + " " + to_string(temp) + "\n" +
            "\nmov " + to_string($2.dir) +" A" + "\n" +
            "addi #" + to_string($2.atributos.dbase)  +"\nmov " + 
            to_string(temp) + " @A\n" + $5.atributos.etiqueta;
            $$.dir = $2.dir;
            
        }*/
        //cout<<"LA TRAD ES "<<$$.trad<<endl;
        //cout<<"NEGRO"<<endl;
        
    }
    | var id It {
        struct Simbolo simb1; 
        simb1.nombre = $2.lexema;
        simb1.tipo = $3.tipo;
        $$.dir = nuevaVar($3.tam , $2.lexema, $2.fila, $2.col); 
        //cout<<"LA DIR DESDE VAR PARA "<<$2.lexema<<" es "<<$$.dir<<endl;
        simb1.dir = $$.dir;
        simb1.tam = $3.tam;
        if(!tsActual->newSymb(simb1))  errorSemantico(ERR_YADECL,$2.lexema,$2.fila,$2.col);
    }
    | print E {if($2.tipo == REAL ) $$.trad = "wrr "; 
                if($2.tipo == ENTERO ) $$.trad = "wri ";   } {
        
        //$$.trad = $2.trad +
          //  "mov " + to_string($2.dir) + " A" + "\n"; 
        $$.trad = $2.trad + $3.trad  + " "+ to_string($2.dir)+ "\nwrl\n";   
    }
    | readtok Ref {if($2.tipo == ENTERO ) $$.trad = "rdi "; 
                if($2.tipo == REAL) $$.trad = "rdr ";  } {
        //$$.trad = $2.trad + "mov " + to_string($2.dir) + " A\n";          
        $$.trad = $2.trad + $3.trad + " " + to_string($2.dir) + "\n"; 
    }
    | whiletok E {
        if($2.tipo != ENTERO) errorSemantico(ERR_IFWHILE,$1.lexema , $1.fila, $1.col );     
    } I {
        int etiqact1 = nuevaEtiqueta();
        int etiqact2 = nuevaEtiqueta(); 
        //cout<<"La trad es "<<endl; 
        $$.trad = "L" + to_string(etiqact1)+ "\n"+
        $2.trad + "mov " + to_string($2.dir) + " A\n" 
        + "jz " + "L" + to_string(etiqact2) + "\n" + 
        $4.trad + "jmp L" + to_string(etiqact1) + "\n" + 
        "L" + to_string(etiqact2) + "\n";   
    }
    | fortok {tsActual = new TablaSimbolos(tsActual); } id asig numint dosp numint  {
        
        int var1 = nuevaVar(1,$3.lexema , $3.fila , $3.col ); 
        $$.dir = var1;
    
        struct Simbolo simb1; 
        simb1.nombre = $3.lexema;
        simb1.tipo = ENTERO;
        simb1.dir = var1;
        simb1.tam = 1;
        //int temp = nuevaTemp($5.lexema, $5.fila, $5.col); 
        //cout<<"LA DIR ES " <<$4.dir<<endl;
        $$.trad = "mov #" + to_string($5.numint ) + " " +  to_string(var1) + "\n";
        /*if ($5.numint < $7.numint ) {
            int res = $5.numint -1; 
            $$.trad = "mov #" + to_string(res) + " " +  to_string(var1) + "\n";
        }
         if ($5.numint > $7.numint ) {
            int res = $5.numint +1; 
            $$.trad = "mov #" + to_string(res) + " " +  to_string(var1) + "\n";
        }*/
        //cout<<"EL LEX ES "<<$4.dir<<endl; 
        //$$.trad = $$.trad + "mov " + "A " + to_string(temp ) + "\n";
        tsActual->newSymb(simb1);
        //$$.trad = 
        //"mov #" + to_string($$.dir) + " A" + "\n" +
        //"mov " + to_string(temp) + " @A" +  "\n"  +
        } 
        I {  
            int etiqact1 = nuevaEtiqueta();
            int etiqact2 = nuevaEtiqueta(); 
            string op1a = "";
            string op1b = "";   
            if($5.numint > $7.numint){ op1a = "subi "; op1b = "lssi "; } 
            if($5.numint < $7.numint){ op1a = "addi "; op1b = "gtri ";} 
            $$.trad = $8.trad
            + "L" + to_string(etiqact1) + "\n" 
            + $9.trad +
            "mov " + to_string($8.dir) + " A\n"  
            + op1a + "#1\n" +
             "mov A " + to_string($8.dir) +
             "\nmov " + to_string($8.dir)+ " A\n"    
             +  "\n" + op1b + " #" + $7.lexema + 
              "\n"
             + "jnz L" + to_string(etiqact2) 
             + "\njmp L" + to_string(etiqact1) 
             + "\nL" + to_string(etiqact2)+"\n"; 
             if ($5.numint == $7.numint ){
                $$.trad = $8.trad
                + "L" + to_string(etiqact1) + "\n" 
                + $9.trad +
                "mov " + to_string($8.dir) + " A\n"  
                "mov A " + to_string($8.dir) +
                "\nmov " + to_string($8.dir)+ " A\n"    
                +  "\n"  ; 
             }
            tsActual = tsActual->padre;
    }
    | iftok E {if($2.tipo!=ENTERO) errorSemantico(ERR_IFWHILE, $1.lexema, $1.fila, $1.col);} I Ip {
        int etiqact1 = nuevaEtiqueta(); 
        int etiqact2 = nuevaEtiqueta();
        $$.trad = $2.trad + 
        "mov " + to_string($2.dir) + " A\n" +
         "jz L" + to_string(etiqact1) + "\n" 
         + $4.trad 
         + "jmp L" + to_string(etiqact2) + "\n" +
         + 
         "L" + to_string(etiqact1)+"\n"
         +$5.trad +
         "L" + to_string(etiqact2) + "\n";
}; 

Ip: elsetok I fi {
    $$.trad = $2.trad; 
    $$.dir = $2.dir; 
    }
    | fi {
        $$.trad = ""; 
    }; 

Blq: blq {tsActual = new TablaSimbolos(tsActual); } Cod {tsActual = tsActual->getPadre();}fblq {
    
    $$.trad = $3.trad;

    
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
    if($2.tipo != ENTERO) errorSemantico(ERR_IFWHILE, $1.lexema, $1.fila, $1.col
    );

    int etiq = nuevaEtiqueta();
    $$.trad = $2.trad + "mov " + to_string($2.dir) + " A\n" + "jz " + "L" + to_string(etiq) + "\n";
    $$.dir = $2.dir;
    $$.atributos.etiqueta = "L" + to_string(etiq) + "\n";

    }
    | {
        $$.trad ="";
        $$.atributos.etiqueta = ""; 

    }


E: E opas {
    if(strcmp($2.lexema, "+") == 0 ){$$.trad = "add"; }
    if(strcmp($2.lexema, "-")== 0){$$.trad = "sub";}
            } 
    T {
    int tmp = nuevaTemp($1.lexema, $1.fila, $1.col);
    $$.dir = tmp; 
    if($1.tipo == ENTERO && $4.tipo == ENTERO ){
       
        $$.trad = $1.trad 
        + "\n" + $4.trad 
        + "\n" +"mov " + to_string($1.dir) + 
         " A\n" + $3.trad +"i " 
         + to_string($4.dir) + 
         "\nmov A " +
          to_string($$.dir) + "\n"; 
        //cout<<"EL T TRAD ES "<<$4.trad<<endl;
        //cout<<"LA TRAD ES \n"<<$$.trad<<endl;
        //cout<<"FIN DE LA TRAD ****** "<<endl; 
        $$.tipo = ENTERO;
        $$.atributos.tipo = "int"; 
    }
    else if($1.tipo == REAL && $4.tipo == ENTERO){
        
        int tmpcp; 
        tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
        $$.trad = $1.trad + $4.trad + "mov " + to_string($4.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
        + "mov " + to_string($1.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp) + "\n"; 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float"; 
    }else if ($1.tipo == REAL && $4.tipo == REAL){
        
        $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n" + $3.trad + "r " + to_string($4.dir) + "\nmov A " + to_string(tmp) + "\n"; 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float";  
    }else if($1.tipo == ENTERO && $4.tipo == REAL){
        int tmpcp; 
        tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
        $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
        + "mov " + to_string($4.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp) + "\n"; 
        $$.tipo = REAL; 
        $$.atributos.tipo = "float"; 
    }

    //cout<<"SOY E Y MI TRAD FINAL ES " <<$$.trad<<endl;
    }
    | opas {if( strcmp($1.lexema,"+") ==0 ){$$.trad = "add"; }
            if(strcmp( $1.lexema ,"-") == 0) {$$.trad = "sub";}} T {
        
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col); 
        $$.trad = $3.trad;
        if($3.tipo == ENTERO){
            $$.trad = $$.trad + "mov #0 A \n"+  $2.trad + "i " + to_string($3.dir)+ "\n mov A "  + to_string(tmp)  + "\n"; 
            $$.tipo = ENTERO; 
            $$.dir = tmp; 
            $$.atributos.tipo = "int";  
        }else if($3.tipo == REAL ){
            $$.trad = $$.trad + "mov $0 A\n" + $2.trad + "r " + to_string($3.dir)+ "\n mov A "  + to_string(tmp) + "\n";  
            $$.tipo = REAL; 
            $$.dir = tmp;
            $$.atributos.tipo = "float"; 
        }
    }
    | T {
        $$.atributos.tipo = $1.atributos.tipo; 
        $$.tipo = $1.tipo; 
        $$.trad = $1.trad; 
        $$.dir = $1.dir;
        $$.atributos.dbase = $1.atributos.dbase;
        $$.lexema = $1.lexema;
        //cout<<"NUESTRA TRAD ES "<<$$.trad<<endl;
    };

T: T opmd {if(strcmp($2.lexema,"*") == 0 ){$$.trad = "mul"; }
           if(strcmp($2.lexema ,"/")== 0){$$.trad = "div";}} F 
            {
         int tmp = nuevaTemp($1.lexema, $1.fila, $1.col);
        $$.dir = tmp; 
        if($1.tipo == ENTERO && $4.tipo == ENTERO ){
        
            $$.trad = $1.trad 
            + "\n" + $4.trad 
            + "\n" +"mov " + to_string($1.dir) + 
            " A\n" + $3.trad +"i " 
            + to_string($4.dir) + 
            "\nmov A " +
            to_string($$.dir) + "\n"; 
            //cout<<"EL T TRAD ES "<<$4.trad<<endl;
            //cout<<"LA TRAD ES \n"<<$$.trad<<endl;
            //cout<<"FIN DE LA TRAD ****** "<<endl; 
            $$.tipo = ENTERO;
            $$.atributos.tipo = "int"; 
        }
        else if($1.tipo == REAL && $4.tipo == ENTERO){
            
            int tmpcp; 
            tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
            $$.trad = $1.trad + $4.trad + "mov " + to_string($4.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
            + "mov " + to_string($1.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp) + "\n"; 
            $$.tipo = REAL; 
            $$.atributos.tipo = "float"; 
        }else if ($1.tipo == REAL && $4.tipo == REAL){
            
            $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n" + $3.trad + "r " + to_string($4.dir) + "\nmov A " + to_string(tmp) + "\n"; 
            $$.tipo = REAL; 
            $$.atributos.tipo = "float";  
        }else if($1.tipo == ENTERO && $4.tipo == REAL){
            int tmpcp; 
            tmpcp = nuevaTemp($1.lexema, $1.fila, $1.col);
            $$.trad = $1.trad + $4.trad + "mov " + to_string($1.dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
            + "mov " + to_string($4.dir) + " A" + "\n" + $3.trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp) + "\n"; 
            $$.tipo = REAL; 
            $$.atributos.tipo = "float"; 
        }
    }
    | F {
        $$.tipo = $1.tipo;
        $$.trad = $1.trad;
        $$.dir = $1.dir;
        $$.atributos.dbase = $1.atributos.dbase;
        $$.lexema = $1.lexema;
        //cout<<$$.trad<<endl; 
        //cout<<"*****FINAL******"<<endl;
    }


F: numint {$$.tipo = ENTERO; 
        //cout<<"COSAS REF" << $1.lexema;
        $$.atributos.tipo = "int"; 
        unsigned temp = nuevaTemp($1.lexema , $1.fila, $1.col); 

        $$.trad =  "mov #" + string($1.lexema) + " " +  to_string(temp) + "\n"; 
        $$.dir = temp; 
        $$.tipo = ENTERO;
        $$.numint = $1.numint; 
        $$.atributos.dbase = temp; 
        }

    | numreal {
        $$.tipo = REAL; 
        $$.atributos.tipo = "real"; 
        
        int temp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.atributos.dbase = temp; 
        $$.trad = "mov $" + string($1.lexema) + " " +  to_string(temp) + "\n";
        $$.dir = temp; 


    }
    | pari E pard {
        $$.tipo = $2.tipo; 
        $$.atributos.tipo = $2.atributos.tipo; 
        $$.trad = $2.trad; 
        $$.atributos.dbase = $2.atributos.dbase; 
        $$.lexema = $2.lexema;
        //cout<<"EN EEEEEEEEE"<<endl;
        //cout<<$$.trad<<endl;
        //cout<<"FIN DE EEEEE"<<endl; 
        $$.dir = $2.dir; 
    }
    | Ref {
        int newt = nuevaTemp($1.lexema, $1.fila , $1.col);

        $$.trad = $1.trad + "mov " + to_string($1.dir) +" A\n";
        $$.trad += "mov @A " + to_string(newt) +"\n";
        

        $$.tipo = $1.tipo; 
        $$.atributos = $1.atributos; 
        $$.dir = newt;
        $$.atributos.dbase = $1.atributos.dbase; 
        
        $$.lexema = $1.lexema;
          
    }; 

Ref: id{ 
       
        if( tsActual->searchSymb($1.lexema) == NULL) {
            //cout<<$1.lexema<<endl;
            errorSemantico(ERR_NODECL,$1.lexema,$1.fila,$1.col);
        }
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo;
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col );
        $$.dir =  tmp;
        $$.atributos.dbase = tsActual->searchSymb($1.lexema)->dir;
        
        $$.trad = "mov #"  + to_string(tsActual->searchSymb($1.lexema)->dir) + " "+ to_string(tmp) + "\n";
        $$.lexema = $1.lexema; 
        //cout<<$$.trad<<endl;
    }

    | id 
    {if(tsActual->searchSymb($1.lexema) == NULL) errorSemantico(ERR_NODECL,$1.lexema,$1.fila,$1.col); 
        if(!esArray(tsActual->searchSymb($1.lexema)->tipo)) errorSemantico(ERR_SOBRAN,$1.lexema,$1.fila,$1.col);
        $$.tipo = tsActual->searchSymb($1.lexema)->tipo; 
     } 
     cori 
     {
        $$.tam = ttActual->tipos[$1.tipo].tamano; 
        $$.tipo =  tsActual->searchSymb($1.lexema)->tipo;
        $$.atributos.dbase = tsActual->searchSymb($1.lexema)->dir;
        $$.dir = tsActual->searchSymb($1.lexema)->dir; 
        } 
    LExpr  
    cord 
    {
        if(esArray($5.tipo)) errorSemantico(ERR_FALTAN, $6.lexema, $6.fila, $6.col); 
        int tmp = nuevaTemp($1.lexema, $1.fila, $1.col); 
        $$.dir = tmp; 
        $$.trad = $5.trad + "\nmov " + to_string($5.dir) + " A\n" + "\naddi #" + to_string($5.dir) + "\n" + "mov A " + to_string(tmp) + "\n"; 
       
        $$.tipo = $5.tipo; 
   }; 

LExpr: LExpr coma {$$.tipo = $1.tipo; if(!esArray($1.tipo)){
   
    errorSemantico(ERR_SOBRAN, $2.lexema, $2.fila, $2.col );}
    } E{
        
        if($4.tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,$2.lexema,$2.fila,$2.col);
        
        $$.tipo = ttActual->tipos[$1.tipo].tipoBase;
        
        $$.atributos.dbase = $0.atributos.dbase; 
        int tmp = nuevaTemp($1.lexema , $1.fila, $1.col); 
        $$.dir = tmp;
        //cout<<"MI TRAD A "<<$0.trad<<endl;
        //cout<<"MI TRAD 2 "<<$3.trad<<endl;
        $$.trad = $1.trad +  $4.trad + "\nmov " + to_string($1.dir) +
         " A\n" + "muli " + "#" + to_string(ttActual->tipos[$1.tipo].tamano)
         + "\naddi " + to_string( $4.dir)  
        + "\n" + "mov A " + to_string(tmp) + "\n"; 
    }
    | E {
       
        if($1.tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,$1.lexema,$1.fila,$1.col);
        int tmp = nuevaTemp($1.lexema, $1.fila,$1.col);
        $$.trad = $1.trad + "mov " + to_string($1.dir) + " " + to_string(tmp)+ "\n";
        
        $$.tipo = ttActual->tipos[$0.tipo].tipoBase;
        $$.atributos.dbase = ttActual->tipos[$0.tipo].tipoBase;
        $$.dir = tmp;
        $$.atributos.dbase = $0.dir; 
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
    //cout<<"ESTOY PASANDO CON CTEMP "<<ctemp;
    ctemp = ctemp + 1; 
    
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
