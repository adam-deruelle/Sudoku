/**
* \author Adam Deruelle
* \date 11 novembre 2023
*
* Ce programme permet de jouer au sudoku
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* \def NB_C
* \brief Nombre de carré.
*
* Nombre de carré présent dans la grille du sudoku
*/
#define NB_C 9
/**
* \def NB_L
* \brief Nombre de Ligne.
*
* Nombre de ligne présent dans un carré de la grille du sudoku
*/
#define NB_L 9


/**
* \typedef tGrille
* \brief Structure d'un tableau double
*
* Contient la grille du jeu
*/
typedef int tGrille[NB_C][NB_L];

bool possible(tGrille grille, int ligne, int colonne, int valeur);
void chargerGrille(tGrille g);
void afficherGrille(tGrille grille);
void saisir(int *valeur);

/**
* \fn int main()
* \brief Programme principal.
* \return Code de sortie du programme (0 : sortie normale).
* 
* Le programme principal permet de jouer
*/
int main() {
    tGrille grille1;
    int numLigne, numColonne, valeur;

    chargerGrille(grille1);

    while (1) {
        afficherGrille(grille1);

        // Saisie des indices de la case
        printf("Indices de la case ? ");
        saisir(&numLigne);
        saisir(&numColonne);
        numLigne -= 1;
        numColonne -= 1;
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

/**
* \fn int possible(tGrille grille, int ligne, int colonne, int valeur).
* \brief Fonction qui retourne VRAI si la case de la grille est vide
* \param grille : paramètre d'entrée qui représente la grille du jeu.
* \param ligne : paramètre d'entrée qui correspond au numéro de la ligne visée
* \param colonne : paramètre d'entrée qui correspond au numéro de la colonne visée
* \param valeur : paramètre d'entrée qui correspond a la valuer a inserer dans la grille
*
* Cette fonction vérifie si une valeur peut être ajoutée dans une case particulière de la grille,
* c’est à-dire si cela respecte les règles du sudoku.
*/
bool possible(tGrille grille, int ligne, int colonne, int valeur){
    int c; //Colonne
    int l; //Ligne
    int res;
    res = true;
    c = 0;
    l = 0;
    // la valeur n’est pas déjà présente sur la même ligne que la case
    while ((c < NB_C) && (res)){
        if (grille[ligne][c] == valeur){
            res = false;
            printf("Chiffre deja present sur la ligne");
        }
        c++;
    }
    
    // la valeur n’est pas déjà présente sur la même colonne que la case
    c = 0;
    l = 0;
    printf("%d", colonne);
    while ((l < NB_C) && (res)){
        if (grille[l][colonne] == valeur){
            res = false;
            printf("Chiffre deja present sur la colonne");
        }
        l++;
    }
    

    // la valeur n’est pas déjà présente dans le même bloc que la case
    c = 0;
    l = 0;
    int ligneDebut = (ligne / 3) * 3;
    int colonneDebut = (colonne / 3) * 3;
    while ((l < NB_L/3) && (res)){
        c = 0;
        while ((c < (NB_C/3)) && (res)){
            if (grille[ligneDebut + l][colonneDebut + c] == valeur){
                res = false;
                printf("Chiffre deja present dans le bloc");
            }
            c++;
        }
        l++;
    }

    return res;
}

/**
* \fn void chargerGrille(tGrille g)
* \brief Charge la grille selon le fichier rentré au clavier
* \param g : paramètre d'entrée/sortie qui correspond a la grille du jeu
*
* Elle permet de charger en mémoire une grille de
* sudoku existante à partir d’un fichier dont le nom est lu au clavier.
*/
void chargerGrille(tGrille g){
    char nomFichier[30];
    FILE * f;
    // printf("Nom du fichier ? ");
    // scanf("%s", nomFichier);
    f = fopen("grilles/Grille1.sud", "rb");
    if (f==NULL){
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    } else {
        fread(g, sizeof(int), NB_C * NB_L, f);
    }
    fclose(f);
}

/**
 * \fn void afficherGrille(tGrille grille)
 * \brief Cette procédure réalise l’affichage à l’écran de la grille et de son contenu
 * \param grille : La grille comportant la liste des entiers a afficher
 * 
 * Une case vide sera représentée par un point.
*/
void afficherGrille(tGrille grille){
    int c; //Carré
    int l; //Ligne
    printf("\n    1 2 3   4 5 6   7 8 9");
    printf("\n  +-------+-------+-------+\n");
    for (c = 0; c < NB_C; c++){
        if ((c == 3) || (c == 6)){
           printf("  +-------+-------+-------+\n"); 
        }
        printf("%d |", c+1);
        for (l = 0; l < NB_L; l++){
            if (grille[c][l] == 0){
                printf(" .");
            }else{
                printf(" %d",grille[c][l]);
            }
            if ((l == 2) || (l == 5)){
                printf(" |");
            }

        }
        printf(" |\n");
    }
    printf("  +-------+-------+-------+\n");
}

/**
 * \fn void saisir(int *valeur)
 * \brief Cette procédure est chargée de lire au clavier une valeur.
 * \param valeur : paramétre de sortie qui correspond a la variable où sera stocké la valeur
 *
 * Cette procédure est chargée de lire au clavier une valeur.
 *  La saisie se répète tant que la valeur n’est pas valide.
 *  En effet, la valeur lue doit être un entier,
 *  et cet entier doit être compris entre 1 et n²
*/
void saisir(int *valeur){
    scanf("%d", valeur);
}