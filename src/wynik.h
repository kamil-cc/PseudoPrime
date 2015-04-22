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
  * Nazwa bie¿¹cego pliku: wynik.h                       *
  * Nag³ówek zawiera:                                    *
  * -deklaracje funkcji statycznych zapisuj¹cych dane    * 
  *  do pliku (2 warianty tej funkcji, do wyboru z menu) *
  * -definicjê klasy s³u¿¹cej do otwierania pliku,       *
  *  zapisu danych, umieszczania informacji o programie, *
  *  podawania rozmiaru pliku,                           *
  * -klasa zawiera wskaŸnik na funkcjê statyczn¹,        *
  *  który jest ustawiany na jedn¹ z funkcji globalnych  *
  *  (w zale¿noœci od potrzeb).                          *
  ********************************************************
  
**/

#ifndef WYNIK_H
#define WYNIK_H 1

#define BAZA 10 //Baza dziesiêtna, u¿ywana w funkcji mpz_sizeinbase()
#define KILOB 1024 //Sta³a do przeliczania bajtów na kilobajty
#define NAZWA "wynik.txt" //Nazwa pliku wyjœciowego
#define ZERO 0 //Sta³a do inicjalizacji licznika cyfr
#define JEDEN 1 //Sta³a do zaokr¹glania rozmiaru plików

#include <fstream>
#include <gmpxx.h>

using namespace std;

static void dodaj_wszystko(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Zapisz wszystko
static void dodaj_filtruj(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Zapisz selektywnie

class wynik //Przechowuje dane zwi¹zane z wynikiem i zapisuje do pliku
{
	private:
		fstream plik; //Plik wyjœciowy
		void (*wsk)(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //WskaŸnik na funkcjê statyczn¹
	public:
		mpz_class licznik; //Iloœæ wygenerowanych liczb
	public:
		wynik();
		void ustaw_metode_zapisu(const bool &wszystkie); //Ustala czy filtrowaæ liczbê podczas zapisu, otwiera plik
		void info_do_pliku(const mpz_class &amin, const mpz_class &amax, const mpz_class &pmin, const mpz_class &pmax, const bool &wszystko, const size_t &min, const size_t &max); //Zapisuje dla jakich danych wygenerowano plik
		void zapisz(mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Wywo³uje jedn¹ z dwóch funkcji globalnych
		size_t rozmiar(void); //Zwraca rozmiar wygenerowanego pliku, zamyka plik
		~wynik();
};

#endif
