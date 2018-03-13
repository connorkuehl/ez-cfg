#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include "lexer.h"

#include <map>
#include <vector>
#include <string>
#include <random>

class grammar final {
public:
    grammar(const std::string& file);

    const std::vector<std::string>& get_random_production(const std::string& rule);
    const std::string& get_start() const;
    bool is_terminal(const std::string& value) const;
    bool is_nonterminal(const std::string& value) const;
    void display() const;
private:
    std::string start;
    std::map<std::string, std::vector<std::vector<std::string>>> rules;
    std::mt19937 mt;

    void parse(const std::vector<lexeme>& tokens);
    void insert_rule(const std::string& rule, const std::vector<std::vector<std::string>>& productions);
};

#endif // GRAMMAR_H_
