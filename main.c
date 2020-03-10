#include "Structs.h"
#include <stdio.h>
#define ENTREE 13
#define MIN 1
#define MAX 100


int main()
{
    int choixMenuPrincipal = 1 ;
    Menu1:
    printf("Menu principal\n1)Nouvelle croisade\n2)Continuer une croisade\n3)A propos\n4)Quitter\n");
    Partie partieEnCours = {0,0,0,0,0,0,0,1};
    choixMenuPrincipal = menu(4);

    if (choixMenuPrincipal == 1)
    {
        initJeu(&partieEnCours);
MarqueP1:
        bouillonJerusalem(&partieEnCours);
MarqueP2:
        paris(&partieEnCours);
    }
    else if (choixMenuPrincipal == 2)
    {
        FILE* sauvegarde = fopen("sauvegarde.txt", "r");


        if (sauvegarde == NULL )
        {
            printf("Erreur : impossible d'acceder au fichier de sauvegarde\n");
            goto Menu1;
        }
        else
        {
            chargementSauvegarde(sauvegarde, &partieEnCours);
            if (partieEnCours.marquePage == 1)
            {
                goto MarqueP1;
            }
            else if (partieEnCours.marquePage == 2)
            {
                goto MarqueP2;
            }
            else
            {
                printf("Sauvegarde corrompue. Veuillez lancer une nouvelle partie.\n");
                goto Menu1;
            }
        }

    }
    else if (choixMenuPrincipal == 3)
    {
        printf("Cette croisade a ete concue par Raphael Oester Ier du nom et Luka Mangano.\n");
        getch();
        goto Menu1;
    }
    else if (choixMenuPrincipal == 4)
    {
        printf("Reviens des que possible pour pourfendre le paien\n");
        return 0;
    }

    return 0 ;
}





