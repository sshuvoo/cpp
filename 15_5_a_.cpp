// Euler method
#include <bits/stdc++.h>
using namespace std;

#define f(x, y) (y * y + 1)  // f(x,y) = (x - y) / 2

int main() {
    int n;
    double x0, y0, h, xn;
    cout << "\nEnter the initial value of x0\n";
    cin >> x0;
    cout << "\nEnter the initial value of y0\n";
    cin >> y0;
    cout << "\nEnter the value of h\n";
    cin >> h;
    cout << "\nEnter the x-value to find the corresponding y-value.\n";
    cin >> xn;
    n = round((xn - x0) / h);
    double x[n + 1], y[n + 1];
    x[0] = x0;
    y[0] = y0;
    for (int i = 0; i < n; i++) {
        y[i + 1] = y[i] + h * f(x[i], y[i]);
        x[i + 1] = x[i] + h;
    }
    cout << "y(" << x[n] << ")\t= " << y[n] << endl;
    return 0;
}