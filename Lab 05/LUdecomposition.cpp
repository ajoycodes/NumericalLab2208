#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9; // for floating-point precision check

int main() {
    while (true) {
        int n;
        cout << "Enter number of equations: ";
        cin >> n;

        // Read augmented matrix A|b
        vector<vector<double>> A(n, vector<double>(n));
        vector<double> b(n);

        cout << "Enter the augmented matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
            cin >> b[i];
        }

        vector<vector<double>> L(n, vector<double>(n, 0.0));
        vector<vector<double>> U(n, vector<double>(n, 0.0));

        bool singular = false; // for zero pivot detection

        // LU decomposition (Doolittle)
        for (int i = 0; i < n; i++) {
            // Upper triangular
            for (int k = i; k < n; k++) {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[i][j] * U[j][k];
                U[i][k] = A[i][k] - sum;
            }

            // Check zero pivot
            if (fabs(U[i][i]) < EPS) {
                singular = true;
                break;
            }

            // Lower triangular
            for (int k = i; k < n; k++) {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }

        if (singular) {
            cout << "\nThe system has no unique solution (singular matrix).\n";
        } else {
            // Forward substitution: L*y = b
            vector<double> y(n);
            for (int i = 0; i < n; i++) {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[i][j] * y[j];
                y[i] = b[i] - sum;
            }

            // Backward substitution: U*x = y
            vector<double> x(n);
            bool infinite = false, noSolution = false;

            for (int i = n - 1; i >= 0; i--) {
                double sum = 0;
                for (int j = i + 1; j < n; j++)
                    sum += U[i][j] * x[j];

                if (fabs(U[i][i]) < EPS) {
                    if (fabs(y[i] - sum) < EPS)
                        infinite = true; // 0 = 0 → infinite
                    else
                        noSolution = true; // 0 = nonzero → inconsistent
                } else {
                    x[i] = (y[i] - sum) / U[i][i];
                }
            }

            // Print L and U
            cout << fixed << setprecision(3);
            cout << "\nLower Triangular Matrix (L):\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << setw(8) << L[i][j];
                cout << "\n";
            }

            cout << "\nUpper Triangular Matrix (U):\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << setw(8) << U[i][j];
                cout << "\n";
            }

            // Print result type
            if (noSolution)
                cout << "\nThe system has no solution.\n";
            else if (infinite)
                cout << "\nThe system has infinite solutions.\n";
            else {
                cout << "\nUnique solution:\n";
                for (int i = 0; i < n; i++)
                    cout << "x" << i + 1 << " = " << x[i] << "\n";
            }
        }

        // Ask to solve another system
        char ch;
        cout << "\nSolve another system? (y/n): ";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            break;
    }

    return 0;
}