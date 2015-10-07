#include "Term_list.h"

Term_list::Term_list():list<Term>(){
}

Term_list::Term_list(const Term_list& other_polynomial){
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.cbegin(); c_itr != other_polynomial.cend(); ++c_itr){
		this->push_back(*c_itr);
	}
}

void Term_list::selection_sort(){

	if(the_itr == --(this->end())){
		return;
	}

	Term max_Term = *the_itr;
	list<Term>::iterator max_itr_pos = the_itr;
	for(list<Term>::iterator itr2 = ++the_itr; itr2 != this->end(); ++itr2){
		if(*itr2 > max_Term)
			max_itr_pos = itr2;
	}
	--the_itr;
	Term current_front_term = *the_itr;
	Term current_max_term = *max_itr_pos;
	Term temp_term;
	temp_term = current_front_term;
	current_front_term = current_max_term;
	current_max_term = temp_term;

	++the_itr;
	selection_sort();
}

void Term_list::collect_like_terms(){
	list<Term>::iterator itr2 = ++the_itr;
	--the_itr;
	if(itr2 == this->end())
		return;
	while(*the_itr == *itr2){
		the_itr->coefficient += itr2->coefficient;
		itr2 = this->erase(itr2);
	}
	the_itr = itr2;
	collect_like_terms();
}

istream& operator >>(istream& INpolyStream, Term_list& polynomial){
	Term Term_i;
	while(INpolyStream >> Term_i){
		polynomial.push_back(Term_i);
	}
	polynomial.the_itr = polynomial.begin();
	polynomial.selection_sort();
	polynomial.the_itr = polynomial.begin();
	polynomial.collect_like_terms();
	return INpolyStream;
}

ostream& operator <<(ostream& OUTpolyStream, const Term_list& polynomial){
	if(polynomial.empty())
		throw std::invalid_argument("The Term_list object is empty.");

	list<Term>::const_iterator c_itr=polynomial.cbegin();
	if(c_itr->negative_term())
		OUTpolyStream << '-';
	for(c_itr = polynomial.cbegin(); c_itr != polynomial.cend(); ++c_itr){
		OUTpolyStream << *c_itr;
		if ((++c_itr) != polynomial.cend()){
			if (c_itr->negative_term())
				OUTpolyStream << " - ";
			else
				OUTpolyStream << " + ";
		}
		--c_itr;
	}
	return OUTpolyStream;
}

Term_list& Term_list::operator +(const Term_list& other_polynomial) const{
	Term_list result_polynomial(*this);
	list<Term>::const_iterator c_itr;
	for(c_itr = other_polynomial.cbegin(); c_itr != other_polynomial.cend(); ++c_itr){
		result_polynomial.push_back(*c_itr);
	}
	list<Term>::iterator itr;
	result_polynomial.the_itr = result_polynomial.begin();
	result_polynomial.selection_sort();
	result_polynomial.the_itr = result_polynomial.begin();
	result_polynomial.collect_like_terms();
	return result_polynomial;
} 
