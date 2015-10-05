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
Term::Term(Term& a_Term){

    coefficient = a_Term.coefficient;
    exponent = a_Term.exponent;
}
bool Term::operator > (Term& other_Term)
{
    return exponent < other_Term.exponent;
}
bool Term::operator ==(Term& other_Term){

    return exponent == other_Term.exponent;
}
istream& operator >>(istream& INtermStream, Term& a_Term){

    char char1, varLetter, carrot;
    INtermStream.get(char1);
        if (isdigit(char1)){
            INtermStream.putback(char1);
    }
    INtermStream >> a_Term.coefficient;
    INtermStream >> varLetter;
    INtermStream >> carrot;
    INtermStream >> a_Term.exponent;
    return INtermStream;        
}

ostream& operator <<(ostream& OUTtermStream, const Term& a_Term){   

    OUTtermStream << a_Term.coefficient;
    OUTtermStream << "X";
    OUTtermStream << "^";
    OUTtermStream << a_Term.exponent;
    return OUTtermStream;
}
