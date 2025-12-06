#include <iostream>
#include <vector>
using namespace std;

double func(double x) {
    return 1.0 / (1 + x*x);
}

double simpson_one_third(double a, double b, int n, const vector<double> &y) {
    double h = (b - a) / n;
    double sum = y[0] + y[n];
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) sum += 2 * y[i];
        else sum += 4 * y[i];
    }
    return (h / 3.0) * sum;
}

double simpson_three_eighth(double a, double b, int n, const vector<double> &y) {
    double h = (b - a) / n;
    double sum = y[0] + y[n];
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) sum += 2 * y[i];
        else sum += 3 * y[i];
    }
    return (3.0 * h / 8.0) * sum;
}

int main() {
    int n;
    cin >> n;
    double a, b;
    cin >> a >> b;

    double h = (b - a) / n;
    vector<double> x(n + 1), y(n + 1);

    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        y[i] = func(x[i]);
    }

    if (n % 2 == 0)
        cout << "Simpson 1/3 = " << simpson_one_third(a, b, n, y) << endl;
    else
        cout << "Simpson 1/3 not applicable" << endl;

    if (n % 3 == 0)
        cout << "Simpson 3/8 = " << simpson_three_eighth(a, b, n, y) << endl;
    else
        cout << "Simpson 3/8 not applicable" << endl;

    return 0;
}