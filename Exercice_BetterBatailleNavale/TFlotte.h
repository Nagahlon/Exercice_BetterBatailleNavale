#pragma once

#include "TBateau.h"
#include "EBool.h"



typedef struct Flotte {

    Bateau nBateau[NBBATEAU];


}Flotte;

enum etatFlotte {


    aFlot, aSombrer

}etatFlotte;



//Prototypes
enum Bool controlFlotte(Flotte f, Case mCase);
void fPlayer(Case mCase, Flotte* f);
void initFlotteJoueur(Flotte* flotteJoueur1, Flotte* flotteJoueur2, Case mCase);
int tailleBateau(Flotte f, int numBateau);
void attaqueBateau(Flotte* f, Case mCase, int* numBateau);
enum etatBateau etatBat(Flotte f, int numBateau);
enum etatFlotte etatFlot(Flotte f);
void minMax(Flotte f, int* minLigne, int* maxLigne, int* minCol, int* maxCol);



//Definitions
//return True si la case passé en paramètre appatient bien à un bateau d'une flotte
enum Bool controlFlotte(Flotte f, Case mCase) {

    int i;
    enum Bool valTest = False;
    for (i = 0; i < NBBATEAU; i++) {
        if (controlCase(f.nBateau[i], mCase) == True)
            valTest = True;


    }

    return valTest;




}

//initFlotteJoueur
void initFlotteJoueur(Flotte* flotteJoueur1, Flotte* flotteJoueur2, Case mCase) {


    printf("Initialisation Bateaux Player 1\n");

    fPlayer(mCase, flotteJoueur1);

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    fflush(stdin);


    printf("Initialisation Bateaux Player 2\n");

    fPlayer(mCase, flotteJoueur2);

    puts("Appuyer sur enter pour continuer\n");
    getchar();
    fflush(stdin);

}

//Procédure attaque bateau
void attaqueBateau(Flotte* f, Case mCase, int* numBateau) {

    int i, j;


    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {
            if (f->nBateau[i].nCase[j].ligne == mCase.ligne && f->nBateau[i].nCase[j].col == mCase.col) {
                f->nBateau[i].nCase[j].ligne = 0;
                f->nBateau[i].nCase[j].col = 0;
                *numBateau = i;


            }

        }
    }

    if (etatBat(*f, *numBateau))
        printf("Couler!!!\n");

    else
        printf("Toucher!!!\n");

}

//retourne etat flotte
enum etatFlotte etatFlot(Flotte f) {

    int i, j;
    enum etatFlotte st = aFlot;

    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {

            if (f.nBateau[i].nCase[j].ligne == 0 && f.nBateau[i].nCase[j].col == 0)
                st = aSombrer;
            else {
                st = aFlot;
                return st;

            }


        }

    }

    return st;

}

//Set val min, max de ligne et colonne d'une flotte de bateaux
void minMax(Flotte f, int* minLigne, int* maxLigne, int* minCol, int* maxCol) {


    int i, j;

    *maxLigne = *maxCol = VALMIN - 1;
    *minLigne = *minCol = VALMAX;

    for (i = 0; i < NBBATEAU; i++) {
        for (j = 0; j < MAXCASE; j++) {

            if (f.nBateau[i].nCase[j].ligne < *minLigne && f.nBateau[i].nCase[j].ligne>0)
                *minLigne = f.nBateau[i].nCase[j].ligne;
            else if (f.nBateau[i].nCase[j].ligne > *maxLigne && f.nBateau[i].nCase[j].ligne > 0)
                *maxLigne = f.nBateau[i].nCase[j].ligne;
            if (f.nBateau[i].nCase[j].col < *minCol && f.nBateau[i].nCase[j].col>0)
                *minCol = f.nBateau[i].nCase[j].col;
            else if (f.nBateau[i].nCase[j].col > *maxCol && f.nBateau[i].nCase[j].col > 0)
                *maxCol = f.nBateau[i].nCase[j].col;

        }
    }
}

//construit la flotte d'un joueur
void fPlayer(Case mCase, Flotte* f) {

    int i;
    int valRandPosLigne = 0;
    int valRandPosCol = 0;
    int valRandTailleBateau = 0;



    for (i = 0; i < NBBATEAU; i++) {

        valRandPosLigne = rand() % (MAXL - MAXCASE) + 1;
        valRandPosCol = rand() % (MAXC - MAXCASE) + 1;
        valRandTailleBateau = rand() % MAXCASE + 1;
        createCase(valRandPosLigne, valRandPosCol, &mCase);
        f->nBateau[i] = createBateau(mCase, valRandTailleBateau);


    }



}



//return la taille d'un bateau d'une flotte passé en paramètre
int tailleBateau(Flotte f, int numBateau) {

    int i;
    int tailleBat = 0;

    for (i = 0; i < MAXCASE; i++) {

        if (f.nBateau[numBateau].nCase[i].col > 0 && f.nBateau[numBateau].nCase[i].ligne > 0)
            tailleBat++;

    }

    return tailleBat;

}

//retourne etat bateau
enum etatBateau etatBat(Flotte f, int numBateau) {


    if (tailleBateau(f, numBateau) == 0) {

        return couler;

    }
    else {


        return toucher;

    }
}