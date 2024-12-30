#include <iostream>

#include "Parser.h"
#include "Prout.h"

int main(int argc, char* argv[]) {

    std::cout << "Hello World!\n";

    // Afficher les arguments de la ligne de commande
    std::cout << "Arguments passed:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Arg[" << i << "]: " << argv[i] << std::endl;
    }

    Parser parser{};

    Cmd* prout = new Prout();
    parser.addCmd(prout);

    parser.Parse(argc, argv);

    return 0;
}
