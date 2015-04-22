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
  * Nazwa bie¿¹cego pliku: dane.h                        *
  * Nag³ówek zawiera:                                    *
  * -sta³e (u¿yte w pliku dane.cpp),                     *
  * -definicjê klasy, która s³u¿y do przechowywania      *
  *  danych wejœciowych,                                 *
  * -deklaracjê funkcji s³u¿¹cej do kontroli poprawnoœæi *
  *  wprowadzonych danych.                               *  
  ********************************************************
  
**/

#ifndef DANE_H
#define DANE_H 1

#define WYKLADNIK_S 1 //Sta³e okreœlaj¹ce, któr¹ liczbê ma zwróciæ funkcja zwroc_liczbe
#define WYKLADNIK_K 2
#define BAZA_S 3
#define BAZA_K 4
#define MIN 2 //Minimalna wartoœæ wprowadzanych danych

#include <gmpxx.h>
#include <climits> //ULONG_MAX

class dane //Dane wejœciowe
{
	public:
		mpz_class baza_start; //Baza, od której program rozpoczyna dzia³anie
		mpz_class baza_kon; //Baza, na której program koñczy dzia³anie
		mpz_class wykladnik_start; //Wyk³adnik, od którego program rozpoczyna dzia³anie
		mpz_class wykladnik_kon; //W
	public:
		bool wszystkie; //True oznacza, ¿e wynik nie jest filtrowany
		size_t o_dolne; //Minimalna iloœæ cyfr w wyniku
		size_t o_gorne; //Maksymalna iloœæ cyfr w wyniku
	public:
		mpz_class& zwroc_liczbe(const int &ktora); //Zwraca liczbê, kontroluje dane
};

#endif
