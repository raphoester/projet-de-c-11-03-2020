#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int XPMaximum(int XP, int *niveau) //fonction qui met à jour le niveau du joueur en fonction de son xp actuelle.
//Renvoie l'XP max du niveau où il est actuellement.
{
    int jauge = 0;
    int augmentation = 0;
    while (jauge<=XP)
    {
        augmentation += 50;
        jauge += augmentation;
    }
    *niveau = augmentation/50;
    return jauge;
}

int affichageStats(int *pdA, int *pdV, int *XP, int *XPRequise)
//fonction qui affiche (dans l'ordre) les points de vie, les points d'attaque, l'expérience obtenie / l'expérience requise,
//le niveau du joueur.
{
    printf("Points de vie : %d\nPoints d'attaque : %d\nExperience : %d/%d\n", *pdV, *pdA, *XP, *XPRequise);
    //Afficher ici le niveau en fonction de l'XP actuelle obtenue.
}


int menu(nbreChoix)
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
    return 404 ;
}


int compteTouche(int touche, int secondesMax)
//Fonction qui compte le nombre de fois où l'utilisateur appuie sur la touche (ENTREE normalement)
//dans le temps secondesMax donné
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
