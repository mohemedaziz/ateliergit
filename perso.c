# ateliergit
premier pas avec git
#include <SDL/SDL.h>
#include "perso.h"
#include <SDL/SDL_image.h>
void init (perso *p,SDL_Surface *screen)
{
int colorkey;
	SDL_Surface *temp;
  temp= IMG_Load("dragon.png");
  p->sprite = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  /*position initial*/
  p->rcSprite.x = 150;
  p->rcSprite.y = 150;
  //frame
  	p->rcSrc.x = 0;
	p->rcSrc.y = 0;
	p->rcSrc.w=96;
	p->rcSrc.h=96;
  colorkey = SDL_MapRGBA(screen->format, 255, 255, 255, 255);
  SDL_SetColorKey(p->sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

//////////////////////////
	
}

void affichage(SDL_Event *event,SDL_Rect *rcSrc)
{
	switch ((*event).key.keysym.sym)
	{
		case SDLK_LEFT:
			if (((*rcSrc).x == 0)&&((*rcSrc).y == 96))
				(*rcSrc).x =96;
			else if (((*rcSrc).x == 96)&&((*rcSrc).y == 96))
				(*rcSrc).x = 192;
			else if (((*rcSrc).x == 192)&&((*rcSrc).y == 96))
				(*rcSrc).x = 288;
			
			else
				{
					(*rcSrc).x=96;
					(*rcSrc).y=96;
				}

			break;
		case SDLK_RIGHT:
				if (((*rcSrc).x == 0)&&((*rcSrc).y == 192))
				(*rcSrc).x =96;
			else if (((*rcSrc).x == 96)&&((*rcSrc).y == 192))
				(*rcSrc).x = 192;
			else if (((*rcSrc).x == 192)&&((*rcSrc).y == 192))
				(*rcSrc).x = 288;
			
			else
				{
					(*rcSrc).x=0;
					(*rcSrc).y=192;
				}

			break;
	}
}
void deplacement(SDL_Event *event,SDL_Rect *rcSprite)
{
	switch ((*event).key.keysym.sym)
	{
		case SDLK_LEFT:
			(*rcSprite).x -= 10;
			break;
		case SDLK_RIGHT:
		 	(*rcSprite).x += 10;
		 	break;
	}
}
void saut(SDL_Rect *rcSrc,SDL_Rect * rcSprite)
{
	if ((((*rcSrc).x ==0)||((*rcSrc).x == 96)||((*rcSrc).x == 192)||((*rcSrc).x ==288))&&(((*rcSrc).y == 96)))
	{
		(*rcSprite).x=(*rcSprite).x-32;
		(*rcSprite).y=(*rcSprite).y-32;	
	}
	else if ((((*rcSrc).x ==0)||((*rcSrc).x == 60)||((*rcSrc).x == 120)||((*rcSrc).x ==180))&&(((*rcSrc).y == 192)))
	{
		(*rcSprite).x=(*rcSprite).x+32;
		(*rcSprite).y=(*rcSprite).y-32;
	}
}
void gestionevent(SDL_Event *event,perso *p,int *gameover)
{
	switch ((*event).type) 
	{
    /* quitter */
    case SDL_QUIT:
      *gameover = 1;
      break;

      /* clavier  */
	    case SDL_KEYDOWN:
	      switch ((*event).key.keysym.sym)
	      	{
	        	
	        	case SDLK_q:
	          	*gameover = 1;
	          	break;
	        	case SDLK_LEFT:
	        	affichage(event,&p->rcSrc);
	        	deplacement(event,&p->rcSprite);

	        	break;
	        	case SDLK_RIGHT:
	        	affichage(event,&p->rcSrc);
	        	deplacement(event,&p->rcSprite);
	        	break;
	        	case SDLK_UP:
	          	affichage(event,&p->rcSrc);
	        	deplacement(event,&p->rcSprite);
	        	break;
	        	case SDLK_DOWN:
	       		affichage(event,&p->rcSrc);
	        	deplacement(event,&p->rcSprite);
	        	break;
	        	case SDLK_SPACE:
	        	if ((p->rcSprite).y!=0)
	        	{
	        		saut(&p->rcSrc,&p->rcSprite);
	        	}
	        	break;
	    	}
	    	break;
	    		case SDL_KEYUP:
	    		switch ((*event).key.keysym.sym)
	    		{
	    			case SDLK_SPACE:
	    			if ((p->rcSprite).y!=0)
	    				(p->rcSprite).y=(p->rcSprite).y+32;
	    			break;
	    		}
	    		break;
    }
}
