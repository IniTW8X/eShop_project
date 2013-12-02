/**
	\file head_funkce.h
	\brief Hlavickovy soubor, ktery obsahuje deklarace vsech funkci pouzitych v hlavnim souboru aplikace main.cpp.
*/

using namespace std;

/**
	\brief Definovani struktury pro praci s .csv souborem obsahujici ID, Nazev, Popis, Cenu a Aktualni pocet kusu na sklade.
	Pocet znaku nazvu a popisu je omezen.
*/
typedef struct
{
	int id;
	char nazev[40]; 
	char popis[128]; 
	int cena; 
	int sklad; 

}vyrobek;

/**
	\brief Funkce pro otevreni .csv souboru v rezimu cteni pro import dat do datove struktury
	\param poleVyrobku udava pole struktur, ktere obsahuji zaznamy o vyrobcich (v tomto pripade = NULL)
	\param velikostPole udava velikost pole struktur, tzn. kolik zaznamu obsahuje dane pole
	\return Vraci ukazatel na nactene pole struktur, pripadne vraci prazdne pole struktur, pokud nastala chyba pri nacitani
*/
vyrobek *nacteniVyrobku(vyrobek *poleVyrobku, int &velikostPole);

/**
	\brief Funkce pro export pole struktur do souboru .html ve forme tabulky
	\param poleVyrobku udava pole struktur, ktere obsahuji zaznamy o vyrobcich
	\param velikostPole udava velikost pole struktur, tzn. kolik zaznamu obsahuje dane pole
	\return Vraci hodnotu 0 pri spravne vykonanem exportu, pripadne 1 pro chybu pri exportu
*/
int exportDoHtml(vyrobek *poleVyrobku, int velikostPole);

/**
	\brief Funkce pro serazeni pole struktur dle ceny
	\param poleVyrobku udava pole struktur, ktere obsahuji zaznamy o vyrobcich
	\param  velikostPole udava velikost pole struktur, tzn. kolik zaznamu obsahuje dane pole
	\return V pripade chyby vraci puvodni pole struktur, v pripade uspechu vraci serazene pole struktur
*/
vyrobek *serazeniDleCeny(vyrobek *poleVyrobku, int velikostPole);

/**
\brief Funkce pro filtraci pole struktur dle uzivatelem zadaneho intervalu
\param poleVyrobku udava pole struktur, ktere obsahuji zaznamy o vyrobcich
\param  velikostPole udava velikost pole struktur, tzn. kolik zaznamu obsahuje dane pole
\return Vraci ukazatel na filtrovane pole struktur, v pripade chyby vraci puvodni pole struktur
*/
vyrobek *filtrInterval(vyrobek *poleVyrobku, int &velikostPole);

/**
\brief Funkce pro vypis vsech polozek do uzivatelem zadane ceny, serazene dle polozek na skladu sestupne
\param poleVyrobku udava pole struktur, ktere obsahuji zaznamy o vyrobcich
\param  velikostPole udava velikost pole struktur, tzn. kolik zaznamu obsahuje dane pole
\return Vraci ukazatel na vyfiltrovane a serazene pole struktur
*/
vyrobek *vypisDoCeny(vyrobek *poleVyrobku, int &velikostPole);