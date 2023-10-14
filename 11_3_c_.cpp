// Gaus-seidel
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(4);
    int n, i, j, k, flag = 0, count = 0;
    cout << "\nEnter the no. of equations\n";
    cin >> n;
    double a[n][n + 1], x[n], eps, y;
    cout << "\nEnter the elements of the augmented matrix row-wise:\n";
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++) cin >> a[i][j];
    cout << "\nEnter the initial values of the variables:\n";
    for (i = 0; i < n; i++) cin >> x[i];
    cout << "\nEnter the accuracy\n";
    cin >> eps;
    // Pivotisation(partial) to make the equations
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
                for (j = 0; j <= n; j++) {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
    cout << "Iteration" << setw(10);
    for (i = 0; i < n; i++) cout << "x" << i << setw(18);
    cout << "\n------------------------------------------------------------";
    do {
        cout << "\n" << count + 1 << "." << setw(16);
        for (i = 0; i < n; i++) {
            y = x[i];
            x[i] = a[i][n];
            for (j = 0; j < n; j++) {
                if (j != i) x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i] / a[i][i];
            if (abs(x[i] - y) <= eps) flag++;
            cout << x[i] << setw(18);
        }
        cout << "\n";
        count++;
    } while (flag < n);
    cout << "\n The solution is as follows:\n";
    for (i = 0; i < n; i++) {
        cout << "x" << i << " = " << round(x[i]) << endl;
    }
    return 0;
}
