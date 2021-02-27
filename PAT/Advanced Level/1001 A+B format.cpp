//
// Created by 木子又欠 on 2020/11/24.
//

#include <stack>
#include <string>
#include <iostream>
using namespace std;

string toS(int x){
    string s;
    if (x>100){
        s = to_string(x);
    }else if (x>10){
        s = "0" + to_string(x);
    }else {
        s= "00" + to_string(x);
    }
    return s;
}

int main(){
    int a, b, num, minus = 0;
    cin >> a >> b;
    stack<int> st;
    num = a + b;
    if (num < 0){
        minus = 1;
        num = -num;
    }
    while (num>0 || st.empty()){
        st.push(num%1000);
        num/=1000;
    }

    if (minus) {
        cout << '-' << st.top();
        st.pop();
    }else{
        cout << st.top();
        st.pop();
    }

    while (!st.empty()){
        cout << ',' << toS(st.top());
        st.pop();
    }
    cout << endl;
}

