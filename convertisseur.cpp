#include <string>
#include <iomanip>
#include "convertisseur.h"
#include <iostream>

using namespace cvt;

/* **************** */
/*
 * Convertisseur Binaire → Autres bases
*/
/* **************** */

/**
 * Convertit un nombre binaire en décimal selon s'il est signé ou non signé.
 * @param nombre Nombre binaire à convertir
 * @param type_entier Type d'entier (signé ou non signé) sous forme booleenne
 * @return Nombre binaire convertit en décimal
 *
 * @warning N'affiche pas le résultat dans la console.
 */
int cvt::binToDec(const std::string &nombre, const bool &type_entier) {
    // Si nombre signé et négatif
    if (type_entier && nombre[0] == '1') {
        nombre.substr(1);
        // On inverse les 0 et les 1
        std::string newNombre;
        for (const char i : nombre) {
            newNombre += i == '0' ? '1' : '0';
        }
        // On le transforme en décimal
        int dec = std::stoi(newNombre, nullptr, 2);
        dec += 1; // On ajoute 1
        dec *= -1; // On inverse le signe pour le mettre en négatif
        return dec;
    }

    // Sinon
    return std::stoi(nombre, nullptr, 2);
}

/**
* Convertit une chaine de caractère contenant un nombre hexadécimal signé ou
 * non signé et affiche ce même nombre convertit en décimal dans la console.
 * @param nombre Nombre à convertir
 * @param type_entier Nombre signé ou non signé
 */
void cvt::binToHex(const std::string &nombre, const bool &type_entier) {
    // On récupère le décimal retourné par la fonction "binToDec"
    // puis on l'utilise pour le convertir en hexadécimal
    std::cout << std::showbase << std::setbase(16) << binToDec(nombre, type_entier);
}

/* **************** */
/*
 * Convertisseur Hexadécimal → Autres bases
*/
/* **************** */

/**
 * Convertit une chaine de caractère contenant un nombre hexadécimal signé ou
 * non signé et renvoit ce même nombre convertit en décimal.
 * @param nombre Nombre à convertir
 * @param type_entier Nombre signé ou non signé
 * @return Nombre convertit en décimal
 */
int cvt::hexToDec(const std::string &nombre, const bool &type_entier) {
    if (type_entier && (nombre[0] == 'F' || nombre[0] == 'f')) {
        nombre.substr(1); // On retire le premier nombre (F en occurrence)

        // Same as binToDec //
        // On inverse les on inverse les lettre/nombres
        const std::string hexa = "0123456789ABCDEF";
        std::string newNombre;
        for (const char& i : nombre) {
            std::string s(1, i);
            // Récupération de son inverse
            // f(x) = 15 - x
            newNombre += hexa[15 - std::stoi(s, nullptr, 16)];
        }
        int dec = std::stoi(newNombre, nullptr, 16);
        dec += 1;
        dec *= -1;
        return dec;
    }
    return std::stoi(nombre, nullptr, 16);
}

/**
* Convertit une chaine de caractère contenant un nombre héxadécimal signé ou
 * non signé et affiche ce même nombre convertit en décimal dans la console.
 * @param nombre Nombre à convertir
 * @param type_entier Nombre signé ou non signé
 */
void cvt::hexToBin(const std::string &nombre, const bool &type_entier) {
    // Récupère le décimal retourné dans la fonction "hexToDec" et l'utilise pour
    // le convertir en binaire.
    std::cout << std::bitset<12>(hexToDec(nombre, type_entier));
}


/* **************** */
/*
 * Convertisseur Décimal → Autres bases
*/
/* **************** */

/**
 * Convertit une chaîne de caractère contenant un décimal (signé ppar défaut)
 * en héxadécimal et l'affiche dans la console.
 * @param nombre Le nombre à convertir en héxadécimal
 */
void cvt::decToHex(const std::string &nombre) {
    std::cout << std::setbase(16) << std::showbase << stoi(nombre, nullptr, 10);
}

/**
 * Convertit une chaîne de caract
 * @param nombre Le nombre à convertir en binaire
 * @param type_entier Le type du nombre, signé ou non signé
 */
void cvt::decToBin(const std::string &nombre, const bool &type_entier) {
    if (type_entier) {
        std::cout << std::bitset<12>(stoi(nombre, nullptr, 10));
    } else {
        std::cout << std::bitset<12>(std::stoul(nombre, nullptr, 10)) ;
    }
}
