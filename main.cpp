#include "grammar.h"
#include "symbol.h"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "ERROR!\nUSAGE IS: " << argv[0] << " path/to/grammar_rule_file.txt\n";
        return 1;
    }

    grammar g(argv[1]);
    production p(g.get_start());

    p.generate(g);
    p.display();
    return 0;
}
