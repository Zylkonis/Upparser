//
// Created by PC on 30/12/2024.
//

#ifndef PROUT_H
#define PROUT_H


#include "Cmd.h"


class Prout: public Cmd {
    int nProut;

public:
    explicit Prout();

    void affectArg(const std::vector<std::string>& lArgs) override;
    void execute() override;
};



#endif //PROUT_H
