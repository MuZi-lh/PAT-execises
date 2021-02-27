//
// Created by 木子又欠 on 2021/1/29.
//


#include <iostream>
#include <cmath>
using namespace std;

// 2 ^41 < 36 ^ 10 < 2 ^42
typedef long long int Lint;

int getNumber(char a){
    if (a>='0' && a<='9') return a-'0';
    else return a - 'a' + 10;
}

Lint toDecimal(string &s, int radix){
    Lint result = 0;
    for (char a : s) {
        result = result * radix + getNumber(a);
    }
    return result;
}

int getMax(string &s){
    int max = 0, tmp;
    for (char a : s) {
        tmp = getNumber(a);
        if (tmp > max) max = tmp;
    }
    return max;
}

int main(){
    string N1, N2, s;
    int tag, radix, got = 0;
    Lint cur, target;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 1) {
        target = toDecimal(N1, radix);
        s = N2;
    }else {
        target = toDecimal(N2, radix);
        s = N1;
    }

    Lint lo = getMax(s) + 1, mid, hi, transRadix;
    if (s.size() > 1) hi = exp(log(target)/(s.size()-1));
    else hi = target;
    while (lo < hi){
        mid = (lo + hi) / 2;
        cur = toDecimal(s, mid);
        if (cur >= target) hi = mid;
        else lo = mid + 1;
    }
    transRadix = lo;
    if (toDecimal(s, transRadix) == target) got = 1;

    /*for (int i = getMax(s) + 1; i <= 36; i++) {
        cur = toDecimal(s, i);
        if (cur == target) {
            got = 1;
            transRadix = i;
            break;
        }
    }*/

    if (got) cout << transRadix;
    else cout << "Impossible";
    return 0;
}