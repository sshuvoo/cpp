#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#define ux(x) (sin(M_PI * x))  // f(x)=(sin(3.1416*x))

int main() {
    cout << fixed << setprecision(4);
    int i, j, m, n, option;
    double c, alpha, h, k, x, t, xi, xf, ti, tf, ui, uf;
    cout << "\nNumerical sol. of PDE using finite difference formula\n";
    cout << "\nEnter value of c\n";
    cin >> c;
    cout << "Enter (1st boundary condition) x and u\n";
    cin >> xi >> ui;  // 1st boundary condition u(xi,t)=ui
    cout << "Enter (2nd boundary condition) x and u\n";
    cin >> xf >> uf;  // 2nd boundary condition u(xf,t)=uf
    ti = 0;           // initial simulation time assigned
    cout << "Enter final simulation time" << endl;
    cin >> tf;
    cout << "Enter value of h and k" << endl;
again:
    cin >> h >> k;
    alpha = (c * c * k) / (h * h);  // calculated alpha
    // check alpha limitation
    if (alpha <= 0 || alpha > 0.5) {
        cout << "please enter new value of h & k such that 0 <= alpha <=0.5 "
                "where, alpha = (c * c * k) / (h * h)\n";
        goto again;
    }
    // calculated division of x & t
    m = (xf - xi) / h;
    n = (tf - ti) / k;
    // u defined as [(n+1) by (m+1)] dimensional array
    double u[n + 1][m + 1];
    // calculated 1st & last column
    for (i = 0; i <= n; i++) {
        u[i][0] = ui;  // 1st column
        u[i][m] = uf;  // last column
    }
    // calculated 1st row
    for (j = 1; j <= m - 1; j++) {
        x = xi + j * h;  // transforming j into x
        u[0][j] = ux(x);
    }
    // row wise calculated 2nd to last row
    for (i = 0; i <= n - 1; i++) {
        for (j = 1; j <= m - 1; j++) {
            u[i + 1][j] =
                alpha * (u[i][j - 1] + u[i][j + 1]) + (1 - 2 * alpha) * u[i][j];
        }
    }
    // printing value of u(x,t)
    while (true) {
        cout << "\nChoose option how you want result:" << endl;
        cout << "1. x, t both vary" << endl;
        cout << "2. x vary, t constant" << endl;
        cout << "3. x constant, t vary" << endl;
        cout << "4. x, t both constant" << endl;
        cin >> option;
        if (option == 1) {
            for (i = 0; i <= n; i++) {
                t = ti + i * k;  // transforming i into t
                for (j = 0; j <= m; j++) {
                    x = xi + j * h;  // transforming j into x
                    cout << "u(" << x << "," << t << ")= " << u[i][j] << endl;
                }
            }
        } else if (option == 2) {
            cout << "Enter value of t where you want to find the value of u:"
                 << endl;
            cin >> t;
            i = (t - ti) / k;  // transforming t into i
            for (j = 0; j <= m; j++) {
                x = xi + j * h;  // transforming j into x
                cout << "u(" << x << "," << t << ")= " << u[i][j] << endl;
            }
        } else if (option == 3) {
            cout << "Enter value of x where you want to find the value of u:"
                 << endl;
            cin >> x;
            j = (x - xi) / h;  // transforming x into j
            for (i = 0; i <= n; i++) {
                t = ti + i * k;  // transforming i into t
                cout << "u(" << x << "," << t << ")= " << u[i][j] << endl;
            }
        } else if (option == 4) {
            cout << "Enter value of x where you want to find the value of u:"
                 << endl;
            cin >> x;
            cout << "Enter value of t where you want to find the value of u:"
                 << endl;
            cin >> t;
            i = (t - ti) / k;  // transforming t into i
            j = (x - xi) / h;  // transforming x into j
            cout << "u(" << x << "," << t << ")= " << u[i][j] << endl;
        }
    }
    return 0;
}
