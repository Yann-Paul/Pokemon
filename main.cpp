#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "Funktionen.hpp"


using namespace std;


string name;  // Spielernamen
char input; // Eingabe im spÃƒÂ¤teren Input
int auswahl;
bool schleife = true; //Fuer Schleife



int main()
{

	// Attacken (name, typ, strength, precision, manacost)
	Attack tackle("Tackle", "normal", 40, 100, 20);
	Attack growl("Growl", "normal", 45, 100, 20);
	Attack solarBeam("Solar Beam", "grass", 45, 100, 25);
	Attack vineWhip("Vine Whip", "grass", 45, 100, 10);
	Attack razorLeaf("Razor Leaf", "psycho", 55, 100, 25);

	// Erstelle die Pokemons
	Pokemon none("None", "None", 0, 0, 0, 0, 0, 0, 0, 0, 0, tackle, tackle);
	Pokemon bisasam("Bisasam", "grass", 1, 5, 5, 5, 0.5, 0.5, 0.5, 10, 2, tackle, growl);
	Pokemon bisaknosp("Bisaknosp", "grass", 2, 15, 15, 15, 0.75, 0.75, 0.75, 20, 3, tackle, razorLeaf);
	Pokemon bisaflor("Bisaflor", "grass", 3, 30, 30, 30, 0, 0, 0, 31, 3, vineWhip, solarBeam);

	individual nullpok(none, 1);
	nullpok.health=0;


	tackle.test();

	bisasam.test();
	bisaflor.test();

	// fuer spaeter
	Pokemon pokedex[3] = { bisasam, bisaknosp, bisaflor };


    //Pokemon auswaehlen
    cout << "Hallo! Um das Spiel beginnen zu koennen brauchst du einen Namen. Bitte waehle deinen Namen aus. " <<endl; // Test
    cin >> name;
    Spieler spieler(name, nullpok, nullpok, nullpok);
    cout << "Hallo " << name <<"! Herzlich Willkommen in der Pokemonarena. Als naechstes waehle bitte dein Pokemon aus."<<endl;
    cout << "Dafuer duecke eine der folgenden Zahlen."<<endl;
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
	individual ausPok(auswahlPokemon, 1);
	cout << "Herzlichen Glueckwunsch. Du hast "<< auswahlPokemon.name <<auswahl<<" ausgewaehlt. Das ist eine gute Wahl"<<endl;
    spieler.pokemon1 = ausPok;
    Spieler Gegner("Gary", ausPok, nullpok, nullpok);
    int winloss = combatroutine(spieler, Gegner);
    if(winloss==-1){
    	cout << "loser" << endl;
    }
    if(winloss==1){
    	cout << "triumph" << endl;
    }


    return 0;
}
