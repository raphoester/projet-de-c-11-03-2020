#include "Structs.h"
#include <stdlib.h>
#include <stdio.h>
void sauvegarde(Partie partieEnCours)
{
    int choix = 0 ;
    printf("Voulez vous sauvegarder votre partie ?\n1)oui\n2)non\n");
    choix = menu(2);
    if (choix == 1)
    {
        FILE* sauvegarde = fopen("sauvegarde.txt", "w");
        if (sauvegarde == NULL)
        {
            printf("Erreur d'ouverture du fichier de sauvegarde. Vous continuez sans sauvegarder.");
        }
        else
        {
            printf("Sauvegarde en cours...\n");
            fprintf(sauvegarde, "%d %d %d %d %d %d %d %d", partieEnCours.pdV, partieEnCours.pdA, partieEnCours.pdD, partieEnCours.chance, partieEnCours.XP, partieEnCours.XPMax, partieEnCours.marquePage, partieEnCours.niveau);
            printf("Fait !\n");
            getch();
        }
    }
    else if (choix == 2)
    {
        printf("A vos risques et perils.\n");
        getch();
    }
    else
    {
        printf("Renvoi de la fonction menu() incorrect.\nLa partie continue sans sauvegarder.\n");
    }
}

void chargementSauvegarde(FILE* sauvegarde, Partie* partieEnCours)
{
    fscanf(sauvegarde, "%d %d %d %d %d %d %d %d", &partieEnCours->pdV, &partieEnCours->pdA, &partieEnCours->pdD, &partieEnCours->chance, &partieEnCours->XP, &partieEnCours->XPMax, &partieEnCours->marquePage, &partieEnCours->niveau);
}


