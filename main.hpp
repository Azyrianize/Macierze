#ifndef main_hpp
#define main_hpp

	#define MAX_N 10
	#define MAX_M 10

	int macierz_1[MAX_N][MAX_M];
	int macierz_2[MAX_N][MAX_M];
	int koncowaMacierz[MAX_N][MAX_M];
	
	int szerokoscMacierzy_1;
	int wysokoscMacierzy_1;
	int szerokoscMacierzy_2;
	int wysokoscMacierzy_2;
	
	
	int nrLinii = 1;
	int i = 0, j = 0;
	int counter_liczb = 0;
	int counter_lines = 1;
	int multNum;
	char znak;
	
	int input;
	
	bool macierz1_saved = false;
	bool macierz2_saved = false;
	
	bool dodawanie = false;
	bool odejmowanie  = false;
	bool mnozenie_dwoch_macierzy  = false;
	bool mnozenie_macierzy_przez_liczbe  = false;
	
	int kolejne_dzialanie;
	int zapis_wyniku;
	
	bool brakDanych = false;
	int liczba_sscanf;
	
#endif

