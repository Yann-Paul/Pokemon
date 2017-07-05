/*
 * PseudoPok.cpp
 *
 *  Created on: 05.07.2017
 *      Author: jacobstupka
 */

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
    int dexNum;
    int level;
    double xp;
    int atk;
    int def;
    int init;
    double health;
    double AP;
    int maxLevel;
    attack attack1;
    attack attack2;


    //Konstruktor
    Pokemon(string name, string type1, int dexNum, int level, double xp, int atk, int def, int init, double health, double AP, int maxLevel, attack attack1, attack attack2){};

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
	growl.name = "growl";
	tackle.typ = "normal";
	tackle.strength = 45;
	tackle.precision = 100;
	tackle.APcost = 40;

	/*Attack tackle("tackle", "normal", 40, 100, 35);
	Attack growl("growl", "normal", 45, 100, 40);*/


	// Erstelle die Pokemons
	Pokemon bisasam("Bisasam", "grass",001, 1, 0, 10, 10, 10, 100, 100, 10, tackle, growl);

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




