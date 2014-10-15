#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
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

template <class T>
class list
{
private:
	Node *head;
	Node *tail;

public:
	list();
	~list();
	void insert(T num);
	bool find(T query);
	bool remove(T target);
	void print();

	void priorityFront(T data);
	void priorityBacl(T data);
	void insertLocation(T data, T index);
	bool removeLocation(T index);
	int size();
};

template <class T>
list<T>::list()
{
	head = NULL;
	tail = NULL;
}

template <class T>
list<T>::~list()
{
	if(head != NULL)
		delete head;
}

//============= Insert ======================================
template <class T>
void list<T>::insert(int num)
{
	
	//initial case
	 if(head == NULL)
	 {
		 head = new Node;
		 head->data = num;
		 head->next = NULL;
		 head->prev = NULL;
		 tail = head;
		 return;
	 }

	 //head case 
	if (num < head->data)
	{
		Node *temp = new Node;
		temp->data = num;
		head->prev = temp;
		temp->next = head;
		head = temp;
		head->prev = NULL;
		return;
	}
	
	//general case
	Node* i= head;

	if (head->next == NULL)
	{
		Node* temp = new Node;
		temp->data = num;
		temp->next = i->next;
		i->next = temp;
		temp->prev = i;
		temp->next = NULL;
		tail = temp;
		return;
	}

	while (i->next->data < num)
	{
		i = i->next;
		if (i ->next == NULL)
		{
			tail->next = new Node;
			tail->next->data = num;
			tail->next->prev = tail;
			tail = tail->next;
			tail->next = NULL;
			return;
		}
	}
	Node* temp = new Node;
	temp->data = num;
	temp->next = i->next;
	i->next = temp;
	temp->prev = i;
	i->next->prev = temp;
	return;
}	

//============= Find ======================================
template <class T>
bool list<T>::find(int value)
{
	Node* result;
	for(result = head; result != NULL; result = result->next) //starting at head and going to the end
	{
		if (result->data == value)
			return true;
	}
	return false;
}

//============= Remove ======================================
template <class T>
bool list<T>::remove(int target)
{
	//initial case
	if (head == NULL)
		return false;

	//head of the list case
	if (head->data == target)
	{
		Node* victim = head; //asigning head as victim
		head = victim->next; //head is now assigned as victim's next
		victim->next = NULL; //victim does not have a next(isolated)
		delete victim;		//delete
		return true;
	}

	//general case
	for (Node* ptr=head; ptr !=NULL; ptr = ptr->next)
	{
		//previous guy finds the target
		if (ptr->next->data == target)
		{
			Node* victim = ptr->next; //locate victim
			ptr->next = victim->next; //reroute list
			victim->next = NULL;	   //isolate victim
			delete victim;			   //delete victim
			return true;
		}
	}
	return false;
}

//============= Print ======================================
template <class T>
void list<T>::print()	
{
	cout << "\nData in linked list:\n";
	for (Node* ptr=head; ptr != NULL; ptr = ptr->next)
	{
		cout << ptr->data << endl;
	}
	cout << "\n";
}

//============= Priority Queue Front ======================================
template <class T>
void list<T>::priorityFront(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

//============= Priority Queue Back ======================================
template <class T>
void list<T>::priorityBack(int data)
{
	tail->next = new Node;
	tail->next->data = data;
	tail->next->prev = tail;
	tail = tail->next;
}

//============= Insert Location ======================================
template <class T>
void list<T>::insertLocation(int data, int index)
{
	int i = 1;

	//inserting index that is larger than listSize
	if (size()+1 < index)
	{
		cout << "Warning: Index out of bounds!\n";
		return;
	}

	//Head case 
	if(i == index) 
	{
		Node*temp = new Node;
		temp->data = data;
		head->prev = temp;
		temp->next = head;
		head = temp;
		head->prev = NULL;
		return;
	}

	//Tail case
	if((size() + 1) == index)
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = tail->next;
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
		tail = temp;
		return;
	}

	//General case
	Node*target = head;

	while (i != index)//traverses through list to index's location
	{
		i++;
		target = target->next;
	}
	Node * temp = new Node;
	temp->data = data;
	temp->prev = target->prev;
	temp->next = target;
	target->prev->next = temp;
	target->prev = temp;
}
//============= Remove Location ======================================
template <class T>
void list<T>:::removeLocation(int index)
{
	int i = 1;
	Node*ptr = head;

	//initial case
	if (head == NULL)
		return false;

	//Head case
	if(i == index) 
	{
		Node*victim = new Node;
		victim = head;
		head = victim->next;
		victim->next = NULL;
		delete victim;
		return true;
	}

	//traverses through list to index's location
	while (i != index)
	{
		i++;
		ptr = ptr->next;
	}

	//Tail case
	if(ptr->next = NULL)
	{
		Node*victim = ptr;
		tail = ptr->prev;
		ptr->next = NULL;
		tail->next = NULL;
		delete ptr;
		return true;
	}

	//General case
	if(i == index)
	{
		Node*victim = ptr;
		ptr->next = victim->next;
		ptr->prev = victim->next;
		victim->next = NULL;
		delete victim;
		return true;
	}
	return false;
}
//============= List size ======================================
template <class T>
list<T>::size()
{
	Node*count = head;
	int size = 1;

	if(head == NULL)
	{
		return size = 0;
	}

	while(count->next != NULL)
	{
		count = count->next;
		size++;
	}
	return size;
}
/*OUTPUT:
What to do? quit (q), insert (i), find (f), remove (r), print (p), insert front
(F), insert back (B), insert location (L), remove location (R), get size (s)

i1
i2
i3
F10
p

Data in linked list:
10
1
2
3

B-1
p

Data in linked list:
10
1
2
3
-1

R1
p

Data in linked list:
1
2
3
-1
*/