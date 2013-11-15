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
#include "head_funkce.h"

using namespace std;

/*
@brief Hlavni funkce programu, ktera vola vsechny ostatni funkce
@param argc Pocet parametru pri spusteni z prikazove radky
@param argv Seznam retezcu pri spusteni z prikazove radky
@return vraci 0 pri spravnem ukonceni programu
*/
int main(int argc, char * argv[]){
	int volba;
	string chyba;


	int vyber = 0;

	system("cls"); // vymazani konzole
	cout << "***************************************************************" << endl
		<< "*         Program pro praci s eShopem a jeho nabidkou         *" << endl
		<< "***************************************************************" << endl;

	cout << endl << "Menu:" << endl
		<< "1. Nacteni zaznamu" << endl
		<< "2. Vypis zbozi serazeneho dle ceny" << endl
		<< "3. Vypis zbozi v zadanem cenovem intervalu" << endl
		<< "4. Vypis zbozi, ktere je mozne objednat, do Vami zadane castky" << endl
		<< "5. Ukoncit program" << endl << endl;

	while (true){
		while (true){
			cout << "Zadej volbu: ";
			cin >> volba;

			if (cin.fail()){
				cin.clear();
				cin >> chyba;
				cout << "*Zadna operace neodpovida Vasemu vstupu." << endl;
			}
			else { break; }
		}

		switch (volba){
		case 1: {}
			break;

		case 2:	{}
			break;

		case 3: {}
			break;
		case 4: {}
			break;

		case 5: {//free(neco);
					return 0; }
			break;

		default: cout << "*Zadna operace neodpovida Vasemu vstupu." << endl;
		}
	}
	return 0;
}
