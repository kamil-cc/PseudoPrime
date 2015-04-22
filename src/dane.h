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
  * Nazwa bie��cego pliku: dane.h                        *
  * Nag��wek zawiera:                                    *
  * -sta�e (u�yte w pliku dane.cpp),                     *
  * -definicj� klasy, kt�ra s�u�y do przechowywania      *
  *  danych wej�ciowych,                                 *
  * -deklaracj� funkcji s�u��cej do kontroli poprawno��i *
  *  wprowadzonych danych.                               *  
  ********************************************************
  
**/

#ifndef DANE_H
#define DANE_H 1

#define WYKLADNIK_S 1 //Sta�e okre�laj�ce, kt�r� liczb� ma zwr�ci� funkcja zwroc_liczbe
#define WYKLADNIK_K 2
#define BAZA_S 3
#define BAZA_K 4
#define MIN 2 //Minimalna warto�� wprowadzanych danych

#include <gmpxx.h>
#include <climits> //ULONG_MAX

class dane //Dane wej�ciowe
{
	public:
		mpz_class baza_start; //Baza, od kt�rej program rozpoczyna dzia�anie
		mpz_class baza_kon; //Baza, na kt�rej program ko�czy dzia�anie
		mpz_class wykladnik_start; //Wyk�adnik, od kt�rego program rozpoczyna dzia�anie
		mpz_class wykladnik_kon; //W
	public:
		bool wszystkie; //True oznacza, �e wynik nie jest filtrowany
		size_t o_dolne; //Minimalna ilo�� cyfr w wyniku
		size_t o_gorne; //Maksymalna ilo�� cyfr w wyniku
	public:
		mpz_class& zwroc_liczbe(const int &ktora); //Zwraca liczb�, kontroluje dane
};

#endif
