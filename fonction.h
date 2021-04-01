#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{		
SDL_Surface *Ennemisurface;
SDL_Rect *position;
int vie;
}Ennemi;
void init (Ennemi * p);
void afficherEnnemi(Ennemi * p, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
