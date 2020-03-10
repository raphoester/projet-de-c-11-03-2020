#include "Structs.h"
void affichageStats(Partie partieEnCours)
//fonction qui affiche (dans l'ordre) les points de vie, les points d'attaque, l'experience obtenie / l'experience requise,
//le niveau du joueur.
{
    printf("Points de vie : %d\nPoints d'attaque : %d\nPoints de defense : %d\n", partieEnCours.pdV, partieEnCours.pdA, partieEnCours.pdD);
    printf("Experience : %d/%d\nNiveau %d\n", partieEnCours.XP, partieEnCours.XPMax, partieEnCours.niveau);
    //Afficher ici le niveau en fonction de l'XP actuelle obtenue.
}


void experiencePlus(Partie* partieEnCours, int experienceBonus)
{
    partieEnCours->XP += experienceBonus ;
    if (partieEnCours->XP >= partieEnCours->XPMax)
    {
        printf("Felicitations, vous gagnez un niveau !\n");
        getch();
        partieEnCours->niveau += 1;
        printf("Vous etes desormais niveau %d\n", partieEnCours->niveau);
        partieEnCours->pdV *= 2;
        partieEnCours->pdA *= 2;
        partieEnCours->pdD *= 2;
        partieEnCours->XP = 0;
        partieEnCours->XPMax = partieEnCours->niveau*100;
        affichageStats(*partieEnCours);
    }
}


