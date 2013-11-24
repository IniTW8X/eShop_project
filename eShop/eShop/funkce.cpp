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
	cout << "Zadejte prosim nazev souboru, ktery chcete nacist (bez pripony)" << endl;
	cin >> nazevSouboru;
	nazevSouboru = cesta + nazevSouboru + pripona;
	ifstream vstup;
	vstup.open((const char *)nazevSouboru.c_str());

	if (!vstup.is_open()){
		cout << "CHYBA - soubor se neotevøel." << endl;
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
		poleVyrobku[cisloZaznamu].cena = atoi(kopStr.c_str());
		getline(vstup, kopStr, '\n');
		poleVyrobku[cisloZaznamu].sklad = atoi(kopStr.c_str());

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

int exportDoHtml(vyrobek *poleVyrobku, int velikostPole){
	string nazevSouboru;
	string cesta = "/Users/Petr/Desktop/";
	string pripona = ".html";
	int i = 0;

	system("cls");
	cout << "Zadej nazev souboru pro export do HTML (bez pripony):" << endl;
	cin >> nazevSouboru;
	nazevSouboru = cesta + nazevSouboru + pripona;

	ofstream vystup;
	vystup.open((const char *)nazevSouboru.c_str());

	if (!vystup.is_open()){
		cout << "CHYBA - soubor se neotevrel." << endl;
		return 1;
	}

	vystup << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">";
	vystup << endl << "<html>" << endl << "<head>";
	vystup << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">";
	vystup << endl << "<title>eShop</title>";
	vystup << endl << "</head>" << endl << "<body bgcolor=\"#FFFFFF\">";
	vystup << endl << "<h1 align=\"center\"><b>Aktualni nabidka naseho eShopu</b></h1>";
	vystup << endl << "<table width=\"650\" border=\"2\" align=\"center\">";
	vystup << endl << "<tr><th width=\"99\"><font size=\"4\">ID</font></th><th width=\"99\"><font size=\"4\">Nazev</font></th><th width=\"149\"><font size=\"4\">Popis vyrobku</font></th><th width=\"99\"><font size=\"4\">Cena</font></th><th width=\"99\"><font size=\"4\">Pocet ks na sklade</font></th></tr>";

	for (int i = 0; i < velikostPole; i++){
		vystup << endl << "<tr><td align=\"center\">" << poleVyrobku[i].id << "</td>" << "</td >" << "<td align=\"center\">" << poleVyrobku[i].nazev << "</td>" << "<td align=\"center\">" << poleVyrobku[i].popis << "</td>" << "<td align=\"center\">" << poleVyrobku[i].cena << "</td>" << "<td align=\"center\">" << poleVyrobku[i].sklad << "</td></tr>" << endl;
	}

	vystup << endl << "</table>";
	vystup << endl << "</body>";
	vystup << endl << "</html>";
	cout << "Export do HTML probehlo uspesne." << endl;
	system("pause");
	vystup.close();
	return 0;
}

