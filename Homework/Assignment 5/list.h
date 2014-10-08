//list.h

#include <iostream>
using namespace std;

#ifndef _LIST_H
#define _LIST_H

struct Node
{
	int data;
	Node *next;
	Node *prev;

	Node()
	{
		next = NULL;
	}
	~Node()
	{
		if(next != NULL)
			delete next;
	}
};

class list
{
private:
	Node *head;
	Node *tail;

public:
	list();
	~list();
	void insert(int num);
	bool find(int query);
	bool remove(int target);
	void print();

	void insertFront(int data);
	void insertBack(int data);
	void insertLocation(int data, int index);
	bool removeLocation(int index);
	int size();
};
#endif