// Newton-Raphson Method : System of equations
#include <bits/stdc++.h>
using namespace std;

#define f(x, y) (x * x - y * y - 3)
#define g(x, y) (x * x + y * y - 13)
#define dfx(x, y) (2 * x)   // f'(x,y) w.r.t x
#define dfy(x, y) (-2 * y)  // f'(x,y) w.r.t y
#define dgx(x, y) (2 * x)   // g'(x,y) w.r.t x
#define dgy(x, y) (2 * y)   // g'(x,y) w.r.t y

int main() {
    cout << fixed << setprecision(6);
    double x0, y0, x, y, d, h, k, accuracy;
again:
    cout << "\nEnter the initial approximation x0 and y0\n";
    cin >> x0 >> y0;                   // 1 2
    cout << "\nEnter the accuracy\n";  // 0.0001
    cin >> accuracy;
    do {
        x = x0;
        y = y0;
        d = dfx(x, y) * dgy(x, y) - dgx(x, y) * dfy(x, y);
        if (d != 0) {
            h = (g(x, y) * dfy(x, y) - f(x, y) * dgy(x, y)) / d;
            k = (f(x, y) * dgx(x, y) - g(x, y) * dfx(x, y)) / d;
            x0 = x + h;
            y0 = y + k;
        } else {
            cout << "\nInitial approximation isn't convergent, try again\n";
            goto again;
        }
    } while (fabs(x - x0) > accuracy || fabs(y - y0) > accuracy);
    cout << "\nThe roots are x = " << x0 << "\ty = " << y0 << endl;
    // The roots are x = 2.828427      y = 2.236068
    return 0;
}