#ifndef LEXER_H_
#define LEXER_H_

#include <vector>
#include <string>

typedef std::string lexeme;

/**
 * Lexes the file.
 *
 * `file` - the path to the file to lex.
 *
 * returns: a collection of every single token/
 *          lexeme in the file
 */
std::vector<lexeme> lex(const std::string& file);

#endif // LEXER_H_
