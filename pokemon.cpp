#include <iostream>
#include <string>
#include <vector>

using namespace std;


int inventory[2] = {5,5}; // Erste Zahl = anzahl Manatränke, Zweite Zahl = anzahl Healthtränke

class Attack
{
public:

	void test(){
	     cout << "Attacke wurde erstellt"<<  endl;  // Test
	}

	string name;
	string typ; //types: grass, water, fire, electro, stone, wind, phsycho
	int strength;
	int precision;
	int manacost;
	//Attack();
	Attack(string name, string typ, int strength, int precision, int manacost){
		this->name = name;
		this->typ = typ;
		this->strength = strength;
		this->precision = precision;
		this->manacost = manacost;
	};
	Attack(){}
private:
};

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

	void test(){
	     cout << "Pokemon wurde erstellt"<<  endl;  // Test
	}

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
	// zur Einfachheit gibt es erst mal nur eine Sorte an Tränken die health oder mana direkt auf 100 setzt

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
    string type; //types: grass, water, fire, electro, stone, wind, phsycho
    int dexNum;
    int level;	// 30 ist erst mal das maximale Level. Dann haut das mit den evolutionen besser hin
    double health;
    double mana;
    double size;
    double weighth;
    int maxLevel;
    int nextevo; // dexNum der nächsten evolution. nextevo ist gleich wie eigene dexNum wenn es keine weitere Evolution gibt
    double xp;
    Attack attack1;
    Attack attack2;

    //Konstruktor
    Pokemon(string name, string type, int dexNum, int level, double health, double mana, double size, double weighth, int maxLevel, int nextevo, double xp, Attack attack1, Attack attack2){
    	this-> name = name;
    	this-> type = type;
    	this-> dexNum = dexNum;
    	this-> level = level;
    	this-> health = health;
    	this-> mana = mana;
    	this-> size = size;
    	this-> weighth = weighth;
    	this-> maxLevel = maxLevel;
    	this-> nextevo = nextevo;
    	this-> xp = xp;
    	this-> attack1 = attack1;
    	this-> attack2 = attack2;
    };



private:
};




int main()
{


	// Attacken (name, typ, strength, precision, manacost)
	Attack tackle("Tackle", "normal", 40, 100, 20);
	Attack growl("Growl", "normal", 45, 100, 20);
	Attack solarBeam("Solar Beam", "grass", 45, 100, 25);
	Attack vineWhip("Vine Whip", "grass", 45, 100, 10);
	Attack razorLeaf("Razor Leaf", "phsycho", 55, 100, 25);

	tackle.test();



	// Erstelle die Pokemons
	Pokemon bisasam("Bisasam", "grass", 001, 1, 100, 100, 0.7, 6.9, 10, 002, 0.0, tackle, growl);
	Pokemon bisaknosp("Bisaknosp", "grass", 002, 11, 100, 100, 1.0, 13.0, 20, 003, 0.0, solarBeam, vineWhip);
	Pokemon bisaflor("Bisaflor", "grass", 003, 21, 100, 100, 2.0, 100.0, 30, 003, 0.0, solarBeam, razorLeaf);

	bisasam.test();



	// fuer spaeter
	//Pokemon pokedex[3] = { bisasam, bisaknosp, bisaflor };


    //Pokemon auswaehlen
    // cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << pokedex <<endl;  // Test
	std::string s = std::to_string(bisasam.attack1.precision);
     std::cout << s << bisasam.type;  // Test
    //cin >> input;



    return 0;
}
