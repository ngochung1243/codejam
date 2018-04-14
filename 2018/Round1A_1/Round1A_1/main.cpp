
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool solveEachLine(string *a, int r, int c, int h, int v, int tt);

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    int t, r, c, h, v;
    input >> t;
    for (int i = 1; i <= t; ++i) {
        int tt = 0;
        input >> r >> c >> h >> v;
        string *a = new string[r];

        for (int j = 0; j < r; j ++) {
            string temp;
            input >> temp;
            a[j] = temp;
            for (int f = 0; f < temp.length(); f++) {
                if (temp[f] == '@') {
                    tt += 1;
                }
            }
        }
        bool b = solveEachLine(a, r, c, h, v, tt);
        cout << "Case #" << i << ": " << (b ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }
}

bool dequi(string *a, int fromRIndex, int toRIndex, int cIndex, int c, int v, int ttperP) {
    if (cIndex == c && v == - 1) {
        return true;
    }
    
    int j = cIndex;
    int cPerP = 0;
    while (j < c) {
        int i = fromRIndex;
        while (i <= toRIndex) {
            if (a[i][j] == '@') {
                cPerP += 1;
                if (cPerP == ttperP) {
                    return dequi(a, fromRIndex, toRIndex, j+1, c, v - 1, ttperP);
                }
            }
            i += 1;
        }
        j +=1;
    }
    return false;
}

bool solveEachLine(string *a, int r, int c, int h, int v, int tt) {
    if (tt % ((h+1) * (v+1)) != 0) {
        return false;
    }
        
    if (tt == 0) {
        return true;
    }
    
    int ttperP = tt / ((h+1) * (v+1));
    int fromRIndex = 0;
    int toRIndex = 0;
    int countdownH = h;
    while (toRIndex < r) {
        if (dequi(a, fromRIndex, toRIndex, 0, c, v, ttperP)) {
            fromRIndex = toRIndex + 1;
            toRIndex = 0;
            countdownH -= 1;
            if (countdownH == -1) {
                return true;
            }
        } else {
            toRIndex += 1;
        }
        
    }
    return false;
}
