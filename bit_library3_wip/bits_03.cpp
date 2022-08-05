#include "bits_03.h"
#include <iostream>

namespace agata {

SwissKnife::SwissKnife(uint32_t bits)
:maskLength(bits) {
    uint32_t bytes = bits / 8;
    if (bits % 8) {
      bytes++;
    }

    std::cout << "Asking for " << bytes << " bytes of memory" << std::endl;
    mask = new uint8_t(bytes);
    // to reset the content of the array to 0
    std::fill(mask, mask+bytes, 0);
  }

SwissKnife::~SwissKnife() {
  delete[] mask;
  std::cout << "Memory deleted for object of length " << GetMaskLength() << std::endl;
  //std::cout << "Memory deleted for object of size " << sizeof(mask) << std::endl; // no error
}

uint32_t SwissKnife::GetMaskLength() const {
  return maskLength;
}

bool SwissKnife::GetBit(uint32_t index) const {
  if (index < GetMaskLength()) {
    uint32_t bit = index % 8;
    uint32_t byte = index / 8;
    return ((mask[byte] & (1 << bit)) != 0);
  } else {
    throw std::invalid_argument( "Invalid index argument" );
  } 
}

void SwissKnife::SetBit(uint32_t index, bool set) {
  if (index < GetMaskLength()) {
    uint32_t bit = index % 8;
    uint32_t byte = index / 8;
    mask[byte] = (set) ? mask[byte] | (1 << bit) : mask[byte] & ~(1 << bit);
  } else {
    throw std::invalid_argument("Invalid argument");
  }
}

/*
SwissKnife SwissKnife::operator + (SwissKnife const &right_obj) {
  SwissKnife result;
  for (int bit = 0; bit <= maxBitIndex; bit++) {
    if (GetBit(bit) || right_obj.GetBit(bit) ) {
      result.SetBit(bit, true);
    }
  }
  return result;
}

SwissKnife SwissKnife::operator - (SwissKnife const &right_obj) {
  SwissKnife result;
  for (int bit = 0; bit <= maxBitIndex; bit++) {
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
*/

} // namespace agata

// printing the string representation of the class to the stream 
std::ostream& operator<< (std::ostream &out, agata::SwissKnife const& knife) {
  for (int bit = knife.GetMaskLength() - 1; bit >= 0; bit--) {
    out << knife.GetBit(bit);
    // adding space between every 4 bits for ease of debugging
    if (bit % 4 == 0){
      out << " ";
    }
  }
  return out;
}
