//
// Created by 木子又欠 on 2021/1/27.
//

#include <iostream>
using namespace std;

int main(){
    int N, cur = 0, tmp, cost = 0;
    cin >> N;
    while (N--){
        cin >> tmp;
        if (tmp > cur) cost +=(tmp - cur) * 6 + 5;
        else if (tmp == cur) cost += 5;
        else cost += (cur - tmp) * 4 + 5;
        cur = tmp;
    }
    cout << cost;
}