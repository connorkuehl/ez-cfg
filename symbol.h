#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "grammar.h"

#include <vector>
#include <memory>

/**
 * The Abstract Base Class representing all kinds of
 * (well only two) symbols needed to generate a string
 * from a CFG.
 *
 * This is intended to be the basis of a polymorphic
 * recursive tree class for convenient generation.
 */
class symbol {
public:
    /**
     * Recursively generates a string.
     *
     * `g` - the grammar to generate a string for.
     */
    virtual void generate(grammar& g) = 0;
    /**
     * Displays the generated string.
     */
    virtual void display() const = 0;
protected:
    std::vector<std::unique_ptr<symbol>> symbols;
};

/**
 * The Production class recursively generates 
 * sub-productions until reaching a terminal clause.
 *
 * This should be the only class necessary for 
 * the calling routine to generate a string from
 * the CFG.
 */
class production final : public symbol {
public:
    production(const std::string& rule);

    void generate(grammar& g) override;
    void display() const override;
private:
    std::string rule;
};

/**
 * The Terminal class represents a terminal symbol
 * in a production rule.
 */
class terminal final : public symbol {
public:
    terminal(const std::string& val);

    void generate(grammar& g) override;
    void display() const override;
private:
    std::string value;
};

#endif // SYMBOL_H_
