#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


SDL_Surface *screen;


struct ennemi 
{
SDL_Surface *Ennemisurface;
SDL_Rect position;
SDL_Rect pose;
int vie;
SDL_Surface *Ennemiannimer;
SDL_Surface *Ennemiannimer1;
int direction;
SDL_Surface *tab[7];
int i;

state state;

};
typedef struct ennemi Ennemi;




void init (Ennemi * p);
void afficherEnnemi(Ennemi * p, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( SDL_Rect posp,  SDL_Rect pose);





