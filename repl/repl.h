#ifndef _REPL_
#define _REPL_

#include "../token/token.h"
#include "../lexer/lexer.h"

#include <string>
#include <iostream>
#include <format>

namespace repl {
    const std::string PROMPT = ">> ";
    void start();
}

#endif
