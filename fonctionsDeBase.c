#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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
        partieEnCours->XP = 0;
        partieEnCours->XPMax = partieEnCours->niveau*100;
    }
}

void affichageStats(Partie partieEnCours)
//fonction qui affiche (dans l'ordre) les points de vie, les points d'attaque, l'exp�rience obtenie / l'exp�rience requise,
//le niveau du joueur.
{
    printf("Points de vie : %d\nPoints d'attaque : %d\n", partieEnCours.pdV, partieEnCours.pdA);
    printf("Experience : %d/%d\nNiveau %d\n", partieEnCours.XP, partieEnCours.XPMax, partieEnCours.niveau);
    //Afficher ici le niveau en fonction de l'XP actuelle obtenue.
}


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
            fprintf(sauvegarde, "%d %d %d %d %d %d %d %d", partieEnCours.pdV, partieEnCours.pdA, partieEnCours.chance, partieEnCours.XP, partieEnCours.XPMax, partieEnCours.marquePage, partieEnCours.niveau);
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
    fscanf(sauvegarde, "%d %d %d %d %d %d %d", &partieEnCours->pdV, &partieEnCours->pdA, &partieEnCours->chance, &partieEnCours->XP, &partieEnCours->XPMax, &partieEnCours->marquePage, &partieEnCours->niveau);
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
        printf("Condition 1 validee\n");
        printf("\nCoordonnes \nx:%d, y:%d\n", partieEnCours->x, partieEnCours->y);
    }

    else if (choixLocal == 2)
    {
        (partieEnCours->y)+=1;
        printf("Condition 2 validee\n");
        printf("\nCoordonnes \nx:%d, y:%d\n", partieEnCours->x, partieEnCours->y);
    }

    else if (choixLocal == 3)
    {
        (partieEnCours->x)+=1;
        printf("Condition 3 validee\n");
        printf("Coordonnes \nx:%d, y:%d\n", partieEnCours->x, partieEnCours->y);
    }

    else if (choixLocal == 4)
    {
        (partieEnCours->x)-=1;
        printf("Condition 4 validee");
        printf("\nCoordonnes \nx:%d, y:%d\n", partieEnCours->x, partieEnCours->y);
    }
}

void recit(char ecrit[300])
{
    printf("%s\n", ecrit);
    getch();
}
