#include <iostream>
using namespace std;

void add(double x, double y) {
    cout << x << " + " << y << " = " << x + y << endl;
}

void subtract(double x, double y) {
    cout << x << " - " << y << " = " << x - y << endl;
}

void multiply(double x, double y) {
    cout << x << " * " << y << " = " << x * y << endl;
}

void divide(double x, double y) {
    if (y == 0) {
        cout << "Error! Division by zero." << endl;
    } else {
        cout << x << " / " << y << " = " << x / y << endl;
    }
}

int main() {
    int choice;
    double num1, num2;

    cout << "Select operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

 while (true) {
        cout << "Enter choice (1/2/3/4): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            switch (choice) {
                case 1:
                    add(num1, num2);
                    break;
                case 2:
                    subtract(num1, num2);
                    break;
                case 3:
                    multiply(num1, num2);
                    break;
                case 4:
                    divide(num1, num2);
                    break;
            }
        } else {
            cout << "Invalid input, Please enter a valid choice." << endl;
        }

        char next_calculation;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> next_calculation;
        if (next_calculation != 'y' && next_calculation != 'Y') {
            break;
        }
    }
    
    return 0;
}