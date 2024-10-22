#include <string>
#include <iostream>
#include "colorize.h"


/*
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107

\x1B[31mTexting\033[0m\t\t
 */

namespace clr {
    // Couleurs
    /**
     * Remise par défaut des couleurs et fond de texte dans le terminal.
     */
    std::string endc = "\x1B[0m";
    std::string black = "\x1B[30m";
    std::string red = "\x1B[91m";
    std::string green = "\x1B[32m";
    std::string yellow = "\x1B[33m";
    std::string blue = "\x1B[34m";
    std::string magenta = "\x1B[35m";
    std::string cyan = "\x1B[36m";
    std::string white = "\x1B[97m";

    // Backgrounds
    std::string bg_black = "\x1B[40m";
    std::string bg_red = "\x1B[41m";
    std::string bg_green = "\x1B[42m";
    std::string bg_yellow = "\x1B[43m";
    std::string bg_blue = "\x1B[44m";
    std::string bg_magenta = "\x1B[45m";
    std::string bg_cyan = "\x1B[46m";
    std::string bg_white = "\x1B[107m";

    /**
     * Constructeur de fenêtre dans le terminal, initialise le titre et la taille
     * voulut.
     * @param titre Titre de la fenêtre
     * @param taille Taille de la fenêtre (par défaut à 2)
     * @param bg Couleur de fond (par défaut en cyan bleue)
     */
    Colorize::Colorize(const std::string &titre, unsigned int taille,  std::string bg) {
        title = titre;
        tailleTitre = titre.size(); // Taille du titre pour gérer la taille de la fenêtre
        tailleFenetre = taille;
        backgroundColor = bg;
    }

    /**
     * Affiche, dans la console, le haut de la fenêtre avec le titre
     * et la taille voulut.
     */
    void Colorize::GenerateWindowsTitle() {
        std::string bordure;
        for (int i = 0; i < tailleFenetre; i++) {
            bordure += "═";
        }
        std::cout << backgroundColor << black << " ╔═" << bordure << "[ " << title << " ]" << bordure << "═╗ " << endc
                << std::endl;
    }

    /**
     * Affiche une description ou un texte sur une seule ligne dans la fenêtre
     * @param description Description affichée
     */
    void Colorize::GenerateWindowsDescription(const std::string &description) {
        // Si description trop grande, le fond sera rouge.
        // Bordures titre + (2 * taille de la fenêtre) + taille du titre.
        const int taille = 4 + (tailleFenetre * 2) + tailleTitre;

        if (description.size() > taille) {
            // s'affiche uniquement si la description est trop large
            std::cout << bg_red << black << " ║ " << description << " ║ " << endc << std::endl;
        } else {
            std::cout << backgroundColor << black << " ║ " << description;
            // taille - la description = Le nombre d'espace à mettre
            for (int i = 0; i < taille - description.size(); i++) {
                std::cout << " ";
            }
            // fin de la fenetre
            std::cout << " ║ " << endc << std::endl;
        }
    }

    /**
     * Affiche, dans la console, le bas de la page adapté à la taille de
     * la fenêtre.
     */
    void Colorize::GenerateEndWindows() {
        const unsigned int taille = 4 + (2 * tailleFenetre) + tailleTitre;
        std::string bas;
        for (int i = 0; i < taille; i++) {
            bas += "═";
        }
        std::cout << backgroundColor << black << " ╚═" << bas << "═╝ " << endc << std::endl;
    }

    /**
     * Simule un clear/clr console avec des sauts de ligne.
     */
    void ClearSpace() {
        for (int i = 0; i < 100;i++) {
            std::cout << std::endl; // Génère des sauts de ligne 100 fois
            // (simule un clear/clr console)
        }
    }

    /**
     * Affiche, dans le terminal, une question et renvoit la réponse.
     * @param question Question à poser à l'utilisateur
     * @return Réponse de l'utilisateur
     */
    unsigned short GenerateUShortQuestion(const std::string &question) {
        unsigned short res;
        std::cout << bg_yellow << white << " └[ " << question << ":" << endc << " ";
        std::cin >> res;
        return res;
    }

    /**
     * Afficher un message d'erreur en rouge et fond blanc dans la console.
     * @param message Message d'erreur à afficher
     */
    void GenerateErrorMessage(const std::string &message) {
        std::cout << bg_white << red << message << endc << std::endl << std::endl;
    }

    /**
     * Affiche la question demandée dans la console et renvoit la
     * réponse de l'utilisateur.
     * @param message Question à afficher
     * @return Réponse de l'utilisateur
     */
    std::string GenerateStrQuestion(const std::string &message) {
        std::cout << bg_yellow << white << "(?) - " << message << ":" << endc << " ";
        std::string res;
        std::cin >> res;
        return res;
    }


}

/*
╔╦═╗
╠╬═╣
║║ ║
╚╩═╝
ASCII Windows
 */

