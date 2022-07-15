#include <iostream>

namespace agata {
/**
 * This class is designed to do the following:
 * - set and unset (clear) a bit at a specific index
 * - get bit value at a specific index
 */

class SwissKnife{
public:
  // using static so that this instance of this member gets shared across all SwissKnife instances
  static const int MaxBitIndex = 7;

  // using explicit to force the compiler to use the constructor below instead of generating automated constructors
  explicit SwissKnife(uint8_t init = 0)
  :mask(init) {}

  /**
  This function returns True if the bit at a new position (after shifting 1 by index and doing an "AND") is set
  (its value is not 0).
  We are using const to make this function safe to execute. With const, this function will not modify any data member,
  so the state of the object (class instance) will remain the same.
  */
  bool GetBit(uint8_t index) const {
    if (index < (sizeof(uint8_t) * 8)) {
      return ((mask & (1 << index)) != 0);
    } else {
      throw std::invalid_argument( "Invalid index argument" );
    } 
  }

  /**
   * This function changes the bit at a spefic index to either True or False
   * index - position of the bit whose value is to be modified.
   * set - value to store in the bit (either true for one or false for zero).
   * not using const in this function because the mask gets modified.
   */
  void SetBit(uint8_t index, bool set) {
    if (index < (sizeof(uint8_t) * 8)) {
      mask = (set) ? mask | (1 << index) : mask & ~(1 << index);
    } else {
      throw std::invalid_argument("Invalid argument");
    }
  }

  /**
   * This + function sets the bit if either the left-side bit or the right-side bit is set.
   * Const means this object will not get modified, hence we are passing by reference.
   * Because of const, passing by value (copying data) would be wasteful.
  */
  SwissKnife operator + (SwissKnife const &right_obj) {
    SwissKnife result;
    for (int bit = 0; bit <= MaxBitIndex; bit++) {
      if (GetBit(bit) || right_obj.GetBit(bit) ) {
        result.SetBit(bit, true);
      }
    }
    return result;
  }

 /**
  * The minus function sets the bit to 1 if the left-side bit is set (True) AND
  * the right-side bit is not set.
  */
  SwissKnife operator - (SwissKnife const &right_obj) {
    SwissKnife result;
    for (int bit = 0; bit <= MaxBitIndex; bit++) {
      if (GetBit(bit) && !right_obj.GetBit(bit) ) {
        result.SetBit(bit, true);
      }
    }
    return result;
  }

  /**
   * The unary negative operator below flips/inverts the mask.
   * If the bit was 1, it will get changed to 0.
   */
  SwissKnife operator - () {
    uint8_t not_mask = ~mask;
    return SwissKnife(not_mask);
  }

// private member of the class
private:
  uint8_t mask;
};

} // namespace agata


// printing the string representation of the class to the stream 
std::ostream& operator<< (std::ostream &out, agata::SwissKnife const& knife) {
  for (int bit = agata::SwissKnife::MaxBitIndex; bit >= 0; bit--) {
    out << knife.GetBit(bit);
    // adding extra space for ease of debugging
    if (bit == 4){
      out << " ";
    }
  }
  return out;
}


int main() {
  agata::SwissKnife swissobj1;
  std::cout << swissobj1 << std::endl;

  swissobj1.SetBit(1, true);
  std::cout << swissobj1 << std::endl;

  agata::SwissKnife swissobj2(8);
  std::cout << swissobj2 << std::endl;

  agata::SwissKnife swissobj3 = swissobj1 + swissobj2;
  std::cout << swissobj3 << std::endl;

  agata::SwissKnife swissobj4 = swissobj3 - swissobj1;
  std::cout << swissobj4 << std::endl;

  agata::SwissKnife swissobj5 = -swissobj2;
  std::cout << swissobj5 << std::endl;

  swissobj5.SetBit(2, false);
  std::cout << swissobj5 << std::endl;
  
  swissobj5.SetBit(4, false);
  std::cout << swissobj5 << std::endl;

  swissobj5.SetBit(7, false);
  std::cout << swissobj5 << std::endl;

  try {
    swissobj5.SetBit(8, false);
    std::cout << swissobj5 << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << "Got SetBit Exception: " << e.what() << std::endl;
  }

  std::cout << "Bit 7 is " << swissobj5.GetBit(7) << std::endl;
  std::cout << swissobj5 << std::endl;

  try {
    bool b = swissobj5.GetBit(8);
    std::cout << "Bit 8 is " << b << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << "Got GetBit Exception: " << e.what() << std::endl;
  }
  std::cout << "That's It Folks!" << std::endl;
  return 0;
}
