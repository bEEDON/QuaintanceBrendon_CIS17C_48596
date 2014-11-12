//Execution begins here

#include "helloworld/Hello.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

int bcoeff(int,int); // binary coefficient (CNR)
int gcd(int,int);
void towers(int,char,char,char);
int max(int *, int); // array and size
float sinR(float); // float for sin
float cosR(float); // radian

// look up trig identities
int main(int argc, char const *argv[])
{	
	Hello hello;

	//Utilized the recursive binary coefficient function
	int rows = 20;
	int cols = rows;
	for(int n = 0; n<rows;n++){
		for(int k = 0; k <=n;k++){
			cout << bcoeff(n,k) << " ";
		}
		cout << endl;
	}

	//Testing the gcd with euclid algorithm
	int n = 12*6, m = 12*17;
	cout << endl;
	cout << "The GCD of " << n << " and " << m << " is " << gcd(m,n) << endl;

	// Towers of Hanoi
	int disks = 3;
	char peg1= 'A', peg2 = 'B', peg3 ='C';

	towers(disks,peg1,peg2,peg3);

	// Fill Array and find the max
	srand(static_cast<unsigned int > (time(0)));
	int size = 100;
	int array[size];
	for(int i = 0;i<size;i++){
		array[i] = rand()%90+10;
	}
	cout << endl;
	cout << "Max element in the array is " << max(array,size) << endl;
	cout << endl;
	// exit


	//Testing out recursive trig functions
	float angDeg = .01; // angle in degrees
	float angRad = angDeg *atan(1)/45;
	cout << "Angle = " << angDeg << " sin = " << sin(angRad) << " our sin = " << sinR(angRad) << endl;
	cout << "Angle = " << angDeg << " cos = " << cos(angRad) << " our sin = " << cosR(angRad) << endl;

	return 0;
}

int bcoeff(int n,int k){

	// Remember a basis is required
	if(k==0)return 1; // basis
	if(k==n)return 1; // right hand side
	return bcoeff(n-1,k-1) + bcoeff(n-1,k);
}
int gcd(int m,int n){
	if(m==0) return n;
	if(m>=n) return gcd(m%n,n);
	if(m<n) return gcd(n%m,m);
}
void towers(int n,char source,char spare,char destination){
	if(n>1) towers(n-1,source,destination,spare);
	cout << "Source = " << source << " move to " << destination << endl;
	if(n>1) towers (n-1, spare, source, destination);
}
int max(int *a, int s){
	if(s==1) return a[0];
	int half = s/2;
	int top = s - half;
	int m1 = max(a,half);
	int m2 = max(a+half,top);
	return (m1>m2?m1:m2);
}

float sinR(float angR){ // angle in radians
	float tol = 1e-6;
	if(angR>-tol&&angR<tol){
		return angR-angR*angR*angR/6;
	}
	else{
		return 2*sinR(angR/2)*cosR(angR/2);
	}
}
float cosR(float angR){
	float tol = 1e-6;
	if(angR>-tol&&angR<tol)return 1-angR*angR/2;
	float a=cosR(angR/2);
	float b=sinR(angR/2);
	return a*a-b*b;
}