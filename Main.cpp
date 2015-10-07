#include "Term_list.h"
#include <string> 
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

string polystring_format(istringstream& INstream); 

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

string polystring_format(istringstream& INstream){

	char next_char;
	bool negative_term = false;
	bool last_was_carrot = false;
	string poly_formatted = "";

	while(INstream >> next_char){
		if (negative_term){
			if (next_char == '-')
				poly_formatted += ' ';
			else{
				poly_formatted += ' ';
				poly_formatted += '-';
				negative_term = false;
			}
		}
		if(isalnum(next_char) || next_char == '^'){
			if(next_char == '^')
				last_was_carrot = true;
			else if (last_was_carrot && isdigit(next_char))
				last_was_carrot = false;
			poly_formatted += next_char;
		}
		else if(next_char == '-'){
			if(poly_formatted.empty() || last_was_carrot){
				if(last_was_carrot)
					last_was_carrot = false;
				poly_formatted += next_char;
			}
			else if(!negative_term){
				negative_term = true;
				poly_formatted += ' ';
			}
			else
				negative_term = false;
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

	// Read in Term_list firstPoly 
	cout << endl << "Input polynomials in this format" << endl
	<< "3x^3+4x^2-2x+7"<< endl << endl <<"Enter the first polynomial: "<< endl;
	getline(cin, Poly1);
	istringstream poly1INstream(Poly1);
	formatted_Poly1 = polystring_format(poly1INstream);
	istringstream poly1fINstream(formatted_Poly1);
	poly1fINstream >> firstPoly;
	cout << firstPoly << endl;

	// Read in Term_list secondPoly 
	cout << "Enter the second polynomial: " << endl;
	getline(cin, Poly2);
	istringstream poly2INstream(Poly2);
	formatted_Poly2 = polystring_format(poly2INstream);
	istringstream poly2fINstream(formatted_Poly2);
	poly2fINstream >> secondPoly;
	cout << secondPoly << endl;

	// Adds the polynomials and prints out the result
	cout << endl << "Result: ";
	cout << firstPoly + secondPoly << endl << endl;
}
