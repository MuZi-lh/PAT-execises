//
// Created by 木子又欠 on 2021/2/26.
//

#include <iostream>
#include <string>
#include <queue>


using namespace std;

struct Time{
    int hour;
    int minute;
    int second;
    bool operator<(const Time &o) const{
        return (hour < o.hour) || (hour == o.hour && minute < o.minute)
               || (hour == o.hour && minute == o.minute && second < o.second);
    }

};
struct Customer{
    Time coming;
    int processing;
    bool operator<(const Customer &o) const{
        return !(coming < o.coming);
    }
};
struct Window{
    Time now;
    bool operator<(const Window &o) const{
        return !(now < o.now);
    }
};

int n, k, served_num = 0;
double total = 0;
priority_queue<Customer> customers;
priority_queue<Window> windows;

int main() {
    string t;
    Customer tmp;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t >> tmp.processing;
        tmp.coming.hour = std::stoi(t.substr(0, 2));
        tmp.coming.minute = std::stoi(t.substr(3, 2));
        tmp.coming.second = std::stoi(t.substr(6, 2));
        customers.push(tmp);
    }
    Window w ={{8,0,0}};
    for (int i = 0; i < k; i++) {
        windows.push(w);
    }
    Time close = {17, 0, 0};
    while (customers.size() && customers.top().coming < close) {
        tmp = customers.top();
        customers.pop();
        w = windows.top();
        windows.pop();
        served_num++;
        if (!(tmp.coming < w.now)) {
            w.now = tmp.coming;
            w.now.minute +=tmp.processing;
            w.now.hour+=w.now.minute / 60;
            w.now.minute %=60;
        }else{
            // 注：这里如果不用60.0  会导致结果出错
            total += 60 * (w.now.hour - tmp.coming.hour) + w.now.minute - tmp.coming.minute +
                     (w.now.second - tmp.coming.second) / 60.0;
            w.now.minute +=tmp.processing;
            w.now.hour+=w.now.minute / 60;
            w.now.minute %= 60;
        }
        windows.push(w);
    }
    double average = total / (double) served_num;
    printf("%.1f", average);
    return 0;
}