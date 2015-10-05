#include "Term_list.h"

Term_list::Term_list():list<Term>(){
}

Term_list::Term_list(Term_list& other_polynomial){
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.begin(); c_itr != other_polynomial.end(); ++c_itr){
		this->push_back(*c_itr);
	}
}

void Term_list::selection_sort(list<Term>::iterator itr1){
	if(itr1 +1 == this->end()){
		return;
	}
	Term max_Term = *itr1;
	list<Term>::iterator max_itr_pos = itr1;
	for(list<Term>::iterator itr2 = itr1 +1; itr2 != this->end(); ++itr2){
		if(*itr2 > max_Term)
			max_itr_pos = itr2;
	}
	swap(*itr1, *max_itr_pos);
	++itr1;
	selection_sort(itr1);
}

void Term_list::collect_like_terms(list<Term>::iterator itr1){
	list<Term>::iterator itr2 = itr1 +1;
	if(itr2 == this->end())
		return;
	while(*itr1 == *itr2){
		itr1->coefficient += itr2->coefficient;
		itr2 = this->erase(itr2);
	}
	itr1 = itr2;
	collect_like_terms(itr1);
}

istream& Term_list::operator >>(istream& INpolyStream, Term_list& polynomial){
	Term Term_i;
	while(INpolyStream >> Term_i){
		polynomial.push_back(Term_i);
	}
	list<Term>::iterator itr = polynomial.begin();
	polynomial.selection_sort(itr);
	itr = polynomial.begin();
	polynomial.collect_like_terms(itr);
	return INpolyStream;
}

ostream& Term_list::operator <<(ostream& OUTpolyStream, Term_list& polynomial){
	if(polynomial.empty())
		throw std::invalid_argument("The Term_list object is empty.");

	list<Term>::const_iterator c_itr;
	for(c_itr = polynomial.begin(); c_itr != polynomial.end(); ++c_itr){
		OUTpolyStream << *c_itr;
	}
	return OUTpolyStream;
}

Term_list& Term_list::operator +(const Term_list& other_polynomial) const{
	Term_list result_polynomial(*this);
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.begin(); c_itr != other_polynomial.end(); ++c_itr){
		result_polynomial.push_back(*c_itr);
	}
	list<Term>::iterator itr;
	itr = result_polynomial.begin();
	result_polynomial.selection_sort(itr);
	itr = result_polynomial.begin();
	result_polynomial.collect_like_terms(itr);
	return result_polynomial;
} 
