#ifndef BITS_03_H
#define BITS_03_H

#include <iostream>

namespace agata {
/**
 * This class is designed to do the following:
 * - set and unset (clear) a bit at a specific index
 * - get the bit value at a specific index
 */

class SwissKnife{
public:

  // using static so that this instance of this member gets shared across all SwissKnife instances
  //static const int MaxBitIndex = (sizeof(uint32_t) * 8) -1;

  // using explicit to force the compiler to use the constructor below instead of generating automated constructors
  //explicit SwissKnife(uint32_t init = 0)
  //:mask(init) {
  //}

  explicit SwissKnife(uint32_t bits = 8);

  ~SwissKnife();

  /**
  * This function returns True if the bit at a specified position is set (that is, the bit value is not 0).
  * index - position of the bit whose value one wants to check.
  * Const is used to make this function safe to execute. With const, this function will not modify any data member,
  * so the state of the object (class instance) will remain the same.
  */
  bool GetBit(uint32_t index) const;

  /**
   * This function changes the bit at a spefic index to either True or False.
   * index - position of the bit whose value is to be modified.
   * set - value to store in the bit (either True for one or False for zero).
   * not using const in this function because the mask gets modified.
   */
  void SetBit(uint32_t index, bool set);


  uint32_t GetMaskLength() const;
  
  /**
   * This + function sets the bit if either the left-side bit or the right-side bit is set.
   * Const means this object will not get modified, hence we are passing by reference.
   * Because of const, passing by value (copying data) would be wasteful.
  */
  SwissKnife operator + (SwissKnife const &right_obj);

 /**
  * The minus function sets the bit to 1 if the left-side bit is set (True) and
  * the right-side bit is not set.
  */
  SwissKnife operator - (SwissKnife const &right_obj);

  /**
   * The unary negative operator below flips/inverts the mask.
   * If the bit was 1, it will get changed to 0.
   */
  SwissKnife operator - ();

// private member of the class
private:
  //uint32_t mask;
  uint32_t maskLength;
  uint8_t *mask;
};

} // namespace agata


// printing the string representation of the class to the stream 
std::ostream& operator<< (std::ostream &out, agata::SwissKnife const& knife);

#endif