#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <functional>

using namespace std;

long double XLessThan1(long double x, int n) {
    if (n <= 6) throw invalid_argument("n must be greater than 6 for XLessThan1.");
    long double mlt = 1;
    for (int i = 2; i <= n - 3; i++) {
        mlt *= (pow(x, 2) + 2 * x) / i;
    }
    return mlt;
}

long double XMoreOrEqual1(long double x, int n) {
    if (n <= 6) throw invalid_argument("n must be greater than 6 for XMoreOrEqual1.");
    if (x == 0) throw invalid_argument("Division by zero in XMoreOrEqual1.");
    long double sum = 0;
    for (int j = 2; j <= n - 4; j++) {
        long double mlt = 1;
        for (int i = 0; i <= n; i++) {
            mlt *= x - (i * j) / double(i + j) - 7;
        }
        sum += mlt;
    }
    sum += 6 / x;
    return sum;
}

void handleInputError(const string& message) {
    cout << "Error: " << message << ". Please try again." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template <typename T>
T getValidatedInput(const string& prompt, function<void(T)> validator) {
    T value;
    while (true) {
        try {
            cout << prompt;
            cin >> value;

            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input");
            }

            validator(value);
            break;
        }
        catch (const invalid_argument& e) {
            handleInputError(e.what());
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

void validateB(long double b, long double a) {
    if (b <= a) throw invalid_argument("b must be greater than a");
}

void validateStep(long double step) {
    if (step <= 0) throw invalid_argument("Step must be positive");
}

void validateN(int n) {
    if (n <= 6) throw invalid_argument("n must be greater than 6");
}

int getValidatedInt(const string& prompt) {
    return getValidatedInput<int>(
        prompt,
        [](int value) {
            if (cin.fail()) throw invalid_argument("Invalid integer input");
        }
    );
}

void calculateAndDisplayResults(long double a, long double b, long double step, int n) {
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "x" << setw(30) << "y" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (long double x = a; x <= b; x += step) {
        try {
            long double result = (x < 1) ? XLessThan1(x, n) : XMoreOrEqual1(x, n);
            cout << setw(10) << fixed << setprecision(5) << x
                << setw(30) << fixed << setprecision(5) << result << endl;
        }
        catch (const exception& e) {
            cout << setw(10) << fixed << setprecision(5) << x
                << setw(30) << "Error: " << e.what() << endl;
        }
    }
}

int main() {
    char continueProgram;

    do {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        try {
            long double a = getValidatedInput<long double>(
                "a = ",
                [](long double) {}
            );

            long double b = getValidatedInput<long double>(
                "b = ",
                [a](long double value) {
                    if (value <= a) throw invalid_argument("b must be greater than a");
                }
            );

            long double step = getValidatedInput<long double>(
                "Input step: ",
                [](long double value) {
                    if (value <= 0) throw invalid_argument("Step must be positive");
                }
            );

            int n = getValidatedInput<int>(
                "Input n (n > 6): ",
                [](int value) {
                    if (value <= 6) throw invalid_argument("n must be greater than 6");
                }
            );

            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Calculating function y for each value of x in range [" << a << ", " << b << "] with step " << step << endl;

            calculateAndDisplayResults(a, b, step, n);
        }
        catch (const exception& e) {
            cout << "Unexpected error: " << e.what() << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> continueProgram;

    } while (continueProgram == 'y' || continueProgram == 'Y');

    cout << "Program finished." << endl;
    return 0;
}
