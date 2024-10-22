#include <iostream>
#include <string>
#include "convertisseur.h"
#include "colorize.h"

// Déclaration des fonctions
void modal();

void calculette(const unsigned short &base, const bool &type_entier);

// Fonction principale
int main() {
    // Fenêtre des informations
    auto console = clr::Colorize("INFO", 10, clr::bg_green);
    console.GenerateWindowsTitle();
    console.GenerateWindowsDescription("Version: 0.1.0/beta");
    console.GenerateWindowsDescription("Made by: Maxence LE ROY");
    console.GenerateEndWindows();
    std::cout << std::endl;

    // Calculatrice
    modal();
}

/**
 * Affiche des question à l'utilisateur.
 *
 * Pose uniquement les question:
 * - Base
 * - Type d'entier
 */
void modal() {
    // Variables de données
    unsigned short base = 10;
    unsigned short type_entier = 0;

    ///////
    // Question sur la base choisit
    /////

    // Fenêtre d'information pour les bases
    auto baseWin = clr::Colorize("CALCULATEUR DES BASES", 12);
    baseWin.GenerateWindowsTitle();
    baseWin.GenerateWindowsDescription("");
    baseWin.GenerateWindowsDescription("Choisir la base de votre nombre:");
    baseWin.GenerateWindowsDescription(" 2 - Binaire");
    baseWin.GenerateWindowsDescription("10 - Decimal");
    baseWin.GenerateWindowsDescription("16 - Hexadecimal");
    baseWin.GenerateEndWindows();

    // Question posée à l'utilisateur
    do {
        // Vérification s'il y a eu des erreurs précédemment
        if (base != 2 && base != 10 && base != 16) {
            clr::GenerateErrorMessage(" /!\\ Valeur entrée invalide. ");
        }
        base = clr::GenerateUShortQuestion("Base (2,10,16)"); // input utilisateur
    } while (base != 2 && base != 10 && base != 16);

    std::cout << std::endl;

    ///////
    // Question sur le type d'entier
    /////

    // Fenêtre d'information pour le type d'entier
    auto intWin = clr::Colorize("BASE " + std::to_string(base), 19);
    intWin.GenerateWindowsTitle();
    intWin.GenerateWindowsDescription("");
    intWin.GenerateWindowsDescription("Choisissez un type d'entier:");
    intWin.GenerateWindowsDescription("0 - Entier signe");
    intWin.GenerateWindowsDescription("1 - Entier non signe");
    intWin.GenerateEndWindows();

    // Question posée à l'utilisateur
    do {
        // Vérification s'il y a eu des erreurs précédemment
        if (type_entier != 0 && type_entier != 1) {
            clr::GenerateErrorMessage(" /!\\ Valeur entrée invalide. ");
        }
        type_entier = clr::GenerateUShortQuestion("Type d'entier (0, 1)"); // input
    } while (type_entier != 0 && type_entier != 1);
    std::cout << std::endl;

    // On passe à la suite (partie de calcul)
    calculette(base, type_entier == 0);
}

/**
 * Demande à l'utilisateur d'entrer un nombre et calcul ce nombre sur les autres bases (2, 10, 16)
 * @param base La base su nombre que souhaite l'utilisateur
 * @param type_entier Si le nombre transmit est signé ou non
 */
void calculette(const unsigned short &base, const bool &type_entier) {
    // Demande du nombre (BOUCLE)
    unsigned short isInvalid = 0;
    std::string nombre = clr::GenerateStrQuestion("Entrez votre nombre");

    clr::ClearSpace(); // Clear la console

    // Récapitulatif
    auto recapWin = clr::Colorize("RECAPITULATIF", 10, clr::bg_blue);
    recapWin.GenerateWindowsTitle();
    recapWin.GenerateWindowsDescription("");
    recapWin.GenerateWindowsDescription("Nombre: " + nombre);
    recapWin.GenerateWindowsDescription("En base: " + std::to_string(base));
    if (type_entier) recapWin.GenerateWindowsDescription("Signe: OUI");
    else recapWin.GenerateWindowsDescription("Signe: NON");
    recapWin.GenerateEndWindows();

    // Affichage du nombre dans les autres bases
    // base 2
    if (base == 2) {
        // Affichage décimal
        std::cout << clr::bg_white << clr::black << " Décimal: " << cvt::binToDec(nombre, type_entier) << " " <<
                clr::endc <<
                std::endl;
        // Affichage hexadécimal
        std::cout << clr::bg_white << clr::black << " Hexadécimal: ";
        cvt::binToHex(nombre, type_entier);
        std::cout << " " << clr::endc;
    }
    // base 10
    if (base == 10) {
        // Binaire
        std::cout << clr::bg_white << clr::black << " Binaire (12 bits): ";
        cvt::decToBin(nombre, type_entier); // Décimal
        std::cout << " " << clr::endc << std::endl;
        // Hexadécimal
        std::cout << clr::bg_white << clr::black << " Hexadécimal: ";
        cvt::decToHex(nombre);
        std::cout << " " << clr::endc << std::endl;
    }
    // base 16
    if (base == 16) {
        // Binaire
        std::cout << clr::bg_white << clr::black << " Binaire (12 bits): ";
        cvt::hexToBin(nombre, type_entier);
        std::cout << " " << clr::endc << std::endl;
        // Decimal
        std::cout << clr::bg_white << clr::black << " Decimal: " << cvt::hexToDec(nombre, type_entier) << " " <<
                clr::endc <<
                std::endl; // Décimal
    }
}
