#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<double>> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << setw(10) << fixed << setprecision(4) << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));

    cout << "Enter augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nInitial Augmented Matrix:\n";
    printMatrix(a);


    for (int i = 0; i < n - 1; i++) {
       
        int pivotRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[pivotRow][i])) {
                pivotRow = k;
            }
        }
        if (pivotRow != i) swap(a[i], a[pivotRow]);

        if (fabs(a[i][i]) < 1e-9) {
            cout << "Zero pivot encountered. Cannot solve.\n";
            return 0;
        }

        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }

        cout << "\nAfter elimination step " << i + 1 << ":\n";
        printMatrix(a);
    }

    //substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

   
    cout << "\nFinal Upper Triangular Matrix:\n";
    printMatrix(a);

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }

    return 0;
}