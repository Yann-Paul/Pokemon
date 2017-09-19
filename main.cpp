#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include "Funktionen.hpp"
#include "map.hpp"


using namespace std;


string name;  // Spielernamen
char input; // Eingabe im spÃƒÂ¤teren Input
int auswahl;
bool schleife = true; //Fuer Schleife



int main()
{


                    
                     
	Individual nullpok(none, 1);
	nullpok.health=0;






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
			cout << "1 = Bisasom        2 = Bisaknosp        3 = Bisaflor"
					<< endl;
			cin >> input;
			break;
		}
	}


	Pokemon auswahlPokemon = bulbasure;
	Individual ausPok(auswahlPokemon, 1);
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

    // gefundenesPokemontype
    int gefundenesPokemontype = map();


    return 0;
}
