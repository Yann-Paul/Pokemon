#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*class Attack
{
public:
	string name;
	string typ;
	int strength;
	int precision;
	int APcost;

	Attack(string name, string typ, int strength, int precision, int APcost){};

private:
};*/

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
    attack attack1;
    attack attack2;

    //Konstruktor
    Pokemon(string name, string type1, string type2, int dexNum, int level, double health, double AP, double size, double weighth, int maxLevel, attack attack1, attack attack2){};

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

	/*Attack tackle("tackle", "normal", 40, 100, 35);
	Attack growl("growl", "normal", 45, 100, 40);*/


	// Erstelle die Pokemons
	Pokemon bisasam("Bisasam", "grass", "poison",001, 1, 100, 100, 0.7, 6.9, 10, tackle, growl);

	bisasam.attack1 = tackle;
	bisasam.attack2 = growl;


	// fuer spaeter
	Pokemon pokedex[1] = { bisasam };


    //Pokemon auswaehlen
    //cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << "bisasam" << endl;
     cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << pokedex << endl;  //fuer spaeter
    //cin >> input;



    return 0;
}


