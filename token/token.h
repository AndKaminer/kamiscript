#ifndef _TOKEN_
#define _TOKEN_

#include <string>
#include <unordered_map>

namespace token {

    //struct tokenType {
    //    std::string type;
    //};
    
    struct Token {
        std::string type;
        std::string literal;
    };

    const std::string ILLEGAL = "ILLEGAL";
    const std::string EOFILE = "EOF";

    const std::string IDENT = "IDENT";
    const std::string INT = "INT";

    const std::string ASSIGN = "=";
    const std::string PLUS = "+";

    const std::string COMMA = ",";
    const std::string SEMICOLON = ";";

    const std::string LPAREN = "(";
    const std::string RPAREN = ")";
    const std::string LBRACE = "{";
    const std::string RBRACE = "}";
    
    const std::string FUNCTION = "FUNCTION";
    const std::string LET = "LET";

    const std::unordered_map<std::string, std::string> keywords = {
        {"fn", FUNCTION},
        {"let", LET}
    };
    
    std::string lookupIdent(std::string ident);
    Token newToken(std::string type, std::string literal);
}

#endif
