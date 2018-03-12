#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include "lexer.h"

#include <map>
#include <vector>
#include <string>

class grammar final {
public:
    grammar(const std::string& file);
private:
    std::string start;
    std::map<std::string, std::vector<std::string>> rules;

    void parse(const std::vector<lexeme>& tokens);
};

#endif // GRAMMAR_H_
