#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(3);
    int i, j, k, n, m;
    cout << "\nThe number of point to be entered " << endl;
    cin >> m;
    double x[m], y[m];
    cout << "\nEnter the value of x " << endl;
    for (i = 0; i < m; i++) cin >> x[i];
    cout << "\nEnter the value of y" << endl;
    for (i = 0; i < m; i++) cin >> y[i];
    cout << "\nEnter the degree of polynomial " << endl;
    cin >> n;
    double B[n + 1][n + 2], a[n + 1], X[2 * n + 1], C[n + 1];
    for (i = 0; i < 2 * n + 1; i++) {
        X[i] = 0.0;
        for (j = 0; j < m; j++) X[i] = X[i] + pow(x[j], i);
    }
    for (i = 0; i < n + 1; i++) {
        C[i] = 0.0;
        for (j = 0; j < m; j++) C[i] = C[i] + pow(x[j], i) * y[j];
    }
    for (i = 0; i < n + 1; i++)
        for (j = 0; j < n + 1; j++) B[i][j] = X[i + j];
    // The matrice B and C to from augmented matrix
    for (i = 0; i < n + 1; i++) B[i][n + 1] = C[i];
    n = n + 1;
    cout << "\nTHe matrix to be entered " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) cout << B[i][j] << setw(10);
        cout << "\n";
    }
    // lets do pivotising
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (abs(B[i][i]) < abs(B[k][i]))
                for (j = 0; j < n + 1; j++) {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }
    cout << "\nafter pivotising matrix " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) cout << B[i][j] << setw(10);
        cout << "\n";
    }
    // Elementary operation
    for (i = 0; i < n - 1; i++)
        for (k = i + 1; k < n; k++) {
            double t = B[k][i] / B[i][i];
            for (j = 0; j <= n; j++) B[k][j] = B[k][j] - t * B[i][j];
        }
    cout << "\nafter Elementary matrix " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) cout << B[i][j] << setw(10);
        cout << "\n";
    }
    // Back subtitution
    for (i = n - 1; i >= 0; i--) {
        a[i] = B[i][n];
        for (j = i + 1; j < n; j++)
            if (j != i) a[i] = a[i] - B[i][j] * a[j];
        a[i] = a[i] / B[i][i];
    }
    cout << "the values of the varible are" << endl;
    for (i = 0; i < n; i++) cout << a[i] << endl;
    cout << "\nThe requied polynomial is : \n";
    cout << "y = " << a[0] << " + " << a[1] << "x + " << a[2] << "x^2" << a[3]
         << "x^3";
    return 0;
}
