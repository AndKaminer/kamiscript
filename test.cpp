#include "./lexer/lexer.h"
#include "./token/token.h"

#include <iostream>
#include <vector>

int main() {
    std::string test = "let five = 5;"
    "let ten = 10;"
    "let add = fn(x, y) {"
    "x + y;"
    "};"
    "let result = add(five, ten);";
    
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

    return 0;
}
