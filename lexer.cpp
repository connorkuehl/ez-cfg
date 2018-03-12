#include "lexer.h"

#include <fstream>
#include <iterator>

std::vector<lexeme> lex(const std::string& file)
{
    std::ifstream unlexed(file);
    std::vector<lexeme> tokens (std::istream_iterator<std::string>{unlexed}, {});
    return tokens;
}
