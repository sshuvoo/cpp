// Newton’s Divided difference formula.
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(6);
    int X[10], Y[10];
    int n, i, j = 1;
    double xn, f, f1 = 1, f2 = 0;
    cout << "Enter the no. of terms\n";
    cin >> n;
    cout << "Enter the different values of x\n";
    for (i = 0; i < n; i++) cin >> X[i];
    cout << "Enter the corresponding values of y\n";
    for (i = 0; i < n; i++) cin >> Y[i];
    cout << "Enter the value of 'xn' for f(xn) evaluation\n";
    cin >> xn;
    f = Y[0];
    do {
        for (i = 0; i < n - 1; i++) {
            Y[i] = ((Y[i + 1] - Y[i]) / (X[i + j] - X[i]));
        }
        cout << endl;
        for (i = 0; i < j; i++) f1 *= (xn - X[i]);
        f2 += (Y[0] * f1);
        f1 = 1;
        n--;
        j++;
    } while (n != 1);
    f += f2;
    cout << "f(" << xn << ") = " << f;
    return 0;
}
