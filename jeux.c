
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


int sourisSur(SDL_Rect pos, int mouseX, int mouseY) { 
	return mouseX >= pos.x && mouseX <= pos.x + pos.w && mouseY >= pos.y && mouseY <= pos.y + pos.h;
}

typedef struct {
	int fullscreen, volume;
} optionMenu;

void afficherMenuOption(SDL_Surface* screen, int* menuActuel, optionMenu* opts) {
int leaveCourant = 0;
SDL_Surface* optionMenu, *leave, *off, *on, *volumeUp, *volumeDown, *mute, *texte, *leave1;

off = IMG_Load("OFF.png");
on  = IMG_Load("ON.png");



leave = IMG_Load("leave.png");
leave1 = IMG_Load("leave1.png");
SDL_Surface* leaves[2] = {leave, leave1};
optionMenu = IMG_Load("menuOption.png");
volumeUp = IMG_Load("full sound.png");
volumeDown = IMG_Load("low sound.png");
mute       = IMG_Load("mute.png");



SDL_Rect positionMenu, fullScreenPos, positionLeave, positionVolumeUp, positionVolumeDown, positionMute, positionText;

positionMenu.x = 0;
positionMenu.y = 0;

fullScreenPos.x = 220;
fullScreenPos.y = 220;
fullScreenPos.h = on->h;
fullScreenPos.w = on->w;

positionVolumeUp.x = fullScreenPos.x-50;
positionVolumeUp.y = fullScreenPos.y-50;

positionVolumeDown.y = positionMute.y = positionVolumeUp.y;
positionVolumeDown.x = positionVolumeUp.x + 40;

positionMute.x = positionVolumeDown.x + 40;

positionVolumeDown.h = positionVolumeUp.h = positionMute.h = volumeUp->h;
positionVolumeDown.w = positionVolumeUp.w = positionMute.w = volumeUp->w;


positionLeave.x = 10;
positionLeave.y = 330;//screen->h - leave->h + 20;
positionLeave.h = leave->h;
positionLeave.w = leave->w;


SDL_Event e;
int vol;
int mouseX, mouseY;
while(menuActuel) {
	while(SDL_PollEvent(&e)){
		switch(e.type) {
			case SDL_KEYDOWN:{
				int key = e.key.keysym.sym;
				if(key == SDLK_ESCAPE) {
					printf("Main Main\n");
					*menuActuel = 0;
					return;
				}
			}	
			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&mouseX, &mouseY);
				if(sourisSur(fullScreenPos, mouseX, mouseY)) {
					opts->fullscreen = !opts->fullscreen;
					if(opts->fullscreen) 
						screen =SDL_SetVideoMode ( 400,400,32, SDL_FULLSCREEN) ;
					else  screen =SDL_SetVideoMode ( 400,400,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
				
					break;
				}
				if(sourisSur(positionLeave, mouseX, mouseY)) {
					*menuActuel = 0;
					return;
				}
				if(sourisSur(positionVolumeUp, mouseX, mouseY)) {
					if(opts->volume < 100){
						opts->volume+=10;
                                                	
                                                 }
				}
				if(sourisSur(positionVolumeDown, mouseX, mouseY)) {
					if(opts->volume > 0)
						opts->volume-=10;	
				}
				if(sourisSur(positionMute, mouseX, mouseY)) {
                                        
					if(opts->volume > 0 ){
                                              vol = opts->volume;
                                              opts->volume = 0;
                                }
                                        else opts->volume = vol;
				}
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&mouseX, &mouseY);
				if(sourisSur(positionLeave, mouseX, mouseY)) {
					leaveCourant = 1;
				} else leaveCourant = 0;
		}
	}
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0 ,0 ,0));
	Mix_VolumeMusic(opts->volume);
	SDL_BlitSurface(optionMenu, NULL, screen, &positionMenu);
	if(opts->fullscreen == 0) 
		SDL_BlitSurface(on, 0, screen, &fullScreenPos);
	else SDL_BlitSurface(off, 0, screen, &fullScreenPos);
	SDL_BlitSurface(leaves[leaveCourant], 0, screen, &positionLeave);
	SDL_BlitSurface(volumeUp, 0, screen, &positionVolumeUp);
	SDL_BlitSurface(volumeDown, 0, screen, &positionVolumeDown);
	SDL_BlitSurface(mute, 0, screen, &positionMute);
       	SDL_Flip(screen);
}
}



int main() {
int menuActuel = 0;
int jouerCourant =0;
int optionCourant = 0;
int leaveCourant = 0;
SDL_Surface *screen=NULL, *image=NULL, *jouer=NULL, *option=NULL, *texte, *jouer1, *option1, *leave, *leave1;
Mix_Chunk *effect;
effect = Mix_LoadWAV("click.wav");
optionMenu opts = {0, 20};
option = IMG_Load("option.png");
image = IMG_Load("background.png");
jouer = IMG_Load("play.png");
jouer1 = IMG_Load("play1.png");
option1 = IMG_Load("option1.png");
leave = IMG_Load("leave.png");
leave1 = IMG_Load("leave1.png");
SDL_Rect positionEcran, positionJouer, positionOption, positionMenu, positionText, positionLeave,positionplay;
SDL_Surface* jouerBouttons[2] = {jouer, jouer1};
SDL_Surface* optionBouttons[2] = {option, option1};
SDL_Surface* leaveBouttons[2] = {leave, leave1};
SDL_Event e;
int continuer = 1;

positionEcran.x = 0;
positionEcran.y = 0;

positionJouer.x = 120;
positionJouer.y = 15;
positionJouer.h = jouer->h;
positionJouer.w = jouer->w;

positionOption.x = 140;
positionOption.y = 100 ;
positionOption.h = option->h;
positionOption.w = option->w;

positionLeave.x = 10;
positionLeave.y = 330;
positionLeave.h = leave->h;
positionLeave.w = leave->w;
TTF_Init();
SDL_Init( SDL_INIT_VIDEO );

Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

TTF_Font *police = NULL;
police = TTF_OpenFont("angelina.TTF", 50);
SDL_Color couleurNoire = {0, 0, 0};
char text[20] = "go !!!";
texte = TTF_RenderText_Blended(police, text, couleurNoire);

positionText.x = 30;
positionText.y = 30;
Mix_Music *musique;
musique = Mix_LoadMUS("musique.mp3");
Mix_PlayMusic(musique, -1);

screen =SDL_SetVideoMode ( 400,400,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;

if(screen==NULL )
  {
   printf("Erreur : %s \n", SDL_GetError() );
   return 1 ;
  }
  int mouseX, mouseY;	
   while (continuer) {
	while(SDL_PollEvent(&e)) {
		switch(e.type) {
			case SDL_KEYDOWN:{
				int key = e.key.keysym.sym;
				if(key == SDLK_ESCAPE)
					continuer = 0;
				break;	
			}	
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&mouseX, &mouseY);
				if(sourisSur(positionJouer, mouseX, mouseY))
					jouerCourant = 1;
				else jouerCourant = 0;
				if(sourisSur(positionOption, mouseX, mouseY)) 
					optionCourant = 1;
                                        

				else optionCourant = 0;
				if(sourisSur(positionLeave, mouseX, mouseY)) 
					leaveCourant = 1;
				else leaveCourant = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(sourisSur(positionOption, mouseX, mouseY)) {
                                        Mix_PlayChannel(1, effect, 0);
					menuActuel = 1;
				}
				if(sourisSur(positionLeave, mouseX, mouseY)) 
					continuer = 0;
				break;
//************************************************************
			case SDL_MOUSEBUTTONDOWN:
				if(sourisSur(positionplay, mouseX, mouseY)) {
					
                                       
				}
				if(sourisSur(positionLeave, mouseX, mouseY)) 
					continuer = 0;
				break;
		}
	}
       
		if(menuActuel == 0) {
			SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0 ,0 ,0));
       			SDL_BlitSurface(image, NULL, screen, &positionEcran); /*Blit de fond */
       			SDL_BlitSurface(jouerBouttons[jouerCourant], NULL, screen, &positionJouer);
       			SDL_BlitSurface(optionBouttons[optionCourant], NULL, screen, &positionOption);
			SDL_BlitSurface(leaveBouttons[leaveCourant], NULL, screen ,&positionLeave);
			SDL_BlitSurface(texte, NULL, screen, &positionText);
       			SDL_Flip(screen);
		}
 
		else if (menuActuel == 1) afficherMenuOption(screen, &menuActuel, &opts);
   }



























































Mix_FreeMusic(musique);
Mix_FreeChunk(effect);
SDL_Quit();
TTF_CloseFont(police);
TTF_Quit();
return 0;
}
