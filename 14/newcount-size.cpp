//
// Created by Apple on 2022/2/27.
//

#include <bits/stdc++.h>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool GT(const string &s, string::size_type m)
{
    return s.size() >= m;
}

class SizeComp {
public:
    SizeComp() = delete;
    SizeComp &operator=(const SizeComp&) = delete;
    ~SizeComp() = default;

    SizeComp(size_t n): sz(n) { }

    bool operator()(const string &s) const { return s.size() >= sz; }

private:
    size_t sz;
};

class PrintString {
public:
    PrintString() = delete;
    PrintString(ostream &o) : os(o) { }
    void operator()(const string &s) const { os << s << " "; }

private:
    ostream &os;
};

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const
    { return s1.size() < s2.size(); }
};

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
    auto count = words.end() - wc;
    cout << count << " " << "words" << " " << sz << "characters or longer " << endl;
    for_each(wc, words.end(), PrintString(cout));
    cout << endl;
}



int main() {

    vector<string> words;
    string next_word;
    while (cin >> next_word) {
        words.push_back(next_word);
    }

    biggies(words, 6);

    return 0;

}