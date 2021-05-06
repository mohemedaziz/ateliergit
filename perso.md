# ateliergit
premier pas avec git
#ifndef ANIM_H_
#define ANIM_H_

typedef struct
{
	
	SDL_Rect rcSrc;
	SDL_Rect rcSprite;
	SDL_Surface *sprite;
}perso;

void init (perso *p,SDL_Surface *screen);
void deplacement(SDL_Event *event,SDL_Rect *rcSprite);
void saut(SDL_Rect *rcSrc,SDL_Rect * rcSprite);
void gestionevent(SDL_Event *event,perso *p,int *gameover);











#endif
