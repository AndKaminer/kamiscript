#include <string>

namespace token {

    struct tokenType {
        std::string type;
    };
    
    struct token {
        tokenType type;
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
}
