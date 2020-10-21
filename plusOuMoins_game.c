#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LevelGame()
{
    int level;
    printf("*** Choisissez le niveau du jeu ***:\n");
    printf("1. Niveau Facile => Nombre mystère entre 1 et 100\n");
    printf("2. Niveau Medium => Nombre mystère entre 1 et 1000\n");
    printf("3. Niveau Difficile => Nombre mystère entre 1 et 10000\n");
    scanf("%d", &level);
    return level;
}

int modePlayers()
{
    int mode;
    printf("=== Bienvenue dans le Jeu Plus Ou Moins ===\n");
    printf("Choisissez votre mode:\n");
    printf("1. Mode 1 Joueur\n");
    printf("2. Mode 2 Joueurs\n");
    scanf("%d", &mode);
    return mode;
}

void Game (int nbreMystere, int valeur)
{
    int nbreDeCoups = 0;
    while (valeur != nbreMystere)
    {
        nbreDeCoups++;
        printf("Quel est le nombre ? ");
        scanf("%d", &valeur);
        if (valeur > nbreMystere)
        {
            printf("C'est moins !\n");
        } else if (valeur < nbreMystere)
        {
            printf("C'est plus !\n");
        } else {
            printf("Bravo, vous avez trouvé le nombre mystere en %d coups!\n", nbreDeCoups);
        }
    }
}

void OnePlayer(int MAX)
{
    const int MIN = 1;
    int nbreMystere, valeur = 0;
    srand(time(NULL));
    nbreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    Game(nbreMystere, valeur);
}

void TwoPlayers ()
{
    int nbreMystere = 0, valeur = 0;
    printf("Entrer le nombre mystère ");
    scanf("%d", &nbreMystere);
    Game(nbreMystere, valeur);
}

void main()
{
    int level, mode;
    mode = modePlayers();
    if (mode == 1)
    {
        level = LevelGame();
        switch (level)
        {
        case 1:
            OnePlayer(100);
            break;
        case 2:
            OnePlayer(1000);
            break;
        case 3:
            OnePlayer(10000);
            break;
        
        default:
            break;
        }
    } else if (mode == 2)
    {
        TwoPlayers();
    }
}