#include "structure.h"
#include "vecteur.h"

double calculNorme(double* v,int taille){
	double resultat = 0.0;
	for (int i=0;i<taille;i++){
		resultat += pow(v[i],2);
	}
	return sqrt(resultat);
}

data_vect** traitement(char* nom_fichier){
	printf("--------recuperation et stockage----------\n");
	FILE* fichier;
	char *s;
	if((fichier = fopen(nom_fichier,"r")) == NULL){
		perror("erreur ouverture fichier ");
		exit(1);
	}
	else{
		data_vect** tab_vec = malloc(150*sizeof(data_vect*));
		char *buf = malloc(1024*sizeof(char));
		int ligne = 0;
		while(fgets(buf,1024,fichier)!=NULL){
			tab_vec[ligne]= allouer_dataVect();
			int compteur = 1;
			s = strtok(buf,",");
			tab_vec[ligne]->v[0] = atof(s);
			// printf("%f  \n", tab_vec[ligne]->v[0]);
			while(s != NULL){
				s = strtok(NULL,",");
				if(compteur<4){
					tab_vec[ligne]->v[compteur] = atof(s);
					compteur++;
				}
				else {
					char *nameToCpy = strtok(s,"\n");
					strcpy(tab_vec[ligne]->nom,nameToCpy);
					// printf("%s   %d  \n",tab_vec[ligne]->nom,ligne );
					tab_vec[ligne]->norme = calculNorme(tab_vec[ligne]->v,4);
					break;
				}
			}
			// printf("là  son BIS nom est : %s ",tab_vec[ligne]->nom );
			// printf("là norme est : %f \n",tab_vec[ligne]->norme);
			ligne++;
		}
		// free(buf);
		// fclose(fichier);
		return tab_vec;
	}
}
data_vect** normaliser_vec(data_vect** d,int taille){
	printf("---------------- Normalisation ------------\n");
	data_vect** vNormaliser = malloc(taille*sizeof(data_vect*));
	for(int l=0;l<taille;l++){
		vNormaliser[l] = allouer_dataVect();
		for(int c=0;c<4;c++){
			vNormaliser[l]->v[c] = d[l]->v[c]/d[l]->norme;
		}
		strcpy(vNormaliser[l]->nom,d[l]->nom);
		vNormaliser[l]->norme = d[l]->norme;
		// printf("%f , %f , %f , %f  VN %s \n",vNormaliser[l]->v[0],vNormaliser[l]->v[1],vNormaliser[l]->v[2],vNormaliser[l]->v[3],vNormaliser[l]->nom );
	}
	return vNormaliser;
}
double* vecteur_moyen(data_vect **tab_vec){
	printf("------------ vecteur moyen -------------\n");
	double *vecteur_moyen = malloc(4*sizeof(double));
	int c = 0;
	while(c != 4)  {
		for(int l=0;l<150;l++){
			vecteur_moyen[c] += tab_vec[l]->v[c];
			// printf("M ---- ici%d . %f \n",l, vecteur_moyen[c]);
		}
		vecteur_moyen[c] = vecteur_moyen[c]/150;
		c++;
	}
//    printf("M ---- %f \n", vecteur_moyen[0]);
//     printf("M ---- %f \n", vecteur_moyen[1]);
//     printf("M ---- %f \n", vecteur_moyen[2]);
//     printf("M ---- %f \n", vecteur_moyen[3]);
	return vecteur_moyen;
}
double distance_euclidien(double* v1,double* v2,int taille){
	double resultat = 0.0;
	for(int i=0;i<taille;i++){
		resultat+=pow(v1[i]-v2[i],2);
	}
	return sqrt(resultat);
}
double nombre_aleatoire(double borneI,double borneS){
	return (borneS-borneI) * ((((double) rand())/(double)RAND_MAX)) + borneI;
}
double min(double a,double b){
	if(a>b){
		return b;
	}
	else
		return a;
}
int* tableau_sans_doublons(int taille){
	int * resultat = malloc(taille*(sizeof(int)));
	for(int i=0;i<taille;i++){
		resultat[i]=i;
	}
	return resultat;
}
void melanger_tableau(int* tableau,int taille){
	int nombre_tire = 0;
	int temp = 0;
	srand(time(0));
	for(int i=0;i<taille;i++){
		nombre_tire=rand()%taille;
		temp=tableau[i];
		tableau[i]=tableau[nombre_tire];
		tableau[nombre_tire]=temp;
		// printf("%d ",tableau[i] );
	}
	// printf("\n");
}

