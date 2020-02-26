#include "fonctionsDeBase.h"
#define MIN 1
#define MAX 100

int combat(char nomMonstre[50], int goumage, Partie *partieEnCours)
//fonction combat qui s'arrête quand le mob meurt ou qui interrompt le programme en cas de mort
{
    int choix;
    int crit = 0;
    Monstre monstre;
    monstre.pdV = ((goumage*goumage)/5)+100;
    monstre.critique = 10 + goumage*0.5;
    monstre.pdA = 50;//formule chiante
    monstre.xp = 50;//formule chiante
    int affrontement = 0;

    printf("1)Position offensive\n2)Position defensive\n3)Boire une lampee de vinasse\n");
    scanf("%d", &choix);
    while (affrontement = 1)
    {
        switch(choix)
        {
        case 1:

            srand(time(NULL));
            crit = (rand() % (MAX - MIN + 1)) + MIN;
            if (crit > partieEnCours->chance) // pas critique
            {
                printf("Vous brandissez votre epee et infligez %d degats\n", partieEnCours->pdA);
                monstre.pdV -= partieEnCours->pdV;
            }
            else // pas crit
            {
                printf("Bouyah, coup critique ! Vous goumez violemment les grands morts de votre adversaire\n");
                getch();
                printf("Vous infligez %d degats\n", (partieEnCours->pdA)*2);
                monstre.pdV -= (partieEnCours->pdA)*2;
            }
            break;
        case 2:
            printf("Apeuré vous vous mettez en PLS \n");
            break;
        case 3:
            printf("GlouGlou, vous recuperez %d points de vie !\n", (partieEnCours->pdV)*0.1);
            partieEnCours->pdV = (partieEnCours->pdV)*0.1;
            break;
        default:
            printf("Vous restez immobile a vous faire peter la rondelle \n");
            break;
        }
    }




}

int recompensesMonstre(char nomRecompense[100], int XPGagnee, Partie *partieEnCours)
//fonction qui génère le texte de récompense
//après avoir vaincu un mob
{

}


// boss pv = 20k puis 10k puis 5k
//ad joueur à la fin du game : 1000 env.
