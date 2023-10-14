// Newton-Raphson Method : f(x) = x^3 − 2x − 5 = 0
#include <bits/stdc++.h>
using namespace std;

#define f(x) (pow(x, 3) - 2 * x - 5)  // f(x)
#define df(x) (3 * pow(x, 2) - 2)     // f'(x)

int main() {
    cout << fixed << setprecision(6);
    double x0, x, accuracy;
again:
    cout << "\nEnter the initial approximation\n";  // 2
    cin >> x0;
    cout << "\nEnter the accuracy\n";  // 0.0001
    cin >> accuracy;
    do {
        x = x0;
        if (df(x) != 0) {
            x0 = x - f(x) / df(x);
        } else {
            cout << "\nInitial approximation isn't convergent, try again\n";
            goto again;
        }
    } while (fabs(x - x0) > accuracy);
    cout << "\nThe root is : " << x0 << endl;
    return 0;
}