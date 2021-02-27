//
// Created by 木子又欠 on 2021/2/5.
//

#include <iostream>
#include <map>
using namespace std;

template <class E>
int getRank(E a[], int n, E t){
    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > t) rank++;
    }
    return rank;
}

int main(){
    int C[2000], M[2000], E[2000], n, m, id, tmp1, tmp2, tmp3, tmp, rank;
    double A[2000], aver;
    char best;
    map<int,int>::iterator it;
    cin >> n >> m;
    map<int,int> map;
    for (int i = 0; i < n; i++) {
        cin >> id >> tmp1 >> tmp2 >> tmp3;
        aver = (tmp1 + tmp2 + tmp3) / 3.0;
        map.insert(make_pair(id,i));
        C[i] = tmp1;
        M[i] = tmp2;
        E[i] = tmp3;
        A[i] = aver;
    }

    for (int i = 0; i < m; i++) {
        cin >> id;
        it = map.find(id);
        if (it == map.end()) {
            cout << "N/A" << endl;
        }else{
            best = 'A';
            rank = getRank(A, n, A[it->second]);

            tmp = getRank(C, n, C[it->second]);
            if (tmp < rank) {
                best = 'C';
                rank = tmp;
            }

            tmp = getRank(M, n, M[it->second]);
            if (tmp < rank) {
                best = 'M';
                rank = tmp;
            }

            tmp = getRank(E, n, E[it->second]);
            if (tmp < rank) {
                best = 'E';
                rank = tmp;
            }

            cout << rank << ' ' << best << endl;
        }
    }
    return 0;
}