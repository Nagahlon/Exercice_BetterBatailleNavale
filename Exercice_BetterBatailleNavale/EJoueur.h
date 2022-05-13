#pragma once

#include "TFlotte.h"



enum etatJoueur {

    gagne, perd

}etatJoueur;



//Prototypes
void saisirAttaque(Case* mCase);
enum etatJoueur etatJ(Flotte f);
int validSaisiJoueur(char val[]);
void effaceEcran();
void saisieJoueur(char valLigne[], char valCol[]);



//Definitions
//procedure Attaque bateau de flotteJoueur
void saisirAttaque(Case* mCase) {

    char valLigne[4], valCol[4];

    saisieJoueur(valLigne, valCol);



    while (!validSaisiJoueur(valLigne) || !validSaisiJoueur(valCol) || (atoi(valLigne) < MINL || atoi(valLigne) > MAXL)
        || (atoi(valCol) < MINC || atoi(valCol) > MAXC)) {

        effaceEcran();
        printf("Mauvaise saisie, recommencer vous devez saisir une val numerique comprise entre %d et %d\n", VALMIN, VALMAX);

        saisieJoueur(valLigne, valCol);


    }
    mCase->ligne = atoi(valLigne);
    mCase->col = atoi(valCol);

}

//retourne  etat du joueur
enum etatJoueur etatJ(Flotte f) {


    if (etatFlot(f) == aSombrer)
        return perd;
    else
        return gagne;

}

//procedure efface
void effaceEcran() {

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    system("cls");

}

//fct valide saisie joueur
int validSaisiJoueur(char val[]) {

    int i;


    for (i = 0; i < strlen(val); i++) {

        if (!isdigit(val[i]))
            return 0;
    }

    return 1;


}

//procédure saisie val joueur

void saisieJoueur(char valLigne[], char valCol[]) {


    printf("Entrez votre tir\n");

    printf("Entrez ligne :\n");
    scanf_s("%d", valLigne);
    fflush(stdin);

    printf("Entrez Colonne :\n");
    scanf_s("%d", valCol);
    fflush(stdin);


}