// Lagranges interpolation
#include <bits/stdc++.h>
using namespace std;
int main() {
    float numerator, dinominator, x, y = 0;
    int n;
    cout << "Enter the terms what you want to calculate:" << endl;
    cin >> n;
    float X[n], Y[n];
    cout << "Enter the different values of x " << endl;
    for (int i = 1; i <= n; i++) cin >> X[i];
    cout << "Enter the corresponding values of " << endl;
    for (int i = 1; i <= n; i++) cin >> Y[i];
    cout << "\nEnter the value of x at which the value of y to be calculated\n";
    cin >> x;
    cout << fixed;
    for (int i = 1; i <= n; i++) {
        numerator = dinominator = 1;
        for (int j = 1; j <= n; j++)
            if (i != j) {
                numerator *= x - X[j];
                dinominator *= X[i] - X[j];
            }
        y = y + (numerator / dinominator) * Y[i];
    }
    cout << "\nThe value of y at x =" << x << "\t is = " << y;
    return 0;
}
