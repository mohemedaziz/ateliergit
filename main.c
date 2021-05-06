# ateliergit

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "perso.h"



int main(int argc, char const *argv[])
{int gameover ;

perso p;
	SDL_Surface *screen, *temp, *sprite, *bg;
	SDL_Rect posbg;
	int colorkey, cont=1;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("SDL Animation" , "SDL Animation");
	screen = SDL_SetVideoMode(1445,965,0,0);
	SDL_EnableKeyRepeat(60,60);
	temp = SDL_LoadBMP("background.bmp"); 
	bg = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	posbg.x=0;
	posbg.y=0;

	init(&p,screen);
	gameover = 0;

	while (!gameover)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			gestionevent(&event,&p,&gameover);
		}
		if (p.rcSprite.x < 0 )
		{
			p.rcSprite.x = 0;
		}
		else if (p.rcSprite.x >1445-96)
		{
			p.rcSprite.x = 1445-96;
		}
		if (p.rcSprite.y < 0)
		{
			p.rcSprite.y = 0;
		}
		else if (p.rcSprite.y > 965-96)
		{
			p.rcSprite.y = 965-96;
		}

		SDL_BlitSurface(bg, NULL, screen, &posbg);
		SDL_BlitSurface(p.sprite, &(p).rcSrc, screen, &(p).rcSprite);
		SDL_Flip(screen);
	}	
SDL_FreeSurface(sprite);
SDL_FreeSurface(bg);
SDL_Quit();
return 0;



}
