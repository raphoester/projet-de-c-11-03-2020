#define MIN 1
#define MAX 100
#include "Structs.h"
#include <stdlib.h>

int combat(char nomMonstre[100], int goumage, Partie *partieEnCours)
//fonction combat qui retourne 0 quand le mob meurt, 1 quand le joueur prend la fuite ou qui interrompt le programme en cas de mort
{
    int choix;
    int crit = 0;
    Monstre monstre;
    monstre.pdV = ((goumage*goumage)/5)+100;
    monstre.critique = 3;
    monstre.pdA = goumage*4 + 30;
    monstre.xp = 50*goumage;
    int reduction = 1;
    for (int i=0;i<100;i++)
    {
        monstre.nom[i] = nomMonstre[i];
    }
    printf("Le combat avec %s commence ! En garde !\n", monstre.nom);
    getch();
    int affrontement = 1;
    while (affrontement = 1)
    {
        reduction = 1;
        printf("Vous avez %d points de vie et %d points d'attaque.\n", partieEnCours->pdV, partieEnCours->pdA);
        printf("%s a %d points de vie et %d points d'attaque.\n", monstre.nom, monstre.pdV, monstre.pdA);
        getch();
        printf("Que faire ?\n");
        printf("1)Attaquer\n2)Position defensive\n3)Boire une lampee de vinasse\n4)Fuir\n");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1:
            srand(time(NULL));
            crit = (rand() % (MAX - MIN + 1)) + MIN;
            if (crit > partieEnCours->chance) // pas critique
            {
                printf("Vous brandissez votre epee et infligez %d points de degats.\n", partieEnCours->pdA);
                monstre.pdV -= partieEnCours->pdA;
            }
            else //  critique
            {
                printf("Bouyah, coup critique ! Vous goumez violemment les grands morts de %s.\n", monstre.nom);
                getch();
                printf("Vous infligez %d degats.\n", (partieEnCours->pdA)*2);
                monstre.pdV -= (partieEnCours->pdA)*2;
            }
            break;
        case 2:
            printf("Apeure, vous vous mettez en PLS.\n");
            reduction = 2;
            break;
        case 3:
            printf("GlouGlou, vous recuperez %d points de vie !\n", monstre.pdA + 100);
            partieEnCours->pdV += (monstre.pdA + 100);
            break;
        case 4:
            printf("Vous prenez vos jambes a votre cou tel une fiotte.\n");
            getch();
            printf("Vous perdez un quinzieme de vos points de vie dans l'aventure.");
            partieEnCours->pdV *= 0.9;
            return 1;
        default:
            printf("Vous restez immobile a vous faire peter la rondelle.\n");
            break;
        }
        if (monstre.pdV <= 0)
        {
            getch();
            printf("Vous avez vaincu %s !\n", monstre.nom);
            getch();
            printf("Vous remportez %d points d'experience.\n", monstre.xp);
            experiencePlus(partieEnCours, monstre.xp);
            return 0;
        }
        getch();
        printf("%s a %d points de vie.\nVous avez %d PV et %d Points d'attaque.\n", monstre.nom, monstre.pdV, partieEnCours->pdV, partieEnCours->pdA);
        getch();
        printf("%s attaque !\n", monstre.nom);
        getch();
        srand(time(NULL));
        crit = (rand() % (MAX - MIN + 1)) + MIN;
        if (crit > partieEnCours->chance) // pas crit
        {
            printf("Il vous inflige %d degats.\n", (monstre.pdA)/reduction);
            partieEnCours->pdV -= monstre.pdA;
            getch();
        }
        else //  crit
        {
            printf("BIG OOF, %s vous a mis une patate de forain sous steroide.\n", monstre.nom);
            getch();
            printf("Vous perdez %d points de vie.\n", ((monstre.pdA)*2)/reduction);
            partieEnCours->pdV -= ((monstre.pdA)*2)/reduction;
            getch;
        }
        // mort
        if (partieEnCours->pdV <= 0)
        {
            getch();
            printf("Oh, on dirait bien que vous vous etes fait rouler dessus par %s.\n", monstre.nom);
            getch();
            printf("FIN DU JEU\n");
            getch();
            exit(EXIT_FAILURE);
        }
    }
}

int recompensesMonstre(char nomRecompense[100], int XPGagnee, Partie *partieEnCours)
{

}
