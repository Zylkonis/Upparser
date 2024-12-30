//
// Created by PC on 30/12/2024.
//

#include "Prout.h"

#include <iostream>
#include <ostream>

Prout::Prout(): Cmd("prout", {"p"}, 1,
                    "This command prints prout n times.",
                    false, true) {
}

void Prout::affectArg(const std::vector<std::string>& lArgs) {
    nProut = std::stoi(lArgs[0]);
}

void Prout::execute() {
    for (int i = 0; i < nProut; i++) {
        std::cout << "prout!" << std::endl;
    }
}
