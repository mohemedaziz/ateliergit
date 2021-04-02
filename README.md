#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonctions.h"


void initPerso(Personne *p)
{
  p->sprite = IMG_Load("images/sprite.png");
  p->Rect posSprite.x=0;
  p->Rect posSprite.y=0;
  p->Rect posSprite.w=350;
  p->Rect posSprite.h=65;
  p->direction=0;
  
  p.LIFE->vies = IMG_Load("images/vie.png");
  p.LIFE->Rect posVie.x=800;
  p.LIFE->Rect posVie.y=8;
  
  p.SCORE->police=TTF_OpenFont("font/font.ttf", 65);
  p.SCORE->posScoreaff.x=400;
  p.SCORE->posScoreaff.y=7;
  
  

}
void afficherPerso(Personne p, SDL_Surface * screen)
{

SDL_BlitSurface(sprite,&RectposSprite,screen,&RectposSprite);
SDL_BlitSurface(heart,NULL,screen,&RectposVie);
p.SCORE->scoreaff=TTF_RenderText_Solid( p.score->police, "Score", p.SCORE->couleurpolice );

}


void deplacerPerso (Personne *p)
{
SDL_PollEvent(&event);
 switch(event.type)
   (
       switch(event.key.keysym.sym)
       (
       
       case SDLK_RIGHT:
           p->direction=0;
           posPerso.x+=10;
           SDL_WaitEvent(&event);
          break;
       case SDLK_LEFT:
           p->direction=1;
           posSprite.x-=10;
           SDL_WaitEvent(&event);
          break;
       case SDLK_DOWN:
           p->direction=2
           posPerso.y+=10;
           SDL_WaitEvent(&event);
          break;
       case SDLK_Up
           p->direction=3
           posperso.y+=10;
           SDL_WaitEvent(&event);
        )
   )


}
