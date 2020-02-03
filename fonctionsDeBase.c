#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>
#include "fonctionsDeBase.h"

void XPMaximum(Partie* partieEnCours) //fonction qui met à jour le niveau du joueur en fonction de son xp actuelle.
{
    int jauge = 0;
    int augmentation = 0;
    while (jauge<=partieEnCours->XP)
    {
        augmentation += 50;
        jauge += augmentation;
    }
    partieEnCours->niveau = augmentation/50;
    partieEnCours->XPMax = jauge;
}

void affichageStats(Partie partieEnCours)
//fonction qui affiche (dans l'ordre) les points de vie, les points d'attaque, l'expérience obtenie / l'expérience requise,
//le niveau du joueur.
{
    printf("Points de vie : %d\nPoints d'attaque : %d\n", partieEnCours.pdV, partieEnCours.pdA);
    printf("Experience : %d/%d\nNiveau %d", partieEnCours.XP, partieEnCours.XPMax, partieEnCours.niveau);
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

int sauvegarde(Partie partieEnCours)
{ // EN COURS DE CONSTRUCTION / NON OPERATIONNEL
    int choix = 0 ;
    printf("Voulez vous sauvegarder votre partie ?\n1)oui\n2)non\n");
    choix = menu(2);
    if (choix = 1)
    {
        //SAUVEGARDER
    }
    else if (choix = 2)
    {
        printf("A vos risques et perils.\n");
    }
    else
    {
        printf("Renvoi de la fonction menu() incorrect.\nLa partie continue sans sauvegarder.\n");
    }

}

int lectureSauvegarde(FILE* sauvegarde1, FILE* sauvegarde2, FILE* sauvegarde3)
{
    struct dirent *lecture ;
    DIR *dossier = opendir("./sauvegardes" );
    while ((lecture = readdir(dossier)))
    {
        printf("%s\n", lecture->d_name);
    }
    closedir(dossier);
}
