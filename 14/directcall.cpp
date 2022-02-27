//
// Created by Apple on 2022/2/27.
//

#include <bits/stdc++.h>
#include "Sales_data.h"

using namespace std;

int main() {

    Sales_data data1, data2;
    cin >> data1 >> data2;
    cout << data1 + data2 << endl;
    cout << 42 + 5 << endl;

    data1 + data2;
    operator+(data1, data2);
    cout << operator+(data1, data2) << endl;

    data1 += data2;
    data1.operator+=(data2);
    cout << data1 << endl;

    return 0;

}