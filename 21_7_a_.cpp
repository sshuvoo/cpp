#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(3);
    int m, n = 2;
    cout << "\nEnter the number of points\n";
    cin >> m;
    double P[m], Q[m], temp, t;
    cout << "\nEnter the x values\n";
    for (int i = 0; i < m; i++) cin >> P[i];
    cout << "\nEnter the y values\n";
    for (int i = 0; i < m; i++) cin >> Q[i];
    // set degree of polynoial
    double A[n + 1][n + 2], X[n + 1];
    for (int i = 0; i <= n; i++) {
        // calculate different element of the augmented matrix in a row
        for (int j = 0; j <= n; j++) {
            A[i][j] = 0;
            for (int k = 0; k < m; k++) {
                A[i][j] += pow(P[k], (i + j));  // xi, xi2, xi3, xi4
            }
        }
        // calculate the last element of the augmented matrix in a row
        A[i][n + 1] = 0;
        for (int k = 0; k < m; k++) {
            A[i][n + 1] +=  pow(P[k], i) * Q[k];  // yi, xiyi, xi2yi
        }
    }

    n = n + 1;
    // Do Pivoting
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[i][i]) < fabs(A[k][i])) {
                for (int j = 0; j <= n; j++) {
                    temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }
    }
    // Do elimentary row operation
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            t = A[i][k] / A[k][k];
            for (int j = 0; j <= n; j++) {
                A[i][j] = A[i][j] - t * A[k][j];
            }
        }
    }
    // back Substitution
    for (int i = n - 1; i >= 0; i--) {
        X[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            if (i != j) X[i] = X[i] - A[i][j] * X[j];
        }
        X[i] = X[i] / A[i][i];
    }
    cout << "\nThe value of the coefficients are : \n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }
    cout << "\nThe requied polynomial is : \n";
    cout << "y = " << X[0] << " + " << X[1] << " x + " << X[2] << " x^2";
    return 0;
}