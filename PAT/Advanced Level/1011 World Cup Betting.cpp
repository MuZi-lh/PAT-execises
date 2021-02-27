//
// Created by 木子又欠 on 2021/1/29.
//

#include <iostream>
#include <iomanip>
using namespace std;

float getMax(float a,float b, float c, char &t){
    float max = 0;
    if (a>b) {
        max = a;
        t = 'W';
    }else{
        max = b;
        t = 'T';
    }
    if (max < c){
        max = c;
        t = 'L';
    }
    return max;
}

int main(){
    float W, T, L, tmp, pro = 0.65;
    char option;
    for (int i = 0; i < 3; i++) {
        cin >> W >> T >> L;
        tmp = getMax(W, T, L, option);
        pro *= tmp;
        cout << option << ' ';
    }
    pro = (pro - 1) * 2;
    cout << fixed << setprecision(2) << pro;
}
