//
// Created by Apple on 2022/2/27.
//

#include <bits/stdc++.h>

using namespace std;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };

struct divide {
    int operator()(int denominato, int divisior) {
        return denominato / divisior;
    }
};



int main() {
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j)
                                { return i * j; };
    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;

    map<string, function<int(int, int)>> binops = {
            {"+", add},
            {"-", minus<int>()},
            { "/", divide()},
            {"*", [](int i, int j) { return i *j; }},
            {"%", mod}
    };

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl; // calls the lambda function object
    cout << binops["%"](10, 5) << endl;

    return 0;

}