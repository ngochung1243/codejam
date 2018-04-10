#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

#define PI 3.14159265

void solveEachLine(double a, double m[3][3]);
int main(int argc, const char * argv[]) {
    int t;
    double a;
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        double m[3][3];
        cin >> a;
        solveEachLine(a, m);
        cout << "Case #" << i << ": " << "\n";
        for (int i = 0; i < 3; i ++) {
            cout << setprecision(16) << m[i][0] << " " << setprecision(16) << m[i][1] << " " << setprecision(16) << m[i][2] << "\n";
        }
    }
}

void solveEachLine(double a, double m[3][3]) {
    double value = a * sqrt(2)/2;
    double arccos = (acos(value) * 180.0 / PI);
    double corner = arccos - 45;
    double xRatio = cos(corner * PI / 180)/2;
    double yRatio = sin(corner * PI / 180)/2;
    double zRatio = 0/2;
    m[0][0] = xRatio;
    m[0][1] = yRatio == 0 ? 0 : -yRatio;
    m[0][2] = zRatio;
    
    m[1][0] = yRatio;
    m[1][1] = xRatio;
    m[1][2] = zRatio;
    
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 0.5;
}
