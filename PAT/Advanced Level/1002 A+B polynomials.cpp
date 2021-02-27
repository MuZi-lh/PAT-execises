//
// Created by 木子又欠 on 2020/11/24.
//

#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

// a1 + a2 =0 时不输出该数据对
int main(){
    int n, m, ex, total;
    float co;
    map<int, float> pol;
    std::map<int,float>::iterator it;
    std::map<int,float>::reverse_iterator rit;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ex >> co;
        pol.insert(std::make_pair(ex,co));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ex >> co;
        it = pol.find(ex);
        if (it != pol.end()) {
            it->second +=co;
        }else{
            pol.insert(std::make_pair(ex,co));
        }
    }
    total = pol.size();
    for (rit = pol.rbegin(); rit != pol.rend(); rit++) {
        if (rit->second == 0){
            total--;
        }
    }
    cout << total;
    for (rit = pol.rbegin(); rit != pol.rend(); rit++) {
        if (rit->second != 0){
            cout << ' ' << rit->first << ' ' << fixed << setprecision(1) << rit->second;
        }
    }
    cout << endl;
}



