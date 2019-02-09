#ifndef VECTEUR_H
#define VECTEUR_H
data_vect* allouer_dataVect();
void free_dataVect(data_vect *vecteur,int nb_champs);
void afficher_v(data_vect *vecteur,int nb_champs);

#endif