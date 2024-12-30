//
// Created by PC on 30/12/2024.
//

#include "Help.h"

#include "Parser.h"

Help::Help(Parser* p): Cmd("help", {"h"}, 0,
                           "This command prints all available commands and their descriptions.",
                           false, true), parser(p) {}

void Help::affectArg(const std::vector<std::string> &lArgs) {}

void Help::execute() {
    std::cout << "all available commands:" << std::endl;
    for (const Cmd* cmd: parser->cmds) {
        std::cout << "Usage : monexe [ " << cmd->getName();
        for (const std::string& alias: cmd->getAlias()) {
            std::cout << alias << "|";
        }
        std::cout << "] Files+" << std::endl
        << "       Files : Files to compile" << std::endl
        << "Options:" << std::endl
        << "        " << cmd->getName();
        for (const std::string& alias: cmd->getAlias()) {
            std::cout << "," << alias << " : ";
        }
        std::cout << cmd->getDescription() << std::endl;
        std::cout << "this command takes " << cmd->getNarg() << " arguments." << std::endl << std::endl;
    }
}

void Help::execute(const Cmd* cmd) const {
    std::cout << "Usage : monexe [ " << cmd->getName();
    for (const std::string& alias: cmd->getAlias()) {
        std::cout << alias << "|";
    }
    std::cout << "] Files+" << std::endl
    << "       Files : Files to compile" << std::endl
    << "Options:" << std::endl
    << "        " << cmd->getName();
    for (const std::string& alias: cmd->getAlias()) {
        std::cout << "," << alias << " : ";
    }
    std::cout << cmd->getDescription() << std::endl;
    std::cout << "this command takes " << cmd->getNarg() << " arguments." << std::endl << std::endl;
}
