//
//  main.cpp
//  Tidy_Numbers
//
//  Created by Mai Hưng on 4/1/18.
//  Copyright © 2018 hungmai. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);
string solveEachLine(string numberString);

int main(int argc, const char * argv[]) {
    ifstream input("test_input.txt");
    ofstream output("test_ouput.txt");
    int n;
    string temp;
    getline(input, temp);
    n = atoi(temp.c_str());
    for (int i = 0; i < n; i++) {
        getline(input, temp);
        string correctNumber = solveEachLine(temp);
        output << "Case #" << i + 1 << ": " << correctNumber << '\n';
    }
}

string solveEachLine(string numberString) {
    string result = numberString;
    int wrongIndex = 1;
    int decreaseIndex = 0;
    for (; wrongIndex < numberString.size(); wrongIndex++) {
        if (numberString[wrongIndex] < numberString[wrongIndex - 1]) {
            for (int i = wrongIndex - 1; i > 0; i--) {
                if (numberString[i] - 1 >= numberString[i - 1]) {
                    decreaseIndex = i;
                    break;
                }
            }
            break;
        }
    }
    
    if (wrongIndex == numberString.size()) {
        return numberString;
    }
    
    int decreaseNumber = numberString[decreaseIndex] - '0';
    if (decreaseNumber - 1 == 0) {
        result = result.substr(1, numberString.length() - 1);
        decreaseIndex -= 1;
    } else {
        decreaseNumber -= 1;
        result = result.replace(decreaseIndex, 1, 1, decreaseNumber + '0');
    }
    
    long prefixReplaceLength = numberString.length() - (decreaseIndex + 1);
    result = result.replace((decreaseIndex + 1), prefixReplaceLength, prefixReplaceLength, '9');
    
    return result;
}
