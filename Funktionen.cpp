#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "Spieler.cpp"



int checktype(string type1, string type2){//liste mit typschwächen, wenn typen final
	return 1;//momentan alles sehr effektiv
}

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
