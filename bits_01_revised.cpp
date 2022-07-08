#include <iostream>

namespace agata {

class SwissKnife{
public:
  // static: there is only one instance of this member shared across all SwissKnife instances
  static const int MaxBitIndex = 7;

  // class constructor with default value; explicit = do not generate automated constructors;
  // use the one given below
  explicit SwissKnife(uint8_t init = 0)
  :mask(init) {}

  // const = this function will not modify any data member, so the state of the object
  // (class instance) will not get modified; safe to execute this function
  bool GetBit(uint8_t index) const {
    // shift 1 by index and do an "AND" operation; if the value at the new position is not 0,
    // then the bit is set.
    return ((mask & (1 << index)) != 0);  
  }
  // no const here because we are modifying the mask
  void SetBit(uint8_t index) {
    // shift 1 by index and then do an "OR" operation; mask = mask | (1 << i);
    mask |= (1 << index); 
  }

  // the + function sets the bit if either the left-side bit or the right-side bit is set
  // const means this object will not get modified, hence we are passing by reference; 
  // passing by value (copying data) would be wasteful
  SwissKnife operator + (SwissKnife const &right_obj) {
    SwissKnife result;
    // iterate in reverse order, from the end
    for (int bit = MaxBitIndex; bit >= 0; bit--) {
      // left-side OR right-side
      if (GetBit(bit) || right_obj.GetBit(bit) ) {
        result.SetBit(bit);
      }
    }
    return result;
  }

  // the minus function sets the bit to 1 if the left-side bit is set (True) AND
  // the right-side bit is not set
  SwissKnife operator - (SwissKnife const &right_obj) {
    SwissKnife result;
    for (int bit = MaxBitIndex; bit >= 0; bit--) {
      // left-side AND right-side
      if (GetBit(bit) && !right_obj.GetBit(bit) ) {
        result.SetBit(bit);
      }
    }
    return result;
  }

  // the unary negative operator below flips/inverts the mask
  // if the bit was 1, it will get changed to 0
  SwissKnife operator - () {
    uint8_t not_mask = ~mask;
    return SwissKnife(not_mask);
  }

// private member of the class (the state of the object)
private:
  uint8_t mask;
};

} // namespace agata


// printing the class to the stream; 
std::ostream& operator<< (std::ostream &out, agata::SwissKnife const& knife) {
  for (int bit = agata::SwissKnife::MaxBitIndex; bit >= 0; bit--) {
    out << knife.GetBit(bit);
    if (bit == 4){
      out << " ";
    }
  }
  return out;
}


int main() {
  // instantiate the object
  agata::SwissKnife swissobj1;
  std::cout << swissobj1 << std::endl;

  swissobj1.SetBit(1);
  std::cout << swissobj1 << std::endl;

  agata::SwissKnife swissobj2(8);
  std::cout << swissobj2 << std::endl;

  agata::SwissKnife swissobj3 = swissobj1 + swissobj2;
  std::cout << swissobj3 << std::endl;

  agata::SwissKnife swissobj4 = swissobj3 - swissobj1;
  std::cout << swissobj4 << std::endl;

  agata::SwissKnife swissobj5 = -swissobj2;
  std::cout << swissobj5 << std::endl;
  
  return 0;
}
