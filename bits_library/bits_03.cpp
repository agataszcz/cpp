#include "bits_03.hpp"
#include <iostream>

namespace agata {

bool SwissKnife::GetBit(uint32_t index) const {
  if (index < (sizeof(uint32_t) * 8)) {
    return ((mask & (1 << index)) != 0);
  } else {
    throw std::invalid_argument( "Invalid index argument" );
  } 
}

void SwissKnife::SetBit(uint32_t index, bool set) {
  if (index < (sizeof(uint32_t) * 8)) {
    mask = (set) ? mask | (1 << index) : mask & ~(1 << index);
  } else {
    throw std::invalid_argument("Invalid argument");
  }
}

SwissKnife SwissKnife::operator + (SwissKnife const &right_obj) {
  SwissKnife result;
  for (int bit = 0; bit <= MaxBitIndex; bit++) {
    if (GetBit(bit) || right_obj.GetBit(bit) ) {
      result.SetBit(bit, true);
    }
  }
  return result;
}

SwissKnife SwissKnife::operator - (SwissKnife const &right_obj) {
  SwissKnife result;
  for (int bit = 0; bit <= MaxBitIndex; bit++) {
    if (GetBit(bit) && !right_obj.GetBit(bit) ) {
      result.SetBit(bit, true);
    }
  }
  return result;
}

SwissKnife SwissKnife::operator - () {
  uint32_t not_mask = ~mask;
  return SwissKnife(not_mask);
}

} // namespace agata


// printing the string representation of the class to the stream 
std::ostream& operator<< (std::ostream &out, agata::SwissKnife const& knife) {
  for (int bit = agata::SwissKnife::MaxBitIndex; bit >= 0; bit--) {
    out << knife.GetBit(bit);
    // adding space between every 4 bits for ease of debugging
    if (bit % 4 == 0){
      out << " ";
    }
  }
  return out;
}
