/**
	\file funkce.cpp
	\brief Soubor s definici vsech funkci pouzitych v programu volanych hlavnim souborem aplikace main.cpp.
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

vyrobek  *nacteniVyrobku(vyrobek *poleVyrobku, int &velikostPole)
{
	string kopStr;
	string nazevSouboru;
	string cesta = "../vstupnidata/";
	string pripona = ".csv";
	int cisloZaznamu = 0;

	poleVyrobku = NULL;
	velikostPole = 0;

	system("cls");
	cout << "Zadejte prosim nazev souboru, ktery chcete nacist (bez pripony)" << endl;
	cin >> nazevSouboru;
	nazevSouboru = cesta + nazevSouboru + pripona;

	ifstream vstup;
	vstup.open((const char *)nazevSouboru.c_str());

	if (!vstup.is_open())
	{
		cout << "CHYBA - soubor se neotevrel nebo nebyl nalezen." << endl;
		system("pause");
		poleVyrobku = NULL;
		return poleVyrobku;
	}
	/**
		\brief Dokud nedojde na konec .csv souboru, veme radek, jehoz polozky jsou oddeleny strednikem (ten tedy nepribira).
		Zprvu alokuje pamet pro prvni radek a pomoci atoi() a strcpy() vlozi data do pole struktur, pote vse opakuje s dalsim radkem, jen vzdy realokuje (zvysi) pamet pro dalsi radek.
	*/
	while (!vstup.eof())
	{
		getline(vstup, kopStr, ';');

		if (kopStr.length() == 0)
		{
			break;
		}

		if (velikostPole == 0)
		{
			poleVyrobku = (vyrobek*)malloc(sizeof(vyrobek)*(++velikostPole));
		}
		else
		{
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
		cout << "Soubor neobsahuje zadna data." << endl;
		system("pause");
		vstup.close();
		return poleVyrobku;
	}

	vstup.close();
	cout << "Nacteni ze souboru probehlo uspesne." << endl;
	system("pause");
	return poleVyrobku;
}

int exportDoHtml(vyrobek *poleVyrobku, int velikostPole)
{
	string nazevSouboru;
	string cesta = "../vystupnidata/";
	string pripona = ".html";

	system("cls");
	cout << "Zadejte prosim nazev souboru pro export do HTML (bez pripony):" << endl;
	cin >> nazevSouboru;
	nazevSouboru = cesta + nazevSouboru + pripona;

	ofstream vystup;
	vystup.open((const char *)nazevSouboru.c_str());

	if (!vystup.is_open()){
		cout << "CHYBA - soubor se nebylo mozne nalezt nebo je poskozen." << endl;
		system("pause");
		return 1;
	}

	vystup << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">";
	vystup << endl << "<html>" << endl << "<head>";
	vystup << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">";
	vystup << endl << "<title>eShop</title>";
	vystup << endl << "</head>" << endl << "<body bgcolor=\"#FFFFFF\">";
	vystup << endl << "<h1 align=\"center\"><b>Aktualni nabidka naseho eShopu</b></h1>";
	vystup << endl << "<table width=\"850\" border=\"3\" align=\"center\">";
	vystup << endl << "<tr><th width=\"50\"><font size=\"4\">ID</font></th>";
	vystup << "<th width=\"150\"><font size=\"4\">Nazev</font></th>";
	vystup << "<th width = \"200\"><font size=\"4\">Popis vyrobku</font></th>";
	vystup << "<th width = \"99\"><font size=\"4\">Cena</font></th>";
	vystup << "<th width=\"99\"><font size=\"4\">Pocet ks na sklade</font></th></tr>";

	for (int i = 0; i < velikostPole; i++)
	{
		vystup << endl << "<tr><td align=\"center\">" << poleVyrobku[i].id << "</td>" 
			<< "<td align=\"center\">" << poleVyrobku[i].nazev << "</td>" 
			<< "<td align=\"center\">" << poleVyrobku[i].popis << "</td>" 
			<< "<td align=\"center\">" << poleVyrobku[i].cena << "</td>" 
			<< "<td align=\"center\">" << poleVyrobku[i].sklad << "</td></tr>" << endl;
	}

	vystup << endl << "</table>" << endl << "</body>" << endl << "</html>";
	cout << "Export do HTML probehlo uspesne." << endl;
	system("pause");
	vystup.close();
	return 0;
}

vyrobek *serazeniDleCeny(vyrobek *poleVyrobku, int velikostPole)
{
	string serazeni;

	system("cls");
	cout << "Serazeni zaznamu dle ceny" << endl 
		 << "*************************" << endl;
	cout << "Seradit zaznamy vzestupne ci sestupne?[vzestupne/sestupne]:" << endl;

	cin >> serazeni;
	if (cin.fail())
	{
		cout << "CHYBA - spatne zvolene serazeni." << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}

	/**
		\brief Serazeni vyrobku dle ceny "Bubblesortem" bud vzestupne, ci sestupne.
	*/
	if (serazeni == "vzestupne")
	{
		for (int i = 0; i < velikostPole - 1; i++)
		{
			for (int j = 0; j < velikostPole - 1; j++)
			{
				if (poleVyrobku[j].cena > poleVyrobku[j + 1].cena)
				{
					vyrobek pom = poleVyrobku[j];
					poleVyrobku[j] = poleVyrobku[j + 1];
					poleVyrobku[j + 1] = pom;
				}
			}
		}
	}
	else if (serazeni == "sestupne")
	{
		for (int i = 0; i < velikostPole - 1; i++)
		{
			for (int j = 0; j < velikostPole - 1; j++)
			{
				if (poleVyrobku[j].cena < poleVyrobku[j + 1].cena)
				{
					vyrobek pom = poleVyrobku[j];
					poleVyrobku[j] = poleVyrobku[j + 1];
					poleVyrobku[j + 1] = pom;
				}
			}
		}
	}
	else
	{
		cout << "CHYBA - spatne zvolene serazeni." << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}
	return poleVyrobku;
}

vyrobek *filtrInterval(vyrobek *poleVyrobku, int &velikostPole)
{
	int dolniMez;
	int horniMez;
	int novaVelikostPole = 0;
	vyrobek *novePoleVyrobku = NULL;

	system("cls");
	cout << "Zobrazeni vyrobku ze zadaneho intervalu" << endl
		<< "***************************************" << endl;
	cout << "Zadej dolni mez intervalu:" << endl;
	cin >> dolniMez;
	if (cin.fail() || dolniMez < 0)
	{
		cout << "Dolni mez byla spatne zadana" << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}

	cout << "Zadej horni mez intervalu:" << endl;
	cin >> horniMez;
	if (cin.fail() || horniMez < 0)
	{
		cout << "Horni mez byla spatne zadana" << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}

	if (dolniMez > horniMez)
	{
		cout << "Dolni mez nemuze byt vetsi nez horni mez!" << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}

	/**
		\brief Pokud je cena vyrobku nad dolni mzi a zaroven pod horni mzi, zprvu alokuj pamet pro prvni vyrobek a prirad vyrobek do nove pole struktur.
		Pote uz jen realokuj pro kazdy radek .
	*/
	for (int i = 0; i < velikostPole; i++)
	{
		if (poleVyrobku[i].cena >= dolniMez && poleVyrobku[i].cena <= horniMez)
		{
			if (novaVelikostPole == 0)
			{
				novePoleVyrobku = (vyrobek*)malloc(sizeof(vyrobek)*(++novaVelikostPole));
			}
			else
			{
				novePoleVyrobku = (vyrobek*)realloc(novePoleVyrobku, sizeof(vyrobek)*(++novaVelikostPole));
			}
			novePoleVyrobku[novaVelikostPole - 1] = poleVyrobku[i];
		}
	}

	if (novaVelikostPole == 0)
	{
		cout << "Nebyl nalezen zadny zaznam v tomto intervalu roku." << endl;
		free(novePoleVyrobku);
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}
	else
	{
		velikostPole = novaVelikostPole;
		free(poleVyrobku);
		return novePoleVyrobku;
	}
}

vyrobek *vypisDoCeny(vyrobek *poleVyrobku, int &velikostPole)
{
	int horniMez;
	int novaVelikostPole = 0;
	vyrobek *novePoleVyrobku = NULL;

	system("cls");
	cout << "Zobrazeni vsech produktu do Vami zadane castky" << endl
		<< "**********************************************" << endl;
	cout << "Zadejte Vasi maximalni castku nakupu:" << endl;

	cin >> horniMez;
	if (cin.fail())
	{
		cout << "Horni mez byla spatne zadana" << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}
	/**
		\brief Pokud je cena vyrobku pod horni mzi a zaroven se jeho pocet kusu na sklade nerovna nule, tak zprvu alokuj pamet pro jednu polozku a prirad ji do noveho pole struktur.
		Pote uz jen realokuj pamet pro pripadne dalsi radky filtru.
	*/
	for (int i = 0; i < velikostPole; i++)
	{
		if (poleVyrobku[i].cena <= horniMez && poleVyrobku[i].sklad != 0)
		{
			if (novaVelikostPole == 0)
			{
				novePoleVyrobku = (vyrobek*)malloc(sizeof(vyrobek)*(++novaVelikostPole));
			}
			else
			{
				novePoleVyrobku = (vyrobek*)realloc(novePoleVyrobku, sizeof(vyrobek)*(++novaVelikostPole));
			}
			novePoleVyrobku[novaVelikostPole - 1] = poleVyrobku[i];
		}
	}

	if (novaVelikostPole == 0)
	{
		cout << "Nebyl nalezen zadny vyrobek do Vami zadane castky." << endl;
		system("pause");
		poleVyrobku = NULL;
		velikostPole = 0;
		return poleVyrobku;
	}
	else
	{
		/**
			\brief Serazeni noveho pole struktur dle poctu kusu na sklade sestupne.
		*/
		for (int i = 0; i < novaVelikostPole - 1; i++){
			for (int j = 0; j < novaVelikostPole - 1; j++){
				if (novePoleVyrobku[j].sklad < novePoleVyrobku[j + 1].sklad){
					vyrobek pom = novePoleVyrobku[j];
					novePoleVyrobku[j] = novePoleVyrobku[j + 1];
					novePoleVyrobku[j + 1] = pom;
				}
			}
		}
		free(poleVyrobku);
		exportDoHtml(novePoleVyrobku, novaVelikostPole);
		velikostPole = novaVelikostPole;
		return novePoleVyrobku;
	}
}