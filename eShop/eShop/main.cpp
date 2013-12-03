/**
	\file main.cpp
	\brief Hlavni soubor programu.
	\author Petr Macak
	\version 1.2
	\mainpage Petr Macak, MAC0345, cv. streda 16:00
	Aplikace "eShop a zbozi v nem" vypracovana jako semestralni projekt v predmetu Programovani I (2013/2014)
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "head_funkce.h" /** \file <head_funkce.h>
							 \brief Hlavickovy soubor, ktery obsahuje deklarace vsech funkci pouzitych v hlavnim souboru aplikace main.cpp.
						*/

using namespace std;

/**
	\brief Hlavni funkce programu obsahujici jednoduche UI pro komunikaci s uzivatelem volajici dalsi funkce
	\return Vraci hodnotu 0
*/
int main()
{
	int volba = 0, velikostPole = 0;
	vyrobek *poleVyrobku = NULL;

	while (true)
	{
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

	
		while (true)
		{
			cout << "Zadejte volbu: ";
			cin >> volba;

			if (cin.fail())
			{
				cout << "Zadna operace neodpovida Vasemu vstupu." << endl;
				system("pause");
			}
			else 
			{ 
				break; 
			}
		}

		switch (volba)
		{
		case 1: 
				poleVyrobku = nacteniVyrobku(poleVyrobku, velikostPole);
			break;  
		case 2:	
			poleVyrobku = serazeniDleCeny(poleVyrobku, velikostPole);
			exportDoHtml(poleVyrobku, velikostPole);
			break;

		case 3: 
			if (velikostPole == 0)
			{
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else
			{
				poleVyrobku = filtrInterval(poleVyrobku, velikostPole);
				exportDoHtml(poleVyrobku, velikostPole);
			}
			break;
		case 4: 
			if (velikostPole == 0)
			{
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else
			{
				poleVyrobku = vypisDoCeny(poleVyrobku, velikostPole);
			}
			break;
		case 5:
			if (velikostPole == 0)
			{
				system("cls");
				cout << "Seznam vyrobku je prazdny, nactete nejprve zaznamy." << endl;
				system("pause");
			}
			else
			{ 
				exportDoHtml(poleVyrobku, velikostPole);
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
