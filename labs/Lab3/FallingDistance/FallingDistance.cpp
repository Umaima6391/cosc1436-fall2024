// FallingDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab 3: Falling Distance
// Umaima Khan
// COSC 1436 - Fall 2024

#include <iostream>
#include <iomanip> // for std::setw and std::setprecision
using namespace std;

// Story 1: This function displays programming information
// Function: displayProgramInfo
// Purpose: Displays the program's title, author, and course information.
// Parameters: None
// Returns: Nothing (void)
void displayProgramInfo() {
    cout << "Program Title: Falling Distance Calculator\n";
    cout << "Name: Umaima Khan\n";
    cout << "Course: COSC 1436 - Fall 2024\n";
}

// Story 2: This function prompts the user for falling time ie, (1-60 seconds)
// Function: getFallingTime
// Purpose: Prompt the user to enter a valid falling time between 1 and 60 seconds.
// Parameters: None
// Returns: An integer representing the falling time.
int getFallingTime() {
    int time;
    do {
        cout << "Please enter the falling time (1-60 seconds): ";
        cin >> time;
        if (time < 1 || time > 60) {
            cout << "Invalid input. Time must be between 1 and 60 seconds.\n";
        }
    } while (time < 1 || time > 60); // Repeat until a valid input is provided

    return time;
}

// Story 3: This is a function to calculate the falling distance based on time (in seconds)
// Function: calculateFallingDistance
// Purpose: Calculates the falling distance using the formula 0.5 * g * t^2, where g is gravity and t is time.
// Parameters: An integer representing the time in seconds.
// Returns: A double representing the calculated falling distance in meters.
double calculateFallingDistance(int time) {
    const double gravity = 9.8; // Gravitational constant in meters per second squared
    return 0.5 * gravity * time * time; // Distance = 0.5 * g * t^2
}

// Story 4 & 6: To display the falling distance table with correct units (meters or feet)
// Function: displayFallingTable
// Purpose: This Function displays a table of falling distances for each second, either in meters or feet.
// Parameters: An integer for the falling time and a boolean for whether the distances should be in meters or feet.
// Returns: Nothing (void)
void displayFallingTable(int time, bool inMeters) {
    // Display the table header
    cout << "\nSeconds      Distance\n";
    cout << "=====================\n";

    for (int i = 1; i <= time; ++i) {
        // Calculate falling distance for each second
        double distance = calculateFallingDistance(i);

        // If the user wants the distance in feet, convert the distance
        if (!inMeters) {
            distance *= 3.28084; // Convert meters to feet
        }

        // Display the time and falling distance with 2 decimal precision
        cout << setw(6) << i << setw(15) << fixed << setprecision(2) << distance;

        // Append the appropriate unit (meters or feet) to the distance
        cout << (inMeters ? " m" : " ft") << "\n";
    }
}

// Story 5: This function allows the user to choose the units (meters or feet)
// Function: getUnitsChoice
// Purpose: Prompts the user to choose the unit for displaying distances (meters or feet).
// Parameters: None
// Returns: A boolean value; true if the user chooses meters, false for feet.
bool getUnitsChoice() {
    char unit;
    do {
        cout << "Do you want the results in meters (m) or feet (f)? ";
        cin >> unit;
        unit = tolower(unit); // Make the comparison case insensitive
        if (unit != 'm' && unit != 'f') {
            cout << "Invalid choice. Please enter 'm' for meters or 'f' for feet.\n";
        }
    } while (unit != 'm' && unit != 'f'); // Repeat until a valid input is provided

    return (unit == 'm'); // Return true if meters is chosen, false for feet
}

// This is the main function (entry point of the program)
// Function: main
// Purpose: Coordinates the program's flow by calling the other functions.
// Parameters: None
// Returns: An integer value indicating successful program termination (0).
int main() {
    // Display program information (Story 1)
    displayProgramInfo();

    // Get the falling time from the user (Story 2)
    int fallingTime = getFallingTime();

    // Get the user's choice for units (meters or feet) (Story 5)
    bool inMeters = getUnitsChoice();

    // Display the falling distance table based on user's input (Story 4 & 6)
    displayFallingTable(fallingTime, inMeters);

    return 0;
}
