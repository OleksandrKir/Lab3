#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <functional>
// changes
using namespace std;

string formatNumber(long double number) {
    ostringstream out;
    out << fixed << setprecision(25) << number;

    string str = out.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }

    return str;
}

long double XLessThan1(long double x, int n) {
    if (n <= 3) throw invalid_argument("n must be greater than 3 for XLessThan1.");
    long double mlt = 1;
    for (int i = 2; i <= n - 3; i++) {
        mlt *= (pow(x, 2) + 2 * x) / i;
    }
    return mlt;
}

long double XMoreOrEqual1(long double x, int n) {
    if (n <= 4) throw invalid_argument("n must be greater than 4 for XMoreOrEqual1.");
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

template<typename T>
T getValidatedInput(const string& prompt, function<bool(T)> validator, const string& errorMessage) {
    T value;
    while (true) {
        cout << prompt;
        if (cin >> value && validator(value)) {
            break;
        }
        cout << "Error: " << errorMessage << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int getValidatedIntInput(const string& prompt, function<bool(int)> validator, const string& errorMessage) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        cin >> input;

        try {
            size_t pos;
            value = stoi(input, &pos);
            if (pos == input.length() && validator(value)) {
                break;
            }
        }
        catch (...) {
        }
        cout << "Error: " << errorMessage << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void calculateAndDisplayResults(long double a, long double b, long double step, int n) {
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(4) << "x" << setw(50) << "y" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (long double x = a; x <= b; x += step) {
        try {
            long double result;
            if (x < 1) {
                result = XLessThan1(x, n);
            }
            else {
                result = XMoreOrEqual1(x, n);
            }
            cout << setw(30) << formatNumber(x) << setw(50) << formatNumber(result) << endl;
        }
        catch (const exception& e) {
            cout << setw(30) << formatNumber(x) << setw(50) << "Error: " << e.what() << endl;
        }
    }
}

int main() {
    char continueProgram;

    do {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        long double a = getValidatedInput<long double>(
            "a = ",
            [](long double value) { return true; },
            "Please input a valid number for 'a'."
        );

        long double b = getValidatedInput<long double>(
            "b = ",
            [a](long double value) { return value > a; },
            "b must be greater than a."
        );

        long double step = getValidatedInput<long double>(
            "Input step: ",
            [](long double value) { return value > 0; },
            "Step must be positive."
        );

        int n = getValidatedIntInput(
            "Input n (n > 6): ",
            [](int value) { return value > 6; },
            "n must be a valid integer greater than 6."
        );

        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Calculating function y for each value of x in range [" << a << ", " << b << "] with step " << step << endl;

        calculateAndDisplayResults(a, b, step, n);

        cout << "Do you want to continue? (y/n): ";
        cin >> continueProgram;

    } while (continueProgram == 'y' || continueProgram == 'Y');

    cout << "Program finished." << endl;
    return 0;
}