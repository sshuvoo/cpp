#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(4);
    int i, j, n = 20, m = 50;
    double t = 0.0, lam, h = 0.1, k = 0.05, T, pi = 3.14159265;
    lam = (k * k) / (h * h);
    cout << "\nn = " << n;
    cout << "\nm = " << m;
    cout << "\nlam = " << lam;
    double x[21], u[21][51];
    cout << "\nValue of x at t = 0";
    for (i = 0; i <= n; i++) {
        x[i] = i * h;
        /// cout<<"\n <<x[i];
    }
    cout << "\tValue of u at t = 0";
    for (i = 0; i <= n; i++) {
        u[i][0] = sin(pi * x[i]);
        cout << "\nx value = " << x[i] << "\tu value = " << u[i][0];
    }
    for (i = 0; i <= n; i = i + 5) {
        cout << "\nvalue = " << u[i][0];
    }
    return 0;
}
