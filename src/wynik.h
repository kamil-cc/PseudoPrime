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
  * Nazwa bie��cego pliku: wynik.h                       *
  * Nag��wek zawiera:                                    *
  * -deklaracje funkcji statycznych zapisuj�cych dane    * 
  *  do pliku (2 warianty tej funkcji, do wyboru z menu) *
  * -definicj� klasy s�u��cej do otwierania pliku,       *
  *  zapisu danych, umieszczania informacji o programie, *
  *  podawania rozmiaru pliku,                           *
  * -klasa zawiera wska�nik na funkcj� statyczn�,        *
  *  kt�ry jest ustawiany na jedn� z funkcji globalnych  *
  *  (w zale�no�ci od potrzeb).                          *
  ********************************************************
  
**/

#ifndef WYNIK_H
#define WYNIK_H 1

#define BAZA 10 //Baza dziesi�tna, u�ywana w funkcji mpz_sizeinbase()
#define KILOB 1024 //Sta�a do przeliczania bajt�w na kilobajty
#define NAZWA "wynik.txt" //Nazwa pliku wyj�ciowego
#define ZERO 0 //Sta�a do inicjalizacji licznika cyfr
#define JEDEN 1 //Sta�a do zaokr�glania rozmiaru plik�w

#include <fstream>
#include <gmpxx.h>

using namespace std;

static void dodaj_wszystko(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Zapisz wszystko
static void dodaj_filtruj(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Zapisz selektywnie

class wynik //Przechowuje dane zwi�zane z wynikiem i zapisuje do pliku
{
	private:
		fstream plik; //Plik wyj�ciowy
		void (*wsk)(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Wska�nik na funkcj� statyczn�
	public:
		mpz_class licznik; //Ilo�� wygenerowanych liczb
	public:
		wynik();
		void ustaw_metode_zapisu(const bool &wszystkie); //Ustala czy filtrowa� liczb� podczas zapisu, otwiera plik
		void info_do_pliku(const mpz_class &amin, const mpz_class &amax, const mpz_class &pmin, const mpz_class &pmax, const bool &wszystko, const size_t &min, const size_t &max); //Zapisuje dla jakich danych wygenerowano plik
		void zapisz(mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max); //Wywo�uje jedn� z dw�ch funkcji globalnych
		size_t rozmiar(void); //Zwraca rozmiar wygenerowanego pliku, zamyka plik
		~wynik();
};

#endif
