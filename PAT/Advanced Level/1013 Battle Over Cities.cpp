//
// Created by 木子又欠 on 2021/2/6.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> link[1005];

void visit(int p, int *v){
    v[p] = 1;
    for (int & adj : link[p]){
        if (!v[adj]) visit(adj, v);
    }
}

int extraPath(int occupied){
    int branch = 0, v[1005] = {0};
    v[occupied] = 1;

    for (int i =1;i<=N;i++)
        if (!v[i]){
            branch++;
            visit(i, v);
        }

    return branch - 1;
}

int main(){
    cin >> N >> M >> K;
    int a, b, occupied;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    for (int i = 0; i < K; i++) {
        cin >> occupied;
        cout << extraPath(occupied) << endl;
    }

    return 0;
}

