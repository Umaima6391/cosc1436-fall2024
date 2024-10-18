#include <iostream>
using namespace std;

void displayProgramInfo() {
    cout << "Program Title: Falling Distance Calculator\n";
    cout << "Name: Umaima Khan\n";
    cout << "Course: COSC 1436 - Fall 2024\n";
}

int getFallingTime() {
    int time;
    do {
        cout << "Please enter the falling time (1-60 seconds): ";
        cin >> time;
        if (time < 1 || time > 60) {
            cout << "Invalid input. Time must be between 1 and 60 seconds.\n";
        }
    } while (time < 1 || time > 60);

    return time;
}
double calculateFallingDistance(int time) {
    const double gravity = 9.8;
    return 0.5 * gravity * time * time; // Distance = 0.5 * g * t^2
}
void displayFallingTable(int time, bool inMeters) {
    cout << "\nSeconds\t  Distance\n";
    cout << "====================\n";

    for (int i = 1; i <= time; ++i) {
        double distance = calculateFallingDistance(i);
        if (!inMeters) { // Convert to feet if necessary
            distance *= 3.28084;
        }
        cout << i << "\t  " << distance << (inMeters ? " m" : " ft") << "\n";
    }
}
bool getUnitsChoice() {
    char unit;
    do {
        cout << "Do you want the results in meters (m) or feet (f)? ";
        cin >> unit;
        unit = tolower(unit);
        if (unit != 'm' && unit != 'f') {
            cout << "Invalid choice. Please enter 'm' for meters or 'f' for feet.\n";
        }
    } while (unit != 'm' && unit != 'f');

    return (unit == 'm');
}

int main() {
    displayProgramInfo();
    int fallingTime = getFallingTime();
    bool inMeters = getUnitsChoice();
    displayFallingTable(fallingTime, inMeters);
    return 0;
}

