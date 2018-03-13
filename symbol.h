#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "grammar.h"

#include <vector>
#include <memory>

class symbol {
public:
    virtual void generate(grammar& g) = 0;
    virtual void display() const = 0;
protected:
    std::vector<std::unique_ptr<symbol>> symbols;
};

class production final : public symbol {
public:
    production(const std::string& rule);

    void generate(grammar& g) override;
    void display() const override;
private:
    std::string rule;
};

class terminal final : public symbol {
public:
    terminal(const std::string& val);

    void generate(grammar& g) override;
    void display() const override;
private:
    std::string value;
};

#endif
