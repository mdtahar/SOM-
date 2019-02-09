#include "structure.h"
#include "vecteur.h"
#include "traitement.h"
#include "pile.h"
#include "neurone.h"

int main(int argc, char const *argv[])
{
	int largeur = 6;
	int hauteur = 10;
	int nbrPoint = 4;
	int nbrVecteur = 150;
	
	int nbNeuron = nbrNeurone(nbrVecteur);
	data_vect** v = traitement("test.txt");
	data_vect** vn = normaliser_vec(v,nbrVecteur);
	double* vecMoyen = vecteur_moyen(vn);
	

	grilleN *g = grille_neurone(largeur,hauteur,nbrPoint,vecMoyen,0.04,0.02);
	

	apprentissage(g,vn,largeur,hauteur,nbrPoint,nbrVecteur,nbNeuron);

	
	return 0;
}