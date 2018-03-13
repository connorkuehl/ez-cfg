#include "grammar.h"

#include <iostream>

grammar::grammar(const std::string& file)
{
    std::random_device rd;
    mt.seed(rd());

    parse(lex(file));
}

const std::vector<std::string>& grammar::get_random_production(const std::string& rule)
{
    auto found{rules.find(rule)};
    if (found == rules.end()) {
        // TODO: error
    }

    auto len{found->second.size()};

    std::uniform_int_distribution<int> dist(0, len - 1);

    return found->second.at(dist(mt));
}

const std::string& grammar::get_start() const
{
    return start;
}

bool grammar::is_terminal(const std::string& value) const
{
    return !is_nonterminal(value);
}

bool grammar::is_nonterminal(const std::string& value) const
{
    return value.at(0) == '_';
}

void grammar::display() const
{
    for (const auto& rule : rules) {
        std::cout << rule.first << std::endl;
        for (const auto& builds : rule.second) {
            std::cout << "\t";
            for (const auto& prod : builds) {
                std::cout << prod << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void grammar::parse(const std::vector<lexeme>& tokens)
{
    // TODO: this method needs to be improved. Badly.
    // A finite state machine might make this cleaner
    // and make it easier to handle errors.
    start = tokens.at(0);

    // This is the current rule that we are building.
    std::string curr_token;
    // This is the total overall list of productions
    // that this rule is capable of generating.
    std::vector<std::vector<std::string>> productions;
    // A production is a list of symbols (terminals &
    // nonterminals).
    std::vector<std::string> production;
    // Flag to determine if we are building a production
    // or not. This affects parser behavior when we find
    // a production symbol. If we are building then we
    // don't want to get distracted and evaluate the symbol.
    auto building{false};

    for (const auto& token : tokens) {
        switch (token.at(0))
        {
            // Production symbol
            case '_': 
                {
                    // not currently building a production rule,
                    // so now we are, and subsequent tokens will
                    // be a production
                    if (!building) {
                        building = true;
                        curr_token = token;
                        productions.clear();
                        production.clear();
                    } else {
                        // we are building a production rule, and
                        // we've just stumbled upon another production
                        // site.
                        production.push_back(token);
                    }
                }
                break;
            case '=':
                break;
                // Production clause separator
            case '|':
                {
                    if (!building) {
                        // TODO: handle error
                    } else {
                        productions.push_back(production);
                        production.clear();
                    }
                }
                break;
                // Production rule terminator
            case ';': 
                {
                    productions.push_back(production);
                    insert_rule(curr_token, productions);
                    building = false;
                }
                break;
                // Terminal
            default:
                production.push_back(token);
                break;
        }
    }
}

void grammar::insert_rule(const std::string& rule, const std::vector<std::vector<std::string>>& productions)
{
    auto found{rules.find(rule)};
    if (found == rules.end()) {
        rules.insert(std::make_pair(rule, productions));
    }
}
