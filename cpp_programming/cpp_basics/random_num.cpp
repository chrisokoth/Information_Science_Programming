#include <iostream>
#include <random>
using namespace std;

int main() {
  // Generate a random number between 1 and 100 (inclusive)
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 100);
  int secret_number = dis(gen);

  // User input and counting guesses
  int guess;
  int attempts = 0;

  // Loop until the guess is correct
  while (guess != secret_number) {
    cout << "Enter your guess (1-100): ";
    cin >> guess;
    attempts++;

    // Provide feedback based on the guess
    if (guess < secret_number) {
      cout << "Your guess is too low. Try again!\n";
    } else if (guess > secret_number) {
      cout << "Your guess is too high. Try again!\n";
    }
  }

  // Congratulate the user and display the number of attempts
  cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";

  return 0;
}

