#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"

void XPMaximum(Partie *partieEnCours) ;
void affichageStats(Partie partieEnCours) ;
int menu(int nbreChoix);
int compteTouche(int touche, int secondesMax);
void chargementSauvegarde(FILE* sauvegarde, Partie* partieEnCours);
void sauvegarde(Partie partieEnCours);
