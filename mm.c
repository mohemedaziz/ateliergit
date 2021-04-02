#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "mm.h"
void init(personnage* joueur,Imm* ecran,Imm* bg,Imm* curseur,Imm* mini_map)
{

ecran->srf=NULL;
   joueur->surface[0]=NULL;
   bg->srf=NULL;
   mini_map->srf=NULL;
   curseur->srf=NULL;
   mini_map->pos.x=0;
   mini_map->pos.y=0;
   curseur->pos.x=0;
   curseur->pos.y=5;
   bg->pos.x=0;
   bg->pos.y=0;

   joueur->position.x=0;
   joueur->position.y=340;

   joueur->nbr_vie=5;
 joueur->current_frame=0;
}

void load(personnage* joueur, Imm* bg,Imm* curseur,Imm* mini_map)
{
 bg->srf=IMG_Load("Unmasked lvl1.png");
 joueur->surface[0]=IMG_Load("mm1.png");
 mini_map->srf=IMG_Load("MM.png");
 curseur->srf=IMG_Load("curseur.png");

joueur->surface[1] = IMG_Load ("mm1.png");
joueur->surface[2] = IMG_Load("mm2.png");
joueur->surface[3] = IMG_Load("mm3.png");
joueur->surface[4] = IMG_Load("mm4.png");
joueur->surface[5] = IMG_Load("mm5.png");




}
int check_input(SDL_Event event, int* test,int done,Imm* ecran,personnage* joueur)
{ int i=0;
joueur->velocity=1;
joueur->acceleration=1;
while( SDL_PollEvent( &event )){
		switch( event.type ){
                    case SDL_QUIT:
		      done=1;
			break;
			case SDL_KEYUP:
				switch( event.key.keysym.sym ){
					case SDLK_SPACE:
                                      
					joueur->position.x+=50;
					joueur->position.y+=50;
                                         if (joueur->position.x>580 )
                                                joueur->position.x=580; 
                                       if( joueur->position.y<0 ||  joueur->position.y>640)
                                                joueur->position.y=350;
					break;
                                        
					case SDLK_d:
					(*test)=0; 
                                       joueur->current_frame=0;
                                          break;
                                        case SDLK_q:
					(*test)=0;
				       joueur->current_frame=8;
}
                                            break;

		    case SDL_MOUSEBUTTONUP:

			        if (event.button.button == SDL_BUTTON_RIGHT){
            			joueur->position.x = event.button.x;
           		        joueur->position.y = event.button.y;
           		        break;

				}else if(event.button.button == SDL_BUTTON_LEFT){
				joueur->position.x+=8;
				joueur->position.y-=20;
				}

			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){
					case SDLK_ESCAPE:
						done=1;
						break;

                                        

					case SDLK_d:
                                              
						joueur->position.x+=10;
                                                 (*test)=1;
                                            if (joueur->position.x>580)
                                           joueur->position.x=580;

						break;
					case SDLK_q:
						joueur->position.x-=10;
						(*test)=2;
                                       if(joueur->position.x<0)
                                               joueur->position.x=0;
                                              
						break;
					case SDLK_RIGHT:
						//(*test)=3;
                                                 joueur->velocity+=joueur->acceleration*2;
					         joueur->position.x+=joueur->velocity*(2*2*2)+joueur->velocity*2;
       						 //bg->camera.y+=((p->velocity*0.5*0.5*0.5)+p->velocity*0.5); 
						break;
					case SDLK_LEFT:
						//(*test)=3;
                                                 joueur->velocity+=joueur->acceleration*2;
					         joueur->position.x-=joueur->velocity*(2*2*2)+joueur->velocity*2;
       						 //bg->camera.y+=((p->velocity*0.5*0.5*0.5)+p->velocity*0.5); 
						break;	
					case SDLK_SPACE:
                                          if (joueur->position.x<580 )
						joueur->position.x+=50;
                                      if( joueur->position.y>=0 ||  joueur->position.y<640)
						joueur->position.y-=50;
                                          if (joueur->position.x>580 )
                                                joueur->position.x=580; 
                                       if( joueur->position.y<0 ||  joueur->position.y>640)
                                                joueur->position.y=340;
						break;		
				}
					break;
		}
	}
	return done;
}


void display(personnage* joueur,Imm* ecran ,Imm* bg ,int *test,Imm* curseur,Imm* mini_map )
{
int i=0;

   SDL_BlitSurface(bg->srf,NULL,ecran->srf,&bg->pos);
  SDL_BlitSurface(joueur->surface[joueur->current_frame],NULL,ecran->srf,&joueur->position);
  
  if(*test == 1){
         if(joueur->current_frame>7)
               joueur->current_frame=0;
    }

 if(*test == 2){ 
     if(joueur->current_frame<7) {
               joueur->current_frame=8;}
         if(joueur->current_frame>13){
                joueur->current_frame=8;} 
   }
     /*    for(i=1;i<7;i++){  
        
        SDL_BlitSurface(bg->srf,NULL,ecran->srf,&bg->pos);
            SDL_BlitSurface(joueur->surface[i],NULL,ecran->srf,&joueur->position);
      
         SDL_Flip(ecran->srf);
        SDL_Delay(100);
        
      }*/
	

/*if(*test == 2){
  for(i=8;i<14;i++){
             SDL_BlitSurface(bg->srf,NULL,ecran->srf,&bg->pos);
     SDL_BlitSurface(joueur->surface[i],NULL,ecran->srf,&joueur->position);
     	SDL_Flip(ecran->srf);
        SDL_Delay(100);

      }
    
} */
SDL_BlitSurface(mini_map->srf,NULL,ecran->srf,&mini_map->pos);
SDL_BlitSurface(curseur->srf,NULL,ecran->srf,&curseur->pos);
SDL_Flip(ecran->srf);

}


void save__perso(personnage *joueur,FILE *f,save_perso *save_p){

save_p->pos_x=joueur->position.x;
save_p->pos_y=joueur->position.y;

f=fopen("save_perso","w");

if (f==NULL){
printf ("erreur d'ouverture du fichier en mode r");}
fprintf(f, "%d\n %d\n",save_p->pos_x,save_p->pos_y);
fclose(f);
}


void load_perso (personnage *joueur,FILE *f,save_perso *save_p)
{
f=fopen("/LOG/file/save_perso","r");
if (f==NULL){
printf ("erreur d'ouverture du fichier en mode r");}
fscanf(f," %d\n %d\n",&save_p->pos_x,&save_p->pos_y);
fclose(f);

joueur->position.x=save_p->pos_x;
joueur->position.y=save_p->pos_y;
}
void mini_map(Imm * curseur ,personnage *perso){
	curseur->pos.x=(float)0.32*(perso->position.x);
	curseur->pos.y=(float)0.32*(perso->position.y);
}
