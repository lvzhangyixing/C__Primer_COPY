//
// Created by Apple on 2022/3/13.
//

#include <bits/stdc++.h>
#include "Quote.h"

using namespace std;

int main() {
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10);

    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    print_total(cout, derived, 10);

    Quote *baseP = &derived;

    double undiscounted = baseP->Quote::net_price(42);

}