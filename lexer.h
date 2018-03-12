#ifndef LEXER_H_
#define LEXER_H_

#include <vector>
#include <string>

typedef std::string lexeme;

std::vector<lexeme> lex(const std::string& file);

#endif
