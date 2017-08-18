/*
 * Projekt.cpp
 *
 *  Created on: 18.08.2017
 *      Author: jacobstupka
 */
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


string name;  // Spielernamen
char input; // Eingabe im späteren Input
int auswahl;
bool schleife = true; //Fuer Schleife

// vector declaration fürs Inventory
int vv[2] = { 5,5 };
std::vector<int> v(&vv[0], &vv[0]+2);

int checktype(string type1, string type2){//liste mit typschwächen, wenn typen final
	return 1;//momentan alles sehr effektiv
}

class Attack
{
public:

	void test(){
	     cout << "Attacke wurde erstellt"<<  endl;  // Test
	}

	string name;
	string type; //types: grass, water, fire, electro, stone, wind, psycho
	int strength;
	int precision;
	int manacost;
	//Attack();
	Attack(string name, string type, int strength, int precision, int manacost){
		this->name = name;
		this->type = type;
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

	void gainXP(double damage){	// damage muss angepasst werden an void angriff
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
    double weight;
    double atk;
    double def;
    double init;
    int maxLevel;
    int nextevo; // dexNum der nächsten evolution. nextevo ist gleich wie eigene dexNum wenn es keine weitere Evolution gibt
    double xp;
    Attack attack1;
    Attack attack2;

    //Konstruktor
    Pokemon(string name, string type, int dexNum, int level, double health, double mana, double size, double weight, double atk, double def, double init, int maxLevel, int nextevo, double xp, Attack attack1, Attack attack2){
    	this-> name = name;
    	this-> type = type;
    	this-> dexNum = dexNum;
    	this-> level = level;
    	this-> health = health;
    	this-> mana = mana;
    	this-> size = size;
    	this-> weight = weight;
    	this-> atk = atk;
    	this-> def = def;
    	this-> init = init;
    	this-> maxLevel = maxLevel;
    	this-> nextevo = nextevo;
    	this-> xp = xp;
    	this-> attack1 = attack1;
    	this-> attack2 = attack2;
    };
    Pokemon(){};


	pair<double,string> angriff(Attack attk){
		double dmg;
		int r=rand() % 100+1;//check, ob Treffer
		if (r>attk.precision){
			dmg=0;//falls nicht kein Schaden
		}
		else {
			dmg=attk.strength*atk;//Schaden aus Angriff des Dieners und Stärke der Attacke
		}
		pair<double,string> tempdmg (dmg,attk.type);
		mana-=attk.manacost;
		return tempdmg;//übergibt pair aus Schadenswert und Typ
	};

	double verteidigen(pair<int,string> tempdmg){//übernimmt pair aus Schadenswert und Typ
		int effective=checktype(tempdmg.second,type);
		double dmg;
		switch(effective){//modifiziert nach Effektivitätsmultiplikator (auf 4/5 bzw 5/4)
		case -1: dmg=tempdmg.first*0.8/def; break;
		case 0: dmg=tempdmg.first/def; break;
		case 1: dmg=tempdmg.first*1.25/def; break;
		}
		health-=dmg;//zieht Schaden ab und setzt Health minimal auf null
		if(health<0){
			health=0;
		}
		return dmg;//gibt Schaden aus für xp-Berechnung
	};

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

int attackalgorithm(Pokemon pokpact, Pokemon pokeact){//entscheide, welche Attacke Gegner verwendet
	if(pokeact.mana<pokeact.attack1.manacost){//teste, ob zureichend Mana für Angriff
		if(pokeact.mana<pokeact.attack2.manacost){
			return 0;//falls Mana unzureichend für beide, nutze Verzweifler
		}
		else{
			return 2;//zu wenig Mana für 1-->Angriff 2
		}
	}
	if(pokeact.mana<pokeact.attack2.manacost){
		return 1;//zu wenig Mana für 2-->Angriff 1
	}
	else{//genug Mana für beide
		int r=rand()%100+1;
		int r1;
		int sus1=checktype(pokeact.attack1.type,pokpact.type);//prüfe auf Typanfälligkeiten
		int sus2=checktype(pokeact.attack2.type,pokpact.type);
		if(sus1>sus2){//falls anfälliger auf Angriff 1 als auf 2, nutze mit p=70% Angriff 1
			r1=70;
		}
		if(sus2>sus1){//70% Angriff 2
			r1=30;
		}
		else{//sonst gleich
			r1=50;
		}
		if(r>r1){
			return 2;
		}
		else{
			return 1;
		}
	}
}

bool combatroutine(Spieler spieler, Spieler enemy){
	int pact;
	int eact=1;
	char choice;//wähle Diener
	cin >> choice;
	switch(choice){
	case '1': pact=1; break;//player-active
	case '2': pact=2; break;
	case '3': pact=3; break;
	}
	do{//Matchroutine (3vs3) bis alle Diener eines Kontrahenten besiegt sind
		Pokemon pokpact;
		Pokemon pokeact;
		switch(pact){//temporäre Diener im Zwischenspeicher
		case 1: pokpact=spieler.pokemon1; break;
		case 2: pokpact=spieler.pokemon2; break;
		case 3: pokpact=spieler.pokemon3; break;
		}
		switch(eact){
		case 1: pokeact=enemy.pokemon1; break;
		case 2: pokeact=enemy.pokemon2; break;
		case 3: pokeact=enemy.pokemon3; break;
		}
		do{//einzelne Kampfroutine (1vs1) bis ein Kämpfer besiegt ist
			int enaction=1;
			char whichaction;
			cin >> whichaction;//frage Spieleraktion ab
			if(whichaction='ph'){
				spieler.usepotion(0, pokpact);
			}
			if(whichaction='pm'){
				spieler.usepotion(1, pokpact);
			}
			if(pokeact.health<30 & enemy.inventory[0]>0){//Gegner nutzt Tränke, falls nötig, und verbraucht dabei seine Aktion
				enemy.usepotion(0,pokeact);
				enaction=0;
			}
			if(enaction=1 & pokeact.mana<pokeact.attack1.manacost & pokeact.mana<pokeact.attack2.manacost & enemy.inventory[1]>0){
				enemy.usepotion(1,pokeact);
				enaction=0;
			}
			else{
				if(pokeact.init>pokpact.init){
					if(enaction=1){
						int attackswitch=attackalgorithm(pokpact,pokeact);
						switch(attackswitch){
						case 0
						}
					}
				}
			}
		}while(pokpact.health>0 & pokeact.health>0);//bis ein Kämpfer besiegt
		switch(pact){//temporäre Daten werden permanent
		case 1: spieler.pokemon1=pokpact; break;
		case 2: spieler.pokemon2=pokpact; break;
		case 3: spieler.pokemon3=pokpact; break;
		}
		switch(eact){
		case 1: enemy.pokemon1=pokeact; break;
		case 2: enemy.pokemon2=pokeact; break;
		case 3: enemy.pokemon3=pokeact; break;
		}
		if(pokpact.health>0){//nächster Diener wird eingesetzt
			eact+=1;
		}
		else{//neuer Diener wird ausgewählt
			cin >> choice;
			switch(choice){
			case '1': pact=1; break;
			case '2': pact=2; break;
			case '3': pact=3; break;
			}
		}
	}while((enemy.pokemon1.health+enemy.pokemon2.health+enemy.pokemon3.health>0) & (spieler.pokemon1.health+spieler.pokemon2.health+spieler.pokemon3.health>0));//bis alle Kämpfer besiegt
	if(spieler.pokemon1.health+spieler.pokemon2.health+spieler.pokemon3.health>0){//falls Spielerdiener leben
		return 1;//Sieg des Spielers
	}
	else{
		return 0;//Sieg des Gegners
	}
}



int main()
{
	// Attacken (name, typ, strength, precision, manacost)
	Attack tackle("Tackle", "normal", 40, 100, 20);
	Attack growl("Growl", "normal", 45, 100, 20);
	Attack solarBeam("Solar Beam", "grass", 45, 100, 25);
	Attack vineWhip("Vine Whip", "grass", 45, 100, 10);
	Attack razorLeaf("Razor Leaf", "psycho", 55, 100, 25);

	tackle.test();



	// Erstelle die Pokemons
	Pokemon none("None", "None", 0, 0, 0, 0, 0.0, 0.0, 0, 0, 0, 0, 0, 0.0, tackle, tackle);
	Pokemon bisasam("Bisasam", "grass", 001, 1, 100, 100, 0.7, 6.9, 5, 5, 5, 10, 002, 0.0, tackle, growl);
	Pokemon bisaknosp("Bisaknosp", "grass", 002, 11, 100, 100, 1.0, 13.0, 15, 15, 15, 20, 003, 0.0, solarBeam, vineWhip);
	Pokemon bisaflor("Bisaflor", "grass", 003, 21, 100, 100, 2.0, 100.0, 30, 30, 30, 30, 003, 0.0, solarBeam, razorLeaf);

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



