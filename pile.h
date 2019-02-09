#ifndef PILE_H
#define PILE_H

void push(pile **p, double Val,int pX,int pY);

int length(pile *p);

void clear(pile **p);

void view(pile *p);

pile* getElementFormPosition(pile *p,int position);

#endif