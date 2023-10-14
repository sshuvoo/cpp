// Fixed-point iteration method
#include <bits/stdc++.h>
using namespace std;
// f(x) = e^(-x) - x = 0
// Convert in the form x = 𝜙(x); i.e x = e^(-x)
#define f(x) (0.5 * (cos(x) + 3))  // 𝜙(x)
#define df(x) (0.5 * sin(x))       // 𝜙'(x)

int main() {
    cout << fixed << setprecision(6);
    double x0, x, accuracy;
    int i = 1;
again:
    cout << "\nEnter the initial approximation\n";  // 0.5
    cin >> x0;
    cout << "\nEnter the accuracy\n";  // 0.0001
    cin >> accuracy;
    if (fabs(df(x0)) < 1) {
        do {
            x = x0;
            x0 = f(x);
            cout << "Iteration " << i++ << " =\t" << x0 << endl;
        } while (fabs(x - x0) > accuracy);
        cout << "\nThe root is : " << x0 << endl;
    } else {
        cout << "\nInitial approximation isn't convergent, try again\n";
        goto again;
    }
    return 0;
}