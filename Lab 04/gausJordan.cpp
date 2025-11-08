#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void printMatrix(vector<vector<double>> & a ){
    int n = a.size();
    for(int i=0; i< n; i++){
        for(int j = 0; j<=n; j++){
            cout<< setw(10) << a[i][j] ;
        }
        cout << endl;
    }
}

int main(){
    int n; 

    cout <<"Enter number of equations: ";
    cin >> n;

    vector< vector< double>> a(n, vector<double> (n+1));

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cin >> a[i][j];
        }
    }

    cout<< "Initial: " << endl;
    printMatrix(a);

    for(int i=0; i<n; i++){
        
        if(fabs(a[i][i])<1e-9){
            for(int k=i+1; k<n; k++){
                if(fabs(a[k][i])>fabs(a[i][i])){
                    swap(a[i], a[k]);
                }
            }
        }

        double pivot = a[i][i];
        for(int j=0; j<=n; j++){
            a[i][j] /= pivot;
        }

        for(int k=0; k<n; k++){
            if(k!=i){
                double factor = a[k][i];
                for(int j=0; j<=n; j++){
                    a[k][j] -= factor * a[i][j];
                }
            }
        }

        cout<< "\nAfter step: " << i+1 << ":\n";
        printMatrix(a);
    }

    cout<< "Final Soln:" << endl;
    for(int i=0; i<n; i++){
        cout<< "x" << i+ 1 << " = " << a[i][n] << endl;
    }

    return 0;

}