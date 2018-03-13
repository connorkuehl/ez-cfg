#include "grammar.h"

#include <sstream>
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

    std::uniform_int_distribution<int> dist(0, len);

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
    start = tokens.at(0);

    std::string curr_token;
    std::vector<std::vector<std::string>> productions;
    std::vector<std::string> production;
    std::stringstream sentence;
    auto building{false};

    for (const auto& token : tokens) {
        switch (token.at(0))
        {
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
            case '|':
                {
                    if (!building) {
                        // error
                    } else {
                        productions.push_back(production);
                        production.clear();
                    }
                }
                break;
            case ';': 
                {
                    productions.push_back(production);
                    insert_rule(curr_token, productions);
                    building = false;
                }
                break;
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
