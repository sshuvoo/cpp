// Bisection Method
#include <bits/stdc++.h>
using namespace std;

#define f(x) (pow(x, 3) + 4 * pow(x, 2) - 10)  // x^3+4x^2-10=0

int main() {
    cout << fixed << setprecision(6);
    double a, b, c, accuracy;
again:
    cout << "\nEnter the initial guesses\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "\nEnter the accuracy\n";
    cin >> accuracy;
    if (f(a) * f(b) < 0) {
        do {
            c = (a + b) / 2;
            if (f(c) == 0) {
                break;
            } else if (f(a) * f(c) < 0) {
                b = c;
            } else {
                a = c;
            }
        } while (fabs(a - b) > accuracy);
    } else {
        cout << "\nEnter different guesses\n";
        goto again;
    }
    cout << "\nThe root is : " << c << endl;
    return 0;
}