
#include <iostream>

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int numTerms;

  std::cout << "Enter the number of terms: ";
  std::cin >> numTerms;

  std::cout << "Fibonacci Series: ";
  for (int i = 0; i < numTerms; ++i) {
    std::cout << fibonacci(i) << " ";
  }

  std::cout << std::endl;

  return 0;
}

