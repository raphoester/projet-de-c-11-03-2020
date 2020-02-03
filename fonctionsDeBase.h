#include <stdio.h>
#include <stdlib.h>

typedef struct Partie Partie;
struct Partie
{
    int pdV;
    int pdA;
    int XP;
    int XPMax;
    int chance;
    int difficulte;
    int marquePage;
    int niveau;
};


void XPMaximum(Partie *partieEnCours) ;
void affichageStats(Partie partieEnCours) ;
int menu(nbreChoix);
int compteTouche(int touche, int secondesMax);
int lectureSauvegarde(FILE* sauvegarde1, FILE* sauvegarde2, FILE* sauvegarde3);
