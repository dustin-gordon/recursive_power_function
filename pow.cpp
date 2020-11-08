// Dustin Gordon

#include <iostream>

using namespace std;

double pow(double base, int exp)
{
    switch(exp)
    {
        case 0: // A^0 = 1
            return 1;

        case 1: // A^1 = A
            return base;

        default:
            if(exp > 0) //Pos. exponents
            {
                return base * pow(base, (exp - 1)); // A^B = A * A^(B-1)
            }
            else if(exp < 0) //Neg. exponents
            {
                double absExp = exp * -1;
                return 1 / (base * pow(base, (absExp - 1))); // A^(-B) = 1/(A^B)
            }
            else
            {
                return 0; //To satisfy compiler expecting a return;
            }
    }
}

int main() 
{
	double x;	//The Base
	int y;		//The Exponent

    cout << "\n* To calculate x^y ..." << "\n*" << endl;
    //User input:
    cout << "* Enter the base (x): ";
	cin >> x;
	cout << "* Enter exponent (y): ";
	cin >> y;
	
	if(x == 0) //Input validation
	{
		if (y > 0)
            cout << "*\n* Result: 0^" << y << " = 0" << endl;
		else
			cout << "\nERROR: 0^0 is not defined!" << endl;
	}
	else
	{
		cout << "*\n* Result: " << x << "^" << y << " = "
		<< pow(x,y) << endl; //Call recursive function
	}
		
	return 0;
}

