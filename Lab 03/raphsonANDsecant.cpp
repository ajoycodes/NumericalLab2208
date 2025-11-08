#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x,3) - 6*pow(x,2) + 11*x -6;
}

double df(double x){
    return 3*pow(x,2) - 12*x + 11;
}

void newtonRaphson(double x0, double tol = 1e-6, int max_iter=100){
    cout<< "Raphson: "<< endl;
    int iter = 0;
    double x = x0;

    while(iter < max_iter){
        double fx = f(x);
        double dfx = df(x);

        if(fabs(dfx)< 1e-9){
            return;
        }

        double x1 = x - fx / dfx ;
        cout << "Iter " << iter + 1 << ": x = " << x1 << " f(x) = " << f(x1) << endl;

        if(fabs(x1-x) < tol){
            cout << "\nRoot ≈ " << x1 << " found in " << iter+1 << " iterations.\n";
            return;
        }

        x = x1;
        iter++;
    }
     cout << "Did not converge within " << max_iter << " iterations.\n";
}

void secant(double x0, double x1, double tol = 1e-6, int max_iter=100){
    cout<< "Secant: "<< endl;
    int iter = 0;
    double f0 = f(x0);
    double f1 = f(x1);

    while(iter < max_iter){
        if(fabs(f1-f0)< 1e-9){
            return;
        }

        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        cout << "Iter " << iter + 1 << ": x = " << x2 << " f(x) = " << f(x2) << endl;

           if(fabs(x2-x1) < tol){
            cout << "\nRoot ≈ " << x2 << " found in " << iter+1 << " iterations.\n";
            return;
        }

        x0 = x1;
        x1= x2;
        f0=f1;
        f1 = f(x1);
        iter++;
    }
    cout << "Did not converge within " << max_iter << " iterations.\n";
}


int main() {
    double guess1, guess2;

    cout << "Enter initial guess for Newton–Raphson: ";
    cin >> guess1;
    newtonRaphson(guess1);

    cout << "\nEnter two initial guesses for Secant method: ";
    cin >> guess1 >> guess2;
    secant(guess1, guess2);

    return 0;
}