//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <string>
#include <tuple>
using namespace std;

//Bildschirmgroeße
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 320;

//initialisiert das Fenster
bool initialize();

//Laedt die Bilder
bool loadMedia();

//Schließt SDL. Muss noch geändert werden
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gbackgroundMap = NULL;
SDL_Surface* gcharacterLeft = NULL;
SDL_Surface* gcharacterRight = NULL;
SDL_Surface* gcharacterBack = NULL;
SDL_Surface* gcharacterFront = NULL;
SDL_Surface* gwind = NULL;
SDL_Surface* gfire = NULL;
SDL_Surface* gstone = NULL;
SDL_Surface* gelectro = NULL;
SDL_Surface* gwater = NULL;
SDL_Surface* ggrass = NULL;
SDL_Surface* gphsycho = NULL;

SDL_Rect dest;

pair<bool,int> grenzenPokemon;

//gibt den Typus des gefundenen Pokemons an:
// 1 = fire, 2 = stone, 3 = wind, 4 = psycho,  5 = electro, 6 = grass
int typeInt;

bool initialize()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
        SDL_Init(SDL_INIT_EVERYTHING);
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    
    //Hintergrundkart laden
    gbackgroundMap = IMG_Load ( "PokemonMap.png" );
    if( gbackgroundMap == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/PokemonMap.jpg", SDL_GetError() );
        success = false;
    }
    
    //Charakterposen laden
    gcharacterLeft = IMG_Load ("characterLeft.png");
    if( gcharacterLeft == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "character", SDL_GetError() );
        success = false;
    }
    
    gcharacterRight = IMG_Load ("characterRight.png");
    if( gcharacterRight == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "character", SDL_GetError() );
        success = false;
    }
    
    gcharacterFront = IMG_Load ("characterFront.png");
    if( gcharacterFront == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "character", SDL_GetError() );
        success = false;
    }
    
    gcharacterBack = IMG_Load ("characterBack.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "character", SDL_GetError() );
        success = false;
    }
    
    //Elemente laden
    gwind = IMG_Load ("wind.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }
    gelectro = IMG_Load ("electro.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }
    gfire = IMG_Load ("fire.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }
    gphsycho = IMG_Load ("phsycho.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }
    gstone = IMG_Load ("stone.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }
    gwater = IMG_Load ("water.png");
    if( gcharacterBack == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "element", SDL_GetError() );
        success = false;
    }

    
    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gbackgroundMap );
    gbackgroundMap = NULL;
    SDL_FreeSurface( gcharacterFront );
    gcharacterFront = NULL;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();
}

// prüft ob dass Character nicht über Hindernisse läuft
pair<bool,int> inGrenzen(int x,int y){
    // innerhalb bildschirm
    if (((x>=0) & (x<=310)) & ((y>=0) & (y<=310))) {
        // nicht oben rechts
        if ((x<213) || (y>20)){
            // nicht im Wasser/Electro/Gras Bereich
            if ((x>280) || (y<80)){
                int entdeckt=rand() % 240+1;
                if (entdeckt <= 7){
                    switch (entdeckt){
                    case 1: grenzenPokemon = make_pair(false,1); break;
                    case 2: grenzenPokemon = make_pair(false,1); break;
                    case 3: grenzenPokemon = make_pair(false,2); break;
                    case 4: grenzenPokemon = make_pair(false,2); break;
                    case 5: grenzenPokemon = make_pair(false,3); break;
                    case 6: grenzenPokemon = make_pair(false,3); break;
                    case 7: grenzenPokemon = make_pair(false,4); break;
                    }

                    return grenzenPokemon;
                }
                else{
                    grenzenPokemon = make_pair(true,0);
                    return grenzenPokemon;
                }
            }
            else {
                // im Strandbereich (Wasser)
                if ((x>150) & (x<190) & (y<130)){
                    int entdeckt=rand() % 40+1;
                    if (entdeckt == 1){
                        grenzenPokemon = make_pair(false,5);
                        return grenzenPokemon;
                        
                    }
                    else{
                        grenzenPokemon = make_pair(true,0);
                        return grenzenPokemon;
                    }

                }
                else {
                    // im zweituntersten rechteck (Elektrobereich)
                    if ((x>80) & (y>210) & (y<245)){
                        // außerhalb des Baumstumpfes
                        if (!((x>105) & (x<125) & (y>215) & (y<240))){
                            int entdeckt=rand() % 40+1;
                            if (entdeckt == 1){
                                grenzenPokemon = make_pair(false,6);
                                return grenzenPokemon;
                            }
                            else{
                                grenzenPokemon = make_pair(true,0);
                                return grenzenPokemon;
                            }

                        }
                        
                    }
                    else {
                        // im untersten Rechteck (Grasbereich)
                        if ((x>150) & (y>245)){
                            int entdeckt=rand() % 40+1;
                            if (entdeckt == 1){
                                grenzenPokemon = make_pair(false,7);
                                return grenzenPokemon;
                            }
                            else{
                                grenzenPokemon = make_pair(true,0);
                                return grenzenPokemon;
                            }

                        }
                    }
                }
            
            }
            
        }
    }
    grenzenPokemon = make_pair(false,0);
    return grenzenPokemon;
}

class Character {
public:
    SDL_Surface *bild;
    int xpos = 200;
    int ypos = 10;
    int tempo = 4;
    SDL_Rect dest;
    SDL_Rect src;
    
    Character(SDL_Surface *_bild) {
        bild = _bild;
    }
    
    void zeichnen(SDL_Surface *surf){
        src = {.x =  200, .y =  10, .w = 13, .h = 16};
        dest = {.x =  xpos, .y =  ypos, .w = 13, .h = 16};
        SDL_BlitSurface(bild, NULL, surf, &dest);
    }
    
    int bewegen(int richtung){
        switch (richtung){
            case 1:
                grenzenPokemon = inGrenzen(xpos, ypos - tempo);
                if (grenzenPokemon.first){
                    ypos -= tempo;
                    bild = gcharacterBack;
                }
                else{
                    if ( grenzenPokemon.second != 0){
                        return(grenzenPokemon.second);
                    }
                }
                break;
            case 2:
                grenzenPokemon = inGrenzen(xpos + tempo, ypos);
                if (grenzenPokemon.first){
                    xpos += tempo;
                    bild = gcharacterRight;
                }
                else{
                    if ( grenzenPokemon.second != 0){
                        return(grenzenPokemon.second);
                    }
                }
                break;

            case 3:
                grenzenPokemon = inGrenzen(xpos, ypos + tempo);
                if (grenzenPokemon.first){
                    ypos += tempo;
                    bild = gcharacterFront;
                }
                else{
                    if ( grenzenPokemon.second != 0){
                        return(grenzenPokemon.second);
                    }
                }
                break;
            case 4:
                grenzenPokemon = inGrenzen(xpos - tempo, ypos);
                if (grenzenPokemon.first){
                    xpos -= tempo;
                    bild = gcharacterLeft;
                }
                else{
                    if ( grenzenPokemon.second != 0){
                        return(grenzenPokemon.second);
                    }
                }
                break;
        }
        return(grenzenPokemon.second);
    }
};

int map()
{

    
    //Start up SDL and create window
    if( !initialize() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gbackgroundMap, NULL, gScreenSurface, NULL );
            
            //Update the surface
            SDL_UpdateWindowSurface( gWindow );
            
            
            SDL_Event e;
            SDL_Surface* surf = SDL_GetWindowSurface(gWindow);
            
            Character character1(gcharacterFront);
            character1.zeichnen(surf);
            
            for (int x=0; x<30000; x++) {
                
                if ( SDL_PollEvent( &e ) != 0 ) {
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                            typeInt = character1.bewegen(1);
                            break;
                        case SDLK_DOWN:
                            typeInt = character1.bewegen(3);
                            break;
                        case SDLK_LEFT:
                            typeInt = character1.bewegen(4);
                            break;
                        case SDLK_RIGHT:
                            typeInt = character1.bewegen(2);
                            break;
                    }
                }
                
                SDL_BlitSurface( gbackgroundMap, NULL, gScreenSurface, NULL );
                character1.zeichnen(surf);
                SDL_UpdateWindowSurface(gWindow);
                
                if (typeInt != 0){
                    
                    // Element anzeigen
                    switch(typeInt){
                        case 1: SDL_BlitSurface( gfire, NULL, gScreenSurface, NULL ); break;
                        case 2: SDL_BlitSurface( gstone, NULL, gScreenSurface, NULL ); break;
                        case 3: SDL_BlitSurface( gwind, NULL, gScreenSurface, NULL ); break;
                        case 4: SDL_BlitSurface( gphsycho, NULL, gScreenSurface, NULL ); break;
                        case 5: SDL_BlitSurface( gelectro, NULL, gScreenSurface, NULL ); break;
                        case 6: SDL_BlitSurface( ggrass, NULL, gScreenSurface, NULL ); break;
                    }
                    
                    SDL_UpdateWindowSurface( gWindow );
                    SDL_Delay(1500);
                    
                    
                    close();
                    return typeInt;
                }
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}
