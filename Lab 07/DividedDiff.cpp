#include <iostream>
#include <vector>
using namespace std;

void buildDivided(double x[], double y[][10], int n) {
    for(int j = 1; j < n; j++)
        for(int i = 0; i < n - j; i++)
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
}

double dividedDifference(double x[], double y[][10], int n, double value) {
    double ans = y[0][0];
    double term = 1;

    for(int i = 1; i < n; i++) {
        term *= (value - x[i-1]);
        ans += term * y[0][i];
    }
    return ans;
}

int main() {
    int n; cin >> n;
    double x[10], y[10][10];

    for(int i = 0; i < n; i++) cin >> x[i] >> y[i][0];
    double value; cin >> value;

    buildDivided(x, y, n);
    cout << "Result = " << dividedDifference(x, y, n, value);
}