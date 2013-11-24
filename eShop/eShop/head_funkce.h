/*
@file head_funkce.h
@brief Hlavickovy soubor s deklaraci vsech funkci pouzitych v hlavnim souboru main.cpp aplikace
*/

using namespace std;

typedef struct vyrobek{
	int id;
	char nazev[40]; 
	char popis[128]; 
	int cena; 
	int sklad; 

}vyrobek;

/*
@brief popis fce
@param popis parametru1
@param  popis parametru2
*/

//void nazev(param1, int param2);

vyrobek *nacteniVyrobku(vyrobek *poleVyrobku, int &velikostPole);

int exportDoHtml(vyrobek *poleVyrobku, int velikostPole);