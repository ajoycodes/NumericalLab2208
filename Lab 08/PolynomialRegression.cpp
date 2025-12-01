#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];

    double S0=n, S1=0, S2=0, S3=0, S4=0;
    double T0=0, T1=0, T2=0;

    for(int i=0;i<n;i++){
        S1 += x[i];
        S2 += x[i]*x[i];
        S3 += x[i]*x[i]*x[i];
        S4 += x[i]*x[i]*x[i]*x[i];

        T0 += y[i];
        T1 += x[i] * y[i];
        T2 += x[i]*x[i] * y[i];
    }

    double A[3][4] = {
        {S0, S1, S2, T0},
        {S1, S2, S3, T1},
        {S2, S3, S4, T2}
    };

    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            double r = A[j][i] / A[i][i];
            for(int k=i;k<4;k++)
                A[j][k] -= r * A[i][k];
        }
    }

    double c = A[2][3] / A[2][2];
    double b = (A[1][3] - A[1][2]*c) / A[1][1];
    double a = (A[0][3] - A[0][2]*c - A[0][1]*b) / A[0][0];

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}