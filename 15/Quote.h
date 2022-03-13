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

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price,
               size_t qty, double disc):
                    Quote(book, price),
                    quantity(qty), discount(disc) { }
    double net_price(size_t) const = 0;
    pair<size_t, double> discount_policy() const
    { return {quantity, discount}; }
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p,
               size_t qty, double disc) :
               Disc_quote(book, p, qty, disc) { }
    double net_price(size_t) const override;
#ifdef REFMEMS
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
#else
    Bulk_quote* clone() const {return new Bulk_quote(*this);}
#endif
};

class Lim_quote : public Disc_quote {
public:
    Lim_quote(const string& book = "",
              double sales_price = 0.0,
              size_t qty = 0, double disc_rate = 0.0):
                Disc_quote(book, sales_price, qty, disc_rate) { }
    double net_price(size_t) const;
#ifdef REFMEMS
    Lim_quote* clone() const & { return new Lim_quote(*this); }
    Lim_quote* clone() && { return new Lim_quote(std::move(*this)); }
#else
    Lim_quote* clone() const { return new Lim_quote(*this); }
#endif
};

double print_total(ostream&, const Quote&, size_t);



#endif //C__PRIMER_COPY_QUOTE_H
