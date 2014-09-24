/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 1:55 PM
 * Purpose:  Explore creation of a linked list class Version 3
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    cout<<list.toString()<<endl;
    //Exit stage right!
    return 0;
}