//
// Created by Apple on 2022/2/25.
//

#ifndef C__PRIMER_COPY_STRVEC_H
#define C__PRIMER_COPY_STRVEC_H

#include <bits/stdc++.h>

using namespace std;

class StrVec {
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);

    StrVec(StrVec&&) noexcept;
    StrVec &operator=(StrVec&&) noexcept;

    ~StrVec() noexcept;

    StrVec(initializer_list<string>);

    void push_back(string&);
    void push_back(string&&);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    string *begin() const { return elements; }
    string *end() const { return first_free; }

    StrVec &operator=(initializer_list<string>);

    string& operator[](size_t n)
        { return elements[n]; }

    const string& operator[](size_t n) const
        { return elements[n]; }

    template<class... Args> void emplace_back(Args&&...);
private:
    allocator<string> alloc;
    void chk_n_alloc()
    { if (size() == capacity()) rellocate(); }
    pair<string*, string*> alloc_n_copy
            (const string*, const string*);
    void free();
    void rellocate();
    string *elements;
    string *first_free;
    string *cap;
};

inline
StrVec::~StrVec() noexcept { free(); }

inline
pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

inline
StrVec::StrVec(StrVec &&s) noexcept
    :elements(s.elements), first_free(s.first_free), cap(s.cap){
    s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

inline
StrVec &StrVec::operator=(initializer_list<string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

inline
StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline
void StrVec::rellocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline
StrVec::StrVec(initializer_list<string> il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
void StrVec::push_back(string & s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

inline
void StrVec::push_back(string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template<class... Args>
inline
void StrVec::emplace_back(Args &&... args) {
    chk_n_alloc();
    alloc.template construct(first_free++, std::forward<Args>(args)...);
}




#endif //C__PRIMER_COPY_STRVEC_H
