#include "token.h"

namespace token {
    Token newToken(std::string type, std::string literal) {
        return Token {type, literal};
    }

    std::string lookupIdent(std::string ident) {
        if (!keywords.contains(ident)) {
            return IDENT;
        } else {
            return keywords.at(ident);
        }
    }
}
