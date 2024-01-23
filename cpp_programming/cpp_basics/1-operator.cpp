#include <iostream>
using namespace std;

int main() {
  // Define variables
  int age = 18;
  bool isCitizen = true;

  // Use AND operator to check two conditions
  bool canVote = age >= 18 && isCitizen;

  // Check and display the result
  if (canVote) {
    cout << "You are eligible to vote!";
  } else {
    cout << "You are not yet eligible to vote.";
  }

  return 0;
}
