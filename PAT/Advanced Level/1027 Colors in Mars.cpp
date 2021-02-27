//
// Created by 木子又欠 on 2021/2/23.
//

#include <iostream>

using namespace std;

int R,G,B;

void print13(int v){
    printf("%c",v < 10? v + '0' : v - 10 + 'A');
}

int main(){
    cin >> R >> G >> B;
    cout<< '#';
    print13(R / 13);
    print13(R % 13);
    print13(G / 13);
    print13(G % 13);
    print13(B / 13);
    print13(B % 13);
    return 0;
}