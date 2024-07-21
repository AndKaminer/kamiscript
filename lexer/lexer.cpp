#include "lexer.h"

namespace lexer {
    void readChar(lexer::lexerState* l) {
        if (l -> position >= l -> input.length()) {
            l -> ch = '\0';
        } else {
            l -> ch = l -> input[l -> readPosition];
        }
        l -> position = l -> readPosition;
        l -> readPosition++;
    }

    lexerState* newLexer(std::string input) {
        lexerState* l = new lexerState {input, 0, 0, '\0'};
        readChar(l);
        return l;
    }

    std::string readIdentifier(lexerState* l) {
        int position = l -> position;
        while (std::isalpha(l -> ch)) {
            readChar(l);
        }

        return l -> input.substr(position, l -> position - position);
    }

    void eatWhitespace(lexerState* l) {
        while (l -> ch == ' ' || l -> ch == '\n' || l -> ch == '\t' || l -> ch == '\r') {
            readChar(l);
        }
    }

    std::string readNumber(lexerState* l) {
        int position = l -> position;

        while (isdigit(l -> ch)) {
            readChar(l);
        }

        return l -> input.substr(position, l -> position - position);
    }

    token::Token nextToken(lexerState* l) {
        token::Token tok;

        eatWhitespace(l);

        switch(l -> ch) {
            case '=':
                tok = token::newToken(token::ASSIGN, std::string(1, l -> ch));
                break;
            case ';':
                tok = token::newToken(token::SEMICOLON, std::string(1, l -> ch));
                break;
            case '(':
                tok = token::newToken(token::LPAREN, std::string(1, l -> ch));
                break;
            case ')':
                tok = token::newToken(token::RPAREN, std::string(1, l -> ch));
                break;
            case ',':
                tok = token::newToken(token::COMMA, std::string(1, l -> ch));
                break;
            case '+':
                tok = token::newToken(token::PLUS, std::string(1, l -> ch));
                break;
            case '{':
                tok = token::newToken(token::LBRACE, std::string(1, l -> ch));
                break;
            case '}':
                tok = token::newToken(token::RBRACE, std::string(1, l -> ch));
                break;
            case '\0':
                tok = token::newToken(token::EOFILE, "");
                break;
            default:
                if (std::isalpha(l -> ch)) {
                    tok.literal = readIdentifier(l);
                    tok.type = token::lookupIdent(tok.literal);
                    return tok;
                } else if (std::isdigit(l -> ch)) {
                    tok.literal = readNumber(l);
                    tok.type = token::INT;
                } else {
                    tok = token::newToken(token::ILLEGAL, "");
                }

        }

        readChar(l);
        return tok;
    }

}

