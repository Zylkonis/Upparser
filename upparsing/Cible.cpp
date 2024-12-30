//
// Created by PC on 29/11/2024.
//

#include "Cible.h"

#include <utility>

Cible::Cible(std::string  description, const bool empty):
    description(std::move(description)), empty(empty) {}

Cible::Cible(std::vector<std::string> cibles, std::string description, const bool empty):
    cibles(std::move(cibles)), description(std::move(description)), empty(empty) {}

const std::vector<std::string>& Cible::getCibles() const {
    return cibles;
}

std::string Cible::getCible(int i) const {
    return cibles[i];
}

void Cible::addCible(std::string cible) {
    cibles.push_back(std::move(cible));
}


const std::string& Cible::getDescription() const{
    return description;
}

void Cible::setDescription(std::string des) {
    description = std::move(des);
}