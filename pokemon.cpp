#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct
{
	string name;
	string typ;
	int strength;
	int precision;
	int APcost;
} attack;

class Pokemon
{
public:

	// fuer spaeter
	/*void usePotion();
	void attack();
	void defend();
	*/

    string name;
    string type1;
    string type2;
    int dexNum;
    int level;
    double health;
    double AP;
    double size;
    double weighth;
    int maxLevel;

    //Konstruktor
    Pokemon(string name, string type1, string type2, int dexNum, int level, double health, double AP, double size, double weighth, int maxLevel){};

private:

};


int main()
{
	// Erstelle die Attacken
	attack tackle;
	tackle.name = "tackle";
	tackle.typ = "normal";
	tackle.strength = 40;
	tackle.precision = 100;
	tackle.APcost = 35;

	attack growl;
	tackle.name = "growl";
	tackle.typ = "normal";
	tackle.strength = 45;
	tackle.precision = 100;
	tackle.APcost = 40;


	// Erstelle die Pokemons
	//Pokemon bisasam(001,"Bisasam", "grass", "poison", 1, 100, 100, 0.7, 6.9, 10, tackle, growl);   //mit Attacken
	Pokemon bisasam("Bisasam", "grass", "poison",001, 1, 100, 100, 0.7, 6.9, 10);

	// fuer spaeter
	//pokedex[1] = { bisasam };
	//Pokemon pokedex[1] = { bisasam };


    //Pokemon auswaehlen
    cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << "bisasam" << endl;
    //    cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << pokedex << endl;  fuer spaeter
    //cin >> input;



    return 0;
}


