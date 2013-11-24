/*
@file main.cpp
@brief Hlavni soubor programu.
*
/*
@author Petr Macak
@version 0.1
*/
/*
@mainpage Petr Macak, MAC0345, cv. støeda 16:00
Aplikace "eShop a zbozi v nem" vypracovana jako semestralni projekt v predmetu Programovani I
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "head_funkce.h"

using namespace std;

/*
@brief Hlavni funkce programu, ktera vola vsechny ostatni funkce
@param argc Pocet parametru pri spusteni z prikazove radky
@param argv Seznam retezcu pri spusteni z prikazove radky
@return vraci 0 pri spravnem ukonceni programu
*/
int main(int argc, char * argv[]){
	int volba = 0, velikostPole = 0;
	vyrobek *poleVyrobku = NULL;
	string chyba;


	int vyber = 0;
	while (true){
		system("cls"); // vymazani konzole
		cout << "***************************************************************" << endl
			<< "*         Program pro praci s eShopem a jeho nabidkou         *" << endl
			<< "***************************************************************" << endl;

		cout << endl << "Menu:" << endl
			<< "1. Nacteni zaznamu" << endl
			<< "2. Vypis zbozi serazeneho dle ceny" << endl
			<< "3. Vypis zbozi v zadanem cenovem intervalu" << endl
			<< "4. Vypis zbozi, ktere je mozne objednat, do Vami zadane castky" << endl
			<< "5. Export aktualne nactenych zaznamu" << endl
			<< "6. Ukoncit program" << endl << endl;

	
		while (true){
			cout << "Zadejte volbu: ";
			cin >> volba;

			if (cin.fail()){
				cin.clear();
				cin >> chyba;
				cout << "*Zadna operace neodpovida Vasemu vstupu." << endl;
			}
			else { break; }
		}

		switch (volba){
		case 1: 
			poleVyrobku = nacteniVyrobku(poleVyrobku, velikostPole);
			break;  
		case 2:	{
			poleVyrobku = serazeniDleCeny(poleVyrobku, velikostPole);
			exportDoHtml(poleVyrobku, velikostPole);
			}
			break;

		case 3: {
			if (velikostPole == 0){
				system("cls");
				cout << "Seznam knih je prazdny." << endl;
				system("pause");
			}
			else{
				filtrInterval(poleVyrobku, velikostPole);
				}
			}
			break;
		case 4: 
			break;
		case 5:{
			if (velikostPole == 0){
				system("cls");
				cout << "Seznam knih je prazdny." << endl;
				system("pause");
			}
			else  exportDoHtml(poleVyrobku, velikostPole);
			}
			break;

		case 6: 
			//free(neco);
			return 0; 
			break;

		default: cout << "*Zadna operace neodpovida Vasemu vstupu." << endl;
		}
	}
	return 0;
}
