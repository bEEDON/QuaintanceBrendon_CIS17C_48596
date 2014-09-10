//========= Tri.h=======================================
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

template <class T>
class Tri{
private:
	int rows,cols, cls, perLine;
	T *colAry, **array;
public:
	Tri();
	~Tri();
	void fillArray();
	void printArray();
};

template <class T>
Tri<T>::Tri()
{
	rows=5,cols=10;
    cls=rows,perLine=10;

	array=new int*[rows];
	colAry=new int[cols];
}
template <class T>
Tri<T>::~Tri(){}

template <class T> 
void Tri<T>::fillArray(){

	for(int col = 0; col < rows; col++){ 
    	colAry[col]=rand()%9+2;  
    }

    //Declare the 2-D Array
    for(int row=0; row < rows; row++){
        array[row]=new int[colAry[row]];
    }

	//Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(T col=0;col<colAry[row];col++){
            array[row][col]=rand()%90+10;
        }
	}
	// return array;  // Deleted because we are using void

}
template <class T>
void Tri<T>::printArray(){

	//Print the Array
    cout<<endl;
    for(int col=0; col < rows; col++){
       cout << colAry[col] << " ";
    }
    cout<<endl;

    //Print the Array
    cout<<endl;
    for(T row=0;row<rows;row++){
        for(T col=0;col<colAry[row];col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


}
