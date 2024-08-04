#ifndef _LEXER_
#define _LEXER_

#include "../token/token.h"

#include <string>
#include <iostream>
#include <cctype>

namespace lexer {
    
    struct lexerState {
        std::string input;
        int position;
        int readPosition;
        char ch;
    };

    void readChar(lexerState* l);
    lexerState* newLexer(std::string input);
    token::Token nextToken(lexerState* l);
    std::string readIdentifier(lexerState* l);
    void eatWhitespace(lexerState* l);
    std::string readNumber(lexerState* l);
    char peekChar(lexerState* l);


}

#endif
