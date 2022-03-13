//
// Created by Apple on 2022/3/13.
//

#include <bits/stdc++.h>
#include "Quote.h"

using namespace std;

int main() {
    Quote basic("0-201-54848-8", 45);
    Bulk_quote bulk("0-201-82470-1", 45, 3, .15);

    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    Quote base("0-201-82470-1", 50);
    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    cout << derived.net_price(20);
    cout << endl;

    base = derived;
    cout << base.net_price(20);
    cout << endl;

    Quote &item = derived;
    cout << item.net_price(20);

    item.isbn();
    cout << endl;

    return 0;

}