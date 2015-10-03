#pragma once
#include "Term.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Term_list{
	public:
	Term_list();

	friend istream& operator >>(istream&& INpolyStream, Term_list& polynomial);
	friend ostream& operator <<(ostream& OUTpolyStream, const Term_list& polynomial);

	Term_list& operator +(const Term_list& other_polynomial);

	private:
	list<Term> list_of_terms;

	void selection_sort();
	void collect_like_terms();
};