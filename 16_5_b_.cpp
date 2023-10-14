// Modified Euler
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define f(x, y) (1 + x * y)  // f(x,y) = (x - y) / 2

int main() {
    cout << fixed << setprecision(4);
    int n;
    double x0, y0, h, xn;
    cout << "\nEnter the initial value of x0\n";
    cin >> x0;
    cout << "\nEnter the initial value of y0\n";
    cin >> y0;
    cout << "\nEnter the x-value to find the corresponding y-value.\n";
    cin >> xn;
    cout << "\nEnter the value of h\n";
    cin >> h;
    n = round((xn - x0) / h);
    double x[n + 1], y[n + 1], y1[n + 1];
    x[0] = x0;
    y[0] = y0;
    y1[0] = y0;
    for (int i = 0; i < n; i++) {
        y1[i + 1] = y[i] + h * f(x[i], y[i]);
        x[i + 1] = x[i] + h;
        y[i + 1] = y[i] + (h / 2) * (f(x[i], y[i]) + f(x[i + 1], y1[i + 1]));
    }
    cout << "y(" << x[n] << ") = " << y[n] << endl;
    return 0;
}