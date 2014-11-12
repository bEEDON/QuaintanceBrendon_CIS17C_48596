//Execution begins here


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
float tan(float angR);

// look up trig identities
int main(int argc, char const *argv[])
{	


	//Testing out recursive trig functions
	float angDeg = .01; // angle in degrees
	float angRad = angDeg *atan(1)/45;
	cout << "Angle = " << angDeg << " sin = " << sin(angRad) << " our sin = " << sinR(angRad) << endl;
	cout << "Angle = " << angDeg << " cos = " << cos(angRad) << " our sin = " << cosR(angRad) << endl;
	//cout << "Angle = " << angDeg << " cos = " << tan(angRad) << " our sin = " << tan(angRad) << endl;

	return 0;
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
float tan(float angR){
	//tan(2x)=(2 tan(x))/(1-(tan(x))^2)
	//|tan(x) ~ x + x^3/3| < epsilon

	float tol = 1e-6;
	if(angR>-tol&&angR<tol)return 1-angR*angR/2;
	float a=tan(angR/2);
	float b=sinR(angR/2);
	return a*a-b*b;

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

