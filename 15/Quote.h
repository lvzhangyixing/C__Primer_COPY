//
// Created by Apple on 2022/3/10.
//

#ifndef C__PRIMER_COPY_QUOTE_H
#define C__PRIMER_COPY_QUOTE_H

#include <bits/stdc++.h>

using namespace std;

class Quote {
    friend istream& operator>>(istream&, Quote&);
    friend ostream& operator<<(ostream&, const Quote&);

public:
    Quote() = default;
    Quote(const string &book, double sales_price):
            bookNo(book), price(sales_price) { }
    virtual ~Quote() = default;
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const
                { return n * price; }

#ifdef REFMEMS
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
#else
    virtual Quote* clone() const {return new Quote(*this);}
#endif

private:
    string bookNo;
protected:
    double price = 0.0;
};



#endif //C__PRIMER_COPY_QUOTE_H
