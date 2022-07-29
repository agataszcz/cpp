#include <iostream>
#include "bits_03.h"

int main() {

  int size;
  // enter how many bits you want to represent
  std::cout << "Enter the length of array: " <<std::endl;
  std::cin >> size;

  agata::SwissKnife swissobj1(size);
  std::cout << "Mask Length " << swissobj1.GetMaskLength() << std::endl;
  std::cout << swissobj1 << std::endl;
  
  swissobj1.SetBit(1, true);
  std::cout << swissobj1 << std::endl;

  swissobj1.SetBit(15, true);
  std::cout << swissobj1 << std::endl;

  swissobj1.SetBit(31, true);
  std::cout << swissobj1 << std::endl;

/*
  agata::SwissKnife swissobj2(300);
  std::cout << swissobj2 << std::endl;

  agata::SwissKnife swissobj3 = swissobj1 + swissobj2;
  std::cout << swissobj3 << std::endl;

  agata::SwissKnife swissobj4 = swissobj3 - swissobj1;
  std::cout << swissobj4 << std::endl;

  agata::SwissKnife swissobj5 = -swissobj2;
  std::cout << swissobj5 << std::endl;

  swissobj5.SetBit(1, false);
  std::cout << swissobj5 << std::endl;
  
  swissobj5.SetBit(4, false);
  std::cout << swissobj5 << std::endl;

  swissobj5.SetBit(7, false);
  std::cout << swissobj5 << std::endl;
  
  try {
    swissobj5.SetBit(32, false);
    std::cout << swissobj5 << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << "Got SetBit Exception: " << e.what() << std::endl;
  }

  std::cout << "Bit 7 is " << swissobj5.GetBit(7) << std::endl;
  std::cout << swissobj5 << std::endl;

  try {
    bool b = swissobj5.GetBit(33);
    std::cout << "Bit 33 is " << b << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << "Got GetBit Exception: " << e.what() << std::endl;
  }
  */

  std::cout << "That's It Folks!" << std::endl;
  return 0;
}
