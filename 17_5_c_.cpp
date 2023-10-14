#include <bits/stdc++.h>

using namespace std;

#define f(x, y) (x + y)  // replace this with your own function

int main() {
    cout << fixed << setprecision(7);
    int n;
    double x0, y0, xn, h, k1, k2, k3, k4;
    cout << "\nEnter the initial value of x0\n";
    cin >> x0;
    cout << "\nEnter the initial value of y0\n";
    cin >> y0;
    cout << "\nFor what value of x , you want to find out the value of y\n";
    cin >> xn;
    cout << "\nEnter the number of subdivisions\n";
    cin >> n;
    double x[n], y[n];
    x[0] = x0;
    y[0] = y0;
    h = (xn - x0) / n;
    for (int i = 0; i < n; i++) {
        k1 = h * f(x[i], y[i]);
        k2 = h * f(x[i] + h / 2.0, y[i] + k1 / 2.0);
        k3 = h * f(x[i] + h / 2.0, y[i] + k2 / 2.0);
        k4 = h * f(x[i] + h, y[i] + k3);
        y[i + 1] = y[i] + 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
        x[i + 1] = x[i] + h;
    }
    cout << "\nThe approximate value of y at x = " << xn << " is = " << y[n]
         << endl;
    return 0;
}
