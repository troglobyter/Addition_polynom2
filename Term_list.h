#pragma once

#include "Term.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Term_list: public list<Term>{

	public:
		Term_list();
		Term_list(const Term_list& other_polynomial);

		friend istream& operator >>(istream& INpolyStream, Term_list& polynomial);
		friend ostream& operator <<(ostream& OUTpolyStream, const Term_list& polynomial);

		Term_list& operator +(const Term_list& other_polynomial) const;

	private:
		list<Term>::iterator the_itr = this->begin();
		void selection_sort();
		void collect_like_terms();
};
