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
    int pdD;
    int XP;
    int XPMax;
    int chance;
    int niveau;
    int marquePage;
    int x;
    int y;
};
