#include <iostream>
#include "agata_strings.hpp"

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Missing the string variable" << std::endl;
        return -1;
    }

    if (agata::isYelling(argv[1])) {
        std::cout << "STOP YELLING!" << std::endl;
    } else {
        std::cout << "Hello, how are you doing?" << std::endl;
    }

    return 0;
}