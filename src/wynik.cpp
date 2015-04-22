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
  * Nazwa bie¿¹cego pliku: wynik.cpp                     *
  ********************************************************
  
**/

#include "wynik.h"

static void dodaj_wszystko(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max)
{
	++licznik;
	plik<<"("<<licznik<<") Liczba: "<<liczba<<",    Cyfry: "<<(unsigned long int)mpz_sizeinbase(liczba.get_mpz_t(), BAZA)<<", Baza: "<<baza<<", Wykladnik: "<<wykladnik<<endl;
	return;
}

static void dodaj_filtruj(fstream &plik, mpz_class &licznik, const mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max)
{
	size_t pom = mpz_sizeinbase(liczba.get_mpz_t(), BAZA); //Zwraca iloœæ cyfr lub iloœæ cyfr + 1, funkcja nie zawsze zwraca poprawn¹ wartoœæ (wiêcej informacji: Dokumentacja GMP)
	if(pom >= min && pom <= max)
	{
		++licznik;
		plik<<"("<<licznik<<") Liczba: "<<liczba<<",    Cyfry: "<<(unsigned long int)pom<<", Baza: "<<baza<<", Wykladnik: "<<wykladnik<<endl;
	}
	return;
}

wynik::wynik()
{
	licznik = ZERO;
}

void wynik::ustaw_metode_zapisu(const bool &wszystkie)
{
	plik.open(NAZWA, ios::out | ios::trunc); //Otwarcie pliku do pisania, kasuje poprzedni¹ zawartoœæ
	if(wszystkie == false)
		wsk=&dodaj_filtruj;
	else
		wsk=&dodaj_wszystko;
	return;
}

void wynik::info_do_pliku(const mpz_class &amin, const mpz_class &amax, const mpz_class &pmin, const mpz_class &pmax, const bool &wszystko, const size_t &min, const size_t &max)
{
	plik<<"Plik wygenerowany przez program: Generator liczb pseudopierwszych"<<endl;
	plik<<"Autor programu: Kamil Burzynski"<<endl;
	plik<<"Dzialanie dla danych:"<<endl;
	plik<<"a(start)="<<amin<<endl;
	plik<<"a(stop)="<<amax<<endl;
	plik<<"p(start)="<<pmin<<endl;
	plik<<"p(stop)="<<pmax<<endl;
	if(wszystko == false)
	{
		plik<<"Filtrowanie wlaczone"<<endl;
		plik<<"Minimalna ilosc cyfr="<<min<<endl;
		plik<<"Maksymalna ilosc cyfr="<<max<<endl;
	}
	else
	{
		plik<<"Filtrowanie wylaczone"<<endl;
	}
	plik<<endl;
	return;
}

void wynik::zapisz(mpz_class &liczba, const mpz_class &baza, const mpz_class &wykladnik, const size_t &min, const size_t &max)
{
	wsk(plik, licznik, liczba, baza, wykladnik, min, max);
	return;
}

size_t wynik::rozmiar(void)
{
	size_t pom = ((plik.tellg()/KILOB) + JEDEN);
	plik.close();
	return pom;
}

wynik::~wynik()
{
}
