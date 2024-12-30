//
// Created by PC on 30/12/2024.
//

#ifndef HELP_H
#define HELP_H


#include <iostream>

#include "Cmd.h"

class Parser;

class Help : public Cmd{
    Parser* parser;
public:
    explicit Help(Parser* parser);

    void affectArg(const std::vector<std::string>& lArgs) override;
    void execute() override;
    void execute(const Cmd* cmd) const;
};



#endif //HELP_H
