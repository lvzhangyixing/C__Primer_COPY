//
// Created by Apple on 2022/3/13.
//

#include <bits/stdc++.h>
#include "Query.h"
#include "TextQuery.h"

using namespace std;

int main(int argc, char **argv) {

    TextQuery file = get_file(argc, argv);

    do {
        string sought;
        if (!get_word(sought)) break;
        Query name(sought);
        const auto results = name.eval(file);
        cout << "\nExecuting Query for: " << name << endl;
        print(cout, results) << endl;
    } while (true);

    return 0;

}