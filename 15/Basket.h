//
// Created by Apple on 2022/3/12.
//

#ifndef C__PRIMER_COPY_BASKET_H
#define C__PRIMER_COPY_BASKET_H

#include <bits/stdc++.h>
#include "Quote.h"

using namespace std;

class Basket {
public:
    void add_item(const shared_ptr<Quote> &sale)
        { items.insert(sale); }
    void add_item(const Quote& sale)
        { items.insert(shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale)
        { items.insert(
                shared_ptr<Quote>(std::move(sale).clone())); }
    double total_receipt(ostream&) const;
    void display (ostream&) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs)
    { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*>
            items{compare};
};



#endif //C__PRIMER_COPY_BASKET_H
