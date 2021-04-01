#include <stdlib.h>
#include <stdio.h>
#include "lot2.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char** argv){
Ennemi * p;
int direction;

if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}
SDL_Surface *screen,*background;
SDL_Rect posscreen,posbackground;
background=IMG_Load("background.jpg");
posscreen.x=0;
posscreen.y=0;
posbackground.x=0;
posbackground.y=0;
screen = SDL_SetVideoMode( 1920, 1080, 32, SDL_HWSURFACE | SDL_RESIZABLE);

int quit=0;
while(quit==0){
SDL_BlitSurface(background,NULL,screen,&posbackground);
init (p );
afficherEnnemi(p, screen);
deplacer(p);


SDL_Flip(screen);
}//boucle while(quit)
}// int main

