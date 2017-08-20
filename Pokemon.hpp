#include <iostream>
#include <string>
#include "Attack.hpp"
using namespace std;


int checktype(string type1, string type2){//liste mit typschwÃ¤chen, wenn typen final
	return 1;//momentan alles sehr effektiv
}


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
		cout << "Mana: " << mana << endl;
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
		cout << "Health: " << health << endl;
		return dmg;//gibt Schaden aus für xp-Berechnung
	};

private:
};
