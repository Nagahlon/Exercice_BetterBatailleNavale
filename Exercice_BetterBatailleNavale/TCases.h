#pragma once



typedef struct Case {


    int ligne;
    int col;


}Case;



//Prototypes
void createCase(int l, int c, Case* mCase);
enum Bool cmpCase(Case mCase, Case tCase);



//Definitons
//Procédure Creation Cases bateaux
void createCase(int l, int c, Case* mCase) {


    mCase->ligne = l; //création ligne
    mCase->col = c; //création colonne


}

//Fct de comparaison de cases
//Return True si 2 case ligne et col sont =
enum Bool cmpCase(Case mCase, Case tCase) {


    if (mCase.col == tCase.col && mCase.ligne == tCase.ligne)
        return True;
    else
        return False;

}