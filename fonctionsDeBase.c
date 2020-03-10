#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int menu(int nbreChoix)
{
    int choix ;
    while(1)
    {
        scanf("%d", &choix);
        if (choix > 0 && choix <= nbreChoix)
        {
            return choix ;
        }
        else
        {
            printf("Valeur incorrecte\nReessayez svp\n");
        }
    }
    return EXIT_FAILURE ;
}


int compteTouche(int touche, int secondesMax)
//Fonction qui compte le nombre de fois o� l'utilisateur appuie sur la touche (ENTREE normalement)
//dans le temps secondesMax donn�
{
    time_t tempsDeFin=time(NULL)+ secondesMax;
    int compteur=0;
    while(time(NULL)<tempsDeFin)
        if(kbhit())
        {
            if(getch() == touche)
            {
                compteur++;
                Sleep(100);
            }
        }
    return compteur ;
}

int lancerDeDes(Partie* partieEnCours)
{
    const int MAXI = 6;
    const int MINI = 1;
    srand(time(NULL));
    if (((rand() % (MAXI - MINI + 1)) + MINI )*partieEnCours->chance > 130)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void deplacementPlateau(int choix, Partie* partieEnCours) //choix 1=nord, 2=sud, 3=est, 4=ouest.
{
    int choixLocal = choix;
    if (choixLocal == 1)
    {
        (partieEnCours->y)-=1;
    }

    else if (choixLocal == 2)
    {
        (partieEnCours->y)+=1;
    }

    else if (choixLocal == 3)
    {
        (partieEnCours->x)+=1;
    }

    else if (choixLocal == 4)
    {
        (partieEnCours->x)-=1;
    }
}

void recit(char ecrit[300])
{
    printf("%s\n", ecrit);
    getch();
}
