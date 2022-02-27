//
// Created by Apple on 2022/2/27.
//

#include <bits/stdc++.h>

using namespace std;
using std::placeholders::_1;

bool size_compare(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}



int main() {

    cout << plus<int>()(3, 4) << endl;

    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10, 20);
    cout << sum << endl;

    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;

    sum = intAdd(10, intNegate(10));

    cout << sum << endl;

    vector<int> vec = {0,1,2,3,4,5,16,17,18,19};

    cout << count_if(vec.begin(), vec.end(),
                     bind(less_equal<int>(), _1, 10));
    cout << endl;

    vector<string> svec;
    string in;
    while (cin >> in)
        svec.push_back(in);

    function<bool(const string&)> fp2 = bind(size_compare, _1, 6);
    cout << count_if(svec.begin(), svec.end(), fp2)
            << endl;
    cout << count_if(svec.begin(), svec.end(),
                     bind(size_compare, _1, 6))
         << endl;

    return 0;

}