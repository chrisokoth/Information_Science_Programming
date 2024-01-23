
#include <iostream>
#include <cmath>

double f(double x) {
  // Define your polynomial function here (e.g., x^2 - 4)
  return x * x - 4;
}

double f_prime(double x) {
  // Define the derivative of your polynomial function here (e.g., 2x)
  return 2 * x;
}

int main() {
  // Initial guess for the root
  double x0 = 2;

  // Tolerance for error in the root approximation
  double tolerance = 0.0001;

  // Counter for maximum iterations
  int max_iterations = 100;

  // Iteration loop
  int i = 0;
  while (std::abs(f(x0)) > tolerance && i < max_iterations) {
    // Update the guess using Newton-Raphson formula
    x0 = x0 - f(x0) / f_prime(x0);

    // Increment iteration counter
    i++;
  }

  // Check if root was found within tolerance and iterations
  if (i < max_iterations) {
    std::cout << "Root found after " << i << " iterations: " << x0 << std::endl;
  } else {
    std::cout << "Root not found within " << max_iterations << " iterations." << std::endl;
  }

  return 0;
}
