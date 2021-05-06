
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
/** 
* @struct Personne 
* @brief struct for personne 
*/ 

typedef struct
{
	SDL_Rect position_perso;  /*!< Rectangle*/ 
	SDL_Surface *sprite;  /*!< Surface. */
} Personne;
/** 
* @struct minimap 
* @brief struct for minimap 
*/ 

typedef struct
{
	SDL_Rect position_mini; /*!< Rectangle*/ 
	SDL_Surface *sprite;      /*!< Surface. */ 
} minimap;
/** 
* @struct temps 
* @brief struct for temps 
*/ 

typedef struct temps
{
	SDL_Surface *texte;   /*!< Surface. */ 
	SDL_Rect position;  /*!< Rectangle*/ 

	TTF_Font *police;

	char entree[100];
	int secondesEcoulees;     
	SDL_Color couleurBlanche;   /*!< Color*/ 
	time_t t1, t2;
	int min, sec;
} temps;


//minimap
void initmap(minimap *m);   
void afficherminimap(minimap m, SDL_Surface *screen);
void free_minimap(minimap *m);
void majminimap (Personne *p, minimap *m ,SDL_Rect camera ,int redimensionnement);
//temps
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t, SDL_Surface *ecran);
//map
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP(Personne p, SDL_Surface *Masque);



