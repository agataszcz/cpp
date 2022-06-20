#include <iostream>
#include "agata_strings.hpp"

int main(int argc, char* argv[]) {
    std::cout << argv[0] << std::endl;
   if (argc == 1) {
     std::cerr << "Missing name" << std::endl;
     return -1;
   }

   std::cout << "Hello " << agata::capitalize(argv[1]) << "!" << std::endl;
   return 0;
}

