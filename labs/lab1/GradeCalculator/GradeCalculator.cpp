// Lab 1
// Umaima Khan
// COSC 1436 Fall 2024

#include <iostream>
#include <iomanip> // Include this for setprecision

int main()
{
    //To display user's information
    std::cout << "Lab 1\n";
    std::cout << "Umaima Khan\n";
    std::cout << "COSC 1436 Fall 2024\n";

    //Variables to store user data
    std::string name;
    int lab1, lab2, lab3, lab4;
    int exam1, exam2, exam3;
    int participation, finalExam;

    //Prompt the user for name and grades
    std::cout << "Please enter your name: ";
    std::cin >> name;
    std::cout << "Please enter lab 1 grade: ";
    std::cin >> lab1;
    std::cout << "Please enter lab 2 grade: ";
    std::cin >> lab2;
    std::cout << "Please enter lab 3 grade: ";
    std::cin >> lab3;
    std::cout << "Please enter lab 4 grade: ";
    std::cin >> lab4;
    std::cout << "Please enter exam 1 grade: ";
    std::cin >> exam1;
    std::cout << "Please enter exam 2 grade: ";
    std::cin >> exam2;
    std::cout << "Please enter exam 3 grade: ";
    std::cin >> exam3;
    std::cout << "Please enter participation grade: ";
    std::cin >> participation;
    std::cout << "Please enter final exam grade: ";
    std::cin >> finalExam;
    std::cout << std::endl;

    // Calculate lab average and Exam average
    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4.0;
    double examAverage = (exam1 + exam2 + exam3) / 3.0;

    // Calculate class average using the given weights
    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);

    // Display lab grades and average
    std::cout << name << ", your lab grades are:\n";
    std::cout << "Lab 1 = " << lab1 << "\n";
    std::cout << "Lab 2 = " << lab2 << "\n";
    std::cout << "Lab 3 = " << lab3 << "\n";
    std::cout << "Lab 4 = " << lab4 << "\n";

    //Display exam grades and average
    std::cout << "\n" << name << ", your exam grades are:\n";
    std::cout << "Exam 1 = " << exam1 << "\n";
    std::cout << "Exam 2 = " << exam2 << "\n";
    std::cout << "Exam 3 = " << exam3 << "\n";

    // Display participation and final exam grades
    std::cout << "\n" << name << ", your other grades are:\n";
    std::cout << "Participation = " << participation << "\n";
    std::cout << "Final Exam = " << finalExam << "\n";

    // Display class average
    std::cout << "\n" << name << ", your class grade is:\n";
    std::cout << "Lab Average (65%) = " << std::fixed << std::setprecision(2) << labAverage << " %\n";
    std::cout << "Exam Average (20%) = " << std::fixed << std::setprecision(2) << examAverage << " %\n";
    std::cout << "Participation (5%) = " << participation << " %\n";
    std::cout << "Final Exam (10%) = " << finalExam << " %\n";
    std::cout << "Class Average = " << std::fixed << std::setprecision(2) << classAverage << " %\n";

    return 0;

}
