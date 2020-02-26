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
int menu(int nbreChoix);
int compteTouche(int touche, int secondesMax);
void chargementSauvegarde(FILE* sauvegarde, Partie* partieEnCours);
void sauvegarde(Partie partieEnCours);
