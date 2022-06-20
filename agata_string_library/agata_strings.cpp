#include "agata_strings.hpp"

#include <cctype>

namespace agata {

std::string capitalize(std::string name) {
  if (name.size() > 0) {
    name[0] = toupper(name[0]);
  } 
  return name;
}

bool isYelling(std::string s) {
  if (s.size() > 0) {
    char last = s[s.size() - 1];
    return last == '!';
  }
  
  return false;
}

}

