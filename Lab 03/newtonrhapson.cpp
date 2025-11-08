#include <iostream>
#include <cmath>

using namespace std;

double f(const vector<double>& coef, double x){
    double val =0.0;
    int n = coef.size();
    for (int i=0; i<n; i++){
        val += coef[i] * pow(x, n-i-1);
    }

    return val;
}

double fprime (const vector<double> & coef, double x){
    double val = 0.0;

    int n = coef.size();
    for(int i=0; i< n; i++){
        val += (n-i-1)*coef[i] *pow(x, n-i-2);
    }

    return val;
}

void newtonRaphson(const vector<double>& coef, double x0, double E = 1e-5, int max_iter = 100){
    double x1;
    int iter = 0;

    do{
        double fx = f(coef, x0);
        double fpx = fprime(coef, x0);

        if(fabs(fpx)<1e-9){
            return;
        }

        x1= x0 - fx/fpx;

        iter ++;
        cout<< "Iter " << iter << ": x = " << x1 << ", f(x) = " << f(coef, x1) << endl;

        if(fabs((x1-x0))/x1 < E) break;

        x0 = x1;

    } while(iter < max_iter);

    cout<< "\nFunction: ";
    int n = coef.size();

    for (int i=0; i<n; i++){
        if(i!=0 && coef[i] >= 0) cout << "+";
        cout << coef[i] << "x^" << (n-i-1);
    }

    cout << " = 0\n";

    cout << "Root: " << x1 << endl;
    cout<< "Iterations = "<< iter << endl;
}


int main(){
    int degree;
    cout<< "Degree" << endl;
    cin>>degree;

    vector<double> coef(degree + 1);
    for (int i=0; i<=degree; i++){
        cin>> coef[i];
    }

    double x0;
    cout <<"Guess: ";
    cin>> x0;

    newtonRaphson(coef, x0);

    return 0;
}