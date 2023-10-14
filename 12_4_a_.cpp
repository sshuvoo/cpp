#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define f(x) (x * x)  // y = x^2

int main() {
    cout << fixed << setprecision(6);
    int n;
    double a, b, h, sum = 0.0, integral;
    cout << "\nEnter the lower limit of the integration\n";
    cin >> a;
    cout << "\nEnter the upper limit of the integration\n";
    cin >> b;
    cout << "\nEnter the number of division\n";
    cin >> n;
    double x[n + 1], y[n + 1];
    h = (b - a) / n;
    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    for (int i = 1; i <= n - 1; i++) {
        sum += 2 * y[i];
    }
    integral = (h / 2) * (y[0] + sum + y[n]);
    cout << "\nThe value of the integral is = " << integral;
    return 0;
}