#pragma once

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class Term{
private:
	int coefficient;
	int exponent;
public:
	friend class Term_list;
	Term();
	Term(int t_coeff, int t_exp);
	Term(const Term& a_Term);
	bool negative_term() const; 
	bool operator >(Term& other_Term);
	bool operator ==(Term& other_Term);
	friend istream& operator >>(istream& INtermStream, Term& a_Term);
	friend ostream& operator <<(ostream& OUTtermStream, const Term& a_Term);
};
