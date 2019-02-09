#include "structure.h"
#include "vecteur.h"
#include "traitement.h"
#include "pile.h"
neurone* allouer_neurone(int nbrPoint){

	neurone *n = malloc(sizeof(neurone));
	n->v = malloc(nbrPoint*sizeof(double));
	// n->distance = 0; 
	n->nom = malloc(64*sizeof(char));

	return n;
}
int nbrNeurone(int nbrVecteur){
	return 5*(int)sqrt(nbrVecteur);
}
// neurone** tab_neurone(double* vecteur,int nbrVecteur,double borneS,double borneI){
// 	printf("--------------Tableau neurone ---------------\n");
// 	int nPoint = 4;
// 	int nbrN = nbrNeurone(nbrVecteur);
// 	neurone** tab_neurone = malloc(nbrN*sizeof(neurone*));
// 	neurone* neurone = allouer_neurone(nPoint);
// 	srand(time(0));
// 	for (int l = 0;l<nbrN;l++){
// 		for(int i = 0;i<nPoint;i++){
// 			neurone->v[i]=nombre_aleatoire(vecteur[i]-borneI,vecteur[i]+borneS);
// 		}
// 		tab_neurone[l] = neurone;
// 		// printf("%f , %f , %f , %f \n",tab_neurone[l]->v[0],tab_neurone[l]->v[1],tab_neurone[l]->v[2],tab_neurone[l]->v[3] );
// 	}
// 	return tab_neurone;
// }
grilleN* allouer_grille(int hauteur,int largeur,int nPoint){
	grilleN *grille = malloc(sizeof(grilleN));

	grille->neurone = malloc(hauteur*sizeof(neurone*));
	if(grille->neurone !=NULL){

		for(int i=0;i<hauteur;i++){
			grille->neurone[i] = (neurone *)malloc(largeur*sizeof(neurone));
		}

		for (int i = 0 ;i < hauteur ; i++) {
            for (int j = 0; j < largeur; j++) { 
                // grille->neurone[i][j] = malloc(sizeof(neurone));
                grille->neurone[i][j].v =  malloc(nPoint*(sizeof(double)));
                grille->neurone[i][j].nom = malloc(64*sizeof(char));

            }
        }
	}
	return grille;

}
grilleN* grille_neurone(int largeur,int hauteur,int nPoint,double* vm,double borneI,double borneS){
	printf("--------------- MATRICE DE NEURONES ----------------\n");
	grilleN *grille = allouer_grille(hauteur,largeur,nPoint); //
	srand(time(0));

	for(int i=0;i<hauteur;i++){ //
		for(int j=0;j<largeur;j++){
			for(int k=0;k<nPoint;k++){
				grille->neurone[i][j].v[k] = nombre_aleatoire(vm[k]-borneI,vm[k]+borneS);
				// grille->neurone[i][j].nom = ". " ;
				// printf("%f ", grille->neurone[i][j].v[k]);
			}
		}
	}
	return grille;
}
pile* bmu(data_vect** t,grilleN *g, int largeur, int hauteur, int nPoint,int posData){
	pile* bm = NULL;
	double distance_min = 999.99;    // ON PEUT AUSSI METTRRE A LA PREMIERE CASE DE LA MATRICE . 
	double tmpDistance = 0.0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){

			tmpDistance = distance_euclidien(g->neurone[i][j].v,t[posData]->v,nPoint);

			if(distance_min == tmpDistance){
				push(&bm,distance_min,i,j);
			}
			else if(tmpDistance < distance_min){
				distance_min = tmpDistance;
				clear(&bm);
				push(&bm,distance_min,i,j);
			}

		}

	}

	// if(length(bm)>1){

	// 	int posAl = (int)(rand()%length(bm));
	// 	printf("length %d , %d posAl\n",length(bm),posAl );
	// 	printf("apress ssss\n");
	// 	return getElementFormPosition(bm,posAl);
		
	// }

	// else {
	// 	printf("apres s\n");	
	// 	return bm;

	// }
	return bm;
}
double getAlpha(int iteration,int totalIteration, double alphaInit){
	return alphaInit * (double)(1.0-(double)iteration/(double)totalIteration);
}
int rayon(int taille,int pourcentage){
	int rayonMax = (taille*pourcentage)/100;
	int voisinMin = 8;
	int rayon = 0;
	int r = (rayon*voisinMin);
    while(r < rayonMax) {
    	r += (rayon * voisinMin);
    	if(r < rayonMax) rayon++;
    	// printf("%d \n",rayon );
    }
    // if(rayon == 0 ) {
    // 	rayon = 1;
    // } 
    rayon = (rayon == 0) ? 1 : rayon;
    // printf("Rayon : %d \n",rayon );
    return rayon;
}
void voisinage(grilleN* n,double* vecteur,int largeur, int hauteur, int nPoint,pile* bmu,int rayon,double alpha){
	int xInf,yInf,xSup,ySup;
	xInf = bmu->posX-rayon; 
	if(xInf<0){
    	xInf = 0;
    }
    yInf = bmu->posY-rayon;
    if(yInf<0){
    	yInf = 0;
    } 
    xSup = bmu->posX+rayon; 
    if(xSup>=hauteur){
    	// xSup = largeur;
    	xSup = hauteur-1;
    }
    ySup = bmu->posY+rayon;
    if(ySup>=largeur){
    	// ySup = hauteur;
    	ySup = largeur-1;
    }
    // printf("X %d : %d , %d \n",bmu->posX,xInf, xSup );
    // printf("Y %d : %d , %d \n",bmu->posY,yInf, ySup );
    for(int x=xInf;x<=xSup;x++){
    	for(int y=yInf;y<=ySup;y++){
    		for(int i=0;i<nPoint;i++){
    			n->neurone[x][y].v[i] += alpha * (vecteur[i] - n->neurone[x][y].v[i]);
    			

    		}
    	}
    }
}
void affichage(grilleN* n,int largeur,int hauteur){
	for(int i = 0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(strcmp("Iris-virginica",n->neurone[i][j].nom) == 0){
				printf("S ");  
			}
			else if(strcmp("Iris-setosa",n->neurone[i][j].nom) == 0){
				printf("O ");  
			}
			else if(strcmp("Iris-versicolor",n->neurone[i][j].nom) == 0){
				printf("M ");  
			}
			else {
				printf(". ");
			}
		}
		printf("\n");
	}
}
void affichage_(grilleN* n,int largeur,int hauteur){
	for(int i = 0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			printf("%s",n->neurone[i][j].nom );
		}
		printf("\n");
	}
}
void apprentissage(grilleN* n,data_vect** t,int largeur,int hauteur,int nPoint,int nbV,int tirageMax){

	int *tab = tableau_sans_doublons(nbV);
	int rayon_ = rayon(tirageMax,50);
	int nbIterTotal = (500 * nbV) * 0.5;
	int phase = nbIterTotal * 0.25;
    double alpha            = 0.0;
    double alpha_init       = 0.7;

    printf("Début \n");
    affichage(n,largeur,hauteur);
    printf("\n");

    for(int i=0;i<nbIterTotal;i++){
    	melanger_tableau(tab,nbV);

    	if(i<=phase){
    		if(rayon_>1){
    			if(i==(phase*1/3)){
    				rayon_--;
    			}
    			else if(i==(phase*2/3)){
    				rayon_--;
    			}
    		}
    		alpha = getAlpha(i,phase,alpha_init);
    	}

    	else {
    		alpha = getAlpha(i,nbIterTotal,alpha_init)*0.1;
    		rayon_ = 1;
    	}

    	pile* b = NULL;
    	for(int j=0;j<nbV;j++){

    		b = bmu(t,n,largeur,hauteur,nPoint,tab[j]);
    		n->neurone[b->posX][b->posY].nom = t[tab[j]]->nom;
    		// strcpy(n->neurone[b->posX][b->posY]->nom,t[tab[j]]->nom);
    		voisinage(n,t[tab[j]]->v,largeur,hauteur,nPoint,b,rayon_,alpha);
    		clear(&b);
    	}
    	if(i == 0){
    		printf("Premiére étape : \n");
    		affichage(n,largeur,hauteur);
    		printf("\n");
    	}
    	if(i+1 == 12500){
    		printf("---------------------- \n" );
    		affichage(n,largeur,hauteur);
    		printf("\n");

    	}
    	
    	if(i== nbIterTotal-1){
    		system("clear");
    	
    		printf("Résultat final : \n");
    		affichage(n,largeur,hauteur);
    		printf("\n");

    		printf("Pour Iris-virginica la lettre est : S \n");
    		printf("Pour Iris-setosa la lettre est : O \n" );
    		printf("Pour Iris-versicolor la lettre est : M \n" );
    		printf("\n");
    	}
    }
}
void afficherV(data_vect** v){
	for(int i =0;i<150;i++){
		printf("%s   %d ",v[i]->nom,i );
	}
	printf("\n" );
}
