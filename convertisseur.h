//
// Created by Mayonnaise on 25/09/2024.
//

#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H
#include <string>

namespace cvt {
    // Convertisseur bin to autre
    int binToDec(const std::string &nombre, const bool &type_entier);

    void binToHex(const std::string &nombre, const bool &type_entier);

    // Convertisseur hex to autre
    int hexToDec(const std::string &nombre, const bool &type_entier);

    void hexToBin(const std::string &nombre, const bool &type_entier);

    // Convertisseur dec to autre
    void decToHex(const std::string &nombre);

    void decToBin(const std::string &nombre, const bool &type_entier);
}


#endif //CONVERTISSEUR_H
