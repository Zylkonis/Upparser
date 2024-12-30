//
// Created by PC on 30/12/2024.
//

#include "Help.h"

Help::Help(Parser* p): Cmd("help", {"h"}, 0,
                                 "This command prints all available commands and their descriptions.",
                                 false, true), parser(p) {}

void Help::affectArg(const std::vector<std::string> &lArgs) {}

void Help::execute() {
    std::cout << "all available commands:" << std::endl;
    for (const Cmd* cmd: parser->cmds) {
        std::cout << cmd->getName();
        for (const std::string& alias: cmd->getAlias()) {
            std::cout << ", " << alias << std::endl;
        }
        std::cout << "this command takes " << cmd->getNarg() << " arguments." << std::endl;
        std::cout << "description: " << cmd->getDescription() << std::endl;
    }
}