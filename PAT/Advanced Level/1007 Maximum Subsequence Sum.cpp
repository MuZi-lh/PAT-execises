//
// Created by 木子又欠 on 2021/1/27.
//
#include <iostream>
using namespace std;


int main(){
    int K, a[10000], i, j, max = -1, sum = 0, l;
    cin >> K;
    i = 0;
    j = K - 1;
    for (int cur = 0; cur < K; cur++) {
        cin >> a[cur];
    }

    l = 0;
    for (int cur = 0; cur < K; cur++) {
        sum +=a[cur];
        if (sum < 0 ){
            sum = 0;
            l = cur + 1;
        }else if (sum > max) {
            max = sum;
            i = l;
            j = cur;
        }
    }
    // 存在0的非正序列，
    // 如-1 0 -2 -3 -4  应该输出0 0 0 而不是 0 -1 -4， 同理 max初始值为-1 而不是0
    if (max < 0) max = 0;
    //************

    cout << max << ' ' << a[i] << ' ' << a[j];
    return 0;
}