/* 
 * File:   main.cpp
 * Author: Brendon Quaintance
 * Created on September 24, 2014, 1:55 PM
 * Purpose:  Create a Linked List
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
    list.toString();
    //Exit stage right!
    return 0;
}