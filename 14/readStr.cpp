//
// Created by Apple on 2022/2/27.
//

#include <bits/stdc++.h>

using namespace std;



class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) { }
    void operator()(const string &s) const { os << s << sep; }

private:
    ostream &os;
    char sep;
};

class ReadLine {
public:
    ReadLine() = delete;
    ReadLine(istream &i) : is(i) { }
    bool operator()(string &s) const { return getline(is, s); }

private:
    istream &is;
};



int main() {

    vector<string> vs;
    ReadLine rl(cin);
    string s;
    while (rl(s))
        vs.push_back(s);

    cout <<"read : " << vs.size() << " elements " << endl;
    PrintString printer;
    printer(s);

    PrintString errors(cerr, '\n');
    errors(s);

    cerr << "for_each printing to cerr" << endl;
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

    return 0;

}