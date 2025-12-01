#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];

    double sumX=0, sumY=0, sumXY=0, sumX2=0;

    for(int i=0;i<n;i++){
        sumX  += x[i];
        sumY  += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double m = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double c = (sumY - m*sumX) / n;

    cout << "m = " << m << endl;
    cout << "c = " << c << endl;
}