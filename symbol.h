#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "grammar.h"

#include <vector>
#include <memory>

class symbol {
public:
    virtual void generate(grammar& g) = 0;
protected:
    std::vector<std::unique_ptr<symbol>> symbols;
};

class production final : public symbol {
public:
    production(const std::string& val);

    void generate(grammar& g) override;
};

class terminal final : public symbol {
public:
    terminal(const std::string& val);

    void generate(grammar& g) override;
};

#endif
