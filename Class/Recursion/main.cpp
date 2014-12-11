//Execution begins here


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

float sinR(float); // float for sin
float cosR(float); // radian

stack<char> myStack;

int main()
{	
	//Testing out recursive trig functions
	float angDeg = 5; // angle in degrees
	float angRad = angDeg *atan(1)/45;
	cout << "Angle = " << angDeg << " sin = " << sin(angRad) << " our sin = " << sinR(angRad) << endl;
	cout << "Angle = " << angDeg << " cos = " << cos(angRad) << " our sin = " << cosR(angRad) << endl;


	int cos = 0;
	int sin = 0;

	while (!myStack.empty())
	{
		 if(myStack.top()=='c'){
			 cos++; 
		 }else if(myStack.top()=='s'){
			 sin++;
		 }
		 myStack.pop();
	}

	cout << "\nNumber of time Hyp Cosine was called: " << cos << endl
		 << "Number of time Hyp Sine was called: " << sin << endl<<endl;


	return 0;
}


float sinR(float angR){ // angle in radians
	float tol = 1e-6;
	myStack.push('s');

	if(angR>-tol&&angR<tol){
		return angR-angR*angR*angR/6;
	}
	else{
		return 2*sinR(angR/2)*cosR(angR/2);
	}
}
float cosR(float angR){
	myStack.push('c');

	float tol = 1e-6;
	if(angR>-tol&&angR<tol)return 1-angR*angR/2;
	float a=cosR(angR/2);
	float b=sinR(angR/2);
	
	return a*a-b*b;
}