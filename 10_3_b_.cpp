 #include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
// test convergency
bool convergency(double B[3][4]) {
    bool converge = true;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            sum += fabs(B[i][j]);
        }
        if (sum > fabs(B[i][i])) {
            converge = false;
            break;
        }
    }
    return converge;
}

int main() {
    cout << fixed << setprecision(6);
    double A[3][4], B[3][4], X[3], X1[3], R[3], ep, temp;
    bool solvable = false;
    cout << "\nEnter equation in the form ax + by + cz = d\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << "a" << i << j << " = ";
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
    // Rearrange the augmented matrix
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= 3; j++) {
                B[i][j] = A[(k + i) % 3][j];
            }
        }
        if (convergency(B) == true) {
            solvable = true;
            break;
        }
        for (int j = 0; j <= 3; j++) {
            temp = B[1][j];
            B[1][j] = B[2][j];
            B[2][j] = temp;
        }
        if (convergency(B) == true) {
            solvable = true;
            break;
        }
    }
    // If any convergeable arrangement found, then try to solve
    if (solvable == false) {
        cout << "\nGiven system of equations can not converge by this method\n";
    } else {
        cout << "\nThe matrix arrangement which will converge\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= 3; j++) {
                cout << B[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "\nEnter initial value of x\n";
        for (int i = 0; i < 3; i++) {
            cout << "x" << i + 1 << " = ";
            cin >> X[i];
        }
        cout << "\nEnter desire accuracy\n";
        cin >> ep;
        do {
            for (int i = 0; i < 3; i++) {
                X1[i] = X[i];
                R[i] = B[i][3] / B[i][i];
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    R[i] = R[i] - ((B[i][j] / B[i][i]) * X[j]);
                }
                for (int i = 0; i < 3; i++) {
                    X[i] = R[i];
                }
            }

        } while (fabs(X1[0] - X[0]) > ep || fabs(X1[1] - X[1]) > ep ||
                 fabs(X1[2] - X[2]) > ep);
        for (int i = 0; i < 3; i++) {
            cout << "\nX" << i + 1 << " = " << X[i] << endl;
        }
    }
    return 0;
}