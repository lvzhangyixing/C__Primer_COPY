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

    HasPtr& operator=(const HasPtr &);

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

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;
    return ret;
}


int main() {

    HasPtr h("hi mom!");
    f(h);

    return 0;

}