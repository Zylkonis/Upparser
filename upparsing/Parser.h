//
// Created by PC on 29/11/2024.
//

#ifndef PARSING_H
#define PARSING_H

#include <vector>

#include "Cible.h"
#include "Cmd.h"
#include "Help.h"


class Parser {
    Help* help;
    std::vector<Cmd*> cmds;
    Cible cibles;
    std::vector<Cmd*> waitingCmds;

    public:
    friend class Help;

    explicit Parser();
    ~Parser();

    void Parse(int argc, char* argv[]);

    void addCmd(Cmd* c);
    bool hasCmd(const std::string& name);
    bool isCmd(const std::string& name) const ;
    Cmd* getCmd(const std::string &name);

    bool isArg(const std::string& name) const ;

    Cible getCibles();

    void processAll() const;
    void getAllMustCmds() const;
    void allMustDone() const;
};



#endif //PARSING_H
