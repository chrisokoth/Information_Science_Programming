/*
Write a program that converts temperatures between Celsius and Fahrenheit.
The program should do the following:
Prompt the user to enter a temperature.
Ask the user to specify whether the entered temperature is in Celsius or Fahrenheit.
Convert the temperature to the other unit (if Celsius, convert to Fahrenheit, and vice versa).
Display the original temperature and the converted temperature.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables to store original and converted temperatures
    float originalTemperature, convertedTemperature;

    // Prompt the user to enter a temperature
    cout << "Enter a temperature: ";
    cin >> originalTemperature;

    // Ask the user to specify the temperature unit (Celsius or Fahrenheit)
    char temperatureUnit;
    cout << "Is the temperature in Celsius or Fahrenheit? (Enter 'C' or 'F'): ";
    cin >> temperatureUnit;

    // Convert temperature based on the specified unit
    if (temperatureUnit == 'C' || temperatureUnit == 'c') {
        // Convert Celsius to Fahrenheit
        convertedTemperature = (originalTemperature * 9 / 5) + 32;
    } else if (temperatureUnit == 'F' || temperatureUnit == 'f') {
        // Convert Fahrenheit to Celsius
        convertedTemperature = (originalTemperature - 32) * 5 / 9;
    } else {
        // Invalid input for temperature unit
        cerr << "Invalid input for temperature unit. Please enter 'C' or 'F'.";
        return 1; // Exit with an error code
    }

    // Display the original and converted temperatures
    cout << "\nOriginal Temperature: " << originalTemperature << " " << (temperatureUnit == 'C' || temperatureUnit == 'c' ? "Celsius" : "Fahrenheit");
    cout << "\nConverted Temperature: " << convertedTemperature << " " << (temperatureUnit == 'C' || temperatureUnit == 'c' ? "Fahrenheit" : "Celsius");

    return 0; // Exit successfully
}


