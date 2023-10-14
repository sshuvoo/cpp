// Runge Kutta system of equation
#include <bits/stdc++.h>
using namespace std;

double df(double x, double y, double z) { return x + z; }
double dg(double x, double y, double z) { return x - y * y; }

int main() {
    cout << fixed << setprecision(7);
    int n;
    double x0, y0, z0, h, xn, k1, k2, k3, k4, l1, l2, l3, l4;
    cout << "\nEnter the initial value of x0\n";
    cin >> x0;
    cout << "\nEnter the initial value of y0\n";
    cin >> y0;
    cout << "\nEnter the initial value of z0\n";
    cin >> z0;
    cout << "\nFor what value of x , you want to find out the value of y\n";
    cin >> xn;
    cout << "\nEnter the number of subdivisions\n";
    cin >> n;
    h = (xn - x0) / n;
    double x[n + 1], y[n + 1], z[n + 1];
    x[0] = x0;
    y[0] = y0;
    z[0] = z0;
    for (int i = 0; i < n; i++) {
        k1 = h * df(x[i], y[i], z[i]);
        l1 = h * dg(x[i], y[i], z[i]);
        k2 = h * df((x[i] + (h / 2)), (y[i] + (k1 / 2)), (z[i] + (l1 / 2)));
        l2 = h * dg((x[i] + (h / 2)), (y[i] + (k1 / 2)), (z[i] + (l1 / 2)));
        k3 = h * df((x[i] + (h / 2)), (y[i] + (k2 / 2)), (z[i] + (l2 / 2)));
        l3 = h * dg((x[i] + (h / 2)), (y[i] + (k2 / 2)), (z[i] + (l2 / 2)));
        k4 = h * df(x[i] + h, y[i] + k3, z[i] + l3);
        l4 = h * dg(x[i] + h, y[i] + k3, z[i] + l3);
        y[i + 1] = y[i] + (1 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        z[i + 1] = z[i] + (1 / 6.0) * (l1 + 2 * l2 + 2 * l3 + l4);
        x[i + 1] = x[i] + h;
    }
    cout << "\nThe approximate value of y at\n";
    cout << "\tx = " << x[n] << "\ty = " << y[n] << "\tz = " << z[n] << endl;
    return 0;
}
