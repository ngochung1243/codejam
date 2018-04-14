//
//  main.cpp
//  Round1A_2
//
//  Created by Mai Hưng on 4/14/18.
//  Copyright © 2018 hungmai. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int thoigiancuathungan(int *a) {
    return a[0] * a[1] + a[2];
}

int thoigiancuathunganvoibit(int *a, int b) {
    if (b > a[0]) {
        return a[0] * a[1] + a[2];
    }
    return b * a[1] + a[2];
}


void swap(int *&a, int *&b)
{
    int *t = a;
    a = b;
    b = t;
}

int partition (int **arr, int low, int high)
{
    int pivot = thoigiancuathungan(arr[high]);    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (thoigiancuathungan(arr[j]) <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int **arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int timvitrithunganitnhatdangranhtaithoidiem(int thoidiem, int **cacthungan, int *luuthoidiem, int sothungan) {
    int minThoiDiemIndex = 0;
    for (int i = 1; i < sothungan; i++) {
        if (luuthoidiem[i] <= thoidiem && luuthoidiem[minThoiDiemIndex] > luuthoidiem[i]) {
            minThoiDiemIndex = i;
        }
    }
    return minThoiDiemIndex;
}


int tongthoigian(int r, int b, int c, int **cacthungan) {
    int *luuthoidiem = new int[c];
    int maxthoigian = 0;
    int thoidiem = 0;
    while (b > 0) {
        int vitrithungan = timvitrithunganitnhatdangranhtaithoidiem(thoidiem + 1, cacthungan, luuthoidiem, c);
        if (vitrithungan != -1) {
            int thoigianthungan = thoigiancuathunganvoibit(cacthungan[vitrithungan], b);
            luuthoidiem[vitrithungan] += thoigianthungan;
            thoidiem = luuthoidiem[vitrithungan];
            if (thoidiem > maxthoigian) {
                maxthoigian = thoidiem;
            }
            b -= cacthungan[vitrithungan][0];
        }
    }
    return maxthoigian;
}



void sapxepthungancoloi(int **cacthungan, int sothungan) {
    quickSort(cacthungan, 0, sothungan - 1);
}

void print(int **a, int sothungan) {
    for (int i = 0; i < sothungan; i++) {
        cout << a[i][0] << a[i][1] << a[i][2] << '\n';
    }
    
}

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    int t;
    input >> t;
    for (int i = 0; i < t; i++) {
        int r, b, c;
        input >> r >> b >> c;
        int **cacthungan = new int*[c];
        for (int j = 0; j < c; j++) {
            cacthungan[j] = new int[3];
            input >> cacthungan[j][0] >> cacthungan[j][1] >> cacthungan[j][2];
        }
        
        sapxepthungancoloi(cacthungan, c);
        int result = tongthoigian(r, b, c, cacthungan);
        cout << "Case #" << i << ": " << result << '\n';
    }
    return 0;
}




