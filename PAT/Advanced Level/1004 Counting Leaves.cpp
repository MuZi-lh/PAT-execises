//
// Created by 木子又欠 on 2021/1/26.
//
#include <iostream>
#include <vector>
using namespace std;

int ParseInt(char a, char b){
    return (a-'0')*10 + (b-'0');
}

int leafNumber[100];
std::vector<int> v[100];
bool isLeaf[100];
int deepth;

void traverse(int curNode, int curLevel){
    if (isLeaf[curNode]) {
        leafNumber[curLevel]++;
        if (curLevel> deepth) deepth = curLevel;
        return;
    }

    for (auto it = v[curNode].begin(); it != v[curNode].end(); it++) {
        traverse(*it, curLevel+1);
    }
}

int main(){
    int N, M, tmpId, K, tmpChild;
    char a, b;
    cin >> N >> M;
    if (N==0) return 0;

    for (bool & i : isLeaf) {
        i = true;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> K;
        tmpId = ParseInt(a, b);
        isLeaf[tmpId] = false;
        for (int j = 0; j < K; j++) {
            cin >> a >> b;
            tmpChild = ParseInt(a, b);
            v[tmpId].push_back(tmpChild);
        }
    }

    traverse(1, 1);

    for (int i = 1; i < deepth; i++) {
        cout << leafNumber[i] << ' ';
    }
    cout << leafNumber[deepth];
    return 0;
}