#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "fonctionsDeBase.h"
#include "histoire.h"
#include "combat.h"
#define ENTREE 13
#define MIN 1
#define MAX 100


int main()
{
    FILE* sauvegardes = NULL ;
    int choixMenuPrincipal = 1 ;
    Menu1:
    printf("Menu principal\n1)Nouvelle croisade\n2)Continuer une croisade\n3)A propos\n4)Quitter\n");
    Partie partieEnCours = {0,0,0,0,0,0,0,0};
    choixMenuPrincipal = menu(4);

    if (choixMenuPrincipal == 1)
    {
        initJeu(& partieEnCours);
MarqueP1:
        bouillonJerusalem(&partieEnCours);
    }
    else if (choixMenuPrincipal == 2)
    {
        FILE* sauvegarde1 = fopen("sauvegarde1.txt", "r");
        FILE* sauvegarde2 = fopen("sauvegarde2.txt", "r");
        FILE* sauvegarde3 = fopen("sauvegarde3.txt", "r");

        if (sauvegarde1 == NULL || sauvegarde2 == NULL || sauvegarde3 == NULL)
        {
            printf("impossible d'accéder aux fichiers de sauvegarde\n");
            goto Menu1;
        }
        else
        {
            lectureSauvegarde(sauvegarde1, sauvegarde2, sauvegarde3);
        }

    }
    else if (choixMenuPrincipal == 3)
    {
        printf("Cette croisade a ete concue par Raphael Oester Ier du nom, Luka Mangano, Mahdi Nasser.\n");
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





