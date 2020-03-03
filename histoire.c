#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "fonctionsDeBase.h"
#define ENTREE 13
#define MIN 1
#define MAX 100

void initJeu(Partie* partieEnCours)
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
    partieEnCours->pdV = (appuyages*27)+100;
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
    //appuyages = compteTouche(ENTREE, secMax);
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
    XPMaximum(partieEnCours);
    affichageStats(*partieEnCours);
    getch();
    system("cls");
    partieEnCours->marquePage = 1;
    sauvegarde(*partieEnCours);
    return 0 ;
}

void bouillonJerusalem(Partie *partieEnCours)
{
    int choix = 0;
    int de = 0;
    printf("Juche sur votre brave destrier Demosthene, Vous partez du chateau sous hypotheque le 15 aout 1096 au petit matin.\n");
    getch();
    printf("Maints serviteurs, esclaves et vassaux vous accompagnent. \n");
    getch();
    printf("La troupe a chevauche toute la journee, et il est maintenant sept heures du soir. \n");
    getch();
    printf("Vous etes parvenu a proximite d'un petit bourg en lisiere de foret, Reville-aux-Bois. \n");
    getch();
    printf("Que faire ?\n1)Ordonner un arret de l'expedition\n2)Continuer la marche (Continuer mission principale)\n");
    affichageStats(*partieEnCours);
    choix = menu(2);

    if (choix == 1)
    {
        printf("Tout le monde s'arrete immediatement a votre ordre et met pied a terre.\n");
        getch();
        printf("Que faire ?\n");
Campement:
        printf("1)Partir chasser\n2)Ordonner qu'on apporte des vivres pour se restaurer\n3)Dormir sur place\n");
        printf("4)Se rendre a Reville-aux-Bois\n");
        choix = menu(4);
        if (choix == 1)
        {
            printf("Vous partez chasser dans la foret de Verdun avec Demosthene.\n");
            getch();
            printf("Votre escuyer Schiappard la Fiotte, son ane et quelques pages vous accompagnent.\n");
            getch();
CarrefourForet:
            printf("Ou aller ?\n1)Nord\n2)Ouest\n3)Sud\n4)Est (retour au campement)\n");
            choix = menu(4);
            if (choix == 1)
            {
                printf("Vous prenez la direction du Nord avec vos serviteurs.\n");
                getch();
                printf("Apres quelque cheminement, vous tombez nez a nez sur avec un sanglier sauvage !\n");
                printf("Il a l'air agressif et ne vous laisse pas le choix : il faut combattre.\n");
                affichageStats(*partieEnCours);
                //combat("le sanglier sauvage", 300, 15, partieEnCours);
                //recompensesMonstre("Cadavre de sanglier", 30, partieEnCours);
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
                        printf("Vous provoquez cousin Hubert en duel pour sa mauvaise grace\n");
                        combat("Cousin Hubert", 500, 45, partieEnCours);
                        recompensesMonstre("Epee de fragile", 50, partieEnCours);
                        affichageStats(*partieEnCours);
                    }
                    else
                    {
                        printf("Renvoi de la fonction menu() invalide.");
                    }
                    printf("Que voulez vous faire maintenant ?\n1)Consommer le sanglier\n2)Consommer le sanglier\n");
                    printf("3)Consommer le sanglier\n");
                    choix = menu(3);
                    if (choix == 1 || choix == 2 || choix == 3)
                    {
                        printf("Vous devorez le sanglier apres l'avoir cuit avec mauvaise grace a cause des ");
                        printf("insistances de votre medecin de guerre.\n");
                        getch();
                        printf("Ce tres bon repas vous rapporte 90 points de vie.\n");
                        partieEnCours->pdV += 90;
                        affichageStats(*partieEnCours);
                        printf("Que faire maintenant ?\n");
                        goto Campement;
                    }
                }
                else if (choix == 2)
                {
                    printf("Vous ordonnez a vos serviteurs de dissequer le sanglier. \n");
                    getch();
                    printf("Pendant ce temps, vous vous asseyez contre un arbre et faites un somme.\n");
                    compteTouche(ENTREE, 3);
                    printf("...\n");
                    getch();
                    printf("Schiappard la Fiotte vous reveille une fois sa besogne achevee.\n");
                    getch();
                    printf("Ce somme vous a redonne des forces, vous gagnez 70 points de vie et 15 points d'attaque.\n");
                    partieEnCours->pdV += 70;
                    partieEnCours->pdA += 15;
                    affichageStats(*partieEnCours);
                    printf("Par contre, Schiappard a cuit le sanglier que vous preferez cru.\n");
                    getch();
                    printf("Que faire ?\n1)Le chatier\n2)S'en foutre\n");
                    choix = menu(2);
                    if (choix == 1)
                    {
                        printf("Vous administrez une paire de baffes a la Fiotte qui s'en va bouder contre un arbre.\n");
                        getch();
                    }
                    else if (choix == 2)
                    {
                        printf("Vous vous montrez clement envers la Fiotte.\n");
                        getch();
                        printf("10 points d'XP recompensent ce comportement digne.\n");
                        getch();
                        partieEnCours->XP += 10;
                        affichageStats(*partieEnCours);
                    }
                    else
                    {
                        printf("Renvoi de la fonction menu() invalide");
                    }
                    printf("Maintenant c'est le sanglier qui va prendre cher.\n");
                    getch();
                    printf("La bete de quarante livres disparait en moins de 20 minutes.\n");
                    getch();
                    printf("Votre appetit surdimensionne vous vaut d'etre craint et respecte.\n");
                    getch();
                    printf("Personne n'ose parler apres votre effrayant repas et vos multiples eructations.\n");
                    getch();
                    printf("Que faire maintenant ?\n");
                    goto Campement;
                }
                else
                {
                    printf("Renvoi de la fonction menu() invalide");
                }
            }
            else if (choix == 2)
            {
            printf("Apres avoir suivi un petit sentier pendant quelques minutes, vous parvenez dans un champ de l'autre cote\n");
            getch();
            printf("Non loin de la, un barrage de castors s'est installe sur un petit cours d'eau.\n");
            getch();
            printf("Que faire ?\n1)Aller chasser le castor\n2)Se baigner dans la riviere\n");
            printf("3)Rebrousser chemin vers le carrefour precedent\n");
            choix = menu(3);
            if (choix == 1)
            {
                printf("Vous vous approchez du barrage, mais aucun castors a l'horizon..\n");
                getch();
                printf("Vous mettez un pied sur le barrage et soudainement des rugissements en sorte.\n");
                getch();
                printf("Effrayez par ces bruits, vous reculez et tombez par terre.\n");
                getch();
                printf("Une bande de dix castors d'elite en sort pour defendre leur foyer.\n");
                getch();
                printf("Vous vous relevez aussitot, pret a goumer du castor !\n");
                getch();
                //combat("Castors d'elite", 120, 40, partieEnCours);
                //recompensesMonstre("10 cadavres de castor", 50, partieEnCours);
                affichageStats(*partieEnCours);
                getch();
                printf("Que faire maintenant ?\n1)Manger le castor\n2)Se baigner\n3)Rebrousser chemin vers le carrefour precedent\n");
                choix = menu(3);
                if (choix == 1)
                {
                    goto MangerCastor;
                }
                else if (choix == 2)
                {
                    goto Baignade;
                }
                else if (choix == 3)
                {
                    printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                    goto CarrefourForet;
                }
                getch();

            }
            else if (choix == 2)
            {
                printf("Vous vous approchez de la riviere et les castors rentrent tous se cacher dans leur barrage.\n");
                getch();
                printf("Que faire ?\n1)Demolir le barrage\n2)Renoncer\n");
                choix = menu(2);
                if (choix == 1)
                {
                    printf("Vous commencez a assener des coups d'epee bien sentis sur le barrage.\n");
                    getch();
                    printf("Immediatement, une bande de dix castors d'elite en sort pour defendre leur foyer.\n");
                    getch();
                    printf("Ces castors sont vraiment feroces et il vous faut les combattre !\n");
                    //combat("Castors d'elite", 120, 40, partieEnCours);
                    //recompensesMonstre("10 cadavres de castor", 50, partieEnCours);
                    printf("Que faire maintenant ?\n1)Demolir le reste du barrage\n2)Manger les castors\n");
                    choix = menu(2);
                    if (choix == 1)
                    {
                        printf("Vous continuez de deferler votre haine sur le barrage.\n");
                        getch();
                        printf("Au bout de quelques minutes, une nouvelle bande de castors, d'une allure plus pacifiste ");
                        printf("que la precedente, en sort.\n");
                        getch();
                        printf("Il semblerait qu'ils veulent se rendre !\nQue faire ?\n1)Les goumer quand meme\n");
                        printf("2)Leur laisser la vie sauve et leur barrage\n3)Leur laisser la vie sauve mais pas leur barrage\n");
                        choix = menu(3);
                        if (choix == 1)
                        {
                            printf("Vous genocidez la population de castors dans la joie et la bonne humeur.\n");
                            //combat("Castors pacifistes", 120, 40, partieEnCours);
                            recompensesMonstre("20 cadavres de castor", 0, partieEnCours);
                            getch();
                            printf("Que faire maintenant ?\n1)Se baigner\n2)Manger les castors\n3)Rebrousser chemin vers le carrefour precedent\n");
                            getch();
                            choix = menu(3);
                            if (choix == 1)
                            {
                                goto Baignade;
                            }
                            else if (choix == 2)
                            {
                                goto MangerCastor;
                            }
                            else if (choix == 3)
                            {
                                printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                                goto CarrefourForet;
                            }
                        }
                        else if (choix == 2)
                        {
                            printf("Les castors retournent dans leur barrage en paix.\n");
                            getch();
                            printf("Cette bonne action vous rapporte 15 points d'XP.");
                            partieEnCours->XP+=15;
                            getch();
                            printf("Que faire maintenant ?\n1)Se baigner\n2)Rebrousser chemin vers le carrefour precedent\n");
                            getch();
                            choix = menu(2);
                            if (choix == 1)
                            {
                                goto Baignade;
                            }
                            else if (choix == 2)
                            {
                                printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                                goto CarrefourForet;
                            }
                        }
                        else if (choix == 3)
                        {
                            printf("Vous commencez a assener des coups d'epee bien sentis sur le barrage. Enerve, les castors vous sautent � la gorge.");
                            getch();
                            printf("Vous vous tenez pr�t � casser du castor !");
                            getch();
                            //combat("Castors pacifistes", 120, 40, partieEnCours);
                            recompensesMonstre("20 cadavres de castor", 0, partieEnCours);
                            getch();
                            printf("Que faire maintenant ?\n1)Se baigner\n2)Manger les castors\n3)Rebrousser chemin vers le carrefour precedent\n");
                            getch();
                            choix = menu(3);
                            if (choix == 1)
                            {
                                goto Baignade;
                            }
                            else if (choix == 2)
                            {
                                goto MangerCastor;
                            }
                            else if (choix == 3)
                            {
                                printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                                goto CarrefourForet;
                            }
                        }
                        else
                        {
                            printf("Renvoi de la fonction menu() invalide.\n");
                        }
                    }
                    else if (choix == 2)
                        {
MangerCastor:
                            printf("Vous attraper la queue du castor et, d'un coup sec, vous lui arrachez sa fourrure\n");
                            getch();
                            printf("Pas besoin de le cuir, vous le preferez cru !\n");
                            getch();
                            printf("Vous vous empressez de croquer dans castor.\n");
                            getch();
                            printf("Ce somme vous a redonne des forces, vous gagnez 70 points de vie et 15 points d'attaque.\n");
                            partieEnCours->pdV += 70;
                            partieEnCours->pdA += 15;
                            printf("Que faire maintenant ?\n1)Se baigner\n2)Rebrousser chemin vers le carrefour precedent\n");
                            getch();
                            choix = menu(2);
                            if (choix == 1)
                            {
                                goto Baignade;
                            }
                            if (choix == 2)
                            {
                                printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                                goto CarrefourForet;
                            }
                        }
                }
                else if (choix == 2)
                {
                    printf("La peine vous envahit, vous decidez de les laisser en paix. Votre bonne action vous rapporte 30 points d'XP\n");
                    getch();
                    partieEnCours->XP+=30;
                    printf("Mais ce ne sont pas ces castors qui vont vous empecher de vous baigner.\n");
                    getch();
Baignade:
                    printf("Vous otez votre armure et entrez dans la riviere.\n");
                    getch();
                    printf("Vous tentez de nager vers l'autre rive.\n");
                    getch();
                    printf("Vous vous apercevez que le courant est beaucoup plus fort que vous ne le pensiez !\n");
                    getch();
                    printf("Vous luttez pour ne pas vous faire emmener.\n");
                    getch();
                    printf("Vos serviteurs sont impuissants sur la berge et vous regardent faiblir.\n");
                    getch();
                    printf("Allez vous vous en sortir ?\n");
                    getch();
                    printf("lancer de des...");
                    //compteTouche(ENTREE, 3);
                    de = lancerDeDes();
                    printf("Vous obtenez %d.\n", de);
                    getch();
                    if (de * partieEnCours->chance > 130)
                    {
                        printf("Victoire ! Vous reussisez a vous extraire de la riviere.\n");
                        getch();
                        printf("Que faire ?\n1)Botter le cul a ces inutiles serviteurs\n2)Retourner au campement\n");
                        choix = menu(2);
                        if (choix == 1)
                        {
                            printf("Vous fixer ces gredins et l'un d'entre eux-vous devisage avec son air hautain.\n");
                            getch();
                            printf("Il ne vous reste plus qu'a lui donner une le�on de vie.\n");
                            getch();
                            printf("Vous engagez le duel !\n");
                            getch();
                            affichageStats(*partieEnCours);
                            //combat("Le gueux", 200, 10, partieEnCours);
                            //recompensesMonstre("1 pi�ce d'or", 50, partieEnCours);
                            printf("Vous faites maintenant demi-tour. De retour au campement, que voulez-vous faire ?\n");
                            getch();
                            goto Campement;
                        }
                        else if (choix == 2)
                        {
                            printf("Vous faites demi-tour. De retour au campement, que voulez-vous faire ?\n");
                            getch();
                            goto Campement;
                        }
                    }
                    else
                    {
                        printf("Zute... vous vous noyez comme un pauvre nullos.\n");
                        getch();
                        printf("Selection naturelle mon pote !\n");
                        getch();
                        printf("Vous etes mort !\n");
                        getch();
                        exit(EXIT_SUCCESS);
                    }
                }
                else
                {
                    printf("Renvoi de la fonction menu() invalide.");
                }

            }
            else if (choix == 3)
            {
                printf("Vous revenez sur vos pas et arrivez au carrefour precedent.\n");
                getch();
                goto CarrefourForet;
            }
            else
            {
                printf("Renvoi de la fonction menu() invalide.");
            }

            }
            else if (choix == 3)
            {
                printf("Vous vous enfoncez dans le bois obscur et tombez sur un petit cours d'eau.\n");
                getch();
                printf("Vous etes fourbu par le long trajet que vous venez de faire.\n");
                getch();
                printf("Que faire ?\n1)Se baigner dans la riviere\n2)Essayer de pecher\n");
                printf("3)Retourner au campement\n");
                choix = menu(3);
                if (choix == 1)
                {
                    printf("Vous otez votre armure et entrez dans la riviere.\n");
                    getch();
                    printf("Vous tentez de nager vers l'autre rive.\n");
                    getch();
                    printf("Vous vous apercevez que le courant est beaucoup plus fort que vous ne le pensiez !\n");
                    getch();
                    printf("Vous luttez pour ne pas vous faire emmener.\n");
                    getch();
                    printf("Vos serviteurs sont impuissants sur la berge et vous regardent faiblir.\n");
                    getch();
                    printf("Allez vous vous en sortir ?\n");
                    getch();
                    printf("lancer de des...");
                    //compteTouche(ENTREE, 3);
                    de = lancerDeDes();
                    printf("Vous obtenez %d.\n", de);
                    getch();
                    if (de * partieEnCours->chance > 130)
                    {
                        printf("Victoire ! vous reussisez a vous extraire de la rivire.\n");
                    }
                    else
                    {
                        printf("Zute... vous vous noyez comme un pauvre nullos.\n");
                        getch();
                        printf("Selection naturelle mon pote !\n");
                        getch();
                        printf("Vous etes mort !\n");
                        getch();
                        exit(EXIT_SUCCESS);
                    }

                }
                else if (choix == 2)
                {
                    printf("Vous marchez le long de la rive et apercevez une barque au loin.\n");
                    getch();
                    printf("Vous vous empressez de monter a bord. Par chance.. un filet de peche !\n");
                    getch();
                    printf("Vous commencez a ramer, et distinguez un banc de poisson a l'horizon.\n");
                    getch();
                    printf("Que faire ?\n1)Se precipiter\n2)Y aller progressivement\n");
                    choix = menu(3);
                    if (choix == 1)
                    {
                        printf("Sans perdre de temps vous ramer a toute vitesse vers le manger !\n");
                        getch();
                        printf("Sans surprise, le banc de poisson a deguerpi !\n");
                        getch();
                        printf("Vous repartez bredouille, la queue entre les jambes.\n");
                        getch();
                        printf("De retour sur la rive, vos serviteurs vous attendent, feu allum�, estomac vide, pret a ingurgiter la peche du jour !\n");
                        getch();
                        printf("Ce n'est quand vous approchant d'eux qu'ils comprennent, qu'ils n'auront rien a becquetter..\n");
                        getch();
                        printf("Cette action vous affaiblit : vous perdez 20 points de vie.\n");
                        getch();
                        partieEnCours->pdV-=20;
                        printf("Vous et vos compagnons vous sentez faible, vous faites demi-tour.\n");
                        getch();
                        printf("De retour au campement, que voulez-vous faire ?\n");
                        goto Campement;
                    }
                    if (choix == 2)
                    {
                        printf("!");
                        getch();
                        printf("Sans surprise, ");
                    }

                }
                else if (choix == 3)
                {
                    printf("Vous changez d'avis et faites demi-tour. De retour au campement, que voulez-vous faire ?\n");
                    getch();
                    goto Campement;
                }
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
            printf("Vous ordonnez a vos serviteur d'aller chasser le gibier\n");
            getch();
            printf("Pendant ce temps, vous vous affalez le long de la rive..\n");
            getch();
            printf(".\n");
            getch();
            printf(".\n");
            getch();
            printf(".\n");
            getch();
            printf("Vous vous reveillez quelques minutes plus tard par l'odeur du giber entrain de cuir.\n");
            getch();
            printf("Vous vous relevez et allez rejoindre la troupe.\n");
            getch();
            printf("L'heure du festin a sonne !\n");
            getch();
            printf("Ce somme vous a redonne des forces, vous gagnez 70 points de vie et 15 points d'attaque.\n");
            partieEnCours->pdV += 70;
            partieEnCours->pdA += 15;
            affichageStats(*partieEnCours);
            getch();
            printf("Que faire ?\n");
            goto Campement;
        }
        else if (choix == 3)
        {
            printf("Vous marchez vers la tente quand..\n");
            getch();
            printf("Assis au loin entrain de revaser, vous voyez Jaskier.\n");
            getch();
            printf("Que faire ?\n1)Lui proposer un entrainement\n2)Apres tout vous etiez parti vous reposer\n");
            choix = menu(2);
            if (choix == 1)
            {
                printf("D'un pas cadence, vous avancer vers Jaskier.\n");
                getch();
                printf("Ce gueue est encore entrain de dormir.\n");
                getch();
                printf("Vous le reveillez a l'aide d'une grosse torgnole !\n");
                getch();
                printf("Il se leve aussitot en position de garde.\n");
                getch();
                printf("Vous lui balancez une epee a la gueule.\n");
                getch();
                printf("La bagarre !!!");
                getch();
                //combat("Jaskier", 500, 45, partieEnCours);
                //recompensesMonstre("", 50, partieEnCours);
                goto Dodo;
            }
            else if (choix == 2);
            {
Dodo:
                printf("Vous rentrez dans votre tente, et vous vous affalez dans votre lit.\n");
                getch();
                printf("Vous vous endormez comme un bebe...\n");
                getch();
                printf(".\n");
                getch();
                printf(".\n");
                getch();
                printf(".\n");
                getch();
                printf("Vous vous reveillez, quelques heures plus tard, pret a casser des gueules !\n");
                getch();
                printf("Que faire ?\n");
                goto Campement;
            }
        }
        else if (choix == 4)
        {
            printf("");
            goto MarcheRevilleauxBois;
        }
        else
        {
            printf("Renvoi de la fonction menu() invalide.");
        }


    }
    else if (choix == 2)
    {
        printf("Vous continuez vers le sud jusqu'au lendemain matin.\n");
        getch();
        printf("Vos hommes sont fourbus et affames, mais obeissent a vos ordres dans l'espoir d'obtenir le salut.\n");
        getch();
        //compteTouche(ENTREE, 3);
MarcheRevilleauxBois:
        printf("Vers 9 heures du matin, Schiappard la Fiotte finit par s'endormir sur son ane.\n");
        getch();
        printf("Que faire ?\n1)Le laisser dormir car de toute facon c'est une fiotte\n");
        printf("2)Ordonner a votre clairon de le reveiller\n3)Le corriger personnellement\n");
        choix = menu(3);
        if (choix == 1)
        {
            printf("La fiotte continue sa sieste.\n");
        }
        else if (choix == 2)
        {
            printf("Le clairon s'approche de l'ane de la fiotte et emet un son clair et puissant.\n");
            getch();
            printf("Schiappard sursaute et tombe de son canasson.\n");
            getch();
            printf("Il remonte laborieusement en proferant moult odieux jurons.\n");
        }
        else if (choix == 3)
        {
            printf("Du plat de votre bouclier, vous goumez les grands morts de la Fiotte.\n");
            getch();
            printf("Elle se reveille et se ressaisit un petit peu.\n");
            getch();
            printf("Ce goumage efficace vous a beaucoup appris. \n");
            getch();
            printf("Vous gagnez 15 points d'experience.\n");
            partieEnCours->XP+=15;
        }
        else
        {
            printf("Renvoi de la fonction menu() invalide.");
        }

    }
    else
    {
        printf("Renvoi de la fonction menu() invalide.");
    }
}

