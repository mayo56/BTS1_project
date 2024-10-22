#include <stdio.h>

// Fonction obligatoires
void initTicTacToeTab(int tab[3][3]);

void displayTicTacToeTab(int tab[3][3]);

void askPlayerToPlay(int tab[3][3], int joueur);

int isPlayerWin(int grille[3][3], int joueur);

// Sous Fonction
void asError(unsigned short input, unsigned short length);

unsigned short isFreePosition(int tab[3][3], unsigned short position[2]);

int isTicTacToeFull(int tab[3][3]);

void main(void) {
    // Variable tableau du morpion
    int tic_tac_toe[3][3];
    initTicTacToeTab(tic_tac_toe); // init

    while (1) {
        displayTicTacToeTab(tic_tac_toe);

        ////////
        // TOUR: Joueur N'1
        /////
        // JEU
        askPlayerToPlay(tic_tac_toe, 1);
        // VERIFICATIONS
        if (isPlayerWin(tic_tac_toe, 1)) {
            // Victoire
            displayTicTacToeTab(tic_tac_toe);
            printf("\n\x1B[102m\x1B[97mLe joueur 1 a gagné !\x1B[0m");
            return;
        }
        if (isTicTacToeFull(tic_tac_toe)) {
            // Grille pleine (le full ne peut être que sur le joueur n'1)
            displayTicTacToeTab(tic_tac_toe);
            printf("\n\x1B[43m\x1B[97mÉgalité entre le jouer n'1 et le joueur n'2 !\x1B[0m");
            return;
        }

        displayTicTacToeTab(tic_tac_toe);

        //////////
        // TOUR: Joueur N'2
        ///////
        askPlayerToPlay(tic_tac_toe, 2);
        if (isPlayerWin(tic_tac_toe, 2)) {
            displayTicTacToeTab(tic_tac_toe);
            printf("\n\x1B[102m\x1B[97mLe joueur 2 a gagné !\x1B[0m");
            return;
        }
    }
}

/**
 * Initialise la grille de morpion à 0.
 * @param tab Tableau du morpion
 */
void initTicTacToeTab(int tab[3][3]) {
    // Boucle qui parcourt le tableau
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            tab[i][k] = 0; // Initialisation à 0 car case vide
        }
    }
}

/**
 * Affiche, dans le terminal, la grille du morpion.
 * @param tab Tableau du morpion
 */
void displayTicTacToeTab(int tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("\x1B[107m\x1B[30m"); // Fond blanc, texte noir
        for (int k = 0; k < 3; k++) {
            printf("\x1B[107m\x1B[30m"); // Fond blanc, texte noir
            switch (tab[i][k]) {
                default: // 0
                    printf("   ");
                    break;
                case 1:
                    printf("\x1B[1m\x1B[31m X \x1B[0m");
                    break;
                case 2:
                    printf("\x1B[1m\x1B[94m O \x1B[0m");
                    break;
            }
            printf("\x1B[107m\x1B[30m");
            if (k < 2) printf(" ║ ");
            else printf("\x1B[0m");
        }
        if (i < 2) printf("\n\x1B[107m\x1B[30m════╬═════╬════\x1B[0m");
        printf("\n");
    }
}

/**
 * Demande au joueur la position qu'il désire prendre
 * et l'ajoute sur la grille du morpion si la position
 * est valide.
 * @param tab Tableau du morpion
 * @param joueur Numéro du joueur qui joue
 */
void askPlayerToPlay(int tab[3][3], int joueur) {
    unsigned short position[2] = {0, 0}; // {x,y}
    unsigned short isValid = 1; // 0: false | 1: true

    ////////
    // Demande d'emplacement
    //////
    do {
        if (isValid == 0) {
            printf("\x1B[101m\x1B[97mEmplacement déjà occupé par le joueur adverse.\x1B[0m\n");
        }

        // Demande en X
        do {
            asError(position[0], 3); // Vérification des erreurs

            if (joueur == 1) {
                // si joueur 1 : rouge
                printf("\x1B[91mJoueur %d\x1B[0m : X (0-2): ", joueur);
            } else {
                // sinon : bleue
                printf("\x1B[96mJoueur %d\x1B[0m : X (0-2): ", joueur);
            }
            scanf("%hd", &position[0]);
        } while (position[0] > 3);

        // Demande en Y
        do {
            asError(position[1], 3); // Vérification des erreurs

            if (joueur == 1) {
                // si joueur 1 : rouge
                printf("\x1B[91mJoueur %d\x1B[0m : Y (0-2): ", joueur);
            } else {
                // sinon : bleue
                printf("\x1B[96mJoueur %d\x1B[0m : Y (0-2): ", joueur);
            }
            scanf("%hd", &position[1]);
        } while (position[1] > 3);
        isValid = isFreePosition(tab, position);
    } while (isValid == 0);

    ////////
    // Changement des valeurs
    /////
    tab[position[1]][position[0]] = joueur;
}

/**
 * Génère une erreur lorsque l'input dépasse la taille maximum.
 * @param input Entrée donnée par le joueur
 * @param length La taille maximum que l'entrée ne doit pas dépasser
 */
void asError(unsigned short input, unsigned short length) {
    if (input > length) printf("\x1B[101m\x1B[97mError input\x1B[0m\n");
}

/**
 * Vérifie si l'emplacement (x, y) donnée par le joueur est libre
 * sur la grille du morpion.
 * @param tab Tableau du morpion
 * @param position Positions données par le joueur
 * @return 0 : Emplacement non libre \n 1 : Emplacement libre
 */
unsigned short isFreePosition(int tab[3][3], unsigned short position[2]) {
    if (tab[position[1]][position[0]] == 0) {
        return 1; // Si libre
    }
    return 0; // Si non libre
}

/**
 * Vérification de victoire d'un joueur.
 * @param grille Tableau du morpion
 * @param joueur Numéro du joueur qui joue
 * @return 0 : Le joueur n'a pas encore gagné \n 1 : Le joueur a gagné
 */
int isPlayerWin(int grille[3][3], int joueur) {
    const int max = 3;
    /////////
    // Vérification horizontales
    //////
    for (int i = 0; i < max; i++) {
        int res = 0; // Nombre d'occurence
        for (int k = 0; k < max; k++) {
            if (grille[i][k] == joueur) {
                // grille[x][y]
                res += 1;
            }
        }
        if (res == 3) return 1;
    }

    //////////
    // Vérifications verticales
    ///////
    for (int i = 0; i < max; i++) {
        int res = 0; // Nombre d'occurence
        for (int k = 0; k < max; k++) {
            if (grille[k][i] == joueur) {
                // grille[y][x]
                res += 1;
            }
        }
        if (res == 3) return 1;
    }

    //////////
    // Vérifications diagonales
    //////
    /// DROITE
    int diag_droit = 0;
    for (int i = 0; i < max; i++) {
        for (int k = 0; k < max; k++) {
            if (i == k && grille[i][k] == joueur) diag_droit++;
        }
    }
    if (diag_droit == max) return 1;
    /// GAUCHE
    int diag_gauche = 0;
    for (int i = 0; i < max; i++) {
        for (int k = 0; k < max; k++) {
            if (i == k && grille[i][k] == joueur) diag_droit++;
        }
    }

    // Si rien ne correspond, alors le joueur n'a pas encore gagné.
    return 0;
}

/**
 * Vérifie si la grille du morpion est pleine.
 * @param tab Tableau du morpion
 * @return 1 : La grille est pleine \n 0 : La grille n'est pas pleine.
 */
int isTicTacToeFull(int tab[3][3]) {
    int res = 0;
    // On cherche à savoir combien de cases sont occupées
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (tab[i][k] == 1 || tab[i][k] == 2) res++; // Ajoute 1 à res
        }
    }
    // On fait le calcul
    if (res - 9 == 0) return 1;
    return 0;
}
