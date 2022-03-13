//
// Created by Apple on 2022/3/13.
//

#include <bits/stdc++.h>

using namespace std;

struct Base {
    Base(): mem(0) { }
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i): mem(i) { }
    int get_mem() { return mem; }
    int get_base_mem() { return Base::mem; }
protected:
    int mem;
};

int main() {
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_base_mem() << endl;
    return 0;

}