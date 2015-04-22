/**

  ********************************************************
  * Program zaliczeniowy przedmiotu Projekt Indywidualny *
  * Autor: Kamil Burzy�ski                               *
  * student II roku Informatyki i Ekonometrii UKSW       *
  * w Warszawie                                          *
  * rok akademicki 2008/2009                             *
  ********************************************************

**/
/**

  ********************************************************
  * Nazwa bie��cego pliku: ppalg.h                       *
  * Nag��wek zawiera:                                    *
  * -definicj� obiektu, w kt�rym wykonywany jest g��wny  *
  *  algorytm programu,                                  *
  * -deklaracj� funkcji pomocniczej wzgl�dem g��wnego    *
  *  algorytmu,                                          *
  * -deklaracj� funkcji - g��wnego algorytmu.            *
  ********************************************************
  
**/

#ifndef PPALG_H
#define PPALG_H 1

#include <gmpxx.h>
#include "dane.h"
#include "wynik.h"

class ppalg
{
	private:
		void dobra_pierwsza(mpz_class &poprz, mpz_class &a3a); //Zwraca liczb� pierwsz�, kt�ra nie dzieli a3a
	public:
		void licz(dane &wej, wynik &wyj); //G��wny algorytm programu
};

#endif
