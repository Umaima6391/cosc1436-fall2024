#include <iostream>
using namespace std;

// Function to display program information 

void displayProgramInfo()
{
    cout << "program title: Lab 4" << endl;
    cout << "name: Umaima Khan" << endl;
    cout << "course: COSC 1436" << endl;
    cout << "semester: Fall 2024" << endl;
}

int main() 
{
    displayProgramInfo();
    // other code will go there 
    return 0;
}

const int Max_SIZE = 100;

int getUserNumber(int number[]) 
{
    int count = 0;
    int num;
    cout << "Enter numbers (0 to stop): " << endl;
    while (count < MAX_SIZE) 
    {
        cin >> num;
        if (num == 0) break;
        if (num < 0) {
            cout << "Invalid input. Please a positive number." << endl;
            continue;
        }
        numbers[count++] = num;
        }
        return count;
}

char displayMainMenu() 
{
    char choice;
    cout << "\nMain Menu:" << endl;
    cout << "1. Get Largest Value" << endl;
    cout << "2. Get Smallest Value" << endl;
    cout << "3. Sum of Values" << endl;
    cout << "4. Mean of Values" << endl;
    cout << "5. Display of Values" << endl;
    cout << "6. Add New Values" << endl;
    cout << "Q. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return toupper(choice);

}

int getLargestValue(int numbers[], int count)
{
    int largest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

int getSmallestValue(int numbers[], int count) {
    int smallest = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }
    return smallest;
}

int getSumOfValues(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

double getMeanOfValues(int numbers[], int count) {
    int sum = getSumOfValues(numbers, count);
    return static_cast<double>(sum) / count;
}

void displayValues(int numbers[], int count) {
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
        cout << endl;
}

int addNewValues(int numbers[], int count) {
    int num;
    cout << "Enter new numbers (0 to stop): " << endl;
    while (count < MAX_SIZE) {
        cin >> num;
        if (num == 0) break;
        if (num < 0) {
            cout << "Invalid input. Please enter a positive number." << endl;
            continue;
        }
        numbers[count++] = num;
    }
    return count;
}

Main Function: 

int main() {
    displayProgramInfo();

    int numbers[MAX_SIZE];
    int count = getUserNumbers(numbers);

    char choice;
    do {
        choice = displayMainMenu();
        switch (choice) {
            case '1':
                cout << "Largest Value: " << getLargestValue(numbers, count) << endl;
                break;
            case '2':
                cout << "Smallest Value: " << getSmallestValue(numbers, count) << endl;
                break;
            case '3':
                cout << "Sum of Values: " << getSumOfValues(numbers, count) << endl;
                break;
            case '4':
                cout << "Mean of Values: " << getMeanOfValues(numbers, count) << endl;
                break;
            case '5':
                displayValues(numbers, count);
                break;
            case '6':
                count = addNewValues(numbers, count);
                break;
            case 'Q':
                cout << "Quitting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'Q');

    return 0;
}

