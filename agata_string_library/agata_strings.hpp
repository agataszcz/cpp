#ifndef AGATA_STRINGS_HPP
#define AGATA_STRINGS_HPP

#include <string>

namespace agata {

// Returns string that has capitalized first letter.
std::string capitalize(std::string name);

// Returns if the last char is "!"
bool isYelling(std::string s);

}; // agata namespace

#endif // AGATA_STRINGS_HPP
