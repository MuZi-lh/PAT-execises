//
// Created by 木子又欠 on 2021/2/22.
//

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Person {				//客户
    int finish, cost;		//完成时间、服务时间
    bool overflow = false;	//是否超时（开始时间大于17：00）
};
struct Window{		//窗口
    int id, time;
    queue<int> link;
    bool operator<(const Window& o) const {
        return time != o.time ? time > o.time : id > o.id;
    }
};
// 每个窗口都是一个独立的队列
// 先初始化N*M个人到队列中， 再进行出一进一
// 每个窗口的时间都独立运算！！！！
int main() {
    int n, m, k, q, now = 1, flag = 1;
    cin >> n >> m >> k >> q;
    vector<Person> people(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> people[i].cost;
    vector<Window> windows(n);
    while (now <= k) {				//初始化黄线内的窗口队列
        for (int i = 0; i < n; i++)
            if (windows[i].link.size() < m && ( now <= k))
                windows[i].link.push(now++);
    }
    priority_queue<Window> qe;
    for (int i = 0; i < n; i++)
        if (!windows[i].link.empty())
            qe.push({i,people[windows[i].link.front()].cost ,windows[i].link});
    while (!qe.empty()) {
        Window first = qe.top();		//最先处理完的窗口
        people[first.link.front()].finish=first.time;
        first.link.pop();
        if (now <= k)
            first.link.push(now++);
        if (!first.link.empty()) {
            // 每个窗口的时间都是独立计算的 （不相关）
            people[first.link.front()].overflow = (first.time  >= 540);	//记录是否超时
            first.time += people[first.link.front()].cost;
            qe.push(first);
        }
        qe.pop();
    }
    for (int i = 0; i < q; i++) {
        cin >> now;
        if (!people[now].overflow)
            printf("%02d:%02d\n", 8 + people[now].finish / 60, people[now].finish % 60);
        else
            printf("Sorry\n");
    }
    return 0;
}