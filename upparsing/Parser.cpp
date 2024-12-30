//
// Created by PC on 29/11/2024.
//

#include "Parser.h"

#include <iostream>
#include <stdexcept>

#include "Help.h"


Parser::Parser() {
    Cmd* h = new Help(this);
    addCmd(h);
}

Parser::~Parser() {
    for (const auto* cmd : cmds) {
        delete cmd;
    }
}

void Parser::Parse(int argc, char* argv[]) {
    std::cout << "argc = " << argc << std::endl;
    size_t i = 1;
    while (i < argc) {
        const std::string& arg = argv[i];
        std::cout << arg << std::endl;
        if (arg[0] == '-') {
            //Lance une erreur si la commande n'existe pas
            Cmd* cmd = getCmd(arg);

            // Collecter les arguments pour la commande
            std::vector<std::string> arguments;
            for (int j = 0; j < cmd->narg && i + 1 < argc; j++) {
                if (isArg(argv[i])) {
                    arguments.push_back(argv[i]);
                }
                else {
                    throw std::runtime_error("La commande " + cmd->name + " n'a pas assez d'arguments, il lui en faut " + std::to_string(cmd->narg) + ".");
                }
            }
            cmd->affectArg(arguments);

            // Exécuter immédiatement si demandé
            if (cmd->isInstant()) {
                std::cout << "lancement de la cmd: " << cmd->name << std::endl;
                cmd->execute();
            }
            i++;
        } else {
            cibles.addCible(arg);
            i++;
        }
    }
}

void Parser::addCmd(Cmd *c) {
    cmds.push_back(c);
}

bool Parser::hasCmd(const std::string& name) {
    for (Cmd* cmd: cmds) {
        if (cmd->isName(name)) {
            return true;
        }
        if (cmd->isAlias(name)) {
            return true;
        }
    }
    return false;
}

bool Parser::isCmd(const std::string& name) const {
    return name[0] == '-';
}

Cmd* Parser::getCmd(const std::string &name) {
    for (Cmd* cmd: cmds) {
        if (cmd->isName(name) || cmd->isAlias(name)) {
            return cmd;
        }
    }
    throw std::runtime_error("Commande non trouvée : " + name);
}

bool Parser::isArg(const std::string &name) const {
    return name[0] != '-';
}

Cible Parser::getCibles() {
    return cibles;
}