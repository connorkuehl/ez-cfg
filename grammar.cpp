#include "grammar.h"

#include <sstream>
#include <iostream>

grammar::grammar(const std::string& file)
{
    parse(lex(file));
}

void grammar::display() const
{
    for (const auto& rule : rules) {
        std::cout << rule.first << std::endl;
        for (const auto& builds : rule.second) {
            std::cout << ":\t" << builds << std::endl;
        }
        std::cout << std::endl;
    }
}

void grammar::parse(const std::vector<lexeme>& tokens)
{
    start = tokens.at(0);

    std::string curr_token;
    std::vector<std::string> productions;
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
                    } else {
                        // we are building a production rule, and
                        // we've just stumbled upon another production
                        // site.
                        sentence << token << " ";
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
                        productions.push_back(sentence.str());
                        sentence.str("");
                    }
                }
                break;
            case ';': 
                {
                    productions.push_back(sentence.str());
                    sentence.str("");
                    insert_rule(curr_token, productions);
                    building = false;
                }
                break;
            default:
                sentence << token << " ";
                break;
        }
    }
}

void grammar::insert_rule(const std::string& rule, const std::vector<std::string>& productions)
{
    auto found{rules.find(rule)};
    if (found == rules.end()) {
        rules.insert(std::make_pair(rule, productions));
    }
}
