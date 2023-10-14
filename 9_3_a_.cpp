#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cout << fixed << setprecision(3);
    double A[3][4], X[3], temp, t;
    cout << "\nEnter Augmented matrix in row wise\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cin >> A[i][j];
        }
        cout << endl;
    }
    cout << "\nThe matrix you entered is :\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    // Do Pivoting
    for (int i = 0; i < 2; i++) {
        for (int k = i + 1; k < 3; k++) {
            if (fabs(A[i][i]) < fabs(A[k][i])) {
                for (int j = 0; j <= 3; j++) {
                    temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }
    }
    cout << "\nThe matrix after pivoting is : \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    // Do elimentary row operatuion
    for (int k = 0; k < 2; k++) {
        for (int i = k + 1; i < 3; i++) {
            t = A[i][k] / A[k][k];
            for (int j = 0; j <= 3; j++) {
                A[i][j] = A[i][j] - t * A[k][j];
            }
        }
    }
    cout << "\nThe matrix after Elimentary row operation is : \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    // back Substitution
    for (int i = 2; i >= 0; i--) {
        X[i] = A[i][3];
        for (int j = i + 1; j < 3; j++) {
            X[i] = X[i] - A[i][j] * X[j];
        }
        X[i] = X[i] / A[i][i];
    }
    cout << "\nThe value of the variables are : \n";
    for (int i = 0; i < 3; i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }
    return 0;
}