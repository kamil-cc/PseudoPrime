/**

  ********************************************************
  * Program zaliczeniowy przedmiotu Projekt Indywidualny *
  * Autor: Kamil Burzyñski                               *
  * student II roku Informatyki i Ekonometrii UKSW       *
  * w Warszawie                                          *
  * rok akademicki 2008/2009                             *
  ********************************************************

**/
/**

  ********************************************************
  * Nazwa bie¿¹cego pliku: ppalg.h                       *
  * Nag³ówek zawiera:                                    *
  * -definicjê obiektu, w którym wykonywany jest g³ówny  *
  *  algorytm programu,                                  *
  * -deklaracjê funkcji pomocniczej wzglêdem g³ównego    *
  *  algorytmu,                                          *
  * -deklaracjê funkcji - g³ównego algorytmu.            *
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
		void dobra_pierwsza(mpz_class &poprz, mpz_class &a3a); //Zwraca liczbê pierwsz¹, która nie dzieli a3a
	public:
		void licz(dane &wej, wynik &wyj); //G³ówny algorytm programu
};

#endif
