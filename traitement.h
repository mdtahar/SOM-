#ifndef TRAITEMENT_H
#define TRAITEMENT_H
double calculNorme(double* v,int taille);
data_vect** traitement(char* nom_fichier);
data_vect** normaliser_vec(data_vect** d,int taille);
double* vecteur_moyen(data_vect **tab_vec);
double distance_euclidien(double* a,double* b,int taille);
double nombre_aleatoire(double borneI,double borneS);
int* tableau_sans_doublons(int taille);
void melanger_tableau(int* tableau,int taille);
double min(double a,double b);

#endif