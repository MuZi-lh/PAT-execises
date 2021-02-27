//
// Created by 木子又欠 on 2021/1/26.
//
#include <iostream>
#include <string>
using namespace std;


string s[10]={
        "zero","one","two","three","four","five","six","seven","eight","nine"
};

int main(){
    int tmp, sum = 0;
    string N, result;
    cin >> N;
    for (char & a : N){
        tmp = a-'0';
        sum += tmp;
    }

    result = to_string(sum);
    for (int i = 0; i < result.size() - 1; i++) {
        tmp = result[i] - '0';
        cout << s[tmp] << " ";
    }
    tmp = result[result.size() - 1] - '0';
    cout << s[tmp] << endl;
    return 0;
}