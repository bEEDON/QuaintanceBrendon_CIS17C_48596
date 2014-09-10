#include "Tri.h"

/* 
 * File:   main.cpp
 * Author: Brendon Quaintance
 * Created on August 27, 2014, 8:05 PM
 * Purpose:  Make a class with a Triangular Array
 */

//Execution Begins Here
int main(int argc, char** argv) {

	srand(static_cast<unsigned int>(time(0)));
	Tri<int> array1; 

	array1.fillArray();
	array1.printArray();
	array1.~Tri();

    //Exit stage right
     return 0;
}