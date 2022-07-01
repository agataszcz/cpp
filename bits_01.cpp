#include <iostream>
#include <bitset>

bool getBit(uint8_t num, uint8_t i) {
  // shift 1 by i and then do an "AND" operation; 
  // if the value at that new position is not 0, then the bit is set.
  return ((num & (1 << i)) != 0);
}

int setBit(uint8_t num, uint8_t i) {
  // shift 1 by i and then do an "OR" operation
  return num | (1 << i);
}

int main() {

  // declare data 1 = 0
  uint8_t data1 = 0;
  std::cout << "Mine 1: " << std::bitset<8>(data1) << std::endl;

  // call setBit to set the bit at position 3 to 1
  uint8_t data2 = setBit(data1, 3);
  std::cout << "Mine after setBit: " << std::bitset<8>(data2) << std::endl;
  
  // compare the result with STD example
  std::bitset<8> test_data;
  test_data.set(3);
  std::cout << "STD: " << test_data << std::endl;

  // check if the bit at position 3 is set by calling getBit
  bool res = getBit(data2, 3);
  // boolalpha: interpret what follows as a boolean
  std::cout << "res: " << std::boolalpha << res << std::endl;

  // compare the result with STD test function for checking if the bit 
  // at a given position is set (that is, if the bit is one)
  std::cout << "STD: " << std::boolalpha << test_data.test(3) << std::endl;

  if (getBit(data2, 3) != test_data.test(3)) {
      std::cerr << "ERROR: Mismatch" << std::endl;
  }
  
  return 0;
}
