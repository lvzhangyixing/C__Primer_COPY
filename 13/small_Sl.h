//
// Created by Apple on 2022/2/23.
//

#ifndef C__PRIMER_COPY_SMALL_SL_H
#define C__PRIMER_COPY_SMALL_SL_H

#include <string>
using namespace std;

class Sales_data {
public:
    Sales_data(const string & s = ""): bookNo(s),
                                        units_sold(0), revenue(0.0) { }
    Sales_data(const string &book, unsigned cnt, double price):
            bookNo(book), units_sold(cnt), revenue(cnt * price) { }
    Sales_data(const Sales_data &rhs): bookNo(rhs.bookNo),
                units_sold(rhs.units_sold), revenue(rhs.revenue) { }
    ~Sales_data() { }
    Sales_data& operator=(const Sales_data &);
private:
    string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

Sales_data&
Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

#endif //C__PRIMER_COPY_SMALL_SL_H
