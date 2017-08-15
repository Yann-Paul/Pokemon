#include <iostream>
#include <string>
#include <vector>

using namespace std;


int inventory[2] = {5,5}; // Erste Zahl = anzahl Manatränke, Zweite Zahl = anzahl healthtränke

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

	void gainXP(double damage){	// damage muss angepasst werden an void attack
		xp = damage / level;
		if (xp >= 100){
			xp = xp-100;
			levelup();
		}
	};

	void usepotion(bool mahe){ // mahe = 1 -> mana; mahe = 0 -> health
		if (mahe){
			mana = 100;
			inventory[0] --;
		}
		else{
			health = 100;
			inventory[1] --;
		}
	}
	// zur einfachheit gibt es erst mal nur eine Sorte an Tränken die health oder mana direkt auf 100 setzt

	void levelup(){
		level ++;
		if (level > maxLevel){
			evolution();
		}
	}

	void evolution(){
		//verändert das Pokemon im Pokedex zum neuen Pokemon
		// muss geschrieben werden, wenn genug Pokemon existieren
	};

    string name;
    string type1;
    string type2;
    int dexNum;
    int level;
    double health;
    double mana;
    double size;
    double weighth;
    int maxLevel;
    double xp;
    attack attack1;
    attack attack2;

    //Konstruktor
    Pokemon(string name, string type1, string type2, int dexNum, int level, double health, double AP, double size, double weighth, int maxLevel, double xp, attack attack1, attack attack2){};

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
	Pokemon bisasam("Bisasam", "grass", "poison", 001, 1, 100, 100, 0.7, 6.9, 10, 0.0, tackle, growl);

	bisasam.attack1 = tackle;
	bisasam.attack2 = growl;


	// fuer spaeter
	Pokemon pokedex[1] = { bisasam };


    //Pokemon auswaehlen
     cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << pokedex << endl;  //
    //cin >> input;



    return 0;
}
