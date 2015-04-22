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
  * Nazwa bie¿¹cego pliku: ppalg.cpp                     *
  ********************************************************
  
**/

#include "ppalg.h"

void ppalg::licz(dane &wej, wynik &wyj)
{
	const mpz_class jeden = 1; //Potrzebna w ró¿nych operacjach arytmetycznych
	const mpz_class q = wej.zwroc_liczbe(WYKLADNIK_S); //Wyk³adnik sta³y
	mpz_class n; //Przechowuje wynik(liczbê pseudopierwsz¹)
	mpz_class n1; //Zmienna przechowuje (a^p-1)/(a-1)
	mpz_class n2; //Zmienna przechowuje (a^p+1)/(a+1)
	mpz_class a2; //Zmienna przechowuje a^2
	mpz_class a3a; //Zmienna przechowuje a(a^2-1)
	mpz_class ap;  //Zmienna przechowuje a^p
	mpz_class p; //Wyk³adnik zwiêkszaj¹cy siê (s³u¿y do wygenerowania liczby pierwszej nieparzystej)
	mpz_class pmax = wej.zwroc_liczbe(WYKLADNIK_K); //Wartoœæ wyk³adnika, przy której koñczymy obliczenia
	mpz_class a = wej.zwroc_liczbe(BAZA_S); //Nadanie wartoœci podstawie
	mpz_class amax = wej.zwroc_liczbe(BAZA_K); //Podstawa maksymalna
	const unsigned long int idwa = 2; //Wartoœæ, na podstawie której generujemy kolejne liczby pierwsze nieparzyste
	
	wyj.ustaw_metode_zapisu(wej.wszystkie); //Ustala czy filtrowaæ liczbê podczas zapisu
	wyj.info_do_pliku(a, amax, q, pmax, wej.wszystkie, wej.o_dolne, wej.o_gorne);
	//Algorytm:
	for(;a<=amax;++a) //Dla kolejnych baz
	{
		mpz_pow_ui(a2.get_mpz_t(), a.get_mpz_t(), idwa); //Liczenie a^2
		a3a = a*(a2 - jeden); //Liczenie a(a^2-1)
		p=q;
		for(dobra_pierwsza(p, a3a); p<=pmax; dobra_pierwsza(p, a3a)) //Dla ka¿dej nastêpnej liczby pierwszej, która nie dzieli a(a^2-1)
		{	
			mpz_pow_ui(ap.get_mpz_t(), a.get_mpz_t(),  p.get_ui()); //Liczenie ap=a^p
			n1=(ap-jeden)/(a-jeden); //Liczenie n1=(ap-1)/(a-1)
			n2=(ap+jeden)/(a+jeden); //Liczenie n2=(ap+1)/(a+1)
			n=n1*n2; //Liczenie n=n1*n2, n jest pseudopierwsza
			wyj.zapisz(n, a, n-jeden, wej.o_dolne, wej.o_gorne); //Zapis liczby do pliku
		}
	}
	return;
}

void ppalg::dobra_pierwsza(mpz_class &poprz, mpz_class &a3a)
{
	mpz_class pom;
	
	mpz_nextprime(pom.get_mpz_t(), poprz.get_mpz_t()); //Nastêpna liczba pierwsza po poprz
	while(mpz_divisible_p(a3a.get_mpz_t(),pom.get_mpz_t())) //Czy dzieli a3a
	{
		poprz=pom; //Tak, dzieli; zmiana poprz
		mpz_nextprime(pom.get_mpz_t(), poprz.get_mpz_t()); //Nastêpna liczba pierwsza po poprz
	}
	poprz=pom; //Zwracanie nastêpnej liczby pierwszej, która nie dzieli a(a^2-1)
	return;
}

