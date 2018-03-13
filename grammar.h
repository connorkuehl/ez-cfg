#ifndef GRAMMAR_H_
#define GRAMMAR_H_

#include "lexer.h"

#include <map>
#include <vector>
#include <string>
#include <random>

/**
 * The Grammar class is responsible for lexing
 * and parsing an input file into a usable grammar
 * for string generation.
 */
class grammar final {
public:
    /**
     * Lexes and parses a file containing a
     * grammar.
     */
    grammar(const std::string& file);

    /**
     * Returns a random production based on the given rule.
     *
     * `rule` - the rule to get a random production clause from.
     *
     * returns: a production (list of symbols), randomly chosen
     *          from the given rule's clauses.
     */
    const std::vector<std::string>& get_random_production(const std::string& rule);
    /**
     * returns: the starting production rule for the grammar.
     */
    const std::string& get_start() const;
    /**
     * returns: true if the symbol is a terminal one, false if not.
     */
    bool is_terminal(const std::string& value) const;
    /**
     * returns: true if the symbol is a nonterminal symbol, false if not.
     */
    bool is_nonterminal(const std::string& value) const;
    /**
     * Displays the contents of the grammar.
     */
    void display() const;
private:
    // The starting production, all grammars must have one of these.
    std::string start;
    // A table of the rules and their production clauses.
    std::map<std::string, std::vector<std::vector<std::string>>> rules;
    // For random number generation.
    std::mt19937 mt;

    /**
     * Parses a collection of tokens into a grammar.
     *
     * `tokens` - the collection of lexemes produced from the
     *            lexing phase.
     */
    void parse(const std::vector<lexeme>& tokens);
    /**
     * Inserts a production rule into the table.
     *
     * `rule` - the symbol for the rule.
     * `productions` - a list of all of the production clauses this rule can
     *                 produce.
     */
    void insert_rule(const std::string& rule, const std::vector<std::vector<std::string>>& productions);
};

#endif // GRAMMAR_H_
