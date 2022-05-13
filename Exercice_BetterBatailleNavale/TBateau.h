#pragma once

#include "TCases.h"

#define NBBATEAU 3
#define MAXCASE 3



typedef struct Bateau {


    Case nCase[MAXCASE];



}Bateau;

enum positionBateau {

    enLigne, enColonne, enDiag

}positionBateau;

enum etatBateau {

    toucher, couler

}etatBateau;



//Prototypes
enum positionBateau pos;
Bateau createBateau(Case nCase, int taille);
enum Bool controlCase(Bateau mBat, Case mCase);



//Definitions
//Fct de création de bateau
//Return une structure bateau
Bateau createBateau(Case nCase, int taille) {

    Bateau res;


    positionBateau = rand() % 3;


    int i;
    for (i = 0; i < MAXCASE; i++) {
        if (i < taille) {
            res.nCase[i].ligne = nCase.ligne;
            res.nCase[i].col = nCase.col;
        }
        else {

            res.nCase[i].ligne = 0;
            res.nCase[i].col = 0;
        }
        if (positionBateau == enLigne) {

            nCase.col++;

        }
        else if (positionBateau == enColonne) {

            nCase.ligne++;

        }
        else if (positionBateau == enDiag) {

            nCase.ligne++;
            nCase.col++;
        }



    }

    return res;
}

//Return True si la case passé en paramètre appartient bien à un bateau
enum Bool controlCase(Bateau mBat, Case mCase) {


    int i;
    enum Bool valTest = False;
    for (i = 0; i < MAXCASE; i++) {

        if (cmpCase(mBat.nCase[i], mCase) == True)
            valTest = True;


    }

    return valTest;


}