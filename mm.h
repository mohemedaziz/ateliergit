#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED


typedef struct 
{
  SDL_Surface* surface[15];
  SDL_Rect position;
  int nbr_vie;
  int current_frame;
float velocity;
float acceleration;
}personnage;
typedef struct{
int pos_x;
int pos_y;
}save_perso;
typedef struct
{
 Uint32 start;
Uint32 end;
Uint32 diff;
}timer;

typedef struct 
{ 
  SDL_Surface* srf;
  SDL_Rect pos;
}Imm; 


void init(personnage* joueur,Imm* ecran,Imm* bg,Imm* curseur,Imm* mini_map);
void load(personnage* joueur, Imm* bg,Imm* curseur,Imm* mini_map);
int check_input(SDL_Event event, int* test,int done,Imm* ecran,personnage* joueur);
void display(personnage* joueur,Imm* ecran ,Imm * bg ,int *test,Imm* curseur,Imm* mini_map );
void save__perso(personnage *joueur,FILE *f,save_perso *save_p);
void mini_map(Imm * curseur ,personnage *perso);
#endif // HEADERNAME_H_INCLUDED0
