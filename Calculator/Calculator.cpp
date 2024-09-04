#include <iostream>
#include <cmath>  // For advanced operations like sqrt, pow

using namespace std;

void showMenu() {
    cout << "Simple Calculator\n";
    cout << "----------------\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exponentiation (^)\n";
    cout << "6. Square Root (√)\n";
    cout << "7. Exit\n";
}

int main() {
    int choice;
    double num1, num2;
    double result = 0; // Stores the result of the last operation
    bool useResult = false; // Flag to indicate if the result is to be used 

    while (true) {
        showMenu();
        cout << "Choose an operation: ";
        cin >> choice;

        // Exit if the user selects 7
        if (choice == 7) break;

        // If using the result from the last operation
        if (useResult) {
            num1 = result; // Use the previous result as the first number if user clicks 'y'
            cout << "Using previous result: " << num1 << endl;
        }
        else {
            // Input first number if not using previous result
            cout << "Enter the first number: ";
            cin >> num1;
        }

        if (choice >= 1 && choice <= 5) {
            cout << "Enter the second number: ";
            cin >> num2;
        }
        else if (choice == 6) {  // For square root
            num2 = 0; // No second number needed for square root
        }

        switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            }
            else {
                cout << "Error: Division by zero!" << endl;
                useResult = false; // Do not use result if error occurred
                continue; // Skip to next iteration
            }
            break;
        case 5:
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 6:
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "Result: " << result << endl;
            }
            else {
                cout << "Error: Negative input for square root!" << endl;
                useResult = false;  // Do not use result if error occurred
                continue; // Skip to next iteration
            }
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            continue; // Skip to next iteration
        }

        // Ask the user if they want to continue with the result
        char cont;
        cout << "Do you want to continue with the result? (y/n): ";
        cin >> cont;
        if (cont == 'y' || cont == 'Y') {
            useResult = true; // Set flag to use result
        }
        else {
            useResult = false; // Reset flag if not continuing with the result
        }
    }

    cout << "Calculator exited." << endl;
    return 0;
}

