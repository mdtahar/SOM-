#include "structure.h"

void push(pile **p, double Val,int pX,int pY){

  pile *element = malloc(sizeof(pile));
  if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échouée. */
  element->valeur = Val;
  element->posX = pX;
  element->posY = pY;
  element->prec = *p;
  *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

int length(pile *p){
  int l=0;
  while(p){
    l++;
    p = p->prec;
  }
  return l;     
}
pile* getElementFormPosition(pile *p,int position){
  int compteur = 0;
  int posiY = 0;
  int posiX = 0;
  double val = 0.0;
  pile *element   = malloc(sizeof(pile));
  while (p) {
      if (compteur == position) {
          posiY = p->posY;
          posiX = p->posX;
          val = p->valeur;
      }
      compteur++;
      p = p->prec;
  }
  element->posX = posiX;
  // printf("%d ",posiX );
  element->posY = posiY;
  // printf("%d ",posiY );
  element->valeur = val;
  // printf("%f ",val );
  return element;
}

void clear(pile **p){
  pile *tmp;
  while(*p){
    tmp = (*p)->prec;
    free(*p);
    *p = tmp;
  }
}
// void view(pile *p)
// {
//   while(p)
//           {
//              printf("valeur : %f, poistionX : %d , positionY : %d  \n",p->valeur,p->posX,p->posY);
//              p = p->prec;
//           }
// }