#include <iostream>
#include "list.h"
using namespace std;

int main()
{
  //assuming you are implementing a class called 'list'
  list llist;
  char option;
  int value;
  int loc;
  
  //user input: quit (q), insert (i), find (f), remove (r), print (p)
  // insert front (F), insert back (B), insert location (L), 
  // remove location (R), get size (s)
  cout << "What to do? quit (q), insert (i), find (f), remove (r), print (p), insert front (F), insert back (B), insert location (L),"
	   << " remove location (R), get size (s)\n\n";
  cin >> option;

  while (option != 'q')
  {
    switch(option)
    {
      //insert value
    case 'i':
      cin >> value;
      llist.insert(value);
      break;

      //insert value to the front
    case 'F':
      cin >> value;
      llist.insertFront(value);
      break;

      //insert value to the back
    case 'B':
      cin >> value;
      llist.insertBack(value);
      break;

      //insert value so a specified location
    case 'L':
      cin >> value;
      cin >> loc;
      llist.insertLocation(value, loc);
      break;
      
      //find value
    case 'f':
      cin >> value;
      if (!llist.find(value))
      {
	  cout << "Value not found" << endl;
      } 
      else 
      {
	cout << "Value found" << endl;
      }
      break;
      
      //remove value
    case 'r':
      cin >> value;
      if (!llist.remove(value))
      {
	cout << "Error: Value not in list" << endl;
      }
      break;

      //remove list value at specified location
    case 'R':
      cin >> loc;
      if (!llist.removeLocation(loc))
      {
	cout << "Error: Index out of bounds" << endl;
      }
      break;
      
      //print size of list
    case 's':
      cout << "Size of list: " << llist.size() << endl;
      break;

      //print list
    case 'p':
      llist.print();
      break;

      //quit program      
    case 'q':
      cout << "Exitiing" << endl;
      break;
      
      
      //unknown command
    default:
      cout << "Error: Command not recognized" << endl;
      
    }
    cin >> option;
  }
  
  return 0;
}
