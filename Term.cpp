#include "Term.h"
#include <iostream>

using namespace std;

Term::Term(){

    coefficient = 0; 
    exponent = 0;
}

Term::Term(int t_coeff, int t_exp){

    coefficient = t_coeff;
    exponent = t_exp;
}

Term::Term(const Term& a_Term){

    coefficient = a_Term.coefficient;
    exponent = a_Term.exponent;
}

bool Term::negative_term() const{

	return coefficient < 0;
}

bool Term::operator > (Term& other_Term)
{
    return exponent > other_Term.exponent;
}

bool Term::operator ==(Term& other_Term){

    return exponent == other_Term.exponent;
}

istream& operator >>(istream& INtermStream, Term& a_Term){
	char varLetter = 'x';
	char carrot = '^';

    INtermStream >> a_Term.coefficient;
	INtermStream >> varLetter;
	if (isspace(varLetter)){
		INtermStream.putback(varLetter);
		a_Term.exponent = 0;
		return INtermStream;
	}
	INtermStream >> carrot;
	if (isspace(carrot)){
		INtermStream.putback(carrot);
		a_Term.exponent = 1;
		return INtermStream;
	}
    INtermStream >> a_Term.exponent;
    return INtermStream;        
}

ostream& operator <<(ostream& OUTtermStream, const Term& a_Term){  
    

    OUTtermStream << abs(a_Term.coefficient);
    if(a_Term.exponent != 0){
        OUTtermStream << "x";
        if(a_Term.exponent != 1){
            OUTtermStream << "^";
            OUTtermStream << a_Term.exponent;
        }
    }
    return OUTtermStream;
}
