#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <stdio.h>

#include "main.hpp"
#include "funkcje.hpp"

using namespace std;

	
int main(int argc, char** argv) 
{

	//////////WCZYTYWANIE DANYCH////////////
	
	//otwieranie pliku tekstowego//
	fstream dane;
	dane.open("dane.txt", ios::in);
	
	//sprawdzanie czy plik tesktowy istnieje//
	if(dane.good()==false)
	{
		cout << "Plik nie istnieje";
		exit(0);
	}

	string linia;
	string liczba;
	//pêtla przez wszystkie linie pliku tesktowego//
	while(getline(dane, linia))
	{	
			if(nrLinii == 1)
			{
				sscanf(linia.c_str(), "%i", &szerokoscMacierzy_1);
				//cout << szerokoscMacierzy_1 << "SZERKOSC" << endl;
				counter_lines++;
			}
			
			if(nrLinii == 2)
			{
				sscanf(linia.c_str(), "%i", &wysokoscMacierzy_1);
				//cout << wysokoscMacierzy_1 << "WYSOKOSC" << endl;
				macierz1_saved = true;
				counter_lines++;
			}
			
			if(nrLinii == counter_lines && macierz1_saved == true)
			{
				//cout << counter_lines << "counter_lines" << nrLinii << "nrLINI" << endl;
				for(int j = 0; j < linia.length(); j++)
				{
					znak = linia[j];
					liczba = liczba + znak;
						
					if(znak == ' ')
					{

						if(liczba != "" && liczba != " ")
						{	
							liczba = liczba.erase(liczba.length()-1, liczba.length());
							//cout << liczba << " ";
							macierz_1[counter_lines-3][counter_liczb] = atoi(liczba.c_str());	
							liczba = "";
							counter_liczb++;	
						}
					}
											
					if(j == linia.length() - 1)
					{
						if(counter_lines <= wysokoscMacierzy_1 + 2)
						{
							if(liczba != "" && liczba != " ")
							{
								macierz_1[counter_lines-3][counter_liczb] = atoi(liczba.c_str());	
							}
							
							if(liczba != "" && liczba != " ")
							{
								counter_liczb++;	
							}
							
							if(counter_liczb != szerokoscMacierzy_1)
							{
								brakDanych = true;
								break;
							}
							else
							{
								liczba = "";
								counter_liczb = 0;	
								counter_lines++;
							}										
						}
						else
						{
							liczba = "";	
							counter_liczb = 0;	
							macierz1_saved = false;	
						}			
					}					
				}	
			}
			
			if(nrLinii == wysokoscMacierzy_1 + 3)
			{
				//cout << nrLinii << " " << wysokoscMacierzy_1 + 3 << endl;
				sscanf(linia.c_str(), "%i", &szerokoscMacierzy_2);
				//cout << szerokoscMacierzy_2 << "SZERKOSC" << endl;
				counter_lines++;	
			}
			
			if(nrLinii == wysokoscMacierzy_1 + 4)
			{
				//cout << nrLinii << " " << wysokoscMacierzy_1 + 4 << endl;
				sscanf(linia.c_str(), "%i", &wysokoscMacierzy_2);
				//cout << wysokoscMacierzy_2 << "WYSOKOSC" << endl;
				macierz2_saved = true;
				counter_lines++;	
			}
			
			if(nrLinii == counter_lines && macierz2_saved == true)
			{
				//cout << counter_lines << "counter_lines" << nrLinii << "nrLINI" << endl;
				for(int j = 0; j < linia.length(); j++)
				{
					znak = linia[j];
					liczba = liczba + znak;
						
					if(znak == ' ')
					{
						if(liczba != "")
						{
							liczba = liczba.erase(liczba.length()-1, liczba.length());
							macierz_2[counter_lines-wysokoscMacierzy_1-5][counter_liczb] = atoi(liczba.c_str());
							//cout << liczba << " ";	
							liczba = "";
							counter_liczb++;
							
						}
					}
											
					if(j == linia.length() - 1)
					{
						if(counter_lines <= wysokoscMacierzy_1 + wysokoscMacierzy_2 + 4)
						{
							if(liczba != "" && liczba != " ")
							{
								macierz_2[counter_lines-wysokoscMacierzy_1-5][counter_liczb] = atoi(liczba.c_str());								
							}
							
							if(liczba != "" && liczba != " ")
							{
								counter_liczb++;	
							}
							
							if(counter_liczb != szerokoscMacierzy_2)
							{
								brakDanych = true;
								break;
							}
							else
							{
								liczba = "";
								counter_liczb = 0;	
								counter_lines++;
							}
								
															
						}
						else
						{
							liczba = "";	
							counter_liczb = 0;	
							macierz2_saved = false;	
						}			
					}					
				}	
			}

					
		//inkrementacja numeru lini w pliku tesktowym//			
		nrLinii++;
	
	}
	
	//zamkniêcie pliku tekstowego//
	dane.close();

	///////WYBOR DZIA£ANIA////////
	cout << endl;
	for(int i = 0; i < szerokoscMacierzy_1; i++)
	{
		for(int j = 0; j < wysokoscMacierzy_1; j++)
		{
			cout << macierz_1[i][j] << " ";
		}	
		cout << endl;
	}
	cout << endl;
	for(int i = 0; i < szerokoscMacierzy_1; i++)
	{
		for(int j = 0; j < wysokoscMacierzy_1; j++)
		{
			cout << macierz_2[i][j] << " ";
		}	
		cout << endl;
	}
	//pêtla do..while aby uzytkownik mia³ wybór czy chce kontynuowaæ i wypróbowaæ inne dzia³ania//
	
	if(brakDanych == false)
	{
		do
		{
	
			//komunikaty dla uzytkownika z mozliwosciami wyboru//
			cout << "Wybierz jakie dzialanie chcialbys podjac:" << endl;
			cout << "1 - dodawanie macierzy" << endl;
			cout << "2 - odejmowanie macierzy" << endl;
			cout << "3 - mnozenie dwoch macierzy" << endl;
			cout << "4 - mnozenie macierzy przez liczbe" << endl << endl;
			
			//cin aby uzytkownik wpisa³ odpowiedni¹ liczbe//
			cout << "Wybor: ";
				
			//zabezpieczenie przed wpisywaniem liter i nie odpowiednich liczb//
			while(!(cin>>input) || (input != 1 && input != 2 && input != 3 && input != 4)) 
			{	 
				cout << endl;
				cin.clear(); 
				cin.sync(); 
			  
				cout << "Blad. Musisz wpisac odpowiedznia liczbe. Prosze sprobowac jeszcze raz" << endl;
				cout << "Wybor: ";		
			}
		
			cout << endl;
			
			//zaleznie od tego co wybierze u¿ytkownik, to dana zmienna zmieni sie na true//
			switch(input)
			{
				case 1: dodawanie = true; break;
				case 2: odejmowanie = true; break;
				case 3: mnozenie_dwoch_macierzy = true; break;
				case 4:	mnozenie_macierzy_przez_liczbe = true; break;
			}
			
			//dana instrukcja warunkowa zadzia³a zaleznie od tego co wybra³ u¿ytkownik// 
			if(dodawanie == true)
			{	
				cout << "To jest wynik dzialania: " << endl << endl;
				//wywo³adnie funkcji umieszczonej w pliku funkcje.cpp//
				DodawanieMacierzy(szerokoscMacierzy_1, wysokoscMacierzy_1, macierz_1, macierz_2, koncowaMacierz);
				dodawanie = false;
			}
			else if(odejmowanie == true)
			{
				cout << "To jest wynik dzialania: " << endl << endl;
				//wywo³adnie funkcji umieszczonej w pliku funkcje.cpp//
				OdejmowanieMacierzy(szerokoscMacierzy_1, wysokoscMacierzy_1, macierz_1, macierz_2, koncowaMacierz);
				odejmowanie = false;
			}
			else if(mnozenie_dwoch_macierzy == true)
			{
				cout << "To jest wynik dzialania: " << endl << endl;
				//wywo³adnie funkcji umieszczonej w pliku funkcje.cpp//
				MnozenieDwochMacierzy(szerokoscMacierzy_1, wysokoscMacierzy_1, szerokoscMacierzy_2, wysokoscMacierzy_2, macierz_1, macierz_2, koncowaMacierz);
				mnozenie_dwoch_macierzy = false;
			}
			else if(mnozenie_macierzy_przez_liczbe == true)
			{
				cout << "Wpisz liczbe przez ktora chcesz pomnozyc macierz: ";
				
				//zabezpieczenie przed wpisywaniem liter//
				while(!(cin>>multNum)) 
				{	 
					cout << endl;
					cin.clear(); 
					cin.sync(); 
				  
					cout << "Blad. Nie mozna wpisywac liter. Prosze sprobowac jeszcze raz" << endl;
					cout << "Wybor: ";		
				}
				
				cout << endl;
				cout << "To jest wynik dzialania: " << endl << endl;
				//wywo³adnie funkcji umieszczonej w pliku funkcje.cpp//
				MnozenieMacierzyLiczba(szerokoscMacierzy_1, wysokoscMacierzy_1, multNum, macierz_1, koncowaMacierz);
				mnozenie_macierzy_przez_liczbe = false;
			}
		
			///////////ZAPISYWANIE DANYCH///////////
		
			//zapytanie do uzytkownika czy chce zapisac wynik//
			cout << endl << "Czy chcesz zapisac wynik? (Poprzedni wynik zostanie nadpisany)" << endl << "1 - Tak" << endl << "2 = Nie" << endl << endl << "Wybor: ";
		
			//zabezpieczenie przed wpisywaniem liter i nie odpowiednich liczb//
			while(!(cin>>zapis_wyniku) || (zapis_wyniku != 1 && zapis_wyniku != 2)) 
			{	 
				cout << endl;
				cin.clear(); 
				cin.sync(); 
			  
				cout << "Blad. Musisz wpisac odpowiedznia liczbe. Prosze sprobowac jeszcze raz" << endl;
				cout << "Wybor: ";		
			}
		
			if(zapis_wyniku == 1)
			{
				fstream wynik;
				
				wynik.open("wynik.txt", ios::out);
				
				for(int i = 0; i < wysokoscMacierzy_1; i++)
				{
					for(int j = 0; j < szerokoscMacierzy_1; j++)
					{
						wynik << koncowaMacierz[j][i] << " ";
					}
					
					wynik << endl;
					
				}
				
				wynik.close();
				cout << "Wynik zostal zapisany" << endl;
			}
			else
			{
				cout << "Wynik nie zostal zapisany" << endl;
			}
		
		
		
		
			//Zapytanie do uzytkownika czy chce kontynuowac prace programu//
			cout << endl << "Chcesz sprobowac innego dzialania?" << endl << "1 - Tak" << endl << "2 = Nie" << endl << endl << "Wybor: ";
			
			//zabezpieczenie przed wpisywaniem liter i nie odpowiednich liczb//
			while(!(cin>>kolejne_dzialanie) || (kolejne_dzialanie != 1 && kolejne_dzialanie != 2)) 
			{	 
				cout << endl;
				cin.clear(); 
				cin.sync(); 
			  
				cout << "Blad. Musisz wpisac odpowiedznia liczbe. Prosze sprobowac jeszcze raz" << endl;
				cout << "Wybor: ";		
			}
			
			cout << endl;
			
			//warunek dla pêtli aby kontynuowaæ lub nie//
		} while(kolejne_dzialanie == 1);
	}
	else
	{
		cout << "Upewnij sie ze wszystkie dane sa ustawione w odpowiednim formacie w pliku" << endl;
		cout << "Musza byc one ustawione po spacji tak jak przy macierzach. Musza to byc takze macierze o maksymalnym rozmiare 10x10" << endl;
		cout << "Przyklad w jakim formacie trzeba wpisac dane:" << endl << endl;
		cout << "5           <- to jest rozmiar szerokosci pierwszej macierzy" << endl;
		cout << "4           <- to jest rozmiar wysokosci pierwszej macierzy" << endl;
		cout << "9 8 51 6" << endl;
		cout << "9 8 51 6" << endl;
		cout << "2 8 13 16" << endl;
		cout << "59 18 1 6" << endl;
		cout << "7 12 11 6" << endl << endl;
		
		cout << "4            <- to jest rozmiar szerokosci drugiej macierzy" << endl;
		cout << "4            <- to jest rozmiar wysokosci drugiej macierzy" << endl;
		cout << "10 0 5 9" << endl;
		cout << "2 8 20 6" << endl;
		cout << "6 8 0 5" << endl;
		cout << "19 8 31 8" << endl;	
	}
 
 
 	cout << endl << "Koniec programu";

	return 0;
}
