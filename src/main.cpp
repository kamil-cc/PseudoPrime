/**

  ********************************************************
  * Program zaliczeniowy przedmiotu Projekt Indywidualny *
  ********************************************************
  * Temat projektu: Program do znajdowania du¿ych liczb  *
  *                 pseudopierwszych (100-150 cyfr).     *
  ********************************************************
  * Autor: Kamil Burzyñski                               *
  * student II roku Informatyki i Ekonometrii UKSW       *
  * w Warszawie                                          *
  * rok akademicki 2008/2009                             *
  * sesja wrzeœniowa                                     *
  ********************************************************

**/
/**

  ********************************************************
  * Pliki potrzebne do kompilacji programu:              *
  * main.cpp                                             *
  * ekran.h                                              *
  * ekran.cpp                                            *
  * dane.h                                               *
  * dane.cpp                                             *
  * ppalg.h                                              *
  * ppalg.cpp                                            *
  * wynik.h                                              *
  * wynik.cpp                                            *
  * Biblioteki statyczne:                                *
  * libgmp.a                                             *
  * libgmp.la                                            *
  * libgmp.lai                                           *
  * libgmpxx.a                                           *
  * libgmpxx.la                                          *
  * libgmpxx.lai                                         *
  * Program kompilowany przy u¿yciu kompilatora MinGW,   *
  * z konsoli Windows, za pomoc¹ polecenia:              *
  * "g++ main.cpp dane.cpp ekran.cpp ppalg.cpp wynik.cpp *
  * -lgmpxx -lgmp -o generator"                          *
  ********************************************************
  
**/
/**

  ********************************************************
  * Nazwa bie¿¹cego pliku: main.cpp                      *
  * Plik zawiera instrukcje odpowiedzialne               *
  * za uruchomienie programu, wywo³anie podstawowych     *
  * funkcji i zakoñczenie wykonywania programu.          *
  ********************************************************
  
**/

#include <cstdlib> //system("PAUSE");
#include "ekran.h"
#include "ppalg.h"
#include "dane.h"
#include "wynik.h"

int main()
{
	ekran konsola; //Obiekt odpowiedzialny za wyœwietlanie tekstu
	dane wej; //Obiekt przechowuj¹cy dane wejœciowe
	ppalg algorytm; //Obiekt zawieraj¹cy g³ówny algorytm programu
	wynik wyj; //Obiekt przechowuj¹cy wyniki
	konsola.witaj(wej); //Komunikat na ekran
	algorytm.licz(wej, wyj);  //Obliczenia 
	konsola.podsumowanie(wyj); //Komunikat na ekran
	konsola.koniec(); //Komunikat na ekran
	system("PAUSE"); //Oczekiwanie na wciœniêcie klawisza 
	return 0;
}
