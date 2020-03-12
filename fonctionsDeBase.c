#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int menu(int nbreChoix)
{
    char choix[10] = {0};
    int choixEntier = 0;
    while(1){
        scanf("%s", &choix);
        printf("\n");
        choixEntier = atoi(choix);
        if(choixEntier > 0 && choixEntier < nbreChoix+1)
        {
            return choixEntier;
        }
        else if(choixEntier > nbreChoix)
        {
            printf("Vous ne pouvez pas choisir un nombre superieur a %d.\n", nbreChoix);
        }
        else
        {
            printf("Ce n'est pas un choix disponible.\n");
        }
    }
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
