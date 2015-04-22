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
  * Nazwa bie¿¹cego pliku: ekran.h                       *
  * Nag³ówek zawiera:                                    *
  * -sta³e (u¿yte w pliku ekran.cpp),                    *
  * -definicjê klasy odpowiedzialnej za wyœwietlanie     *
  *  tekstu w oknie konsoli i liczenie czasu wykonywania *
  *  g³ównego algorytmu,                                 *
  * -deklaracje funkcji s³u¿¹cych do wyœwietlania        * 
  *  odpowiednich komunikatów.                           *
  ********************************************************
  
**/
 
#ifndef EKRAN_H
#define EKRAN_H 1

#define USMIECH (char)2 //Sta³e zastêpuj¹ce kody grafiki w ASCII
#define GROTR (char)16
#define GROTL (char)17
#define STRZALKA (char)26

#include <iostream>
#include <ctime> //time_t, time()
#include <gmpxx.h>
#include "dane.h"
#include "wynik.h"

using namespace std;

class ekran //Odpowiada za wyœwietlanie tekstu
{
	private:
		time_t pocz; //Czas rozpoczêcia obliczeñ
		time_t kon; //Czas zakoñczenia obliczeñ
	public:
		void witaj(dane &wej); //Wyœwietla komunikat powitalny
        void podsumowanie(wynik &wyj); //Wyœwietla podsumowanie operacji
		void koniec(void); //Wyœwietla komunikat koñcowy
};

#endif
