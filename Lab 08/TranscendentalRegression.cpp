#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];

    vector<double> Y(n);  // ln(y)
    for(int i=0;i<n;i++) Y[i] = log(y[i]);

    double sumX=0, sumY=0, sumXY=0, sumX2=0;

    for(int i=0;i<n;i++){
        sumX += x[i];
        sumY += Y[i];
        sumXY += x[i] * Y[i];
        sumX2 += x[i] * x[i];
    }

    double m = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double C = (sumY - m*sumX) / n;

    double c = exp(C);   // because C = ln(c)

    cout << "m = " << m << endl;
    cout << "c = " << c << endl;
}
