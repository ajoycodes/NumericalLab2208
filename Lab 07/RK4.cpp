#include <iostream>
#include <vector>
using namespace std;

double f(double x, double y) {
    return x+y;
}

double rk4_step(double x, double y, double h) {
    double k1 = h*f(x,y);
    double k2 = h*f((x+h/2), (y+k1/2));
    double k3 = h*f((x+h/2), (y+k2/3));
    double k4 = h*f((x+h), (y+k3));

    return y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
}

double rk4(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;

    while (x<xn) {
        y = rk4_step(x, y, h);
        x += h;
    }

    return y;
}

int main() {
    double x0, y0, h, xn;
    cin>> x0 >> y0 >> h >> xn;

    cout<< "Result: " << rk4(x0, y0, h, xn) << endl;
}