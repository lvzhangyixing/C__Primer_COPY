//
// Created by Apple on 2022/2/14.
//

#include <bits/stdc++.h>

using namespace std;

class Foo {
public:
    Foo() = default; //需要默认构造函数，因为Foo有一个拷贝构造函数
    Foo(const Foo&); //拷贝构造函数

};

Foo::Foo(const Foo &) { std::cout << "Foo copy ctor" << std::endl; }


int main() {

    Foo x;
    Foo y(x); //拷贝构造函数,x是左值
    Foo z(std::move(x)); //拷贝构造函数,因为这里没有移动构造函数

    return 0;

}