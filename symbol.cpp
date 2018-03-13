#include "symbol.h"

#include <iostream>

production::production(const std::string& rule)
: rule{rule}
{
}

void production::generate(grammar& g)
{
    auto product{g.get_random_production(rule)};

    for (const auto& p : product) {
        std::unique_ptr<symbol> prod;
        if (g.is_terminal(p)) {
            prod = std::move(std::unique_ptr<symbol>(new terminal(p)));
        } else {
            prod = std::move(std::unique_ptr<symbol>(new production(p)));
        }
        
        prod->generate(g);
        symbols.push_back(std::move(prod));
    }
}

void production::display() const
{
    for (const auto& sym : symbols) {
        sym->display();
        std::cout << " ";
    }

    std::cout << std::endl;
}

terminal::terminal(const std::string& val)
: value{val}
{
}

void terminal::generate(grammar& g)
{
}

void terminal::display() const
{
    std::cout << value;
}
