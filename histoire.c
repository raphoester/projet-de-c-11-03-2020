#define ENTREE 13
#define MIN 1
#define MAX 100
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#define TAILLE_PLATEAU 9
#include <conio.h>

void initJeu(Partie* partieEnCours)
{
    int secMax = 0;
    int appuyages = 0;
    printf("Bienvenue dans cette croisade, chevalier !\n");
    getch();
    system("cls");
    printf("En l'an de grace 1096, Godefroy de Bouillon, duc de Basse-Lotharingie, prend les armes aux cotes de son frere ");
    printf("Baudouin de Bourgogne, Hugues de Vermandois, Robert II de Normandie et Etienne de Blois.\n");
    getch();
    printf("Ces valeureux chevaliers partent a Jerusalem suivant l'appel du pape Urbain II pour");
    printf("delivrer le Saint Sepulcre, tombe aux mains des perfides Sarrasins. \n");
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

    printf("Maintenant, voyons voir si vous avez de la chance... (c'est fait au hasard, vous n'avez rien a faire)\n");
    //compteTouche(ENTREE, 2);
    srand(time(NULL));
    partieEnCours->chance = (rand() % (MAX - MIN + 1)) + MIN;
    printf("Ton indice de chance est de  %d !\n\n", partieEnCours->chance);
    getch();

    printf("Chevalier, tu es fin pret. Equipe toi, Jerusalem t'attend.\n");
    partieEnCours->XPMax = 100;
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
    int bouffe = 0;
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
        printf("1)Partir chasser\n2)Ordonner qu'on apporte des vivres pour se restaurer\n");
        if (bouffe >= 1)
        {
            printf("3)Dormir\n");
        }
        choix = menu(3);
        if (choix == 1)
        {
            printf("Vous partez chasser dans la foret de Verdun avec Demosthene.\n");
            getch();
            printf("Votre escuyer Schiappard la Fiotte, son ane et quelques pages vous accompagnent.\n");
            getch();
CarrefourForet :
            printf("Ou aller ?\n1)Nord\n2)Ouest\n3)Sud\n4)Est (retour au campement)\n");
            choix = menu(4);
            if (choix == 1)
            {
                printf("Vous prenez la direction du Nord avec vos serviteurs.\n");
                getch();
                printf("Apres quelque cheminement, vous tombez nez a nez avec un sanglier sauvage !\n");
                getch();
                printf("Il a l'air agressif et ne vous laisse pas le choix : il faut combattre !\n");
                getch();
                affichageStats(*partieEnCours);
                getch();
                printf("\n");
                if (combat("le sanglier sauvage", 10, partieEnCours) == 1) // si il a fui
                {
                    goto CarrefourForet;
                }
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
                        if (combat("Cousin Hubert", 17, partieEnCours) == 1)
                        {
                            printf("Votre couardise encourage cousin Hubert et il vous vole votre sanglier.\n");
                            printf("CHEH petit fragile.\n");
                            goto Campement;
                        }
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
                        getch();
                        printf("Il ne reste plus qu'a retourner au carrefour precedent.\n");
                        getch();
                        goto CarrefourForet;
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
                        printf("50 points d'XP recompensent ce comportement digne.\n");
                        getch();
                        experiencePlus(partieEnCours, 50);
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
                    bouffe +=1;
                    printf("Il n'y a plus rien a faire ici. Vous retournez au carrefour precedent.\n");
                    getch();
                    goto CarrefourForet;
                }
                else
                {
                    printf("Renvoi de la fonction menu() invalide");
                }
            }
            else if (choix == 2)
            {
                printf("Apres avoir suivi un petit sentier pendant quelques minutes, vous parvenez dans un champ de l'autre cote.\n");
                getch();
                printf("Non loin de la, un barrage de castors s'est installe sur un petit cours d'eau.\n");
                getch();
                printf("Que faire ?\n1)Se baigner dans la riviere\n2)Aller chasser le castor\n");
                printf("3)Rebrousser chemin vers le carrefour precedent\n");
                choix = menu(3);
                if (choix == 1)
                {
                    printf("Vous vous approchez de la riviere vous baignez sans enlever votre armure.\n");
                    getch();
                    printf("On est jamais trop mefiant avec les sarrasins.\n");
                    getch();
                    printf("Tandis que vous nagez avec aisance la brasse papillon dans l'eau fraiche et ravigotante, ");
                    printf("vous constatez que vos mouvements sont de plus en plus difficiles.");
                    getch();
                    printf("Votre armure est en train de rouiller !\n");
                    getch();
                    printf("Vous luttez a toute force contre la gravite qui vous entraine.\n");
                    getch();
                    printf("Allez vous vous en sortir ? Telle est la question...\n");
                    getch();
                    printf("Apppuyez sur une touche pour lancer le de.\n");
                    getch();
                    printf("Lancer de de en cours...\n");
                    compteTouche(ENTREE, 3);
                    if (lancerDeDes(partieEnCours) == 0)
                    {
                        printf("Vous reussissez a vous extraire de la riviere, chouette !\n");
                        getch();
                        printf("Par contre, cette aventure vous a epuise.\n");
                        getch();
                        printf("Vous perdez 70 points de vie et 15 points d'attaque.\n");
                        getch();
                        partieEnCours->pdV-=70;
                        partieEnCours->pdA-=15;
                        affichageStats(partieEnCours);
                        getch();
                        printf("Vous rentrez au campement pour vous reposer.\n");
                        goto Campement;
                   }
                    else
                    {
                        printf("Oopsi doo, spaghetti ooo... On dirait bien que vous etes mort noye.\n");
                        getch();
                        printf("Coup dur pour Godefroy de Bouillon.\n");
                        getch();
                        exit(EXIT_SUCCESS);

                    }
                }
                else if (choix == 2)
                {
                    printf("Vous vous approchez du barrage et les castors rentrent tous se cacher a l'interieur.\n");
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
                        if (combat("La bande de castors d'elite", 30, partieEnCours) == 1)
                        {
                            printf("Vous etes de retour au carrefour de la foret.\n");
                            goto CarrefourForet;
                        }

                        printf("Que faire maintenant ?\n1)Demolir le reste du barrage\n2)Manger les castors\n");
                        printf("3)Retourner au carrefour precedent\n");
                        choix = menu(4);
                        if (choix == 1)
                        {
                            printf("Vous continuez de deferler la colere divine sur le barrage.\n");
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
                                if (combat("La clique des castors pacifistes", 5, partieEnCours) == 1);
                                {
                                    printf("Quel genre de fiotte fuit face a des castors pacifiques ?\n");
                                    getch();
                                    printf("Cette couardise insupportable vous fait perdre 15 points d'attaque en prime.\n");
                                    getch();
                                    printf("Vous etes de retour au carrefour dans la foret.");
                                    getch();
                                    goto CarrefourForet;
                                }
                                getch();
                                printf("Il n'y a plus rien a faire ici. Appuyez sur une touche pour rebrousser chemin.\n");
                                getch();
                                goto CarrefourForet;
                            }
                            else if (choix == 2)
                            {
                                printf("Les castors retournent dans leur barrage en paix.\n");
                                getch();
                                printf("Cette bonne action vous rapporte 20 points d'XP.");
                                experiencePlus(partieEnCours, 20);
                                getch();
                                printf("Il n'y a plus rien a faire ici. Appuyez sur une touche pour rebrousser chemin.\n");
                                getch();
                                goto CarrefourForet;
                            }
                            else if (choix == 3)
                            {
                                printf("Les prieres des castors vous amadouent mais vous etes quand meme vachement venere.\n");
                                getch();
                                printf("Le barrage redevient un petit tas de bois informe qui flotte.\n");
                                getch();
                                printf("Cette action peu ecologique reveille la conscience de gauchiste de la Fiotte.\n");
                                getch();
                                printf("Il se met a chouiner comme un journaliste de Liberation.\n");
                                getch();
                                printf("Cette fois-ci vous n'avez pas le choix : il faut agir contre cette gangrene mentale.\n");
                                getch();
                                printf("*Goumage efficace de Schiappard la Fiotte en cours...*\n");
                                compteTouche(ENTREE, 3);
                                printf("Operation terminee avec succes.\n");
                                getch();
                                printf("Tout revigore, vous reprenez le cours de votre expedition.\n");
                                getch();
                                printf("Il n'y a plus rien a faire ici. Appuyez sur une touche pour rebrousser chemin.\n");
                                getch();
                                goto CarrefourForet;
                            }
                            else
                            {
                                printf("Renvoi de la fonction menu() invalide.\n");
                            }

                        }
                        else if (choix == 2)
                        {
                            printf("Vous attraper un castor par la queue et, d'un coup sec, vous lui scalpez sa fourrure\n");
                            getch();
                            printf("Pas besoin de le cuire, vous le preferez cru !\n");
                            getch();
                            printf("Vous vous empressez de croquer dans ce castor.\n");
                            getch();
                            printf("Ce repas vous a redonne des forces, vous gagnez 70 points de vie et 15 points d'attaque.\n");
                            partieEnCours->pdV += 50;
                            partieEnCours->pdA += 15;
                            printf("Il n'y a plus rien a faire ici, vous rebroussez chemin vers le carrefour precedent.\n");
                            getch();
                            goto CarrefourForet;
                        }
                        else if (choix == 3)
                        {
                            printf("Vous rebroussez chemin et retournez au carrefour.");
                            goto CarrefourForet;
                        }
                        else
                        {
                            printf("Renvoi de la fonction menu() invalide.\n");
                        }
                    }
                    else if (choix == 2)
                    {
                        printf("Vous etes un bon chretien et laissez tranquilles les malheureux castors.\n");
                        getch();
                        printf("Vous recuperez 30 XP pour la peine\n");
                        experiencePlus(partieEnCours, 30);
                        printf("Il n'y a plus rien a faire ici. Appuyez sur une touche pour rebrousser chemin.\n");
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
                printf("3)Rebrousser chemin\n");
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
                    compteTouche(ENTREE, 3);
                    if(lancerDeDes(partieEnCours) == 0)
                    {
                        printf("Victoire ! vous reussisez a vous extraire de la riviere.\n");
                        printf("Que faire ?\n1)Botter le cul a ces inutiles serviteurs\n2)Rebrousser chemin\n");
                        choix = menu(2);
                        if (choix == 1)
                        {
                            printf("Vous devisagez ces gredins et l'un d'entre eux-vous devisage avec son air hautain.\n");
                            getch();
                            printf("Il ne vous reste plus qu'a lui donner une lecon de vie.\n");
                            getch();
                            printf("Vous engagez le duel !\n");
                            getch();
                            affichageStats(*partieEnCours);
                            if (combat("Le gueux insubordonne", 15, partieEnCours) == 1);
                            {
                                printf("QUELLE FIOTTE !\n");
                                getch();
                                printf("Le gueux insubordonne prend la conf et vous derobe tout votre stock de poisson tandis que vous fuyez.\n");
                                getch();
                                printf("Vous n'avez plus de poisson, par contre, vous avez le seum...\n");
                                getch();
                                printf("Vous retournez, seul et triste, au carrefour de la foret pour vous refaire un peu a la chasse.\n");
                                goto CarrefourForet;
                            }
                            printf("Vous faites maintenant demi-tour. Vous etes de retour au carrefour.\n");
                            getch();
                            goto CarrefourForet;
                        }
                        else if (choix == 2)
                        {
                            printf("Vous faites demi-tour. Vous etes de retour au carrefour.\n");
                            getch();
                            goto CarrefourForet;
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
                else if (choix == 2)
                {
                    printf("Vous marchez le long de la rive et apercevez une barque au loin.\n");
                    getch();
                    printf("Vous vous empressez de monter a bord. Par chance.. vous y trouvez un filet de peche !\n");
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
                        printf("De retour sur la rive, vos serviteurs vous attendent, feu allume, estomac vide, pret a ingurgiter la peche du jour !\n");
                        getch();
                        printf("C'est seulement lorsque vous vous approchez qu'ils comprennent qu'ils n'auront rien a becquetter.\n");
                        getch();
                        printf("Cette nullite vous fait perdre confiance en vous : vous perdez 20 points de vie.\n");
                        getch();
                        partieEnCours->pdV-=20;
                        printf("Vous et vos compagnons vous sentez faible, vous faites demi-tour.\n");
                        getch();
                        printf("De retour au carrefour, que voulez-vous faire ?\n");
                        goto CarrefourForet;
                    }
                    else if (choix == 2)
                    {
                        printf("Sans perdre de temps vous ramez progressivement vers le manger.\n");
                        getch();
                        printf("Arrive a proximite, vous vous appretez a lancer le filet.\n");
                        getch();
                        printf("\n");
                        printf("*** jeu du lancer de filet ! ***\n");
                        getch();
                        /*printf("Dans trois secondes, appuyez sur Alt-F4 !\n");
                        compteTouche(ENTREE, 5);
                        printf("C'etait un piege, hohohoho\n");
                        getch();
                        printf("Pour vraiment avoir votre poisson, appuyez sur M comme Maman : M-A-M-A-N.\n");
                        compteTouche(ENTREE, 1);
                        printf("3...\n");
                        compteTouche(ENTREE, 1);
                        printf("2...\n");
                        compteTouche(ENTREE, 1);
                        printf("3...\n");
                        compteTouche(ENTREE, 1);
                        printf("5...\n");
                        compteTouche(ENTREE, 1);
                        printf("12...\n");
                        compteTouche(ENTREE, 1);
                        printf("40000...\n");
                        compteTouche(ENTREE, 1);
                        printf("GO !\n");
                        if (compteTouche(109 , 5) >= 1)
                        {
                            printf("C'etait un piege, mdrrrrrrrrrrrrr\n");
                            getch();
                            exit(EXIT_SUCCESS);
                        */
                        printf("Bravo vous avez chope de la poiscaille. Vous rentrez sur la berge\n");
                        getch();
                        printf("Que faire maintenant ?\n1)Rentrer au campement\n2)Rebrousser chemin\n3)Manger le poissonet\n");
                        choix = menu(3);
                        if (choix == 1)
                        {
                            printf("Vous etes de retour au campement.\n");
                            goto Campement;
                        }
                        else if (choix == 2)
                        {
                            printf("Vous etes de retour au carrefour dans la foret\n");
                            goto CarrefourForet;
                        }
                        else if (choix == 3)
                        {
                            printf("Heureux comme un poisson dans un l'eau, vous retournez sur la berge.\n");
                            getch();
                            printf("Tous vos serviteurs vous contemple comme un messi.\n");
                            getch();
                            printf("Ils ne savent peut-etre pas encore qu'ils vont seulement vous regarder manger !\n");
                            getch();
                            printf("Vous commencez a vous enfiler quelques poissons dans le cornet\n");
                            getch();
                            printf("Cette collation vous rapport 70 points de vie et 15 points d'attaque\n");
                            getch();
                            partieEnCours->pdV += 70;
                            partieEnCours->pdA += 15;
                            printf("Quand tout a coup, un pouilleux vient vers vous quemander du poisson\n");
                            getch();
                            printf("Que faire ?\n1)Partager son casse croute\n2)L'inviter a prendre la porte\n");
                            choix = menu(2);
                            if (choix == 1)
                            {
                                printf("Votre generosite a pris le dessus.\n");
                                getch();
                                printf("Votre bonne action vous rapporte 50 points d'XP\n");
                                getch();
                                experiencePlus(partieEnCours, 50);
                                affichageStats(*partieEnCours);
                                getch();
                                printf("\n");
                            }
                            else if (choix == 2)
                            {
                                printf("Vous continuez a manger, le regardant droit dans les yeux.\n");
                                getch();
                                printf("Le silence en dit long.\n");
                                getch();
                                printf("Il repart bredouille, la boule au ventre.\n");
                                getch();
                                printf("Cette mauvaise action vous retourne le cerveau\n");
                                getch();
                                printf("Vous perdez 10 pourcent de chance.\n");
                                getch();
                                partieEnCours->chance -= 10;
                                printf("\n");
                            }
                        }
                        else
                        {
                            printf("Renvoi de la fonction menu() invalide");
                        }
                        printf("Suite a ces aventures, vous rebroussez chemin vers le carrefour precedent.\n");
                        goto CarrefourForet;
                    }
                }
                else if (choix == 3)
                {
                    printf("Vous changez d'avis et faites demi-tour. De retour au campement, que voulez vous faire ?.\n");
                    goto Campement;
                }
            }
            else if (choix == 4)
            {
                printf("Vous changez d'avis et faites demi-tour. De retour au campement, que voulez vous faire ?.\n");
                goto Campement;
            }

            else
            {
                printf("Renvoi de la fonction menu() invalide");
            }

        }
        else if (choix == 2)
        {
            printf("Vous ordonnez a vos serviteurs d'aller chasser le gibier\n");
            getch();
            printf("Pendant ce temps, vous vous asseyez contre un arbre..\n");
            getch();
            printf(".\n");
            getch();
            printf(".\n");
            getch();
            printf(".\n");
            getch();
            printf("Vous vous reveillez quelques minutes plus tard a l'odeur du giber entrain de cuire.\n");
            getch();
            printf("Vous vous relevez et allez rejoindre la troupe.\n");
            getch();
            printf("L'heure du festin a sonne !\n");
            getch();
            printf("Le repas vous redonne des forces, vous gagnez 70 points de vie et 15 points d'attaque.\n");
            partieEnCours->pdV += 70;
            partieEnCours->pdA += 15;
            affichageStats(*partieEnCours);
            bouffe +=1;
            getch();
            printf("Que faire en attendant la nuit ?\n");
            getch();
            goto Campement;
        }
        else if (choix == 3)
        {
            printf("Vous marchez vers la tente quand..\n");
            getch();
            printf("Assis au loin en train de cirer ses bottes, vous voyez Cousin Hubert.\n");
            getch();
            printf("Que faire ?\n1)Le provoquer en duel car ses bottes sont plus brillantes que les votres\n");
            printf("2)Aller dormir comme c'etait initialement prevu\n");
            choix = menu(2);
            if (choix == 1)
            {
                printf("D'un pas decide, vous avancez vers Cousin Hubert.\n");
                getch();
                printf("Il se leve aussitot au garde a vous.\n");
                getch();
                printf("Vous lui tendez une epee.\n");
                getch();
                printf("En GAAAAARDE !!!\n");
                if (combat("Cousin hubert", 19, partieEnCours) == 1)
                {
                    printf("Bah alors on a peur de cousin Hubert?!\n");
                    getch();
                    printf("Pour la peine vous n'avez plus le droit de dormir.\n");
                    getch();
                    printf("Vous etes de retour au campement.\n");
                    bouffe = 0;
                    goto Campement;
                }
                printf("Vous pouvez prendre l'epee de Cousin Hubert qui est encore mort.\n");
                getch();
                printf("Le faire ou ne pas le faire ?\n1)Le faire\n2)Ne pas le faire\n");
                choix = menu(2);
                if (choix == 1)
                {
                    printf("En fait cette epee est completement eclatee au sol.\n");
                    getch();
                    printf("Vous perdez 30 points d'attaque\n");
                    partieEnCours->pdA -= 30;
                    affichageStats(*partieEnCours);
                }
                else if (choix == 2)
                {
                    printf("Bravo, le pillage c'est mal.\n");
                    getch();
                    printf("Vous gagnez 50 points d'experience car le pillage, c'est mal.\n");
                    getch();
                    experiencePlus(partieEnCours, 50);
                }
                getch();


            }
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
            printf("Vous vous reveillez le lendemain, pret a casser des gueules !\n");
            getch();
            printf("Que faire ?\n");
            goto Campement;
        }
    }
    else if (choix == 2)
    {
        printf("Vous continuez vers le sud jusqu'au lendemain matin.\n");
        getch();
        printf("Vos hommes sont fourbus et affames, mais obeissent a vos ordres dans l'espoir d'obtenir le salut.\n");
        getch();
        //compteTouche(ENTREE, 3);
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
            printf("Vous gagnez 50 points d'experience.\n");
            experiencePlus(partieEnCours, 50);
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
Jerusalem:
    printf("Quelques jours de marche plus tard.\n");
    getch();
    printf(".\n");
    getch();
    printf(".\n");
    getch();
    printf("Vous atteignez enfin la Terre Sainte.\n");
    getch();
    printf("Lorsqu'une tempete de sable approche.\n");
    getch();
    printf("Vous...\n");
    partieEnCours->marquePage = 2;
    sauvegarde(*partieEnCours);
    return 0;
}

void paris(Partie* partieEnCours)
{
    //au debut du niveau, il est en haut a gauche (nord ouest). il commencera par courir vers l'est.
    //Plus il ira vers le sud, plus les mobs seront forts.
    int maurice = 0;
    partieEnCours->x = 1;
    partieEnCours->y = 0;
    int choix = 0;
    printf("Vous vous reveillez sur un sol dur et froid, il y a beaucoup de bruit autour de vous.\n\n");
    getch();
    printf("Appuyez sur une touche pour ouvrir les yeux.\n");
    getch();
    printf("...\n");
//compteTouche(ENTREE, 2);
    printf("Vous etes dans une rue tres animee, couche devant une devanture.\n");
    getch();
    printf("Les locaux parlent une langue tres etrange qui ressemble au francois mais qui n'est point du francois.\n");
    getch();
    printf("De nombreux sarrasins affluent de toute part, et vous vous sentez en danger !\n");
    getch();
    printf("Vous vous relevez et vous mettez a courir.\n");
    getch();
    printf("Les sarrasins sont toujours aussi nombreux a mesure que vous avancez.\n");
    getch();
    printf("Vous remarquez partout autour de vous d'etranges chariottes colorees ");
    printf("qui avancent a balle sur des grandes pistes noires.\n");
    getch();
    printf("Peu apres, vous vous retrouvez face a un carrefour entre deux routes.\n");
    getch();
    printf("Le chemin a gauche semble bloque.\n");
    getch();
    printf("Ou aller ?\n1)Devant vous\n2)A droite\n");
    choix = menu(2);
    if (choix == 1)
    {
        choix = 3;
    }
    deplacementPlateau(choix, partieEnCours);

    while (1)
    {
        printf("coordonnees au debut de la grosse boucle while : x %d y %d \n", partieEnCours->x, partieEnCours->y);
        if (partieEnCours->x == 0 && partieEnCours->y == 0)
        {
            recit("Vous arrivez a une grande place circulaire.");
            recit("Au centre, une statue monumentale representant un monsieur sur son cheval.");
            recit("Un petit homme aux yeux minuscules se colle a vous en tenant un objet rectangulaire devant lui.");
            printf("Que faire ?\n1)Un sourire\n2)Goumer cette raclure cosmopolite\n");
            choix = menu(2);
            if (choix == 1)
            {
                recit("Votre sourire devoile la verite sur votre hygiene dentaire et effraie le pauvre chinois.");
                recit("Felicitationns ! Vous avez degoute un touriste de Paris.");
                recit("Il ne reviendra plus, vous pouvez etre fier de vous !");
                recit("Vous remportez 30 points d'experience.");
                experiencePlus(partieEnCours, 30);
                affichageStats(*partieEnCours);
            }
            else
            {
                if (combat("Le chinois asthmatique", 2, partieEnCours) == 1)
                {
                    getch();
                    recit("\nVous avez fui devant le chinois asthmatique.");
                    recit("Vous mourrez instantanement a cause d'une surcharge de fragilite.");
                    recit("FIN DU JEU");
                    exit(EXIT_SUCCESS);
                }
            }
            printf("Ou aller maintenant ?\n1)Est\n2)Sud\n");
            choix = menu(2);
            if (choix = 1)
            {
                choix = 3;
            }
            deplacementPlateau(choix, partieEnCours);
        }
        else if (partieEnCours->x == 1 && partieEnCours->y == 0)
        {
            recit("Vous arrivez a un carrefour absolument nul avec rien au milieu.");
            recit("Il n'y a rien a faire, a part quelques gourgandines fort peu vetues.");
            recit("Mais vous n'avez pas le coeur a besogner la gourgandine pour le moment.");
            printf("Vers ou continuer votre route ?\n1)Ouest\n2)Sud\n3)Est\n");
            choix = menu(3);
            if (choix == 1)
            {
                choix = 4;
            }
            deplacementPlateau(choix, partieEnCours);
        }
        else if (partieEnCours->x == 2 && partieEnCours->y == 0)
        {
            getch();
            if (maurice == 0)
            {
                printf("Vous arrivez a un nouveau croisement de deux routes.\n");
                getch();
                printf("Le lieu est toujours rempli a ras bord de sarrasins.\n");
                getch();
                printf("Vous decidez de jouer la ruse pour ne pas vous faire reperer en territoire hostile et decidez de n'en decapiter aucun.\n");
                getch();
                printf("Sur le bord du trottoir, un vieillard est assis par terre devant un gobelet.\n");
                getch();
                printf("Il n'a pas l'air presse.\nQue faire ?\n1)Lui demander ce que c'est que ce foutoir\n");
                printf("2)Poursuivre sa route\n");
                choix = menu(2);
                if (choix == 1)
                {
                    recit("GODEFROY : Hola, vieillard, quel est cet etrange endroit infeste de sarrasins ?");
                    recit("MAURICE : Eh beh c'est le quartier du marais mon pote...");
                    recit("GODEFROY : Ce marais ne m'inspire pas confiance.");
                    recit("GODEFROY : Et dis moi, dans quelle ville sommes nous ? Dans quel pays ?");
                    recit("MAURICE : T'es maboule ou quoi ? On est en France, a Paris.");
                    recit("Le Paris que vous connaissez n'a rien a voir avec le spectacle qui s'offre a vous.");
                    recit("GODEFROY : Et en quelle annee ? Parle !");
                    recit("MAURICE : Ben, on est en 2020, mon pote... T'as un peu force sur la villageoise, toi.");
                    recit("MAURICE : Au fait, t'as pas une ptite piece ?");
                    recit("Vous sortez un gros tas de pieces de votre poche et en aspergez Maurice.");
                    recit("GODEFROY : Tiens, mon brave ! voici des ecus sonnants et trebuchants pour ta peine.");
                    recit("Maurice est absolument abasourdi de la pluie de dorure qui vient de s'abattre devant lui.");
                    recit("Il vous promet qu'il n'oubliera pas ce geste noble et ouvre une 8:6 en votre honneur.");
                    recit("Cela vous rend tout joyeux et le fait de vous etre fait un pote vous revigore.");
                    recit("Vous remportez 30 points d'experience en l'honneur de Maurice.");
                    experiencePlus(partieEnCours, 30);
                    affichageStats(*partieEnCours);
                    recit("Il mentionne au passage son nom : Maurice.");
                    printf("Mefiant, vous continuez votre route, abasourdi que la capitale de la France");
                    recit(" soit a ce point envahie de sarrasins en 2020.");
                    maurice = 1;
                }
                else if (choix == 2)
                {
                    recit("Vous faites une pause pour faire le point.");
                    recit("Tout le monde vous devisage sans que vous ne compreniez pourquoi.");
                    recit("Vous grimpez neanmoins a un lampadaire pour comprendre un peu mieux la geographie du lieu.");
                    recit("Le clochard par terre vous regarde avec un air etonne.\n");
                    recit("Un monsieur habille en bleu s'approche de vous et vous crie dessus.\n");
                    recit("Apparemment, il veut que vous descendiez de la.");
                    recit("Cette demande imperieuse vous enerve au plus haut point.");
                    recit("Vous descendez effectivement de votre lampadaire, mais vous tirez votre epee et engagez un duel avec lui !");
                    recit("Immediatement, tout le monde se met a hurler et a courir dans tous les sens.");
                    recit("\"Quelle epoque de tarlouzes...\" - pensez-vous en attaquant le policier.");
                    combat("Le policier", 20, partieEnCours);
                    recit("Tandis que le monsieur en bleu git a vos pieds et que la rue est deserte, vous reprenez votre chemin.");
                }
            }
            else
            {
                recit("Vous etes de retour a l'endroit ou vous avez rencontre Maurice.");
                recit("Il semblerait que Maurice en a eu marre de faire la manche et est parti profiter de votre argent.");
                recit("Brave Maurice.");
            }
            recit("Vers ou aller ensuite ?\n1)Est\n2)Sud\n3)Ouest\n");
            choix = menu(3);
            if (choix == 1)
            {
                choix = 3 ;
            }
            else if (choix == 3)
            {
                choix = 4 ;
            }
            deplacementPlateau(choix, partieEnCours);
        }
        else if (partieEnCours->x == 3 && partieEnCours->y == 0)
        {
            recit("Vous arrivez a un nouveau carrefour.");
            recit("Devant vous, la grande rue continue mais a votre droite il y a un petit passage d'ou sort un splendide rayon de soleil.");
            recit("Soudain, surgissent devant vous des enfants montes sur des diaboliques appareils a roulettes !");
            recit("Vous tentez mutuellement de vous esquiver mais sans succes.");
            recit("L'un d'eux vous percute de plein fouet tandis que l'autre finit sa course en zigzaguant dans un lampadaire.");
            printf("Que faire ?\n1)Se battre\n2)Les aider a se relever \n3)S'en aller");
            choix = menu(3);
            if (choix == 1)
            {
                if (combat("Le gang des caids en trottinette", 8, partieEnCours)==1)
                {
                    recit("OOF, vous etes un gros fragile.");
                    printf("Ou fuir ?\n1)Ouest\n2)Sud\n3)Est");
                    choix = menu(3);
                    if (choix == 1)
                    {
                        choix = 4;
                    }
                    deplacementPlateau(choix, partieEnCours);
                }
                recit("Vous gagnez une trottinette ! dorenavant, vous vous deplacez en trottinette.");
                recit("Cela vous permet de vous fondre beaucoup mieux dans la masse.");
                int trottinette = 1;
                printf("Ou aller ensuite ?\n1)Ouest\n2)Sud\n3)Est");
                choix = menu(3);
                if (choix == 1)
                {
                    choix = 4;
                }
                deplacementPlateau(choix, partieEnCours);
            }
            else if (choix == 2)
            {
                recit("Vous contemplez les trotinetteurs prepuberes pleurer sur le parterre et votre coeur s'etreint.");
                recit("Vous les saisissez chacun par un bras et les remettez sur pied avec une tape dans le dos.");
                recit("L'un d'eux s'ecroule sous l'effet de cette frappe pourtant amicale.");
                recit("Ca lui apprendra a etre un fragile.");
                recit("Cette bonne action vous rapporte 50 points d'experience.");
                experiencePlus(partieEnCours, 50);
                printf("Ou aller ensuite ?\n1)Ouest\n2)Sud\n3)Est");
                choix = menu(3);
                if (choix == 1)
                {
                    choix = 4;
                }
                deplacementPlateau(choix, partieEnCours);
            }
            else if (choix == 3)
            {
                recit("Avec un gros rire de chevalier rempli de testosterone, vous tracez votre chemin.");
                printf("Ou aller ensuite ?\n1)Ouest\n2)Sud\n3)Est");
                choix = menu(3);
                if (choix == 1)
                {
                    choix = 4;
                }
                deplacementPlateau(choix, partieEnCours);
            }
        }
        else
        {
            recit("Cette partie du jeu n'est pas encore construite, revenez plus tard !");
            recit("Vous pouvez cependant entrer des coordonnees pour vous teleporter ou vous voulez en attendant.");
            printf("Entrez une valeur pour x : ");
            scanf("%d", &(partieEnCours->x));
            printf("Entrez une valeur pour y : ");
            scanf("%d", &(partieEnCours->y));
            recit("Teleportation...");
            recit("Fait !");
        }
    }
}
