#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lot2.h"

void init (Ennemi * p){

p->Ennemisurface=IMG_Load("Character.jpg");

p->vie = 100;
}



void afficherEnnemi(Ennemi * p, SDL_Surface * screen){

p->position->x=0;

p->position->y=0;

SDL_BlitSurface(p->Ennemisurface,NULL,screen,p->position);
}


void animerEnnemi( Ennemi * p){

if (direction==0)

{

SDL_FreeSurface(p->Ennemisurface);

SDL_BlitSurface(p->Ennemiannimer,NULL,screen,p->position);

SDL_Delay(50);

SDL_FreeSurface(p->Ennemiannimer);

SDL_BlitSurface(p->Ennemisurface,NULL,screen,p->position);

}

else {

SDL_FreeSurface(p->Ennemisurface);

SDL_BlitSurface(p->Ennemiannimer1,NULL,screen,p->position);

SDL_Delay(50);

SDL_FreeSurface(p->Ennemiannimer1);

SDL_BlitSurface(p->Ennemisurface,NULL,screen,p->position);

}

}





void deplacer( Ennemi * p){

SDL_Delay(1000);

p->position.x+=50;

direction=0; 

animerEnnemi(p);

}
