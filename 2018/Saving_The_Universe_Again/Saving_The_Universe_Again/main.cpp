#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int solveEachLine(int shield, string robotProgram);
void countTotalDamage(int a[], string robotProgram);

int main(int argc, const char * argv[]) {
    int t, n;
    string m;
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cin >> n >> m;  // read n and then m.
        int result = solveEachLine(n, m);
        cout << "Case #" << i << ": " << ((result != -1) ? to_string(result) : "IMPOSSIBLE") << '\n';
    }
}

int solveEachLine(int shield, string robotProgram) {
    int result = 0;
    int a[3];
    countTotalDamage(a, robotProgram);
    int robotToTalDamage = a[0];
    int c_count = a[1];
    int s_count = a[2];
    if (robotToTalDamage <= shield) {
        return 0;
    }
    
    if (s_count > shield) {
        return -1;
    }
    
    int currentDamage = robotToTalDamage;
    for (int i = (int)(robotProgram.length() - 1); i >= 0; i--) {
        if (robotProgram[i] == 'C') {
            c_count -= 1;
            if (i + 1 < robotProgram.length() && robotProgram[i + 1] == 'S') {
                for (int j = i; j < robotProgram.length() - 1; j++) {
                    if (robotProgram[j + 1] == 'S') {
                        robotProgram[j] = 'S';
                        robotProgram[j + 1] = 'C';
                        currentDamage -= pow(2, c_count);
                        result += 1;
                        if (currentDamage <= shield) {
                            return result;
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

void countTotalDamage(int a[], string robotProgram) {
    int damage = 0;
    int charge = 1;
    int c_count = 0;
    int s_count = 0;
    for (int i = 0; i < robotProgram.length(); i++) {
        if (robotProgram[i] == 'C') {
            charge *= 2;
            c_count += 1;
        } else if (robotProgram[i] == 'S') {
            damage += charge;
            s_count += 1;
        }
    }
    a[0] = damage;
    a[1] = c_count;
    a[2] = s_count;
}
