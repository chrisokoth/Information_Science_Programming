#include "main.hpp"

int main() {
  int num1 = 15, num2 = 7;
  std::string name = "John Doe";

  // Swap the values of num1 and num2
  swapIntegers(num1, num2);

  // Print the swapped values
  std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

  // Convert the name to uppercase
  std::string upperName = toUpperCase(name);

  // Print the uppercase name
  std::cout << "Uppercase name: " << upperName << std::endl;

  return 0;
}

