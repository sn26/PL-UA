
#ifndef _TablaSimbolos_
#define _TablaSimbolos_

#include <string>
#include <vector>

using namespace std;

const int ENTEROT=1;
const int REALT=2;
const int FUNCIONT=3;
const int VOIDT=4;

struct Simbolo {

  string nombre;
  int tipo;
  string nomtrad;
};


class TablaSimbolos {

   private:

      bool buscarAmbito(Simbolo s); // ver si está en el ámbito actual
   
   public:
   
      TablaSimbolos *padre;
      vector<Simbolo> simbolos;
   
      TablaSimbolos(TablaSimbolos *padre);
      TablaSimbolos *getPadre() { return padre; }
   
      bool newSymb(Simbolo s);
      Simbolo* searchSymb(string nombre);
};


#endif