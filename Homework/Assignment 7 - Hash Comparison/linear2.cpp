/*================ Linear Search Algorithm ======================
Programmer: Brendon Quaintance
Assignment: Hash Comparison
Date: 10/29/14
================================================================*/

//Included Libraries
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(string[], int, string);

int main(){

	/*
	//Declaring Time Variables
	clock_t start;
	clock_t end;
	//Starting Timer
	start = clock();

    //Sorting The String Array
    std::string array[5] = { "zero", "one", "two", "three", "four" } ;
    std::sort( array, array+5 ) ;
    for( const auto& str : array ) std::cout << str << ' ' ;
    std::cout << '\n' ;
	
	//Ending Timer
	end = clock();
	cout << "Runtime = " << (end - start) / CLK_TCK << " seconds.\n\n";
	*/
	return 0;
}

int linearSearch(string array[], int numElems, string value){

	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found
	while (index < numElems && !found)
	{
		if (array[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or −1
}//End linearSearch