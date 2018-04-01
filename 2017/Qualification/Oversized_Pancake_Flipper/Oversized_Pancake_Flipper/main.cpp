//
//  main.cpp
//  Quarification
//
//  Created by Mai Hưng on 3/25/18.
//  Copyright © 2018 hungmai. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int solveEachLine1(string lineString, int flipCount);

int main(int argc, const char * argv[]) {
    ifstream file("test_input.txt");
    string temp;
    string s;
    int k = 0;
    int i = 0;
    while (getline(file, temp, ' ')) {
        if (i == 0) {
            s = temp;
        } else {
            k = atoi(temp.c_str());
        }
        i++;
    }
    
    int solveCount = solveEachLine1(s, k);
    string solveString = to_string(solveCount);
    cout << s << " " << k << "\n";
    cout << (solveCount != -1 ? solveString : "IMPOSIBLE") << "\n";
    
    return 0;
}

int solveEachLine1(string lineString, int flipCount) {
    int result = 0;
    for (int i = flipCount; i > 0; i--) {
        string iBlank(i, '-');
        string iBlankHappy(flipCount-i, '+');
        string iCorrectBlank = iBlank + iBlankHappy;
        
        string iHappy(i, '+');
        string iHappyBlank(flipCount-i, '-');
        string iCorrectHappy = iHappy + iHappyBlank;
        size_t foundBlank = string::npos;
        do {
            foundBlank = lineString.find(iCorrectBlank);
            if (foundBlank != string::npos) {
                ++result;
                lineString.replace(foundBlank, iCorrectBlank.length(), iCorrectHappy);
            }
        } while (foundBlank != string::npos);
    }
    string lastBlank(flipCount, '-');
    size_t foundLastBlank = lineString.find(lastBlank);
    if (foundLastBlank != string::npos) {
        return result + 1;
    } else {
        size_t foundExistedBlank = lineString.find("-");
        if (foundExistedBlank != string::npos) {
            return -1;
        } else {
            return result;
        }
    }
}

//int solveEachLine2(string lineString, int flipCount) {
//    int result = 0;
//    size_t foundBlank = 0;
//    do {
//        foundBlank = lineString.find("-");
//        string flipString = lineString.substr(foundBlank, flipCount);
//    }while (foundBlank != string::npos || lineString.length() - foundBlank > flipCount - 1);
//}


