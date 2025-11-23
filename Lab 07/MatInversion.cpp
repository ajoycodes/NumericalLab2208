#include <iostream>
#include <vector>
using namespace std;

void getCofactor(double A[][10], double temp[][10], int p, int q, int n) {
    int row =0, col = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i!=p && j!=q) {
                temp[row][col++] = A[i][j];
                if (col == n-1) {
                    col = 0;
                    row++;
                }
            }
        }
    }
}

double determinant(double A[][10], int n) {
    if (n==1) return A[0][0];

    double temp[10][10];
    double det = 0;
    int sign = 1;

    for (int i=0; i<n; i++) {
        getCofactor(A, temp, 0, i, n);

        det += sign * A[0][i] * determinant(temp, n-1);

        sign = -sign;
    }

    return det;
}


void adjoint(double A[][10], double adj[][10], int n) {
    if (n==1) {
        adj[0][0] = 1;
        return;
    }

    double temp[10][10];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            getCofactor(A, temp, i, j, n);

            int sign = ((i+j)%2 ==0)? 1:-1;

            adj[j][i] = sign*determinant(temp, n-1);
        }
    }
}


bool inverse(double A[][10], double inv[][10], int n) {
    double det = determinant(A, n);

    if (det==0) return false;

    double adj[10][10];
    adjoint(A, adj, n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            inv[i][j]= adj[i][j]/det;
        }
    }

    return true;
}


int main() {
    int n;
    cin >> n;

    double A[10][10], invA[10][10];

    // Input matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    // Compute inverse
    if(inverse(A, invA, n)) {
        // Print inverse matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << invA[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "Inverse does not exist";
    }
}