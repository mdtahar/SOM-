#include "structure.h"

data_vect* allouer_dataVect(){
	data_vect *vecteur = malloc(sizeof(data_vect));

	vecteur ->v = malloc(4*sizeof (double));
	vecteur ->nom = malloc(64*sizeof(char));
	// Gerer le cas ou y a erreur d'allocation 
	//////////////////////
	vecteur -> norme = 0;
	return vecteur;
}
void free_dataVect(data_vect *vecteur,int nb_champs){
	free(vecteur->nom);
	// for(int i=0;i<nb_champs;i++){
	// 	free((vecteur->v)[i]);
	// }
	free(vecteur->v);
	free(vecteur);
}

void afficher_v(data_vect *vecteur,int nb_champs){
	for(int i = 0;i <nb_champs;i++){
		printf("%f , ",(vecteur->v)[i] );
	}
	printf("%s  !!!! \n",vecteur->nom );
}
