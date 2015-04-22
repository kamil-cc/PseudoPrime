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
  * Nazwa bie¿¹cego pliku: ekran.cpp                     *
  ********************************************************
  
**/

#include "ekran.h"

void ekran::witaj(dane &wej)
{
	char pom;
	cout<<endl;
	cout<<GROTL<<" Program sluzy do generowania duzych liczb pseudopierwszych "<<GROTR<<endl;
	cout<<"Zastosowany algorytm liczy kolejno: "<<endl;
	cout<<"  (1) n1=((a^p)-1)/(a-1)"<<endl;
	cout<<"  (2) n2=((a^p)+1)/(a+1)"<<endl;
	cout<<"  (3) n1*n2=pseudopierwsza"<<endl;
	cout<<"w zakresie od a(start) do a(stop) oraz od p(start) do p(stop)."<<endl;
	cout<<"Nalezy wprowadzac dane wedlug ponizszych instrukcji:"<<endl;
	cout<<"Prosze podac baze, dla ktorej program rozpocznie prace [2, +niesk.]:"<<endl;
	cout<<STRZALKA<<" a(start)=";
	cin>>wej.baza_start;
	cout<<"Prosze podac baze, dla ktorej program zakonczy prace [2, +niesk.]:"<<endl;
	cout<<STRZALKA<<" a(stop)=";
	cin>>wej.baza_kon;
	cout<<"Prosze podac wykladnik, dla ktorego program rozpocznie prace [2, "<<ULONG_MAX<<"]:"<<endl;
	cout<<STRZALKA<<" p(start)=";
	cin>>wej.wykladnik_start;
	cout<<"Prosze podac wykladnik, dla ktorego program zakonczy prace [2, "<<ULONG_MAX<<"]:"<<endl;
	cout<<STRZALKA<<" p(stop)=";
	cin>>wej.wykladnik_kon;
	cout<<"Czy program ma filtrowac wyniki w zaleznosci od ilosci cyfr?"<<endl;
	cout<<STRZALKA<<" (t/n): ";
	cin>>pom;
	if(pom == 't' || pom == 'T')
		wej.wszystkie=false;
	else
		wej.wszystkie=true;
	if(wej.wszystkie == false)
	{
		cout<<"Podaj minimalna ilosc cyfr w generowanej liczbie:"<<endl;
		cout<<STRZALKA<< " min=";
		cin>>wej.o_dolne;
		cout<<"Podaj maksymalna ilosc cyfr w generowanej liczbie:"<<endl;
		cout<<STRZALKA<<" max=";
		cin>>wej.o_gorne;
	}
	cout<<"Prosze czekac, trwa wykonywanie obliczen..."<<endl;
	pocz=time(NULL);
	return;
}

void ekran::podsumowanie(wynik &wyj)
{
	kon=time(NULL);
	cout<<"Program pomyslnie wykonal wszystkie operacje "<<USMIECH<<endl; 
	cout<<"Czas wykonywania obliczen to: "<<difftime(kon, pocz)<<" sekund"<<endl;
	cout<<"Ilosc wygenerowanych liczb to: "<<wyj.licznik<<endl;
	cout<<"Wyniki obliczen zostaly zapisane do pliku: "<<NAZWA<<endl;
	cout<<"Rozmiar utworzonego pliku to: "<<wyj.rozmiar()<<" KB"<<endl;
	return;
}

void ekran::koniec(void)
{
	cout<<GROTL<<" Autor programu: Kamil Burzynski "<<GROTR<<endl;
	return;
}

