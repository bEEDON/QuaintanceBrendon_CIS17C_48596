#include <iostream>
using namespace std;


float futureValue(float presentValue, float interestRate, float years);

int main()
{	
	int years = 100;
	float amount = 1000;
	float interestRate = .09;

	cout << "Future Value of: "<<amount<<endl
		 <<" = "<<futureValue(amount, interestRate, years);

	cout << endl << endl;
	return 0;
}

float futureValue(float presentValue, float interestRate, float years)
{
	for(int i = 1; i <= years; i++)
    {
         if(i>0){
			 return (presentValue*(1+i));
		 }else{
			return(presentValue * (1+i));
		 }
	}
}