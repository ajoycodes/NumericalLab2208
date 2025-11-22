#include <iostream>
#include <vector>
using namespace std;


void buildForward(double diff[][10], double y[], int n) {
    for(int i = 0; i < n; i++) diff[i][0] = y[i];

    for(int j = 1; j < n; j++)
        for(int i = 0; i < n - j; i++)
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
}

double fact(int n) {
    double f=1;
    for (int i=1; i<=n; i++) {
        f *= i;
    }
    return f;
}

double newtonForward(double x[], double y[], int n, double value) {
    double diff[10][10];
    buildForward(diff, y, n);

    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    double ans = diff[0][0];
    double uterm = 1;

    for(int i = 1; i < n; i++) {
        uterm *= (u - (i - 1));
        ans += (uterm * diff[0][i]) / fact(i);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    double x[10], y[10];
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    double value; cin >> value;

    cout << "Result = " << newtonForward(x, y, n, value);
}