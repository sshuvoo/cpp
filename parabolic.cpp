// Finite difference scheme to solve a 1D heat equation with two point bc's
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
// Function of initial condition

int main() {
    cout.precision(5);
    cout.setf(ios::fixed);
    int i, j, n = 100, m = 200, mm;
    double t, lam, h, k, pi = 3.14159265;
    h = 1. / n;  // x-grid
    k = 1. / m;  // t-grid
    mm = 10 * m;
    lam = k * k / (h * h);
    cout << "\n h=" << h;
    cout << "\n k=" << k;
    cout << "\n lam=" << lam;
    double x[n + 1], u[n + 1][mm + 2];
    //	cout<<"\n value of x at t=0";
    for (j = 0; j <= mm + 1; j++) {
        for (i = 0; i <= n; i++) {
            u[i][j] = 0;
        }
    }
    // cout<<"\n value of u at t=0";
    for (i = 0; i <= n; i++) {
        x[i] = i * h;
        u[i][0] = sin(pi * x[i]);
        //	cout<<"\n "<<"u("<<x[i]<<",0)="<<u[i][0];
    }
    // Values for the first grid points
    for (i = 1; i <= n; i++) {
        u[i][1] =
            u[i][0] + 0.5 * lam * (u[i + 1][0] - 2 * u[i][0] + u[i - 1][0]);
    }

    // Values for other grid points
    for (j = 1; j <= mm; j++) {
        for (i = 1; i < n; i++) {
            u[i][j + 1] = -u[i][j - 1] + 2 * u[i][j] +
                          lam * (u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]);
        }
    }
    //		for (j=0;j<=mm;j++)
    //	{
    //		for(i=0;i<n;i++)
    //		{
    //				cout<<u[j][i]<<" ";
    //		}
    //		cout<<endl;
    //		}
    // Output=Value of u(x,t) for t=0.0
    cout << "\n "
         << "Value of u(x,t) for t=1.0";
    for (i = 0; i <= n; i = i + 10)
        cout << "\n"
             << "U(" << x[i] << ",1.0)=" << u[i][200];
    // Value of u(x,t) for x=0.5
    //	cout<<"\nU(0.5,1.0)"<<u[50][200];
    //	cout<<"\n value of u(x,t) for x=0.5";
    //	for(j=0;j<=200;j=j+100)
    //	cout<<"\n"<<"U(0.5,"<<u[50][j];

    cout << "\n "
         << "Value of u(x,t) for x=0.50";
    for (j = 0; j <= 2000; j = j + 100) {
        t = j * k;
        //	cout<<"\n"<<"TT="<<TT;
        cout << "\n"
             << "U(0.5," << t << ")=" << u[50][j];
    }

    return 0;
}
