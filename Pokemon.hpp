#include <iostream>
#include <string>
#include <tuple>
#include "Attack.hpp"
using namespace std;


int checktype(string type1, string type2){//liste mit typschwaechen, wenn typen final
	int typ1;
	int typ2;
	if(type1=="grass"){
		typ1=0;
	}
	if(type1=="water"){
		typ1=1;
	}
	if(type1=="fire"){
		typ1=2;
	}
	if(type1=="electro"){
		typ1=3;
	}
	if(type1=="stone"){
		typ1=4;
	}
	if(type1=="wind"){
		typ1=5;
	}
	if(type2=="grass"){
			typ2=0;
	}
	if(type2=="water"){
			typ2=1;
	}
	if(type2=="fire"){
			typ2=2;
	}
	if(type2=="electro"){
			typ2=3;
	}
	if(type2=="stone"){
			typ2=4;
	}
	if(type2=="wind"){
			typ2=5;
	}
	switch(typ1){
	case 0: switch(typ2){
	case 1: return 1;
	case 2: return -1;
	case 4: return 1;
	case 5: return -1;
	}
	case 1: switch(typ2){
	case 0: return -1;
	case 2: return 1;
	case 4: return 1;
	}
	case 2: switch(typ2){
	case 0: return 1;
	case 1: return -1;
	case 2: return -1;
	case 4: return -1;
	}
	case 3: switch(typ2){
	case 1: return 1;
	case 4: return -1;
	case 5: return 1;
	}
	case 4: switch(typ2){
	case 2: return 1;
	case 3: return 1;
	case 5: return -1;
	}
	case 5: switch(typ2){
	case 0: return 1;
	case 4: return -1;
	}
	}
	return 0;//momentan alles sehr effektiv
}


class Pokemon
{
public:

	void test(){
	     cout << "Pokemon wurde erstellt"<<  endl;  // Test
	}

	string name;
    string type; //types: grass, water, fire, electro, stone, wind, psycho
    int dexNum;
    double atkbase;
    double defbase;
    double initbase;
    double atkmod;
    double defmod;
    double initmod;
    int maxLevel;
    int nextevo; // dexNum der nÃ¤chsten evolution. nextevo ist gleich wie eigene dexNum wenn es keine weitere Evolution gibt
    Attack baseattack1;
    Attack baseattack2;

    //Konstruktor
    Pokemon(string name, string type, int dexNum, double atkbase, double defbase, double initbase, double atkmod, double defmod, double initmod, int maxLevel, int nextevo, Attack baseattack1, Attack baseattack2){
    	this-> name = name;
    	this-> type = type;
    	this-> dexNum = dexNum;
    	this-> atkbase = atkbase;
    	this-> defbase = defbase;
    	this-> initbase = initbase;
    	this-> atkmod = atkmod;
    	this-> defmod = defmod;
    	this-> initmod = initmod;
    	this-> maxLevel = maxLevel;
    	this-> nextevo = nextevo;
    	this-> baseattack1 = baseattack1;
    	this-> baseattack2 = baseattack2;
    };
    Pokemon(){};

private:
};

class individual
{
public:

	Pokemon pokemon;
	string name;
	string type;
    int level;	// 30 ist erst mal das maximale Level. Dann haut das mit den evolutionen besser hin
    double health;
    double mana;
    double atk;
    double def;
    double init;
    int maxLevel;
    int nextevo; // dexNum der nÃ¤chsten evolution. nextevo ist gleich wie eigene dexNum wenn es keine weitere Evolution gibt
    double xp;
    Attack attack1;
    Attack attack2;

    //Konstruktor
    individual(Pokemon pokemon, int level){
    	this-> pokemon = pokemon;
    	name = pokemon.name;
    	type = pokemon.type;
    	atk = pokemon.atkbase+pokemon.atkmod*level;
    	def = pokemon.defbase+pokemon.defmod*level;
    	init = pokemon.initbase+pokemon.initmod*level;
    	maxLevel = pokemon.maxLevel;
    	nextevo = pokemon.nextevo;
    	attack1 = pokemon.baseattack1;
    	attack2 = pokemon.baseattack2;
    	this-> level = level;
    	health = 100;
    	mana = 100;
    	xp = 0;
    };
    individual(){};

	void evolution(){
			// verÃ¤ndert das Pokemon im Pokedex zum neuen Pokemon
			// muss geschrieben werden, wenn genug Pokemon existieren
		};

	void levelup(){
			level ++;
	    	atk = pokemon.atkbase+pokemon.atkmod*level;
	    	def = pokemon.defbase+pokemon.defmod*level;
	    	init = pokemon.initbase+pokemon.initmod*level;
			if (level > maxLevel){
				evolution();
			}
		};

	void gainXP(double damage){	// damage muss angepasst werden an void angriff
			xp = damage / level;
			if (xp >= 100){
				xp = xp-100;
				levelup();
			}
		};

	pair<double,string> angriff(Attack attk){
		double dmg;
		int r=rand() % 100+1;//check, ob Treffer
		if (r>attk.precision){
			dmg=0;//falls nicht kein Schaden
		}
		else {
			dmg=attk.strength*atk;//Schaden aus Angriff des Dieners und StÃ¤rke der Attacke
		}
		pair<double,string> tempdmg (dmg,attk.type);
		mana-=attk.manacost;
		cout << "Mana: " << mana << endl;
		return tempdmg;//Ã¼bergibt pair aus Schadenswert und Typ
	};

	double verteidigen(pair<int,string> tempdmg){//Ã¼bernimmt pair aus Schadenswert und Typ
		int effective=checktype(tempdmg.second,type);
		double dmg;
		switch(effective){//modifiziert nach EffektivitÃ¤tsmultiplikator (auf 4/5 bzw 5/4)
		case -1: dmg=tempdmg.first*0.8/def; break;
		case 0: dmg=tempdmg.first/def; break;
		case 1: dmg=tempdmg.first*1.25/def; break;
		}
		health-=dmg;//zieht Schaden ab und setzt Health minimal auf null
		if(health<0){
			health=0;
		}
		cout << "Health: " << health << endl;
		return dmg;//gibt Schaden aus fÃ¼r xp-Berechnung
	};


};
