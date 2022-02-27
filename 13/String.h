//
// Created by Apple on 2022/2/23.
//

#ifndef C__PRIMER_COPY_STRING_H
#define C__PRIMER_COPY_STRING_H

#include <bits/stdc++.h>

using namespace std;


class String {
    friend String operator+(const String&, const String&);
    friend  String add(const String&, const String&);
    friend ostream &operator<<(ostream&, const String&);
    friend ostream &print(ostream&, const String&);

public:
    String() = default;
    String(const char *cp) :
            sz(strlen(cp)), p(a.allocate(sz))
            { uninitialized_copy(cp, cp + sz, p); }
    String(const String &s):sz(s.sz), p(a.allocate(s.sz))
            { uninitialized_copy(s.p, s.p + sz, p); }
    String(String &&s) noexcept : sz(s.size()), p(s.p)
            { s.p = 0; s.sz = 0; }
    String(size_t n, char c) : sz(n), p(a.allocate(n))
    { uninitialized_fill_n(p, sz, c); }
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    ~String() noexcept { if (p) a.deallocate(p, sz); }
    String &operator=(const char*);
    String &operator=(char);
    String &
    operator=(initializer_list<char>);

    const char *begin()                     { return p; }
    const char *begin() const               { return p; }
    const char *end()                  { return p + sz; }
    const char *end() const            { return p + sz; }

    size_t size() const                    { return sz; }
    void swap(String &s)
                    { auto tmp = p; p = s.p; s.p = tmp;
                      auto cont = sz; sz = s.sz; s.sz = cont; }

private:
    size_t sz = 0;
    char *p = nullptr;
    static allocator<char> a;
};
String make_plural(size_t ctr, const String &, const String &);
inline
void swap(String &s1, String s2)
{
    s1.swap(s2);
}

#endif //C__PRIMER_COPY_STRING_H
