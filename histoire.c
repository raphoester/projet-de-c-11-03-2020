#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "fonctionsDeBase.h"
#define ENTREE 13
#define MIN 1
#define MAX 100

int initJeu(Partie* partieEnCours)
{
    int secMax = 0;
    int appuyages = 0;
    printf("Bienvenue chevalier !\nChoisis un niveau de difficulte\n");
    printf("1)Francois Hollande\n2)Bernard Tapie\n3)Louis VI le gros\n4)Saddam Hussein\n");
    partieEnCours->difficulte = menu(4);

    system("cls");
    printf("En l'an de grace 1096, Godefroy de Bouillon, duc de Basse-Lotharingie, prend les armes aux cotes de son frere ");
    printf("Baudouin de Bourgogne, Hugues de Vermandois, Robert II de Normandie et Etienne de Blois.\nCes valeureux chevaliers ");
    printf("partent a Jerusalem suivant l'appel du pape Urbain II pour delivrer le Saint Sepulcre, tombe aux mains ");
    printf("des perfides Sarrasins. \n");
    getch();
    system("cls");
    printf("Avant de partir, Godefroy se rend chez un enchanteur pour qu'il lui confere bonne fortune lors de ses guerroyages.\n");
    getch();
    printf("GODEFROY : \"Merlin, j'ai besoin de tes sortileges!\"\n");
    getch();
    printf("MERLIN : \"Sire, ma magie peut vous apporter force, grace et testosterone pendant votre combat pour Dieu!\n");
    getch();
    printf("GODEFROY : \"Eh bien, besogne toi promptement, ma destinee m'attend.\"\n");
    getch();
    printf("MERLIN : \"Salve Regina, mater misericordia, vita, dulcedo et spes nostra, salve. Ad te clamamus,");
    printf("exsules, filii hevae. \nAd te suspiramus, gementes et flentes, in hac lacrimarum valle. Eia Ergo, advocata nostra, ");
    printf("illos tuos misericordes oculos ad nos converte.\nEt iesum, benedictum fructum ventris tui, nobis post hoc exilium");
    printf("ostende.\nO Clemens, o Pia, o Dulcis Virgo Maria !\"\n\n");
    getch();

    //secMax = 7;
    printf("Quand je dis \"C'est parti\", appuyez frenetiquement et le plus vite possible sur la touche entree : \n");
    //compteTouche(ENTREE, 2);
    printf("3... \n");
    //compteTouche(ENTREE, 1);
    printf("2...\n");
    //compteTouche(ENTREE, 1);
    printf("1...\n");
    //compteTouche(ENTREE, 1);
    printf("C'EST PARTI ! \n");
    //appuyages = compteTouche(ENTREE, secMax);
    printf("\nSTOOOOP ! Vous avez appuye %d fois en %d secondes\n", appuyages, secMax);
    //compteTouche(ENTREE, 3);
    partieEnCours->pdV = (appuyages*25)+100;
    printf("Vous avez donc %d points de vie !", partieEnCours->pdV);

    printf("\n\nRebelote pour les points d'attaque :\n");
    secMax = 5;
    //compteTouche(ENTREE, 1);
    printf("3... \n");
    //compteTouche(ENTREE, 1);
    printf("2...\n");
    //compteTouche(ENTREE, 1);
    printf("1...\n");
    //compteTouche(ENTREE, 1);
    printf("C'EST PARTI ! \n");
    appuyages = compteTouche(ENTREE, secMax);
    printf("\nSTOOOOP ! Vous avez appuye %d fois en %d secondes\n", appuyages, secMax);
    //compteTouche(ENTREE, 3);
    partieEnCours->pdA = appuyages + 15;
    printf("Vous obtenez %d points d'attaque !\n", partieEnCours->pdA);
    getch();

    printf("Maintenant, voyons voir si tu as de la chance... (c'est fait au hasard, tu n'as rien a faire)\n");
    //compteTouche(ENTREE, 2);
    srand(time(NULL));
    partieEnCours->chance = (rand() % (MAX - MIN + 1)) + MIN;
    printf("Ton indice de chance est de  %d !\n\n", partieEnCours->chance);
    getch();

    printf("Chevalier, tu es fin pret. Equipe toi, Jerusalem t'attend.\n");
    XPMaximum(&partieEnCours);
    affichageStats(*partieEnCours);
    getch();
    system("cls");
    partieEnCours->marquePage = 1;
    sauvegarde(*partieEnCours);
    return 0 ;
}

int bouillonJerusalem(Partie *partieEnCours)
{
    int choix = 0;
    printf("Juche sur votre brave destrier Demosthene, Vous partez du chateau sous hypotheque le 15 aout 1096 au petit matin.\n");
    getch();
    printf("Maints serviteurs, esclaves et vassaux vous accompagnent. \n");
    getch();
    printf("Demosthene, qui d'ordinaire parle, se tait pour n'effrayer personne.\n");
    getch();
    printf("La troupe a chevauche toute la journee, et il est maintenant sept heures du soir. \n");
    getch();
    printf("Vous etes parvenu a proximite d'un petit bourg en lisiere de foret, Reville-aux-Bois. \n");
    getch();
    printf("Que faire ?\n1)Ordonner un arret de l'expedition\n2)Continuer la marche\n");
    affichageStats(*partieEnCours);
    choix = menu(2);

    if (choix == 1)
    {
        printf("Tout le monde s'arrete immediatement a votre ordre et met pied a terre.\n");
        getch();
        printf("Que faire ?\n");
Campement:
        printf("1)Partir chasser (didactitiel)\n2)Ordonner qu'on apporte des vivres pour se restaurer\n3)Dormir sur place\n");
        printf("4)Se rendre a Reville-aux-Bois\n");
        choix = menu(4);
        if (choix == 1)
        {
            printf("Vous partez chasser dans la foret de Verdun avec Demosthene.\n");
            getch();
            printf("Votre escuyer Schiappard la Fiotte, son ane et quelques pages vous accompagnent.\n");
            getch();
            printf("Ou aller ?\n1)Nord\n2)Ouest\n3)Sud\n4)Est (retour au campement)\n");
            choix = menu(4);
            if (choix == 1)
            {
                printf("Vous prenez la direction du Nord avec vos serviteurs.\n");
                getch();
                printf("Apres quelque cheminement, vous tombez nez a nez sur avec un sanglier sauvage !\n");
                printf("Il a l'air agressif et ne vous laisse pas le choix : il faut combattre.\n");
                affichageStats(*partieEnCours);
                combat("le sanglier sauvage", 300, 15);
                printf("\nVous avez vaincu le sanglier, felicitations !\n");
                recompensesMonstre("Cadavre de sanglier", 30, partieEnCours);
                printf("Que voulez vous faire maintenant ?\n1)Rentrer au campement\n2)Tout manger tout seul\n");
                choix = menu(2);
                if (choix == 1)
                {
                    printf("Vous rebroussez chemin et arrivez promptement au campement.\n");
                    getch();
                    printf("Tout le monde admire le sanglier que vous avez occis.\n");
                    getch();
                    printf("Seul votre cousin germain Hubert se tait et cache son extase.\nQue faire ?\n");
                    printf("1)L'ignorer\n2)Liberer Hubert de sa tete sans autre forme de proces\n");
                    printf("3)Le provoquer en duel tel un chevalier digne\n");
                    choix = menu(3);
                    if (choix == 1)
                    {
                        printf("Vous feignez ne vous apercevoir de rien. Les rejouissances continuent.\n");
                    }
                    else if (choix == 2)
                    {
                        printf("D'un coup d'epee net et precis, cousin Hubert quitte ce monde.\n");
                        getch();
                        printf("Ce comportement est indigne d'un bon chretien. Vous ne gagnez aucun XP pour cette pietre victoire.\n");
                        getch();
                        printf("Le poids de votre conscience vous torture. Vous perdez 50 points de vie et 10 points d'attaque.\n");
                        partieEnCours->pdV -=50;
                        partieEnCours->pdA -=10;
                        affichageStats(*partieEnCours);
                    }
                    else if (choix == 3)
                    {

                    }
                    else
                    {
                        printf("Renvoi de la fonction menu() invalide.");
                    }

                }
                else if (menu == 2)
                {
                    //il mange tout tout seul comme un boloss
                }
                else
                {

                }
            }
            else if (choix == 2)
            {

            }
            else if (choix == 3)
            {

            }
            else if (choix == 4)
            {
                printf("Vous changez d'avis et faites demi-tour. De retour au campement, que voulez-vous faire ?\n");
                goto Campement;
            }
            else
            {
                printf("Renvoi de la fonction menu() invalide");
            }
        }
        else if (choix == 2)
        {

        }
        else if (choix == 3)
        {

        }
        else if (choix == 4)
        {

        }
        else
        {
            printf("Renvoi de la fonction menu() invalide.");
        }


    }
    else if (choix == 2)
    {

    }
    else
    {
        printf("Renvoi de la fonction menu() invalide.");
    }


}

