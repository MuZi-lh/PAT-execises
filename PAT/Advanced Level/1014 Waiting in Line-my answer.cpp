//
// Created by 木子又欠 on 2021/2/23.
//

#include <iostream>
#include <list>
using namespace std;

int now = 0, N, M, K, Q;
int serve_time[1010], query[1010], finish_time[1010];
int done = 0, inLine = 0, cur = 0;
list<int> window[20], id[20];
// 不断让客户穿过黄线，若已满，则先让至少一个客户完成，
// 之后添加客户到最短的队列中
// list用queue可能效果更好（差不多）
void dequeue(){
    if (now > 540) {
        for (int i = 0; i < N; i++) {
            while (window[i].size()) {
                inLine--;
                done++;
                window[i].pop_front();
                finish_time[id[i].front()] = now + serve_time[id[i].front()];
                id[i].pop_front();
            }
        }
        return;
    }
    int min = 0, waste;
    while (!window[min].size()) min++;
    for (int i = min + 1; i < N; i++) {
        if (window[i].size())
            if (window[i].front() < window[min].front()) min = i;
    }
    waste = window[min].front();
    now += waste;
    for (int i = 0; i < N; i++) {
        if (window[i].size()){
            window[i].front() -= waste;
            if (window[i].front() == 0) {
                inLine--;
                done++;
                window[i].pop_front();
                finish_time[id[i].front()] = now;
                id[i].pop_front();
            }
        }
    }
}

void enqueue(){
    int shortest = 0;
    for (int i = 1; i < N; i++) {
        if (window[i].size() < window[shortest].size()) shortest = i;
    }
    if (window[shortest].size() >= M) {
        dequeue();
        enqueue();
    }else{
        inLine++;
        window[shortest].push_back(serve_time[cur]);
        id[shortest].push_back(cur);
    }
}

void printTime(int custom){
    int t = finish_time[custom];
    if ( t - serve_time[custom] >= 540){
        cout << "Sorry" << endl;
        return;
    }else if (t < 120){
        cout << '0' << 8 + t / 60 << ':';
    }else{
        cout << 8 + t / 60 << ':';
    }
    if (t % 60 >= 10){
        cout << t % 60 << endl;
    }else{
        cout << '0' << t % 60 << endl;
    }
}


int main(){
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> serve_time[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> query[i];
    }
    for (cur = 0;cur < K;cur++){
        enqueue();
    }
    while (inLine) dequeue();

    for (int i = 0; i < Q; i++) {
        printTime(query[i] - 1);
    }
    return 0;
}