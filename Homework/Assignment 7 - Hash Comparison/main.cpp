/*================ Linear, Binary, and Hash ======================
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

//Class designed for Hash Comparison
class HashMap {
private:
      HashEntry **table;
public:
      HashMap() {
            table = new HashEntry*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                  table[i] = NULL;
      }
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == NULL)
                  return -1;
            else
                  return table[hash]->getValue();
      }
      void put(int key, int value) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] != NULL)
                  delete table[hash];
            table[hash] = new HashEntry(key, value);
      }     
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }
};

string linearSearch(const string [], int, int); // prototype
void binarySearch(apvector <int> &array, int lowerbound, int upperbound, int key)

int main(){
	
	//Declaring Time Variables
	float start;
	float end;


    //Sorting The String Array
    string array[5] = { "zero", "one", "two", "three", "four" } ;
    sort( array, array+5 ) ;
    for( const auto& str : array ) cout << str << ' ' ;
    cout << '\n' ;
	
	//Starting Timer for Linear Search
	start = clock();
	linearSearch(array, 1, 5);
	//Ending Timer
	end = clock();
	cout << "Runtime for Linear = " << (end - start) / CLK_TCK << " seconds.\n\n";

	//Starting Timer for Binary Search
	start = clock();
	binarySearch(array, 0, 5, 1);
	//Ending Timer
	end = clock();
	cout << "Runtime for Linear = " << (end - start) / CLK_TCK << " seconds.\n\n";

	//Starting Timer for Hash
	start = clock();
	hash(array,0,1);
	put(array);
	//Ending Timer
	end = clock();
	cout << "Runtime for Linear = " << (end - start) / CLK_TCK << " seconds.\n\n";
}

int linearSearch( const int array[], int key, int sizeOfArray )
{
   for ( int j = 0; j < sizeOfArray; j++ ){
      if ( array[ j ] == key ){
         return j;
      }
   }
   return -1;
}
void binarySearch(apvector <int> &array, int lowerbound, int upperbound, int key)
{
       int position;
       int comparisonCount = 1;    //count the number of comparisons (optional)

       // To start, find the subscript of the middle position.
       position = ( lowerbound + upperbound) / 2;

       while((array[position] != key) && (lowerbound <= upperbound))
       {
              comparisonCount++;
              if (array[position] > key)               // If the number is > key, ..
             {                                                       // decrease position by one.
                    upperbound = position - 1;    
             }                                                      
             else                                                
            {                                                        // Else, increase position by one.
                   lowerbound = position + 1;     
             }
             position = (lowerbound + upperbound) / 2;
       }
      if (lowerbound < = upperbound)
      {
            cout<< "The string was found in array subscript "<< position<<endl<<endl; 
            cout<< "The binary search found the string after " << comparisonCount 
                   << " comparisons.\n";              
            // printing the number of comparisons is optional
       }      
       else
             cout<< "Sorry, the string is not in this array.  The binary search made "
                   <<comparisonCount << " comparisons.";
       return;  // you may also consider returning the subscript
} 