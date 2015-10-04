#include "Term_list.h"
#include <string> 
#include <cctype>
#include <iostream>

using namespace std;

string& polystring_format(istringstream& INstream); 

void AddPolys();

int main()
{
	char choice;
			
			////////////MENU/////////////
	cout << "~~~~~~~~~~~Program to add two polynomials~~~~~~~~~~~" << endl<< endl;
	cout << "1. Add Polynomials" << endl << "2. Quit" << endl << "Choose (1 or 2): ";
	cin >> choice;
	cin.ignore(100, '\n');
	switch (choice)
	{
	//ADD
	case '1': 
		AddPolys();
		break;
	//Quit
	case 'q':
	case 'Q':
	case '2': 
		system("cls");
		cout << endl << "Thank You!" << endl;
		break;
	//Invalid choice
	default:					
		cout << "Invalid choice" << endl;
	}

	system("pause");
	return(0);
}

string& polystring_format(istringstream& INstream){

	char next_char;
	bool negative_term = false;
	string poly_formatted;
	while(INstream >> next_char){
		if(negative_term && next_char == '-'){
			poly_formatted += ' ';
			negative_term = false;
		}
		if(isalnum(next_char) || next_char == '^')
			poly_formatted += next_char;
		else if(next_char == '-'){
			if(poly_formatted.empty() || poly_formatted.back() == '^')
				poly_formatted += next_char;
			else{
				poly_formatted += ' ';
				negative_term = true;
			}
		else if(next_char == '+')
			poly_formatted += ' ';
	}

	string::iterator itr = poly_formatted.begin();
	if(isalpha(*itr))
		poly_formatted = '1' + poly_formatted;
	for(itr = poly_formatted.begin(); itr != poly_formatted.end(); ++itr){
		if(isalpha(*itr)){
			if(!isdigit(*(itr -1)))
				poly_formatted.insert(itr,1,'1');
		}
	}
	return poly_formatted;
}
		

 
void AddPolys()
{
	//string variables for user input and formatted , Term_list variables for two polynomials, input string stream variable.
	string Poly1, formatted_Poly1;
	string Poly2, formatted_Poly2;
	Term_list firstPoly, secondPoly;
	istringstream polyINstream;

	// Read in Term_list firstPoly 
	cout << endl << "Input polynomials in this format" << endl
	<< "3x^3+4x^2-2x+7"<< endl << endl <<"Enter the first polynomial: "<< endl;
	getline(cin, Poly1);
	polyINstream(Poly1);
	formatted_Poly1 = polystring_format(polyINstream);
	polyINstream(formatted_Poly1);
	polyINstream >> firstPoly; 

	// Read in Term_list secondPoly 
	cout << "Enter the second polynomial: " << endl;
	getline(cin, Poly2);
	polyINstream(Poly2);
	formatted_Poly2 = polystring_format(polyINstream);
	polyINstream(formatted_Poly2);
	polyINstream >> secondPoly;

	// Adds the polynomials and prints out the result
	cout << endl << "Result: ";
	cout << firstPoly + secondPoly << endl << endl;
}
