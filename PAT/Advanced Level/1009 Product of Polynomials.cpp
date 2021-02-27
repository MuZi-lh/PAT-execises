//
// Created by 木子又欠 on 2021/1/27.
//

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

struct Polynomial{
    int exp[2005];
    float coe[2005];
};

int main(){
    int M, N, count, min;
    Polynomial A, B, pro;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> A.exp[i] >> A.coe[i];
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B.exp[i] >> B.coe[i];
    }
    for (int i = 0; i < 2005; i++) {
        pro.exp[i] = i;
        pro.coe[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            pro.coe[A.exp[i]+B.exp[j]] += A.coe[i] * B.coe[j];
        }
    }
    cout << fixed << setprecision(1);
    count = 0;
    for (int i = 2004; i >= 0; i--) {
        if (pro.coe[i] != 0) {
            count++;
            min = i;
        }
    }
    cout << count << ' ';
    for (int i = 2004; i > min; i--) {
        if (pro.coe[i] > 0) cout << pro.exp[i] << ' ' << pro.coe[i] << ' ';
    }
    cout << pro.exp[min] << ' ' << pro.coe[min];
}