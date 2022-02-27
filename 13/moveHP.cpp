//
// Created by Apple on 2022/2/22.
//

#include <bits/stdc++.h>

using namespace std;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }

    HasPtr(const HasPtr &p):
        ps(new string(*p.ps)), i(p.i) { }

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0; }

    HasPtr& operator=(HasPtr rhs)
            { swap(*this, rhs); return *this; }

    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {

    HasPtr hp("hi mom");
    HasPtr hp2(hp);

    hp = hp2;
    hp = std::move(hp2);

    return 0;

}