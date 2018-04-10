#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int solveEachLine(int n, int m[]);
int solveEachLine2(int n, long m[]);
int main(int argc, const char * argv[]) {
    int t, n;
    
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n;  // read n and then m.
        long m[n];
        for (int j = 0; j < n; ++j) {
            long a;
            cin >> a;
            m[j] = a;
        }
        int result = solveEachLine2(n, m);
        cout << "Case #" << i << ": " << ((result != -1) ? to_string(result) : "OK") << '\n';
    }
}

int solveEachLine2(int n, long m[]) {
    bool done = false;
    bool firstError = false;
    int wrongCountIndex = 0;
    while (!done) {
        done = true;
        firstError = false;
        for (int i = 0; i < n - 2; ++i) {
            if (m[i] > m[i + 2]) {
                done = false;
                long temp = m[i];
                m[i] = m[i + 2];
                m[i + 2] = temp;
            }
            
            if (!firstError) {
                if (m[i + 1] < m[i]) {
                    wrongCountIndex = i;
                    firstError = true;
                } else if (m[i + 1] > m[i + 2]) {
                    wrongCountIndex = i + 1;
                    firstError = true;
                }
            }
            
            if (!firstError) {
                wrongCountIndex = -1;
            }
        }
    }
    return wrongCountIndex;
}

int solveEachLine(int n, int m[]) {
    bool done = false;
    bool firstError = false;
    int wrongCountIndex = 0;
    while (!done) {
        done = true;
        firstError = false;
        for (int i = 0; i < n - 2; ++i) {
            if (m[i] > m[i + 2]) {
                done = false;
                int temp = m[i];
                m[i] = m[i + 2];
                m[i + 2] = temp;
                if ((m[i + 1] < m[i] || m[i + 1] > m[i + 2]) && !firstError) {
                    wrongCountIndex += 1;
                    firstError = true;
                }
            }
            
            if ((m[i + 1] < m[i] || m[i + 1] > m[i + 2]) && !firstError) {
                wrongCountIndex += 1;
                firstError = true;
            }
            
            if (!firstError) {
                wrongCountIndex = -1;
            }
        }
    }
    return wrongCountIndex;
}
