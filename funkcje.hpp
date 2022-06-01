#ifndef funkcje_hpp
#define funkcje_hpp

	#define MAX_N 10
	#define MAX_M 10

	void DodawanieMacierzy(int szerokosc, int wysokosc, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M]);
	void OdejmowanieMacierzy(int szerokosc, int wysokosc, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M]);
	void MnozenieDwochMacierzy(int szerokosc_M1, int wysokosc_M1, int szerokosc_M2, int wysokosc_M2, int macierz1[MAX_N][MAX_M], int macierz2[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M]);
	void MnozenieMacierzyLiczba(int szerokosc, int wysokosc, int liczba, int macierz1[MAX_N][MAX_M], int koncowaMacierz[MAX_N][MAX_M]);

#endif

