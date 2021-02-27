//
// Created by 木子又欠 on 2021/1/27.
//
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string ID;
    string sign_in_time;
    string sign_out_time;
}record;

int main(){
    int M;
    string ID, sign_in_time, sign_out_time;
    record unlock_person, lock_person;
    cin >> M;
    if (M == 0) return 0;
    cin >> ID >> sign_in_time >> sign_out_time;
    unlock_person = {ID, sign_in_time, sign_out_time};
    lock_person = unlock_person;

    for (int i = 1; i < M; i++) {
        cin >> ID >> sign_in_time >> sign_out_time;
        if (sign_in_time < unlock_person.sign_in_time) {
            unlock_person = {ID, sign_in_time, sign_out_time};
        }
        if (lock_person.sign_out_time < sign_out_time){
            lock_person = {ID, sign_in_time, sign_out_time};
        }
    }
    cout << unlock_person.ID << ' ' << lock_person.ID;
    return 0;
}