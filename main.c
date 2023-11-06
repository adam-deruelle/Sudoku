#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tableau[[]];
}tGrille;


int main(){
    tGrille grille1[81];
    int numLigne, numColonne, valeur;
    chargerGrille(grille1);
    while (condition) {
        afficherGrille(grille1);
        ecrireEcran("Indices de la case ? ");
        saisir(numLigne);
        saisir(numColonne);
        if (grille1[numLigne][numColonne]!=0){
            ecrireEcran("IMPOSSIBLE, la case n'est pas libre.");
        }
        else {
            ecrireEcran("Valeur à insérer ? ");
            saisir(valeur);
            if (possible(grille1, numLigne, numColonne, valeur)){
                grille1[numLigne][numColonne] = valeur;
            }
        }
    }
    ecrireEcran("Grille pleine, fin de partie");
    return EXIT_SUCCESS;
}
