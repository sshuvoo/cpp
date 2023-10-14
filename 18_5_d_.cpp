#include <bits/stdc++.h>
using namespace std;

double f1(double x, double y, double z) { return x + z; }

double f2(double x, double y, double z) { return x - y * y; }

void rungeKutta(double x0, double y[], double z[], double h, double x) {
    int n = (int)((x - x0) / h);
    double k1, k2, k3, k4, l1, l2, l3, l4;

    for (int i = 1; i <= n; i++) {
        k1 = h * f1(x0, y[i - 1], z[i - 1]);
        l1 = h * f2(x0, y[i - 1], z[i - 1]);

        k2 = h * f1(x0 + 0.5 * h, y[i - 1] + 0.5 * k1, z[i - 1] + 0.5 * l1);
        l2 = h * f2(x0 + 0.5 * h, y[i - 1] + 0.5 * k1, z[i - 1] + 0.5 * l1);

        k3 = h * f1(x0 + 0.5 * h, y[i - 1] + 0.5 * k2, z[i - 1] + 0.5 * l2);
        l3 = h * f2(x0 + 0.5 * h, y[i - 1] + 0.5 * k2, z[i - 1] + 0.5 * l2);

        k4 = h * f1(x0 + h, y[i - 1] + k3, z[i - 1] + l3);
        l4 = h * f2(x0 + h, y[i - 1] + k3, z[i - 1] + l3);

        // Update next value of x
        x0 = x0 + h;

        // Update next value of y
        y[i] = y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        z[i] = z[i - 1] + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    }

    // Print the solution
    cout << "The numerical solution of the system of first-order differential "
            "equations is : \n";
    for (int i = 0; i <= n; i++) {
        cout << "y" << i << "(" << x << ") = " << y[i] << endl;
    }
}

int main() {
    cout << fixed << setprecision(7);
    double x0, y0, z0, xf, h;
    cout << "\nEnter the initial value of x0\n";
    cin >> x0;
    cout << "\nEnter the initial value of y0\n";
    cin >> y0;
    cout << "\nEnter the initial value of z0\n";
    cin >> z0;
    cout << "\nFor what value of x , you want to find out the value of y\n";
    cin >> xf;
    cout << "\nEnter the number of subdivisions\n";
    cin >> h;

    int n = (int)((xf - x0) / h);

    // Initialize arrays
    double* y = new double[n];
    double* z = new double[n];

    // Set initial conditions
    y[0] = y0;
    z[0] = z0;
    /* set initial values of y */

    // Call Runge-Kutta method
    rungeKutta(x0, y, z, h, xf);

    // Free memory
    delete[] y;
    delete[] z;

    return 0;
}
