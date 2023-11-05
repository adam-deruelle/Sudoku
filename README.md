# Sudoku
Programme Principal
===================
```
programme sudoku c'est

//Fonctions
fonction selectionnerGrilleDep() délivre tableau de entier;
fonction genererGrille(entF grilleDep[]: tableau de entier) délivre tableau de entier;
fonction demanderChiffre() délivre entier;
fonction convertirCarEntier(entF lettre: caractère) délivre entier;
fonction verifierEntreeUtilCase(entF coordX: caractère, entF coordY: entier) délivre booléen;
fonction verifierEntreeUtilChiffre(entF chiffreUtil: entier) délivre booléen;

//Procédures
procédure afficherRegles();
procédure afficherGrille(entF tabChiffres[]: tableau de entier);
procédure demanderCase(sortF x: entier, sortF y: entier);
procédure placerChiffre(entF x: entier, entF y: entier, entF chiffreUtil: entier, entF/sortF tabChiffres[]: tableau de entier);
procédure verifierVictoire(entF tabChiffres[]: tableau de entier, sortF victoire : victoire);
procédure finDePartie(entF: entier x, sortF rejouer: booléen);
procédure afficherSeparationLigne();
procédure afficherSeparationCarre();
procédure afficherligne();
procédure afficherEntete();
procédure verifierGrille(entF tabChiffres[]: tableau de entier, entF chiffreUtil: entier);
procédure verifierLigne(entF ligne[]: tableau de entier, entF chiffreUtil: entier, sortF estPresent: booléen);
procédure verifierColonne(entF colonne[]: tableau de entier, entF chiffreUtil: entier, sortF estPresent: booléen);
procédure verifierVictoire(entF tabChiffres[]: tableau de entier, sortF victoire: booléen);

// Constantes
constante entier TAILLE := 81;
constante entier RECO := -1; // si case est -1 alors recommencer
constante entier QUIT := 0;
constante chaine CHEMIN[10] := "./grilles";
constante entier REJOUER = 1;

début
    // Variables
    grilleDep: tableau[TAILLE] de entier; // La grille de départ choisit parmis les fichiers
    tabChiffres: tableau[TAILLE] de entier; // La grille avec les chiffres
    x, y: entier; // Les coordonées que l'utilisateur a rentrées en converties entier
    chiffreUtil: entier; // Chiffre que veut placer l'utilisateur
    victoire: booléen;
    rejouer: booléen;
    // Initialisation
    victoire := faux;
    rejouer := vrai;
    // Boucle principale
    tant que (rejouer) faire
        grilleDep := selectionnerGrilleDep()
        afficherRegles();
        tabChiffres := genererGrille(grilleDep);
        tant que ((victoire == faux) ET (x != QUIT) ET (x != RECO)) faire
            afficherGrille(entE tabChiffres);
            demanderCase(sortE x, sortE y);
            si (x != QUIT) alors
                chiffreUtil := demanderChiffre();
                placerChiffre(entE x, entE: y, entE chiffreUtil, entE/sortE tabChiffres[]);
                verifierVictoire(entE tabChiffres[], sortE victoire);
            finsi
        finfaire

        finDePartie(entE x, sortE rejouer);
    finfaire
fin
```


Liste des Procédures et Fonctions
=================================

Affichage
---------

**Procédure** : **_afficherRegles_**  
Affiche les régles du jeu.

**Paramètres** :  
Aucun

--------
**Procédure** : **_finDePartie_**  
Verifie les conditions de fin de partie et affiche le message correspondant

**Paramètres** :
_x_ (Entrée) : entier, emplacement de la case sur l'axe x     
_rejouer_ : booléen, indique si l'utilisateur souhaite rejouer

--------
**Procédure** : **_afficherGrille_**   
Affiche la grille du jeu.

**Paramètres** :  
_tabChiffres_ (Entrée) : tableau d'entiers, tableau contenant les chiffres de la grille.

--------   
**Procédure** : **_afficherSeparationLigne_**  
Permet d'afficher la séparation entre chaque ligne de la grille

**Paramètres** :  
Aucun

--------
**Procédure** : **_afficherSeparationCarre_**  
Affiche la ligne de séparation des carrés

**Paramètres** :  
Aucun

--------
**Procédure** : **_afficherligne_**  
Affiche la ligne avec les chiffres et cases vides

**Paramètres** :  
Aucun

--------
**Procédure** : **_afficherEntete_**   
Affiche les lettres permettant a l'itilsateur de savoir où jouer

**Paramètres** :  
Aucun

--------

Actions sur la grille
=====================  

**Fonction** : **_selectionnerGrilleDep_**  
Selectionne une grille parmis celle proposer dans les consignes

**Paramètres** :  
Aucun

**Résultat** :  
Tableau d'entiers, grille avec uniquement 

--------

**Fonction** : **_genererGrille_**  
Genere une grille de chiffres avec des zéros pour les cases vides

**Paramètres**
_grilleDep_ (Entrée) : tableau d'entier

**Résultat** :  
Tableau d'entiers, grille de départ

--------

**Procédure** : **_placerChiffre_**  
Place le chiffre dans la grille

**Paramètres** :  
_x_ (Entrée) : entier, emplacement de la case sur l'axe x  
_y_ (Entrée) : entier, emplacement de la case sur l'axe y  
_chiffreUtil_ (Entrée) : entier, chiffre que l'utilisateur veut rentrer
_tabChiffres_ (Entrée/Sortie) : tableau d'entiers, la grille

--------

**Procédure** : **_verifierGrille_**  
Verifie si le chiffre n'est pas dans la grille  

**Paramètres** :  
_tabChiffres_ (Entrée) : tableau d'entiers, la grille  
_chiffreUtil_ (Entrée): entier, l'entrée de l'utilisateur  

--------

**Procédure** : **_verifierLigne_**  
Vérifie si le chiffre de l'utilisateur est déja présent dans la ligne

**Paramètres** :  
_ligne_ (Entrée) : tableau d'entiers, la ligne où va être placé le chiffre  
_chiffreUtil_ : entier, l'entrée de l'utilisateur   
_estPresent_ (Sortie) : booléen, indique si le chiffre est présent  

--------

**Procédure** : **_verifierColonne_**  
Vérifie si le chiffre de l'utilisateur est déja présent dans la colonne

**Paramètres** :  
_colonne_ (Entrée) : tableau d'entiers, la colonne où va être placé le chiffre  
_chiffreUtil_ : entier, l'entrée de l'utilisateur   
_estPresent_ (Sortie) : booléen, indique si le chiffre est présent  

--------

**Procédure** : **_verifierVictoire_**  
Verifie si chaque cases est remplie

**Paramètres** :  
_tabChiffres_ (Entrée) : tableau d'entiers, la grille  
_victoire_ (Sortie) : booléen, indique la victoire   

--------

Interactions utilisateur
========================

**Procédure** : **_demanderCase_**  
Demande la case a l'utilsateur sous la forme A1 et retourne deux entiers

**Paramètres** :  
_x_ (Entrée) : entier, emplacement de la case sur l'axe x  
_y_ (Entrée) : entier, emplacement de la case sur l'axe y  

--------

**Fonction** : **_convertirCarEntier_**  
Convertit la lettre entrée en chiffre utilisable par la grille  (exemple: A devient 1)

**Paramètres** :  
lettre (Entrée) : caractère,  la lettre que l'on veut convertir 

**Résultat** :  
entier, l'entier correspondant

--------

**Fonction** : **_verifierEntreeUtilCase_**  
Verifie si l'entrée utilisateur est correcte

**Paramètres** :  
_coordX_ (Entrée) : caractère,  la lettre de la case  
_coordY_ (Entrée) : entier,  l'indice de la case

**Résultat** :  
booléen, indique si l'entrée utilisateur est correcte

--------

**Fonction** : **_demanderChiffre_**  
Demande le chiffre que veut placer l'utilisateur

**Paramètres** :  
Aucun

**Resultat** :   
entier, le résultat de la saisie

--------
procédure verifierEntreeUtilChiffre(entF  sortF chiffreValide: booléen);  


**Fonction** : **_verifierEntreeUtilChiffre_**  
Verifie si le chiffre que l'utilisateur veut placer est correct

**Paramètres** :  
_chiffreUtil_ (Entrée): entier, le chiffre de l'utilisateur

**Resultat** :  
booléen, indique si le chiffre est correct

--------
