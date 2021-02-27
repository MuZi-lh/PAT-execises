//
// Created by 木子又欠 on 2021/2/23.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Time{
    int day;
    int hour;
    int minute;
    bool operator<(const Time&o) const{
        return (day<o.day) || (day == o.day && hour < o.hour)
               || (day == o.day && hour == o.hour && minute<o.minute);
    }
};
struct Call{
    string person;
    Time time;
    bool on;
};

int n, lasting;
float c;
string t, tmp, month;
vector<int> cost(24);

bool comparison(const Call &a,const Call &b){
    return a.person != b.person ? a.person < b.person : a.time < b.time;
}
bool paired(const Call &a,const Call &b){
    return a.person == b.person? a.on && !b.on : false;
}
float singleCost(const Call &start,const Call &end){
    Time s = start.time, e = end.time;
    float sum = 0;
    e.hour += 24 * (e.day - s.day);
    if (e.hour == s.hour) {
        sum += (e.minute - s.minute) * cost[s.hour];
        lasting = e.minute - s.minute;
    } else{
        sum += (60 - s.minute) * cost[s.hour];
        for (int i = s.hour + 1; i < e.hour; i++) {
            sum += 60 * cost[i % 24];
        }
        sum += e.minute * cost[e.hour % 24];
        lasting = 60 * (e.hour - s.hour) - s.minute + e.minute;
    }
    return sum/100;
}
void printBill(const Time &s,const Time &e){
    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
           s.day, s.hour, s.minute, e.day, e.hour, e.minute, lasting, c);
}
int main() {
    for (int i = 0; i < 24; i++) {
        cin >> cost[i];
    }
    map<std::string, float> bill;
    cin >> n;
    vector<Call> records(n);
    for (int i = 0; i < n; i++) {
        cin >> records[i].person >> t >> tmp;
        records[i].time.day = std::stoi(t.substr(3, 2));
        records[i].time.hour = std::stoi(t.substr(6, 2));
        records[i].time.minute = std::stoi(t.substr(9, 2));
        records[i].on = tmp == "on-line";
    }
    month = t.substr(0,2);
    sort(records.begin(),records.end(),comparison);
    for (int i = 0; i < n - 1; i++) {
        if (paired(records[i], records[i+1])){
            c = singleCost(records[i], records[i+1]);
            auto it =bill.find(records[i].person);
            if (it != bill.end()){
                it->second += c;
            }else{
                if (bill.size()){
                    printf("Total amount: $%.2f\n",(--it)->second);
                }
                cout << records[i].person << ' ' << month << endl;
                bill[records[i].person] = c;
            }
            printBill(records[i].time, records[i + 1].time);
            i++;
        }
    }
    auto it = bill.end()--;
    printf("Total amount: $%.2f\n",(--it)->second);

    return 0;
}