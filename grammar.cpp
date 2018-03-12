#include "grammar.h"
#include "parser.h"

grammar::grammar(const std::string& file)
{
    parse(lex(file));
}

void grammar::parse(const std::vector<lexeme>& tokens)
{
    start = tokens.at(0);

    std::vector<std::string> built_by_current_rule;

    for (const auto& token : tokens) {
        switch (token.at(0)) {
            case '_': {                     // production rule
                          break;
                      }
            case '=':
                      break;
            case ';':                       // rule terminator
                      break;
            case '|':                       // production separator
                      break;
        }
    }
}
