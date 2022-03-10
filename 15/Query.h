//
// Created by Apple on 2022/3/9.
//

#ifndef C__PRIMER_COPY_QUERY_H
#define C__PRIMER_COPY_QUERY_H

#include <bits/stdc++.h>
#include "TextQuery.h"

using namespace std;

class Query_base {
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const
                            { return q->eval(t); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query): q(query) { }
    shared_ptr<Query_base> q;
};

inline
ostream &
operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const string &s): query_word(s) { }
    QueryResult eval(const TextQuery &t) const
                    { return t.query(query_word); }
    string rep() const { return query_word; }
    string query_word;
};

inline
Query::Query(const string &s):q(new WordQuery(s)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s):
        lhs(l), rhs(r), opSym(s) { }
    string rep() const { return "(" + lhs.rep() + " "
                                                + opSym + " "
                                                + rhs.rep() + ")"; }

    Query lhs, rhs;
    string opSym;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
                        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
            BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    shared_ptr<Query_base>(new NotQuery(operand));
}

ifstream& open_file(ifstream&, const string&);
TextQuery get_file(int, char**);
bool get_word(string&);
bool get_words(string&, string&);
ostream &print(ostream&, const QueryResult&);


#endif //C__PRIMER_COPY_QUERY_H
