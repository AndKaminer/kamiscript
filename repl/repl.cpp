#include "repl.h"

namespace repl {

    void start() {
        while (true) {
            std::cout << PROMPT;
            std::string input;
            std::getline(std::cin, input);
            
            lexer::lexerState* l = lexer::newLexer(input);
            token::Token tok;

            while ((tok = nextToken(l)).type != token::EOFILE) {
                std::cout << std::format("Token type: {}  Token Literal: {}\n", tok.type, tok.literal);
            }
        }
    }
}
