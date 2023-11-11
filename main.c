#include <stdio.h>
#include <stdlib.h>

typedef struct{

}tGrille;

const int TAILLE = 0;

int possible(tGrille grille, int ligne, int colonne, int valeur);
void chargerGrille(tGrille g);
void afficherGrille(tGrille grille);
void saisir(int *valeur);

int main() {
    tGrille grille1;
    int numLigne, numColonne, valeur;

    chargerGrille(grille1);

    while (!grillePleine(grille1)) {
        afficherGrille(grille1);

        // Saisie des indices de la case
        printf("Indices de la case ? ");
        saisir(&numLigne);
        saisir(&numColonne);

        // Vérification si la case est libre
        if (grille1[numLigne][numColonne] != 0) {
            printf("IMPOSSIBLE, la case n'est pas libre.\n");
        } else {
            // Saisie de la valeur à insérer
            saisir(&valeur);

            // Vérification de la validité de la valeur
            if (possible(grille1, numLigne, numColonne, valeur)) {
                grille1[numLigne][numColonne] = valeur;
            }
        }
    }

    printf("Grille pleine, fin de partie\n");

    return EXIT_SUCCESS;
}

int possible(tGrille grille, int ligne, int colonne, int valeur){

}

void chargerGrille(tGrille g){
    char nomFichier[30];
    FILE * f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f==NULL){
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    } else {
        fread(g, sizeof(int), TAILLE*TAILLE, f);
    }
    fclose(f);
}

void afficherGrille(tGrille grille){

}

void saisir(int *valeur){

}