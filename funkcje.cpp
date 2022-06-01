#include "funkcje.hpp"
#include <iostream>

using namespace std;

//w argumentach przekazywana jest szerokosc, wysokosc macierzy oraz tablice//
void DodawanieMacierzy(int szerokosc, int wysokosc, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M])
{
	for(int i = 0; i < wysokosc; i++)
	{
		for(int j = 0; j < szerokosc; j++)
		{
			koncowaMacierz[i][j] = macierz1[i][j] + macierz2[i][j];				
			cout << koncowaMacierz[i][j] << "  ";	
		}	
		
		cout << endl;
			
	}
}

//w argumentach przekazywana jest szerokosc, wysokosc macierzy oraz tablice//
void OdejmowanieMacierzy(int szerokosc, int wysokosc, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M])
{
	for(int i = 0; i < wysokosc; i++)
	{
		for(int j = 0; j < szerokosc; j++)
		{
			koncowaMacierz[i][j] = macierz1[i][j] - macierz2[i][j];			
			cout << koncowaMacierz[i][j] << "  ";	
		}	
		
		cout << endl;
			
	}
}

//w argumentach przekazywana jest szerokosc, wysokosc obydwu macierzy oraz tablice//
void MnozenieDwochMacierzy(int szerokosc_M1, int wysokosc_M1, int szerokosc_M2, int wysokosc_M2, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M])
{
	int temp = 0;
	int wynik_mnozenia = 0;
			
	for(int i = 0; i < wysokosc_M1; i++)
	{	
		for(int j = 0; j < szerokosc_M2; j++)
		{
			for(int k = 0; k < szerokosc_M1; k++)
			{
				temp = macierz1[i][k] * macierz2[k][j];
				wynik_mnozenia += temp;			
			}
			
			koncowaMacierz[i][j] = wynik_mnozenia;				
			cout << koncowaMacierz[i][j] << "  ";			
			wynik_mnozenia = 0;
				
		}
		
		cout << endl;
				
	}	
}

//w argumentach przekazywana jest szerokosc, wysokosc macierzy oraz tablice//
void MnozenieMacierzyLiczba(int szerokosc, int wysokosc, int liczba, int macierz1[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M])
{
	for(int i = 0; i < wysokosc; i++)
	{
		for(int j = 0; j < szerokosc; j++)
		{
			koncowaMacierz[i][j] = macierz1[i][j] * liczba;	
			cout << koncowaMacierz[i][j] << "  ";	
		}	
		
		cout << endl;
			
	}
}
