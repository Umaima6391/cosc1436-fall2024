#include <iostream>
#include <iomanip> // For std::setprecision
using namespace std;

// Function declarations (prototypes)
double getLoanAmount();
float getInterestRate();
double getMonthlyPayment(double loanAmount);
void calculateLoanDetails(double loanAmount, float interestRate, double monthlyPayment);

//Display programs information
int main() {
    cout << "----------------------------------" << endl;
    cout << "Loan Interest Calculation Program" << endl;
    cout << " Umaima Khan" << endl;
    cout << " COSC 1436, Fall 2024" << endl;
    cout << "----------------------------------" << endl;

    // Get user inputs
    double loanAmount = getLoanAmount();
    double interestRate = getInterestRate();
    double monthlyPayment = getMonthlyPayment(loanAmount);

    // Calculate and display loan details
    calculateLoanDetails(loanAmount, interestRate, monthlyPayment);

    return 0;
}

// Function definitions

// Function to get the loan amount from the user
double getLoanAmount() {
    double loanAmount;

    while (true) {
        cout << "Please enter the loan amount (between $1 and $1,000): ";
        cin >> loanAmount;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid numeric value." << endl;
        } else if (loanAmount >= 1 && loanAmount <= 1000) {
            return loanAmount;
        } else {
            cout << "Error: Loan amount must be between $1 and $1,000." << endl;
        }
    }
}

// Function to get the interest rate from the user
float getInterestRate() {
    float interestRate;

    while (true) {
        cout << "Please enter the interest rate (% between 1.0 and 100.0): ";
        cin >> interestRate;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid numeric value." << endl;
        } else if (interestRate >= 1.0 && interestRate <= 100.0) {
            return interestRate;
        } else {
            cout << "Error: Interest rate must be between 1.0 and 100.0." << endl;
        }
    }
}

// Function to get the monthly payment from the user
double getMonthlyPayment(double loanAmount) {
    double payment;

    while (true) {
        cout << "How much do you want to pay each month? (Between $0 and $" << loanAmount << "): ";
        cin >> payment;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid numeric value." << endl;
        } else if (payment >= 0 && payment <= loanAmount) {
            return payment;
        } else {
            cout << "Error: Payment must be between $0 and $" << loanAmount << "." << endl;
        }
    }
}

// Function to calculate and display loan details for 12 months
void calculateLoanDetails(double loanAmount, float interestRate, double monthlyPayment) {
    double currentBalance = loanAmount;
    double totalPayments = 0.0;
    double totalInterest = 0.0;

    // Display table header
    cout << endl;
    cout << "Month   Balance        Payment        Interest       New Balance" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // Month 1: No interest, no payment
    cout << " 1   ";
    cout << "$ " << fixed << setprecision(2) << loanAmount << "          ";  // Old balance (same as loan amount)
    cout << "$ 0.00           ";  // No payment
    cout << "$ 0.00           ";  // No interest
    cout << "$ " << fixed << setprecision(2) << loanAmount << endl;  // New balance (same as loan amount)

    // Loop for months 2 to 12
    for (int month = 2; month <= 12; month++) {
        // Calculate interest for the month
        double interestForMonth = currentBalance * (interestRate / 100.0);

        // Add interest to the current balance
        currentBalance += interestForMonth;

        // Handle the monthly payment
        double paymentThisMonth = monthlyPayment;
        if (currentBalance < paymentThisMonth) {
            paymentThisMonth = currentBalance; // Pay off the loan
        }

        // Subtract the payment from the current balance
        currentBalance -= paymentThisMonth;

        // Track total payments and interest
        totalPayments += paymentThisMonth;
        totalInterest += interestForMonth;

        // Display monthly details
        cout << setw(2) << month << "   ";
        cout << "$ " << fixed << setprecision(2) << currentBalance + paymentThisMonth - interestForMonth << "          "; // Old balance
        cout << "$ " << fixed << setprecision(2) << paymentThisMonth << "           ";
        cout << "$ " << fixed << setprecision(2) << interestForMonth << "           ";
        cout << "$ " << fixed << setprecision(2) << currentBalance << endl;

        // If balance goes below zero, show 0 for the remainder of the months
        if (currentBalance <= 0) {
            currentBalance = 0; // Reset balance to zero

            // Print zeros for remaining months
            for (int remainingMonth = month + 1; remainingMonth <= 12; remainingMonth++) {
                cout << setw(2) << remainingMonth << "   ";
                cout << "$ " << fixed << setprecision(2) << 0.00 << "           "; // Old balance
                cout << "$ " << fixed << setprecision(2) << 0.00 << "           "; // Payment
                cout << "$ " << fixed << setprecision(2) << 0.00 << "           "; // Interest
                cout << "$ " << fixed << setprecision(2) << 0.00 << endl; // New balance
            }
            break; // Exit the loop if the loan is paid off
        }
    }

    // Display total payments and interest
    cout << "Total                  $ " << fixed << setprecision(2) << totalPayments
        << "       $ " << totalInterest << endl;
}
