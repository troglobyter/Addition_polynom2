#include <iostream>

using namespace std;

class Term{
private:
int coefficient;
int exponent;
public:
Term();
Term(int t_coeff, int t_exp);
Term(Term& a_Term);
bool operator >(Term& other_Term);
bool operator ==(Term& other_Term);
friend istream& operator >>(istream& INtermStream, Term& a_Term);
friend ostream& operator <<(ostream& OUTtermStream, const Term& a_Term);
