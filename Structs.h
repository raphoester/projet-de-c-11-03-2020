typedef struct Monstre Monstre;
struct Monstre{
    int pdV;
    int pdA;
    int critique;
    int xp;
    char nom[100];
};
typedef struct Partie Partie;
struct Partie
{
    int pdV;
    int pdA;
    int XP;
    int XPMax;
    int chance;
    int difficulte;
    int marquePage;
    int niveau;
    int x;
    int y;
};
