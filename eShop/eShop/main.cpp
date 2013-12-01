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

int main(){
	int volba = 0, velikostPole = 0;
	vyrobek *poleVyrobku = NULL;
	string chyba;


	int vyber = 0;
	while (true){
		system("cls");
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
				cout << "Zadna operace neodpovida Vasemu vstupu." << endl;
				system("pause");
			}
			else { break; }
		}

		switch (volba){
		case 1: 
			if (poleVyrobku == NULL){
				poleVyrobku = nacteniVyrobku(poleVyrobku, velikostPole);
			}
			else{
				cout << "Vyrobky jsou jiz nacteny." << endl;
				system("pause");
			}
			break;  
		case 2:	
			poleVyrobku = serazeniDleCeny(poleVyrobku, velikostPole);
			exportDoHtml(poleVyrobku, velikostPole);
			break;

		case 3: {
			if (velikostPole == 0){
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else{
				filtrInterval(poleVyrobku, velikostPole);
				}
			}
			break;
		case 4: 
			if (velikostPole == 0){
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else{
				vypisDoCeny(poleVyrobku, velikostPole);
			}
			break;
		case 5:{
			if (velikostPole == 0){
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else  exportDoHtml(poleVyrobku, velikostPole);
			}
			break;

		case 6: 
			free(poleVyrobku);
			return 0; 
			break;

		default: 
			cout << "Zadna operace neodpovida Vasemu vstupu." << endl; 
			system("pause");
		}
	}
	return 0;
}
