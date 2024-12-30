#include <iostream>

#include "Parser.h"
#include "Prout.h"

int main(int argc, char* argv[]) {

    // Afficher les arguments de la ligne de commande
    std::cout << "Command line:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << " " ;
    }
    std::cout << std::endl;

    Parser parser{};

    Cmd* prout = new Prout();
    parser.addCmd(prout);

    parser.Parse(argc, argv);

    return 0;
}
