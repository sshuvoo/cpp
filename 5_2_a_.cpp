// Newton's Backward Interpolation
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(6);
    int n;
again:
    cout << "\nEnter the number of values\n";
    cin >> n;
    double X[n], Y[n][n];
    cout << "\nEnter the values of x\n";
    for (int i = 0; i < n; i++) cin >> X[i];
    cout << "\nEnter the values of y\n";
    for (int i = 0; i < n; i++) cin >> Y[i][0];
    // Calculate difference Table
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            Y[i][j] = Y[i][j - 1] - Y[i - 1][j - 1];
        }
    }
    cout << "\nThe backward difference table : \n";
    cout << "\tx\t\ty";
    for (int i = 1; i < n; i++) {
        cout << "\t\td" << i << "y";
    }
    cout << "\n\t.............................................";
    cout << ".............................................\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << X[i];
        for (int j = 0; j <= i; j++) {
            cout << "\t" << Y[i][j];
        }
        cout << "\n";
    }
    // Code of interpolation
    double xn, h, p, sum = Y[n - 1][0], term = 1;
    h = X[1] - X[0];
    cout << "\nEnter the value of x at which y to be calculated\n";
    cin >> xn;
    p = (xn - X[n - 1]) / h;
    for (int i = 1; i < n; i++) {
        term = term * (p + i - 1) / i;
        sum = sum + term * Y[n - 1][i];
    }
    cout << "\nThe value of y at " << xn << " is " << sum;
    return 0;
}