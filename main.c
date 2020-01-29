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
    choixMenuPrincipal = menu(4);

    if (choixMenuPrincipal == 1)
    {
        int chance = 0 ;
        int pdA = 0 ;
        int pdV = 0 ;
        int difficulte = 0 ;
        int XP = 0 ;
        int XPMax = 0;

        initJeu(&chance, &pdA, &pdV, &difficulte, &XP, &XPMax);
        bouillonJerusalem(&chance, &pdA, &pdV, &difficulte, &XP, &XPMax);
    }
    else if (choixMenuPrincipal == 2)
    {
        sauvegardes = fopen("sauvegardes.txt", "r");
        if (sauvegardes != NULL)
        {

        }
        else
        {
            printf("impossible d'ouvrir le fichier de sauvegardes\n");
            goto Menu1;
        }






        //trouver un moyen de charger des parties enregistrées
    }
    else if (choixMenuPrincipal == 3)
    {
        printf("Cette croisade a ete concue par Raphael Oester Ier du nom, Luka Mangano, Mahdi quelque chose.\n");
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





