#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct  data_vect
{
	double *v;
	char* nom;
	double norme; 

}data_vect;

typedef struct neurone{
	double *v;
	double distance;
	char *nom;
}neurone;

typedef struct grilleN{
	neurone **neurone;
}grilleN;

typedef struct pile{
	double valeur;
	int posX;
	int posY;
	struct pile *prec;
}pile;

#endif