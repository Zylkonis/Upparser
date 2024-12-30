//
// Created by PC on 30/12/2024.
//

#include "Prout.h"

#include <iostream>
#include <ostream>

Prout::Prout(): Cmd("prout", {"p"}, 2,
                    "This command remembers type of fart and prints prout n times.",
                    false, false) {
}

void Prout::affectArg(const std::vector<std::string>& lArgs) {
    type = lArgs[0];
    nProut = std::stoi(lArgs[1]);
}

void Prout::execute() {
    std::cout << "type = " << type << std::endl;
    for (int i = 0; i < nProut; i++) {
        std::cout << "prout!" << std::endl;
    }
}
