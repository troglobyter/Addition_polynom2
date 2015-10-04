#include "Term_list.h"

Term_list::Term_list(){

}

Term_list::Term_list(const Term_list& other_polynomial){
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.list_of_terms.begin(); c_itr != other_polynomial.list_of_terms.end(); ++c_itr){
		list_of_terms.push_back(*c_itr);
	}
}

void Term_list::selection_sort(list<Term>::iterator itr1){
	if(itr1 +1 == list_of_terms.end()){
		return;
	}
	Term max_Term = *itr1;
	list<Term>::iterator max_itr_pos = itr1;
	for(list<Term>::iterator itr2 = itr1 +1; itr2 != list_of_terms.end(); ++itr2){
		if(*itr2 > max_Term)
			max_itr_pos = itr2;
	}
	swap(*itr1, *max_itr_pos);
	++itr1;
	selection_sort(itr1);
}

void Term_list::collect_like_terms(list<Term>::iterator itr1){
	list<Term>::iterator itr2 = itr1 +1;
	if(itr2 == list_of_terms.end())
		return;
	while(*itr1 == *itr2){

		itr1->coefficient += itr2->coefficient;
		itr2 = list_of_terms.erase(itr2);
	}
	itr1 = itr2;
	collect_like_terms(itr1);
}

istream& Term_list::operator >>(istream& INpolyStream, Term_list& polynomial){
	Term Term_i;
	while(INpolyStream >> Term_i){
		polynomial.list_of_terms.push_back(Term_i);
	}
	list<Term>::iterator itr = polynomial.list_of_terms.begin();
	polynomial.selection_sort(itr);
	itr = polynomial.list_of_terms.begin();
	polynomial.collect_like_terms(itr);
}

ostream& Term_list::operator <<(ostream& OUTpolyStream, const Term_list& polynomial){
	if(list_of_terms.empty())
		throw std::invalid_argument("There is no polynomial.");

	list<Term>::const_iterator c_itr;
	for(c_itr = polynomial.list_of_terms.begin(); c_itr != polynomial.list_of_terms.end(); ++c_itr){
		OUTpolyStream << *itr;
	}
	return OUTpolyStream;
}

Term_list& operator +(const Term_list& other_polynomial) const{
	Term_list result_polynomial(this);
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.list_of_terms.begin(); c_itr != other_polynomial.list_of_terms.end(); ++c_itr)
		result_polynomial.list_of_terms.push_back(*c_itr);

	list<Term>::iterator itr;
	itr = result_polynomial.list_of_terms.begin();
	result_polynomial.selection_sort(itr);
	itr = result_polynomial.list_of_terms.begin();
	result_polynomial.collect_like_terms(itr);

	return result_polynomial;
}
