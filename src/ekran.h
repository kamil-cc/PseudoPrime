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
  * Nazwa bie��cego pliku: ekran.h                       *
  * Nag��wek zawiera:                                    *
  * -sta�e (u�yte w pliku ekran.cpp),                    *
  * -definicj� klasy odpowiedzialnej za wy�wietlanie     *
  *  tekstu w oknie konsoli i liczenie czasu wykonywania *
  *  g��wnego algorytmu,                                 *
  * -deklaracje funkcji s�u��cych do wy�wietlania        * 
  *  odpowiednich komunikat�w.                           *
  ********************************************************
  
**/
 
#ifndef EKRAN_H
#define EKRAN_H 1

#define USMIECH (char)2 //Sta�e zast�puj�ce kody grafiki w ASCII
#define GROTR (char)16
#define GROTL (char)17
#define STRZALKA (char)26

#include <iostream>
#include <ctime> //time_t, time()
#include <gmpxx.h>
#include "dane.h"
#include "wynik.h"

using namespace std;

class ekran //Odpowiada za wy�wietlanie tekstu
{
	private:
		time_t pocz; //Czas rozpocz�cia oblicze�
		time_t kon; //Czas zako�czenia oblicze�
	public:
		void witaj(dane &wej); //Wy�wietla komunikat powitalny
        void podsumowanie(wynik &wyj); //Wy�wietla podsumowanie operacji
		void koniec(void); //Wy�wietla komunikat ko�cowy
};

#endif
