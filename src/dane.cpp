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
  * Nazwa bie¿¹cego pliku: dane.cpp                      *
  ********************************************************
  
**/

#include "dane.h"

mpz_class& dane::zwroc_liczbe(const int &ktora)
{
	switch(ktora)
	{
		case WYKLADNIK_S:
			if(wykladnik_start < MIN)
				wykladnik_start=MIN;
			if(wykladnik_start > ULONG_MAX)
				wykladnik_start=ULONG_MAX;
			return wykladnik_start;
		break;
		case WYKLADNIK_K:
			if(wykladnik_kon < MIN)
				wykladnik_kon=MIN;
			if(wykladnik_kon > ULONG_MAX)
				wykladnik_kon=ULONG_MAX;
			return wykladnik_kon;
		break;
		case BAZA_S:
			if(baza_start < MIN)
				baza_start=MIN;
			return baza_start;
		break;
		case BAZA_K:
			if(baza_kon < MIN)
				baza_kon=MIN;
			return baza_kon;
		break;
	}
}
