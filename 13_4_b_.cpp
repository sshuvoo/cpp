#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define f(x) (log(x))  // y = ln(x)

int main() {
    cout << fixed << setprecision(6);
    int n;
    double a, b, h, sum = 0.0, integral;
    cout << "\nEnter the lower limit of the integration\n";
    cin >> a;
    cout << "\nEnter the upper limit of the integration\n";
    cin >> b;
again:
    cout << "\nEnter the number of division (even)\n";
    cin >> n;
    if (n % 2 == 0) {
        double x[n + 1], y[n + 1];
        h = (b - a) / n;
        for (int i = 0; i <= n; i++) {
            x[i] = a + i * h;
            y[i] = f(x[i]);
        }
        for (int i = 1; i <= n - 1; i = i + 2) {
            sum += 4 * y[i];
        }
        for (int i = 2; i <= n - 2; i = i + 2) {
            sum += 2 * y[i];
        }
        integral = (h / 3) * (y[0] + y[n] + sum);
        cout << "\nThe value of the integral is = " << integral;
    } else {
        cout << "\nYour number of division is odd, try again\n";
        goto again;
    }
    return 0;
}