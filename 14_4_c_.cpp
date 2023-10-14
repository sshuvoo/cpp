#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define f(x) (1 / x)  // y = 1/x

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
        if (i % 3 == 0) {
            sum += 2 * y[i];
        } else {
            sum += 3 * y[i];
        }
    }
    integral = ((3 * h) / 8) * (y[0] + y[n] + sum);
    cout << "\nThe value of the integral is = " << integral;
    return 0;
}