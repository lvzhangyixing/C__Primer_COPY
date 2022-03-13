//
// Created by Apple on 2022/3/13.
//

#include <bits/stdc++.h>
#include "Basket.h"

using namespace std;

int main() {
    Basket sale;
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(shared_ptr<Quote>(new Quote("123", 45)));
    sale.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("345", 45, 3, .15)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Bulk_quote("678", 55, 5, .25)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Lim_quote("abc", 35, 2, .10)));
    sale.add_item(shared_ptr<Quote>(new Quote("def", 35)));
    sale.add_item(shared_ptr<Quote>(new Quote("def", 35)));

    sale.total_receipt(cout);

    Basket bsk;
    // arguments are the ISBN, price, minimum quantity, and discount
    bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
    bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
    bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
    bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
    bsk.add_item(shared_ptr<Quote>(new Bulk_quote("0-201-82470-1", 50, 5, .19)));
    bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
    bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
    bsk.add_item(shared_ptr<Quote>(new Lim_quote("0-201-54848-8", 35, 2, .10)));
    bsk.total_receipt(cout);


    return 0;

}