#include "./lexer/lexer.h"
#include "./token/token.h"
#include "./repl/repl.h"

#include <iostream>
#include <vector>

int main() {
    std::string test = "let five = 5;"
    "let ten = 10;"
    "let add = fn(x, y) {"
        "x + y;"
    "};"
    "let result = add(five, ten);"
    "!-/*5;"
    "5 < 10 > 5;"
    "if (5 < 10) {"
    "   return true;"
    "} else {"
    "   return false;"
    "}"
    "10 == 10;"
    "10 != 9;"
    ;
    
    lexer::lexerState* l = lexer::newLexer(test);

    std::vector<token::Token> res = {};
    while (true) {
        token::Token t = nextToken(l);
        res.push_back(t);
        if (t.type == token::EOFILE) {
            break;
        }
    }

    std::vector<token::Token>::iterator ptr;

    for (ptr = res.begin(); ptr < res.end(); ptr++) {
        std::cout << ptr -> type << ' ' << ptr -> literal << '\n';
    }

    repl::start();

    return 0;
}
