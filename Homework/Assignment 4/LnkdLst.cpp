/* 
 * File:   LnkdLst.cpp
 * Author: Brendon Quaintance
 * Created on September 24, 2014
 */

#include "LnkdLst.h"


LnkdLst::LnkdLst(int){
	head = NULL;
}
void LnkdLst::append(int num){
	//initial case
	 if(head == NULL)
	 {
		 head = new Node;
		 head->data = num;
		 return;
	 }

	 //head case 
	if (num < head->data)
	{
		Node *temp = new Node;
		temp->data = num;
		temp->next = head;
		head = temp;
		return;
	}
	
	//general case
	Node* i= head;

		if (head->next == NULL)
		{
			Node* temp = new Node;
			temp->data = num;
			head->next = temp;
			temp->next = NULL;
			return;
		}
		/*
		while (i->next->data < num)
		{
			i = i->next;
			if (i ->next == NULL)
			{
				Node* temp = new Node;
				temp->data = num;
				i->next = temp;
				temp->next = NULL;
				return;
			}
		}*/
		Node* temp = new Node;
		temp->data = num;
		temp->next = i->next;
		i->next = temp;
}
void LnkdLst::toString(){
    if(head){
        worker=head;
        do{
             cout<<"Data element in the list ->"<<worker->data<<endl;
        }while(worker=worker->next);
    }
}
LnkdLst::~LnkdLst(){
    int counter=0;
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
            cout<<"Destroying Link "<<counter+1<<endl;
        }while(head);
    }
}

