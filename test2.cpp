#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

    string arithmetic = "+-/*";
    string expression;
    string currentNumber = "";

    double numbers[10];
    int numberCount = 0;

    char operators[10];
    int operatorCount = 0;

    cin >> expression;

    // Separate numbers and operators
    for (int i = 0; i < expression.length(); i++) {

        if (isdigit(expression[i])) {
            currentNumber += expression[i];
        }

        else {

            for (int j = 0; j < arithmetic.length(); j++) {

                if (expression[i] == arithmetic[j]) {

                    operators[operatorCount] = expression[i];
                    operatorCount++;

                    cout << "Number: " << currentNumber << '\n';
                    cout << "Operator: " << expression[i] << '\n';

                    numbers[numberCount] = stod(currentNumber);
                    numberCount++;

                    currentNumber = "";
                }
            }
        }
    }

    // Save the last number
    numbers[numberCount] = stod(currentNumber);
    numberCount++;

    // Show numbers
    for (int i = 0; i < numberCount; i++) {
        cout << numbers[i] << '\n';
    }

    // Show operators
    for (int i = 0; i < operatorCount; i++) {
        cout << operators[i] << '\n';
    }

    // Show each operation
    for (int i = 0; i < operatorCount; i++) {

        cout << numbers[i] << " "
             << operators[i] << " "
             << numbers[i + 1] << '\n';
    }

    // Handle * and / first
    for (int i = 0; i < operatorCount; i++) {

        if (operators[i] == '*' || operators[i] == '/') {

            if (operators[i] == '*') {

                numbers[i] = numbers[i] * numbers[i + 1];

                cout << "found multiply "
                     << numbers[i] << '\n';
            }

            if (operators[i] == '/') {

                // Check for division by zero
                if (numbers[i + 1] == 0) {
                    cout << "Error: Cannot divide by zero\n";
                    return 0;
                }

                else {

                    numbers[i] = numbers[i] / numbers[i + 1];

                    cout << "found divison"
                         << numbers[i] << '\n';
                }
            }

            // Remove the extra number
            for (int j = i + 1; j < numberCount - 1; j++) {
                numbers[j] = numbers[j + 1];
            }

            numberCount--;

            // Remove the used operator
            for (int j = i; j < operatorCount - 1; j++) {
                operators[j] = operators[j + 1];
            }

            operatorCount--;

            i--;
        }
    }

    // Show the arrays after * and /
    cout << "\nAfter precedence:\n";

    for (int i = 0; i < numberCount; i++) {
        cout << numbers[i] << '\n';
    }

    for (int i = 0; i < operatorCount; i++) {
        cout << operators[i] << '\n';
    }

    // final calculation: + and -
    double result = numbers[0];

    for (int i = 0; i < operatorCount; i++) {

        switch (operators[i]) {

            case '+':
                result += numbers[i + 1];
                break;

            case '-':
                result -= numbers[i + 1];
                break;
        }
    }

    cout << "Result: " << result << '\n';

    return 0;
}
