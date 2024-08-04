#include "./main.h"

int main() {
    std::cout << "Welcome to KamiScript version " << VERSION << '\n';
    std::cout << "Type in commands below\n";
    repl::start();

    return 0;
}
