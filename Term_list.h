#pragma once

#include "Term.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Term_list: public list<Term>{

	public:
	Term_list();
	Term_list(Term_list& other_polynomial);

	friend istream& operator >>(istream& INpolyStream, Term_list& polynomial);
	friend ostream& operator <<(ostream& OUTpolyStream, const Term_list& polynomial);

	Term_list& operator +(const Term_list& other_polynomial) const;

	private:
	void selection_sort(list<Term>::iterator itr1);
	void collect_like_terms(list<Term>::iterator itr1);
};
