#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "Funktionen.hpp"


using namespace std;


string name;  // Spielernamen
char input; // Eingabe im spÃ¤teren Input
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
	Pokemon none("None", "None", 0, 0, 0, 0, 0.0, 0.0, 0, 0, 0, 0, 0, 0.0, tackle, tackle);
	Pokemon bisasam("Bisasam", "grass", 001, 1, 100, 100, 0.7, 6.9, 5, 5, 5, 10, 002, 0.0, tackle, growl);
	Pokemon bisaknosp("Bisaknosp", "grass", 002, 11, 100, 100, 1.0, 13.0, 15, 15, 15, 20, 003, 0.0, solarBeam, vineWhip);
	Pokemon bisaflor("Bisaflor", "grass", 003, 21, 100, 100, 2.0, 100.0, 30, 30, 30, 30, 003, 0.0, solarBeam, razorLeaf);



	tackle.test();

	bisasam.test();
	bisaflor.test();

	// fuer spaeter
	Pokemon pokedex[3] = { bisasam, bisaknosp, bisaflor };


    //Pokemon auswaehlen
    cout << "Hallo! Um das Spiel beginnen zu kÃ¶nnen brauchst du einen Namen. Bitte wÃ¤hle deinen Namen aus. " <<endl; // Test
    cin >> name;
    Spieler spieler(name, none, none, none);
    cout << "Hallo " << name <<"! Herzlich Willkommen in der Pokemonarena. Als nÃ¤chstes wÃ¤hle bitte dein Pokemon aus."<<endl;
    cout << "DafÃ¼r drÃ¼cke eine der folgenden Zahlen."<<endl;
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
    spieler.pokemon2 = auswahlPokemon;
    spieler.pokemon3 = auswahlPokemon;
    Spieler Gegner("Gary", auswahlPokemon, auswahlPokemon, auswahlPokemon);
    int winloss = combatroutine(spieler, Gegner);
    if(winloss==-1){
    	cout << "loser" << endl;
    }
    if(winloss==1){
    	cout << "triumph" << endl;
    }


    return 0;
}


