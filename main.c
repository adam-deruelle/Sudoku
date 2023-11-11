#include <stdio.h>
#include <stdlib.h>

int possible(int grille[9][9], int ligne, int colonne, int valeur);
void chargerGrille(int grille[9][9]);
void afficherGrille(int grille[9][9]);
void saisir(int *valeur);

int main() {
    int grille1[9][9];
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
