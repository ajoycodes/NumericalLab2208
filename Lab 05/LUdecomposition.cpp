#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout<< "Enter order of matrix: "<< endl;
    cin>>n;
    
    vector< vector<double>> A(n, vector<double>(n));
    vector< vector<double>> L(n, vector<double>(n,0));
    vector< vector<double>> U(n, vector<double>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> A[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int k=i; k<n; k++){
            double sum =0;
            for(int j=0; j<i; j++){
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }
        
        for(int k=i; k<n; k++){
            if(i==k){
                L[i][k]=1;
            }else{
                double sum =0;
                for(int j=0; j<i; j++){
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum)/U[i][i];
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout <<setw(10)<< fixed <<setprecision(3) << L[i][j] << " ";
        }
        cout<< endl;
    }
    
    cout<< endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout <<setw(10)<< fixed <<setprecision(3) << U[i][j] << " ";
        }
        cout<< endl;
    }
    
    
    return 0;
}