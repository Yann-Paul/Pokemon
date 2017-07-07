/*
 * PseudoPok.cpp
 *
 *  Created on: 05.07.2017
 *      Author: jacobstupka
 */

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <tuple>

using namespace std;
class Action; class Pokemon;

class Action
{
public:
	string name;
	string type;
	int strength;
	int prec;
	int cost;
	Action(string nname, string ntype, int nstrength, int nprec, int ncost){
		name=nname;
		type=ntype;
		strength=nstrength;
		prec=nprec;
		cost=ncost;
	}
};

/*typedef struct
{
	string name;
	string type;
	double strength;
	double prec;
	double cost;
} Action;*/

class Pokemon
{
public:

	// fuer spaeter
	/*void usePotion();
	*/

    string name;
    string type;
    int dexNum;
    int level;
    double xp;
    double atk;
    double def;
    double init;
    double health;
    double AP;
    int maxLevel;
    Action *action1;
    Action *action2;

    //Konstruktor ausgeschrieben
    Pokemon(string nname, string ntype, int ndexNum, int nlevel, double nxp, double natk, double ndef, double ninit, double nhealth, double nAP, int nmaxLevel, Action *naction1, Action *naction2){
    	name=nname;
    	type=ntype;
    	dexNum=ndexNum;
    	level=nlevel;
    	xp=nxp;
    	atk=natk;
    	def=ndef;
    	init=ninit;
    	health=nhealth;
    	AP=nAP;
    	maxLevel=nmaxLevel;
    	action1=naction1;
    	action2=naction2;
    };

    /*
     * tuple<double,string> attack(action actionl) {     //was ist falsch mit tuples?
    	AP-=actionl.APcost;
    	int r;
    	srand(time(NULL));
    	r=rand()%100+1;
    	if(r<=actionl.precision){
    		double a=actionl.strength*atk;      //typemod missing
    		return make_tuple(a, actionl.typ);
    	}
    	else {
    		return make_tuple(0, ' ');
    	}
    };
    */

    double attack(Action *actionl){
    	AP=-actionl->cost;
    	int r;
    	srand(time(NULL));
    	r=rand()%100+1;
    	if(r<=actionl->prec){
    		double a=actionl->strength*atk;    //typemod missing
    		return a;
    	}
    	else {
    		return 0;
    	}
    }

    void defend(double a){
    	health-=a/def;
    	if(health>0)
    	return;
    }

    void status(){
    	double a[3]={health, AP, xp};
    	cout << "Health: " << a[0] << " AP: " << a[1] << " xp: " << a[2] << endl;
    	return;
    }

private:

};


void fight(Pokemon pokp, Pokemon pokc){
	do{
		if(pokp.init>=pokc.init){
			cout << "Choose an action: " << pokp.action1->name << pokp.action2->name << "flee swap capture potion" << endl;
			char a[20];
			cin >> a;
			if(a==pokp.action1->name){
				double a=pokp.attack(pokp.action1);
				pokc.defend(a);
			}
			if(a==pokp.action2->name){
				double a=pokp.attack(pokp.action2);
				pokc.defend(a);
			}
			if(!pokc.health>0){
				return;
			}
			int r;
			srand(time(NULL));
			r=rand()%2+1;
			if(r==1){
				double a=pokc.attack(pokc.action1);
				pokp.defend(a);
			}
			if(r==2){
				double a=pokc.attack(pokc.action2);
				pokp.defend(a);
			}
		}
		else{
			cout << "Choose an action: " << pokp.action1->name << pokp.action2->name << "flee swap capture potion" << endl;
			char a[20];
			cin >> a;
			int r;
			srand(time(NULL));
			r=rand()%2+1;
			if(r==1){
				double a=pokc.attack(pokc.action1);
				pokp.defend(a);
			}
			if(r==2){
				double a=pokc.attack(pokc.action2);
				pokp.defend(a);
			}
			if(!pokp.health>0){
				return;
			}
			if(a==pokp.action1->name){
				double a=pokp.attack(pokp.action1);
				pokc.defend(a);
			}
			if(a==pokp.action2->name){
				double a=pokp.attack(pokp.action2);
				pokc.defend(a);
			}

		}
	} while (pokp.health>0 && pokc.health>0);
}


int main()
{
	// Erstelle die Attacken
	Action tackle("tackle","normal",40,100,35);

	Action growl("growl","normal",45,100,40);

	/*Attack tackle("tackle", "normal", 40, 100, 35);
	Attack growl("growl", "normal", 45, 100, 40);*/


	// Erstelle die Pokemons
	Pokemon bisasam("Bisasam", "grass",001, 1, 0, 10, 10, 10, 100, 100, 10, &tackle, &growl);
	Pokemon glumanda("Glumanda", "fire",004, 1, 0, 12, 8, 10, 100, 100, 10, &tackle, &growl);


	double a=bisasam.attack(&tackle);
	glumanda.defend(a);
	glumanda.status();


	bisasam.action1 = &tackle;
	bisasam.action2 = &growl;


	// fuer spaeter
	Pokemon pokedex[1] = { bisasam };


    //Pokemon auswaehlen
    //cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << "bisasam" << endl;
     cout << "Willkommen im Pokedex. Bitte waehle eines der folgenden Pokemon aus " << pokedex << endl;  //fuer spaeter
    //cin >> input;



    return 0;
}
