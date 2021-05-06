#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeux.h"
#include <time.h>

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
/** 
* @brief To initialize the minimap m . 
* @param m the minimap 
* @return Nothing 
*/ 

void initmap(minimap *m)
{
    m->position_mini.x = 0;
    m->position_mini.y = 0;
    m->sprite = NULL;
    m->sprite = IMG_Load("mini.png");
}

/** 
* @brief To show the minimap m . 
* @param ecran the screen 
* @param m the minimap 
* @return Nothing 
*/ 

void afficherminimap(minimap m, SDL_Surface *ecran)
{

    SDL_BlitSurface(m.sprite, NULL, ecran, &m.position_mini);
}

/** 
* @brief liberation .  
* @param m the minimap 
* @return Nothing 
*/ 
void free_minimap(minimap *m)
{
    SDL_FreeSurface(m->sprite);
}

/** 
* @brief To initialize the time. 
* @param t the time 
* @return Nothing 
*/ 
void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x = 850;
    t->position.y = 50;
    t->police = NULL;
    t->police = TTF_OpenFont("digital-7.ttf", 40);
    strcpy(t->entree, "");
    (t->secondesEcoulees) = 0;
    time(&(t->t1)); //temps du debut
}

/** 
* @brief To show the time . 
* @param ecran the screen 
* @param t the time 
* @return Nothing 
*/ 
void afficher_temps(temps *t, SDL_Surface *ecran)
{
    SDL_Color couleurnoir = {0, 0, 0};
    
    time(&(t->t2)); // temps actuel

    t->secondesEcoulees = t->t2 - t->t1;

    t->min = ((t->secondesEcoulees / 60) % 60);
    t->sec = ((t->secondesEcoulees) % 60);
    int millisecondes=SDL_GetTicks()%60;
    
    sprintf(t->entree, "%02d:%02d:%02d", t->min, t->sec, millisecondes);    

    t->texte = TTF_RenderText_Blended(t->police, t->entree, couleurnoir);

    SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 
}

/** 
* @brief liberation . 
* @param ecran the screen 
* @param t the time 
* @return Nothing 
*/ 
void free_temps(temps *t, SDL_Surface *ecran)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)    
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position

    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}

int collisionPP(Personne p, SDL_Surface *Masque)
{
    SDL_Color test, couleurnoir = {0, 0, 0};

    SDL_Rect pos[8];
 
    pos[0].x = p.position_perso.x;
    pos[0].y = p.position_perso.y;
    pos[1].x = p.position_perso.x + p.position_perso.w / 2;
    pos[1].y = p.position_perso.y;
    pos[2].x = p.position_perso.x + p.position_perso.w;
    pos[2].y = p.position_perso.y;
    pos[3].x = p.position_perso.x;
    pos[3].y = p.position_perso.y + p.position_perso.h / 2;
    pos[4].x = p.position_perso.x;
    pos[4].y = p.position_perso.y + p.position_perso.h;
    pos[5].x = p.position_perso.x + p.position_perso.w / 2;
    pos[5].y = p.position_perso.y + p.position_perso.h;
    pos[6].x = p.position_perso.x + p.position_perso.w;
    pos[6].y = p.position_perso.y + p.position_perso.h;
    pos[7].x = p.position_perso.x + p.position_perso.w;
    pos[7].y = p.position_perso.y + p.position_perso.h / 2;
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)  
    {
        x = pos[i].x;
        y = pos[i].y;
        test = GetPixel(Masque, x, y);
        if (test.r == 0 && test.g == 0 && test.b == 0)
            collision = 1;
    }
    return collision;
}

/** 
* @param p the person
* @param camera the camera 
* @param m the minimap 
* @return Nothing 
*/ 
void majminimap (Personne *p, minimap *m ,SDL_Rect camera ,int redimensionnement){      
  if (camera.x==0)
  p->position_perso.x += redimensionnement;

  if (camera.x==1)
  p->position_perso.x -= redimensionnement;

  if (camera.x==2)
  p->position_perso.y += redimensionnement;

  if (camera.x==3)
  p->position_perso.y -= redimensionnement;

}









