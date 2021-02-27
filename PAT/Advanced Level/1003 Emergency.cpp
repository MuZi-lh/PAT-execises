//
// Created by 木子又欠 on 2020/11/24.
//

#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

int count;
int N, M, source, destination, temp1, temp2, templ;
int res[500], sum[500], rou[500], d[500];
// res: rescue number of Point i
// sum: largest rescue number of shortest routines of Point i
// rou: number of shortest routines of Point i
// d  : distance from source to  Point i
bool v[500];
int l[500][500];

void Dijkstra(int cur){
    if (cur == destination) return;
    v[cur] = true;

    for (int i = 0; i < N; i++) {
        if (!v[i]){
            if (d[cur] + l[cur][i] < d[i]){
                d[i] = d[cur] + l[cur][i];
                sum[i] = sum[cur] + res[i];
                rou[i] = rou[cur];
            }else if (d[cur] + l[cur][i] == d[i]){
                rou[i] += rou[cur];
                if (sum[cur] + res[i]> sum[i]) sum[i] = sum[cur] + res[i];
            }
        }
    }

    // find next Point
    int tmp = 0;
    while (v[tmp]) tmp++;
    for (int i = 0; i < N; i++) {
        if (!v[i] && d[i]<d[tmp]) tmp = i;
    }
    Dijkstra(tmp);
}

int main(){
    cin >> N >> M >> source >> destination;

    for (int i = 0; i < N; i++) {
        cin >> res[i];
        v[i] = false;
        d[i] = 0x3FFFFFFF;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            l[i][j] = 0x3FFFFFFF;
        }
    }


    for (int i = 0; i < M; i++) {
        cin >> temp1 >> temp2 >> templ;
        l[temp1][temp2] = templ;
        l[temp2][temp1] = templ;
    }

    sum[source] = res[source];
    rou[source] = 1;
    d[source] = 0;
    Dijkstra(source);

    cout << rou[destination] << ' ' << sum[destination];
}