#include <iostream>
#include <string>
#include <vector>

using namespace std;


string name;  // Spielernamen
char input; // Eingabe im späteren Input
int auswahl;
bool schleife = true; //Fuer Schleife

// vector declaration fürs Inventory
int vv[2] = { 5,5 };
std::vector<int> v(&vv[0], &vv[0]+2);

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
    Pokemon(){};
private:
};

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
	Pokemon none("None", "None", 0, 0, 0, 0, 0.0, 0.0, 0, 0, 0.0, tackle, tackle);
	Pokemon bisasam("Bisasam", "grass", 001, 1, 100, 100, 0.7, 6.9, 10, 002, 0.0, tackle, growl);
	Pokemon bisaknosp("Bisaknosp", "grass", 002, 11, 100, 100, 1.0, 13.0, 20, 003, 0.0, solarBeam, vineWhip);
	Pokemon bisaflor("Bisaflor", "grass", 003, 21, 100, 100, 2.0, 100.0, 30, 003, 0.0, solarBeam, razorLeaf);

	bisasam.test();



	// fuer spaeter
	Pokemon pokedex[3] = { bisasam, bisaknosp, bisaflor };


    //Pokemon auswaehlen
    cout << "Hallo! Um das Spiel beginnen zu können brauchst du einen Namen. Bitte wähle deinen Namen aus. " <<endl; // Test
    cin >> name;
    Spieler spieler(name, none, none, none);
    cout << "Hallo " << name <<"! Herzlich Willkommen in der Pokemonarena. Als nächstes wähle bitte dein Pokemon aus."<<endl;
    cout << "Dafür drücke eine der folgenden Zahlen."<<endl;
    cout << "1 = Bisasam        2 = Bisaknosp        3 = Bisaflor"<<endl;
    cin >> input;

	while (schleife) {
		switch (input) {
		case '1':
			auswahl = 1;
			schleife = false;
			break;
		case '2':
			auswahl = 2;
			schleife = false;
			break;
		case '3':
			auswahl = 3;
			schleife = false;
			break;
		default:
			cout << "Bitte gib nur eine der unten stehenden Zahlen an" << endl;
			cout << "1 = Bisasam        2 = Bisaknosp        3 = Bisaflor"
					<< endl;
			cin >> input;
			break;
		}
	}

	Pokemon auswahlPokemon = pokedex[(auswahl-1)];
    cout << "Herzlichen Glückwunsch. Du hast "<< auswahlPokemon.name <<auswahl<<" ausgewählt. Das ist eine gute Wahl"<<endl;
    spieler.pokemon1 = auswahlPokemon;

    return 0;
}
