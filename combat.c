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
    monstre.xp = 4*goumage;
    int defense = 0;
    for (int i=0;i<100;i++)
    {
        monstre.nom[i] = nomMonstre[i];
    }
    printf("Le combat avec %s commence ! En garde !\n", monstre.nom);
    getch();
    while (1)
    {
        defense = 0;
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
            printf("Vous vous mettez en position defensive.\n");
            defense = 1;
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
            if (defense)
            {
                printf("Grace a votre position defensive, %s vous inflige seulement %d degats.\n", monstre.nom, (monstre.pdA)/2);
                getch();
                printf("Vous parvenez a riposter et infligez %d degats !\n", partieEnCours->pdD + (lancerDeDes(partieEnCours)*(partieEnCours->pdA/2)));
                getch();
            }
            else
            {
                printf("%s vous inflige %d degats.\n", monstre.nom, monstre.pdA);
                partieEnCours->pdV -= monstre.pdA;
                getch();
            }

        }
        else //  crit
        {
            printf("BIG OOF, %s vous a mis une patate de forain sous steroide.\n", monstre.nom);
            getch();
            printf("Vous perdez %d points de vie.\n", ((monstre.pdA)*2));
            partieEnCours->pdV -= ((monstre.pdA)*2);
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
void combatJeanLassalle(Partie *partieEnCours)
//fonction combat qui retourne 0 quand le mob meurt, 1 quand le joueur prend la fuite ou qui interrompt le programme en cas de mort
{
    int choix;
    int crit = 0;
    Monstre jeanLassalle;
    jeanLassalle.pdV = 17000
    jeanLassalle.critique = 3;
    jeanLassalle.pdA = 700
    int defense = 0;
    int sort = 3;
    int changement = 0;

    printf("Le combat avec Jean Lassalle commence ! En garde !\n");
    while (1)
    {
        defense = 0;
        printf("Vous avez %d points de vie et %d points d'attaque.\n", partieEnCours->pdV, partieEnCours->pdA);
        printf("Jean Lassalle a %d points de vie et %d points d'attaque.\n", jeanLassalle.pdV, jeanLassalle.pdA);
        getch();
        printf("Que faire ?\n");
        printf("1)Attaquer\n2)Position defensive\n3)Boire une lampee de vinasse\n");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1:
            srand(time(NULL));
            crit = (rand() % (MAX - MIN + 1)) + MIN;
            if (crit > partieEnCours->chance) // pas critique
            {
                printf("Vous brandissez votre epee et infligez %d points de degats.\n", partieEnCours->pdA);
                jeanLassalle.pdV -= partieEnCours->pdA;
            }
            else //  critique
            {
                printf("Bouyah, coup critique ! Vous goumez violemment les grands morts de Jean Lassalle.\n");
                getch();
                printf("Vous infligez %d degats.\n", (partieEnCours->pdA)*2);
                jeanLassalle.pdV -= (partieEnCours->pdA)*2;
            }
            break;
        case 2:
            printf("Vous vous mettez en position defensive.\n");
            defense = 1;
            break;
        case 3:
            printf("GlouGlou, vous recuperez %d points de vie !\n", jeanLassalle.pdA + 100);
            partieEnCours->pdV += (jeanLassalle.pdA + 100);
            break;
        default:
            printf("Vous restez immobile a vous faire peter la rondelle par Jean Lassalle.\n");
            break;
        }
        if (monstre.pdV <= 0)
        {
            getch();
            printf("Vous avez vaincu Jean Lassalle !\n", monstre.nom);
            getch();
            return 0;
        }
        getch();
        printf("Jean Lassalle a %d points de vie.\nVous avez %d PV et %d Points d'attaque.\n", jeanLassalle.pdV, partieEnCours->pdV, partieEnCours->pdA);
        getch();
        printf("Jean Lassalle attaque !\n");
        getch();
        if (sort == 0)
        {
            recit("Jean Lassalle utilise sa motoculteuse magique pour infliger des degats collossaux !");
        }
        else if (sort == 1)
        {
            recit("Jean Lassalle vous frappe avec sa houlette magique !");
        }
        else if (sort == 2)
        {
            recit("Jean Lassalle vous eternue sur la tronche ! C'est un coup devastateur en vertu de son nez gigantesque.");
        }
        else if (sort == 3)
        {
            recit("Jean Lassalle fait appel a la puissance des pyrenees et devient fort comme une montagne !");
            recit("Il gagne 500 points de vie.");
            jeanLassalle.pdV += 500;
        }
        else if (sort == 4)
        {
            recit("Jean Lassalle recupere 500 points de vie en avalant de la bonne vinasse du sud-ouest avec de l'Etorki.");
            jeanLassalle.pdV += 500;
        }
        if (sort == 5)
        {
            sort = 0;
        }
        else if (sort == -1)
        {
            sort = 4;
        }
        if (lancerDeDes(partieEnCours)==1)
        {
            changement = 1;
        }
        else
        {
            changement -= 1;
        }
        sort += changement ;
        if (jeanLassalle.pdA >= 300 && )
        {
            jeanLassalle.pdA -= (lancerDeDes(partieEnCours)*500);
        }
        else
        {
            jeanLassalle.pdA = 700;
        }
        srand(time(NULL));
        crit = (rand() % (MAX - MIN + 1)) + MIN;
        if (crit > partieEnCours->chance) // pas crit
        {
            if (defense)
            {
                printf("Grace a votre position defensive, %s vous inflige seulement %d degats.\n", monstre.nom, (monstre.pdA)/2);
                getch();
                printf("Vous parvenez a riposter et infligez %d degats !\n", partieEnCours->pdD + (lancerDeDes(partieEnCours)*(partieEnCours->pdA/2)));
                getch();
            }
            else
            {
                printf("Jean Lassalle vous inflige %d degats.\n", jeanLassalle.pdA);
                partieEnCours->pdV -= jeanLassalle.pdA;
                getch();
            }
        }
        else //  crit
        {
            printf("OOF, coup critique. Jean Lassalle vous a fait gouter a la vraie puissance du pays basque.\n");
            getch();
            printf("Vous perdez %d points de vie.\n", ((jeanLassalle.pdA)*2));
            partieEnCours->pdV -= ((jeanLassalle.pdA)*2);
            getch;
        }
        // mort
        if (partieEnCours->pdV <= 0)
        {
            getch();
            printf("Vous n'etiez pas de taille face a Jean Lassalle.\n");
            getch();
            recit("L'aventure s'arrete ici pour vous. ");
            recit"Vous etes condamne a etre son esclave jusqu'a la fin de vos jours.");
            printf("FIN DU JEU\n");
            getch();
            exit(EXIT_SUCCESS);
        }
    }
}


