//
// Created by Apple on 2022/2/26.
//

#ifndef C__PRIMER_COPY_SALES_DATA_H
#define C__PRIMER_COPY_SALES_DATA_H

#include <bits/stdc++.h>

using namespace std;

class Sales_data {
    friend ostream &operator<<
            (ostream &, const Sales_data &);

    friend istream &operator>>(istream &, Sales_data &);

    friend bool operator==(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, const Sales_data &);

    friend istream &read(istream &, Sales_data &);

public:
    Sales_data() = default;

    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(const string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(istream &);

    string isbn() const { return bookNo; }

    Sales_data &operator+=(const Sales_data &);

private:
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() < rhs.isbn(); }

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
            lhs.units_sold == rhs.units_sold &&
            lhs.revenue == rhs.revenue;
}

inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

Sales_data operator+(const Sales_data&, const Sales_data&);
ostream &operator<<(ostream&, const Sales_data&);
istream &operator>>(istream&, Sales_data&);

#endif //C__PRIMER_COPY_SALES_DATA_H
