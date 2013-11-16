/*
@file funkce.cpp
@brief Soubor s definici vsech funkci pouzivanych v programu.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "head_funkce.h"

using namespace std;

vyrobek  *nacteniVyrobku(vyrobek *poleVyrobku, int &velikostPole){
	string kopStr;
	string nazevSouboru;
	string cesta = "/Users/Petr/Desktop/";
	string pripona = ".csv";
	int cisloZaznamu = 0;

	system("cls");
	cout << "Zadejte prosim nazev souboru, ktery chcete nacist (vcetne pripony) " << endl;
	cin >> nazevSouboru;
	nazevSouboru = cesta + nazevSouboru + pripona;
	ifstream vstup;
	vstup.open((const char *)nazevSouboru.c_str());

	if (!vstup.is_open()){
		cout << "Chyba pri otevreni souboru." << endl;
		poleVyrobku = NULL;
		return poleVyrobku;
	}

	if (poleVyrobku != NULL){
		free(poleVyrobku);
		poleVyrobku = NULL;
		velikostPole = 0;
	}

	while (!vstup.eof()){
		getline(vstup, kopStr, ';');

		if (kopStr.length() == 0)
			break;

		if (velikostPole == 0){
			poleVyrobku = (vyrobek*)malloc(sizeof(vyrobek)*(++velikostPole));
		}
		else{
			poleVyrobku = (vyrobek*)realloc(poleVyrobku, sizeof(vyrobek)*(++velikostPole));
		}

		poleVyrobku[cisloZaznamu].id = atoi(kopStr.c_str());
		getline(vstup, kopStr, ';');
		strcpy(poleVyrobku[cisloZaznamu].nazev, kopStr.c_str());
		getline(vstup, kopStr, ';');
		strcpy(poleVyrobku[cisloZaznamu].popis, kopStr.c_str());
		getline(vstup, kopStr, ';');
		poleVyrobku[cisloZaznamu].id = atoi(kopStr.c_str());
		getline(vstup, kopStr, '\n');
		poleVyrobku[cisloZaznamu].id = atoi(kopStr.c_str());

		kopStr = "";
		cisloZaznamu++;
	}

	if (velikostPole == 0)
	{
		cout << "Soubor je prazdny." << endl;
		vstup.close();
		return poleVyrobku;
	}
	vstup.close();
	cout << "Nacteni ze souboru probehlo uspesne." << endl;
	system("pause");
	return poleVyrobku;
}
