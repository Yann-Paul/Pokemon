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

// Attacken (name, typ, strength, precision, manacost)
Attack tackle("Tackle", "stone", 40, 50, 10);
Attack growl("Growl", "wind", 45, 90, 20);
Attack solarBeam("Solar Beam", "grass", 45, 60, 25);
Attack vineWhip("Vine Whip", "grass", 45, 90, 10);
Attack razorLeaf("Razor Leaf", "psycho", 55, 70, 25);
Attack lavaspit("Lavaspit","fire",45,45,10);
Attack burn("Burn","fire",45,80,20);
Attack burn3rdDegree("Burn 3rd Degree","fire",55,75,25);
Attack aquaBubble("Aqua Bubble", "water", 50, 40, 10);
Attack waterfall("Waterfall", "water", 40, 100, 25);
Attack iceThorn("Ice Thorn", "water", 80, 55, 30);
Attack dust("Dust", "stone", 20, 100, 10);
Attack slingshot("Slingshot", "stone", 60, 60, 20);
Attack landslide("Landslide", "stone", 45, 100, 35);


// Erstelle die Pokemons (name, typ, dexNum, atkbase, defbase, initbase, atkmod, defmod, initmod, maxLevel, nextevo, baseattack1, baseattack2)
Pokemon none("None", "None", 0, 0, 0, 0, 0, 0, 0, 0, 0, tackle, tackle);
Pokemon bulbasure("Bisasam", "grass", 1, 4, 6, 6, 0.5, 0.5, 0.5, 10, 2, tackle, solarBeam);
Pokemon ivysure("Bisaknosp", "grass", 2, 13, 17, 14, 0.75, 0.75, 0.75, 20, 3, tackle, razorLeaf);
Pokemon venusure("Bisaflor", "grass", 3, 20, 40, 35, 0, 0, 0, 31, 3, vineWhip, solarBeam);
Pokemon charmandoor("Charmandoor", "fire", 4, 6, 4, 4, 0.5, 0.5, 0.5, 10, 5, growl, lavaspit);
Pokemon charmelon("Charmelon", "fire", 5, 17, 13, 15, 0.75, 0.75, 0.75, 20, 6, growl, burn);
Pokemon charwizard("Charwizard", "grass", 6, 40, 20, 30, 0, 0, 0, 31, 6, razorLeaf, burn3rdDegree);
Pokemon squirtula("Squirtula", "water", 7, 5, 5, 5, 0.5, 0.5, 0.5, 10, 8, aquaBubble, vineWhip);
Pokemon diplmatictortle("Diplomatictortle", "water", 8, 15, 15, 15, 0.75, 0.75, 0.75, 20, 9, waterfall, growl);
Pokemon blastwave("Blastwave", "water", 9, 30, 30, 30, 0, 0, 0, 31, 9, waterfall, iceThorn);
Pokemon geobro("Geobro", "stone", 10, 7, 3, 5, 0.5, 0.5, 0.5, 10, 11, dust, lavaspit);
Pokemon marblous("Marblous", "stone", 11, 14, 16, 15, 0.75, 0.75, 0.75, 20, 12, tackle, slingshot);
Pokemon marbgiant("Marbgiant", "stone", 12, 25, 35, 33, 0, 0, 0, 31, 12, slingshot, landslide);


class Individual
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
    Individual(Pokemon pokemon, int level){
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
    Individual(){};

    // veraendert das Pokemon im Pokedex zum neuen Pokemon
    // muss geschrieben werden, wenn genug Pokemon existieren
	void evolution(){
        switch (pokemon.dexNum){
            case 1: pokemon = ivysure; break;
            case 2: pokemon = venusure; break;
            case 4: pokemon = charmelon; break;
            case 5: pokemon = charwizard; break;
            case 7: pokemon = diplmatictortle; break;
            case 8: pokemon = blastwave; break;
            case 10: pokemon = marblous; break;
            case 11: pokemon = marbgiant; break;
        }
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
			dmg=attk.strength*atk;//Schaden aus Angriff des Dieners und Staerke der Attacke
		}
		pair<double,string> tempdmg (dmg,attk.type);
		mana-=attk.manacost;
		cout << "Mana: " << mana << endl;
		return tempdmg;//Uebergibt pair aus Schadenswert und Typ
	};

	double verteidigen(pair<int,string> tempdmg){//Uebernimmt pair aus Schadenswert und Typ
		int effective=checktype(tempdmg.second,type);
		double dmg;
		switch(effective){//modifiziert nach Effektivitaetsmultiplikator (auf 4/5 bzw 5/4)
		case -1: dmg=tempdmg.first*0.8/def; break;
		case 0: dmg=tempdmg.first/def; break;
		case 1: dmg=tempdmg.first*1.25/def; break;
		}
		health-=dmg;//zieht Schaden ab und setzt Health minimal auf null
		if(health<0){
			health=0;
		}
		cout << "Health: " << health << endl;
		return dmg;//gibt Schaden aus fuer xp-Berechnung
	};


};
