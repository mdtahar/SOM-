#ifndef NEURONE_H
#define NEURONE_H

neurone* allouer_neurone(int nbrPoint);
int nbrNeurone(int nbrVecteur);
grilleN* allouer_grille(int hauteur,int largeur,int nPoint);
grilleN* grille_neurone(int largeur,int hauteur,int nPoint,double* vm,double borneI,double borneS);
pile* bmu(data_vect** t,grilleN *g, int largeur, int hauteur, int nPoint,int posData);
double getAlpha(int iteration,int totalIteration, double alphaInit);
void voisinage(grilleN* n,double* vecteur,int largeur, int hauteur, int nPoint,pile* bmu,int rayon,double alpha);
void affichage(grilleN* n,int largeur,int hauteur);
void affichage_(grilleN* n,int largeur,int hauteur);
void apprentissage(grilleN* n,data_vect** t,int largeur,int hauteur,int nPoint,int nbV,int tirageMax);



#endif
