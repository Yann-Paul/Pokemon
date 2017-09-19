#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "Spieler.hpp"



int attackalgorithm(Individual pokpact, Individual pokeact){//entscheide, welche Attacke Gegner verwendet
	if(pokeact.mana<pokeact.attack1.manacost){//teste, ob zureichend Mana fÃƒÂ¼r Angriff
		if(pokeact.mana<pokeact.attack2.manacost){
			return 0;//falls Mana unzureichend fÃƒÂ¼r beide, nutze Verzweifler
		}
		else{
			return 2;//zu wenig Mana fÃƒÂ¼r 1-->Angriff 2
		}
	}
	if(pokeact.mana<pokeact.attack2.manacost){
		return 1;//zu wenig Mana fÃƒÂ¼r 2-->Angriff 1
	}
	else{//genug Mana fÃƒÂ¼r beide
		int r=rand()%100+1;
		int r1;
		int sus1=checktype(pokeact.attack1.type,pokpact.type);//prÃƒÂ¼fe auf TypanfÃƒÂ¤lligkeiten
		int sus2=checktype(pokeact.attack2.type,pokpact.type);
		if(sus1>sus2){//falls anfÃƒÂ¤lliger auf Angriff 1 als auf 2, nutze mit p=70% Angriff 1
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


int combatroutine(Spieler spieler, Spieler enemy){
	cout << "angekommen" << endl;
	bool flightparameter=false;
	int pact;
	int eact=1;
	char choice;//wÃƒÂ¤hle Diener
	cout << "Waehle Pokemon" << endl;
	cin >> choice;
	switch(choice){
	case '1': pact=1; break;//player-active
	case '2': pact=2; break;
	case '3': pact=3; break;
	}
	cout << "gewaehlt" << endl;
	do{//Matchroutine (3vs3) bis alle Diener eines Kontrahenten besiegt sind
		Individual pokpact;
		Individual pokeact;
		switch(pact){//temporÃƒÂ¤re Diener im Zwischenspeicher
		case 1: pokpact=spieler.pokemon1; break;
		case 2: pokpact=spieler.pokemon2; break;
		case 3: pokpact=spieler.pokemon3; break;
		}
		switch(eact){
		case 1: pokeact=enemy.pokemon1; break;
		case 2: pokeact=enemy.pokemon2; break;
		case 3: pokeact=enemy.pokemon3; break;
		}
		do{//einzelne Kampfroutine (1vs1) bis ein KÃƒÂ¤mpfer besiegt ist
			int enaction=1;
			char whichaction;
			cout << "WÃ¤hle Aktion (f,h,m,1,2)" << endl;
			cin >> whichaction;//frage Spieleraktion ab
			if(whichaction=='f'){
				flightparameter=true;
				break;
			}
			if(whichaction=='h'){
				spieler.usepotion(0, pokpact);
				cout << "healthpotion" << endl;
			}
			if(whichaction=='m'){
				spieler.usepotion(1, pokpact);
				cout << "manapotion" << endl;
			}
			if(pokeact.health<30 & enemy.inventory[0]>0){//Gegner nutzt TrÃƒÂ¤nke, falls nÃƒÂ¶tig, und verbraucht dabei seine Aktion
				enemy.usepotion(0,pokeact);
				cout << "enemypotion" << endl;
				enaction=0;
			}
			if(enaction==1 & pokeact.mana<pokeact.attack1.manacost & pokeact.mana<pokeact.attack2.manacost & enemy.inventory[1]>0){
				enemy.usepotion(1,pokeact);
				enaction=0;
			}
			else{
				cout << "schlagabtausch" << endl;
				pair<double,string> ang;
				double xptemp;
				if(pokeact.init>pokpact.init){
					if(enaction==1){
						int attackswitch=attackalgorithm(pokpact,pokeact);
						switch(attackswitch){
						case 0: break;
						case 1: ang=pokeact.angriff(pokeact.attack1); break;
						case 2: ang=pokeact.angriff(pokeact.attack2); break;
						}
						pokpact.verteidigen(ang);
					}
					if(pokpact.health>0){
						switch(whichaction){
						case '0': break;
						case '1': ang=pokpact.angriff(pokpact.attack1); break;
						case '2': ang=pokpact.angriff(pokpact.attack2); break;
						}
						xptemp=pokeact.verteidigen(ang);
						pokpact.gainXP(xptemp);
					}
				}
				else{
					switch(whichaction){
					case '0': break;
					case '1': ang=pokpact.angriff(pokpact.attack1); break;
					case '2': ang=pokpact.angriff(pokpact.attack2); break;
					}
					xptemp=pokeact.verteidigen(ang);
					pokpact.gainXP(xptemp);
					if(enaction==1 & pokeact.health>0){
						int attackswitch=attackalgorithm(pokpact,pokeact);
						switch(attackswitch){
						case 0: break;
						case 1: ang=pokeact.angriff(pokeact.attack1); break;
						case 2: ang=pokeact.angriff(pokeact.attack2); break;
						}
						pokpact.verteidigen(ang);
					}
				}
			}
		}while(pokpact.health>0 & pokeact.health>0);//bis ein KÃƒÂ¤mpfer besiegt
		switch(pact){//temporÃƒÂ¤re Daten werden permanent
		case 1: spieler.pokemon1=pokpact; break;
		case 2: spieler.pokemon2=pokpact; break;
		case 3: spieler.pokemon3=pokpact; break;
		}
		switch(eact){
		case 1: enemy.pokemon1=pokeact; break;
		case 2: enemy.pokemon2=pokeact; break;
		case 3: enemy.pokemon3=pokeact; break;
		}
		if(flightparameter==true){
			break;
		}
		if(pokpact.health>0){//nÃƒÂ¤chster Diener wird eingesetzt
			eact+=1;
		}
		else{//neuer Diener wird ausgewÃƒÂ¤hlt
			cout << "wÃ¤hle neues pokemon" << endl;
			cin >> choice;
			switch(choice){
			case '1': pact=1; break;
			case '2': pact=2; break;
			case '3': pact=3; break;
			}
		}
	}while((enemy.pokemon1.health+enemy.pokemon2.health+enemy.pokemon3.health>0) & (spieler.pokemon1.health+spieler.pokemon2.health+spieler.pokemon3.health>0));//bis alle KÃƒÂ¤mpfer besiegt
	if(flightparameter==true){
		return 0;//Flucht ist keine Niederlage!
	}
	if(spieler.pokemon1.health+spieler.pokemon2.health+spieler.pokemon3.health>0){//falls Spielerdiener leben
		return 1;//Sieg des Spielers
	}
	else{
		return -1;//Sieg des Gegners
	}
}
