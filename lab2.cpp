#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
// aa
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
    long double mlt = 1;
    for (int i = 2; i <= n - 3; i++) {
        long double term = (pow(x, 2) + 2 * x) / i;
        mlt *= term;
    }
    return mlt;
}

long double XMoreOrEqual1(long double x, int n) {
    long double sum = 0;
    for (int j = 2; j <= n - 4; j++) {
        long double mlt = 1;
        for (int i = 0; i <= n; i++) {
            long double term = x - (i * j) / double(i + j) - 7;
            mlt *= term;
        }
        sum += mlt;
    }
    sum += 6 / x;
    return sum;
}

int main() {
    char continueProgram;

    do {
        long double a, b, step;
        int n;

        cout << setw(30) << "Calculator of equation" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Input the range [a, b]:" << endl;

        cout << "a = ";
        while (!(cin >> a)) {
            cout << "Error: please input a valid number for 'a'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "a = ";
        }

        cout << "b = ";
        while (!(cin >> b) || b <= a) {
            cout << "Error: please input a valid number for 'b' (b must be greater than a)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "b = ";
        }

        cout << "Input step: ";
        while (!(cin >> step) || step <= 0) {
            cout << "Error: please input a valid step (must be positive)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input step: ";
        }

        cout << "Input n (n > 6): ";
        while (true) {
            if (cin >> n && cin.peek() == '\n' && n > 6) {
                break;
            }
            else {
                cout << "Error: please input a valid integer for 'n' (n must be greater than 6)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input n: ";
            }
        }
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "Calculating function y for each value of x in range [" << a << ", " << b << "] with step " << step << endl;
        cout << "----------------------------------------" << endl;
        cout << setw(4) << "x" << setw(50) << "y" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        for (long double x = a; x <= b; x += step) {
            long double result;
            if (x < 1) {
                result = XLessThan1(x, n);
            }
            else {
                result = XMoreOrEqual1(x, n);
            }

            cout << setw(30) << formatNumber(x) << setw(50) << formatNumber(result) << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> continueProgram;

    } while (continueProgram == 'y' || continueProgram == 'Y');

    cout << "Program finished." << endl;

    return 0;
}