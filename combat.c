#include "fonctionsDeBase.h"
#define MIN 1
#define MAX 100

int combat(char nomMonstre[100], int goumage, Partie *partieEnCours)
//fonction combat qui s'arrête quand le mob meurt ou qui interrompt le programme en cas de mort
{
    int choix;
    int crit = 0;
    Monstre monstre;
    monstre.pdV = ((goumage*goumage)/5)+100;
    monstre.critique = 10 + goumage*0.5;
    monstre.pdA = goumage*4 + 30;
    monstre.xp = 50*goumage;
    for (int i=0;i<100;i++)
    {
        monstre.nom[i] = nomMonstre[i];
    }
    int affrontement = 0;

    while (affrontement = 1)
    {
        printf("1)Attaquer\n2)Position defensive\n3)Boire une lampee de vinasse\n");
        scanf("%d", &choix);
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
            else //  critique
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
        printf("Monstre : %s\nPoints de vie : %d\nPoints ", monstre.nom, monstre.pdV);
        getch();
        printf("%s attaque !\n", monstre.nom);
        srand(time(NULL));
        crit = (rand() % (MAX - MIN + 1)) + MIN;
        if (crit > partieEnCours->chance) // pas crit
        {
            printf("Il vous inflige %d degats\n", monstre.pdA);
            partieEnCours->pdV -= monstre.pdA;
        }
        else //  crit
        {
            printf("BIG OOF, le monstre vous a mis une patate de forain sous steroide\n");
            getch();
            printf("Vous perdez %d points de vie\n", (monstre.pdA)*2);
            partieEnCours->pdV -= (monstre.pdA)*2;
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
