#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.cpp"
using namespace std;

// vector declaration fürs Inventory
int vv[2] = { 5,5 };
std::vector<int> v(&vv[0], &vv[0]+2);

class Spieler
{
public:
	string name;
	vector<int> inventory; // = {5,5}; // Erste Zahl = anzahl Manatränke, Zweite Zahl = anzahl Healthtränke;
	Pokemon pokemon1;
	Pokemon pokemon2;
	Pokemon pokemon3;
	Spieler(string name, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3){
		this-> name = name;
		this-> inventory = v;
		this-> pokemon1 = pokemon1;
		this-> pokemon2 = pokemon2;
		this-> pokemon3 = pokemon3;
	};

	void usepotion(bool mahe, Pokemon pokemon){ // mahe = 1 -> mana; mahe = 0 -> health
		if (mahe){
			pokemon.mana = 100;
			inventory[0] --;
		}
		else{
			pokemon.health = 100;
			inventory[1] --;
		}
	}
	// zur Einfachheit gibt es erst mal nur eine Sorte an Tränken die health oder mana direkt auf 100 setzt
};
