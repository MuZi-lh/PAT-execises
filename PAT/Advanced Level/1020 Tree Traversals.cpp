//
// Created by 木子又欠 on 2021/2/23.
//

#include <iostream>
#include <queue>
using namespace std;

struct BinNode{
    int value;
    BinNode* left=NULL;
    BinNode* right=NULL;
};
int n;
int in[30], post[30];
BinNode* tree;
BinNode* node[30];
queue<BinNode*> q;

int getPos(int *a, int x){
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
}

BinNode* buildTree(int inL, int inR, int postL, int postR){
    if (inL > inR) return NULL;
    BinNode* cur = node[postR];
    if (inL == inR) return cur;
    int pos = getPos(in, post[postR]);
    cur->left = buildTree(inL, pos - 1, postL, postL + pos - inL - 1);
    cur->right = buildTree(pos + 1, inR, postR - inR + pos, postR - 1);
    return cur;
}

void printLevel(BinNode* cur){
    if (cur == NULL) return;
    cout << ' ' << cur->value;
    q.push(cur->left);
    q.push(cur->right);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        node[i] = new BinNode;
        cin >> post[i];
        node[i]->value = post[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    tree = buildTree(0, n - 1, 0, n - 1);

    cout << tree->value;
    q.push(tree->left);
    q.push(tree->right);
    while(q.size()){
        printLevel(q.front());
        q.pop();
    }
    return 0;
}

