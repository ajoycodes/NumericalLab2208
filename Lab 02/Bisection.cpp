#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x,4) - 3*pow(x,3) + 2*pow(x,2) + 6*x;
}

double bisection(double a, double b, double E, int& iteration) {
    double c;
    iteration = 0;

    if (f(a) * f(b) > 0) {
        cout << "Invalid initial bracket!" << endl;
        return NAN;
    }

    while ((b - a) >= E) {
        c = (a + b) / 2.0;
        iteration++;

        if (fabs(f(c)) < E)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

void findBracket(double xmin, double xmax, double steps, double E) {
    double x1 = xmin, x2 = xmin + steps;
    int rootCount = 0;

    while (x2 <= xmax) {
        if (f(x1) * f(x2) < 0) {
            int iter = 0;
            double root = bisection(x1, x2, E, iter);
            rootCount++;
            cout << fixed << setprecision(6);
            cout << "Root " << rootCount << ": " << root 
                 << "   (iterations: " << iter << ")" << endl;
        }
        x1 = x2;
        x2 += steps;
    }

    if (rootCount == 0)
        cout << "No roots found in the given range." << endl;
}

int main() {
    double xmin = -10, xmax = 10;
    cout << "Search Interval: [" << xmin << ", " << xmax << "]" << endl;
    findBracket(xmin, xmax, 0.5, 1e-4);
    return 0;
}