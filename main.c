#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "func.h"
/** 
* @file main.c 
* @brief lot4. 
* @author bechir
* @version 0.1 
* @date Apr 23,2021  
* 
* lot4 program * 
*/

int main()
{
    int collision, distance = 100;
    SDL_Event event;
    minimap m;
    Personne p, pM, pMprochaine;
    temps t;
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *masked = NULL,*chiffres[30];
    SDL_Rect position_BG, position_chiffres , position_camera;
    int longueurM = 8000, largeurM = 800, longueur = 800, largeur = 80, i = 0;
    int redimensionnement =  distance * longueur / longueurM;
    ecran = SDL_SetVideoMode(1000, 800, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    TTF_Init();
    if (ecran == NULL)
    {
        printf("ERREUR: %s\n", SDL_GetError());
        return 1;
    }

    position_BG.x = 0;
    position_BG.y = 0;

    imageDeFond = IMG_Load("map.png");
    int continuer = 1;
    initmap(&m);
    initialiser_temps(&t);
    
    masked = IMG_Load("mask.png");

    p.sprite = IMG_Load("mm1.png");
    p.position_perso.x = 0;
    p.position_perso.y = 170;

    pM.sprite = IMG_Load("A.png");
    pM.position_perso.x = 0;
    pM.position_perso.y = 550; 

    pMprochaine.position_perso.x = pM.position_perso.x;
    pMprochaine.position_perso.y = pM.position_perso.y;

   

    while (continuer)
    {

        SDL_BlitSurface(imageDeFond, NULL, ecran, &position_BG);
        afficherminimap(m, ecran);
        SDL_BlitSurface(p.sprite, NULL, ecran, &p.position_perso);
        SDL_BlitSurface(pM.sprite, NULL, ecran, &pM.position_perso);
        afficher_temps(&t, ecran);

        //mapCollision(Hero *entity);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                case SDLK_RIGHT:
                    pMprochaine.position_perso.x += distance;
                    if (collisionPP(pMprochaine, masked) == 0)
                    { position_camera.x=0;
 
                        pM.position_perso.x = pMprochaine.position_perso.x;
                        
                        majminimap(&p,&m,position_camera,redimensionnement);
                    }
                    else
                    {  if (i==13)
                          i=0; 
                        i++;
                        pMprochaine.position_perso.x = pM.position_perso.x;
                        SDL_BlitSurface(chiffres[i], NULL, ecran, &pM.position_perso);
                        SDL_Delay(300);
                    }
                    break;

                case SDLK_LEFT:
                    pMprochaine.position_perso.x -= distance;
                    if (collisionPP(pMprochaine, masked) == 0)
                    {   position_camera.x=1;
                        pM.position_perso.x = pMprochaine.position_perso.x;
                        majminimap(&p,&m,position_camera,redimensionnement);
                    }
                    else
                    {  if (i==13)
                          i=0;
                        i++;
                        pMprochaine.position_perso.x = pM.position_perso.x;
                        SDL_BlitSurface(chiffres[i], NULL, ecran, &pM.position_perso);
                        SDL_Delay(300);
                    }
                break;


                    case SDLK_DOWN:
                    pMprochaine.position_perso.y += distance;
                    if (collisionPP(pMprochaine, masked) == 0)
                    {
                        position_camera.x=2;
                        pM.position_perso.y = pMprochaine.position_perso.y;
                        majminimap(&p,&m,position_camera,redimensionnement);
                    }
                    else
                    {  if (i==13)
                          i=0;
                        i++;
                        pMprochaine.position_perso.y = pM.position_perso.y;
                        SDL_BlitSurface(chiffres[i], NULL, ecran, &pM.position_perso);
                        SDL_Delay(300);
                    }
                    break;



                case SDLK_UP:
                    pMprochaine.position_perso.y -= distance;
                    if (collisionPP(pMprochaine, masked) == 0)
                    {   position_camera.x=3;
                        pM.position_perso.y = pMprochaine.position_perso.y;
                        majminimap(&p,&m,position_camera,redimensionnement);
                    }
                    else
                    {   if (i==13)
                          i=0;
                        i++;
                        pMprochaine.position_perso.y = pM.position_perso.y;
                        SDL_BlitSurface(chiffres[i], NULL, ecran, &pM.position_perso);
                        SDL_Delay(300);
                    }

                    break;

                case SDLK_p:
                    imageDeFond = IMG_Load("map1mask.png");
                    break;
                case SDLK_o:
                  imageDeFond = IMG_Load("map1.png");

                }
                
            }
        }
        SDL_Flip(ecran);
    }
    free_minimap(&m);
    SDL_FreeSurface(p.sprite);

 

    free_temps(&t, ecran);
    SDL_FreeSurface(ecran);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}

