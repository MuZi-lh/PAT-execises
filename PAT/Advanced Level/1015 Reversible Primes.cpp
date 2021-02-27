//
// Created by 木子又欠 on 2021/2/23.
//

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int t){
    if (t<2) return false;
    for (int i = 2; i * i <= t; i++) {
        if (t % i == 0) return false;
    }
    return true;
}
// vector big-endian: 下标和权值成正相关
int vector2dec(vector<int> v, int D){
    int result = 0;
    for (int i = 0; i <v.size(); i++) {
        result = result * D + v[i];
    }
    return result;
}

vector<int> dec2vector(int N, int D){
    vector<int> v;
    int t = N;
    while (t > 0){
        v.push_back(t % D);
        t /= D;
    }
    return v;
}

int main(){
    int N = 1, D, tmp;
    cin >> N;
    while(N>=0) {
        if (N>=0) cin >> D;
        if (isPrime(N) && isPrime(vector2dec(dec2vector(N, D), D))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> N;
    }
}