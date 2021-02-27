//
// Created by 木子又欠 on 2021/2/23.
//

#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;
// 不需要通过后序中序构造二叉树
// 直接递归得到前序
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    level[index] = post[root];
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    // root的左子树
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    // root的右子树
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    return 0;
}