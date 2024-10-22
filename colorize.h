// -*- C++ -*-
//===----------------------------------------------------------------------===//
// LIBRAIRIE OPEN SOURCE POUR LES COURS
// Crée par : Maxence LE ROY, BTS CIEL à VANNES.
//
// Librairie permettant de donner un style MS-DOS à l'affichage dans le
// terminal et liste des codes couleurs de texte et ee fond pour le texte
// affiché dans le terminal.
//===----------------------------------------------------------------------===//


#ifndef COLORIZE_H
#define COLORIZE_H

namespace clr {
    /**
    * Classe de colorisation du terminal. Affiche une fenêtre style MS-DOS
    * dans le terminal en fonction des règles transmises.
    *
    * ```c++
    * auto windows = clr::Colorize("myWindow", 5);
    * ```
    */
    class Colorize {
    public:
        std::string title; // titre
        unsigned long tailleTitre; // taille du titre
        unsigned int tailleFenetre; // taille de la fenêtre
        std::string backgroundColor; // couleur de la fenêtre

        Colorize(const std::string &titre, unsigned int taille = 2, std::string bg = "\x1B[46m");

        void GenerateWindowsTitle();

        void GenerateWindowsDescription(const std::string &description);

        void GenerateEndWindows();
    };

    void ClearSpace();

    unsigned short GenerateUShortQuestion(const std::string &question);

    void GenerateErrorMessage(const std::string &message);

    std::string GenerateStrQuestion(const std::string &message);

    // Couleur de texte
    extern std::string black;
    extern std::string red;
    extern std::string green;
    extern std::string yellow;
    extern std::string blue;
    extern std::string magenta;
    extern std::string cyan;
    extern std::string white;

    // Couleurs de fond
    extern std::string bg_black;
    extern std::string bg_red;
    extern std::string bg_green;
    extern std::string bg_yellow;
    extern std::string bg_blue;
    extern std::string bg_magenta;
    extern std::string bg_cyan;
    extern std::string bg_white;

    // Couleur de fin (passage en couleur par défaut)
    extern std::string endc;
}

#endif //COLORIZE_H
