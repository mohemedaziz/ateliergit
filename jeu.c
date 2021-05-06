#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeux.h"

void init (Ennemi *p){

p->Ennemisurface=IMG_Load("Character.jpg");
p->vie = 100;
p->direction=0;
p->tab[1]=IMG_Load("dragon01.png");
p->tab[2]=IMG_Load("dragon02.png");
p->tab[3]=IMG_Load("dragon03.png");
p->tab[4]=IMG_Load("dragon04.png");
p->tab[5]=IMG_Load("dragon05.png");
p->tab[6]=IMG_Load("dragon06.png");
p->tab[7]=IMG_Load("dragon07.png");
p->position.x=1000;
p->position.y=40;
p->i=3;
}



void afficherEnnemi(Ennemi * p, SDL_Surface * screen){
SDL_BlitSurface(p->Ennemisurface,NULL,screen,&p->position);
}


void animerEnnemi( Ennemi * p){
if (p->direction==0)
{
SDL_BlitSurface(p->tab[p->i],NULL,screen,&p->position);
}
}


void deplacer( Ennemi * p){
int aa=1;
{
SDL_Delay(100);
p->position.x-=20;
p->i++;
if (p->i==7)
  p->i=0;
animerEnnemi(p);
if (p->position.x-=500)
{p->position.x-=1000;}
}
}



int collisionBB( SDL_Rect posp,  SDL_Rect pose) 
{
int cols;

if((posp.x+posp.w<pose.x)||(posp.x>pose.x+pose.w) ||(posp.y+posp.h<pose.y)||(posp.y>pose.y+pose.h))
{
cols=0;
}
else 
cols=1;
return 0;
}









