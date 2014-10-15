

#include <iostream>
using namespace std;

template <class T>
struct Node
{
  T data;
  Node * next;
  Node(T data) : data(data), next(NULL) {}
};

template <class T>
class CircularLinkedList
{
public:
  CircularLinkedList() : head(NULL) {}
  ~CircularLinkedList();
  void addNode(T data);
  void deleteNode(T data);
private:
  Node<T> * head;
};

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
  if (head)
    {
      Node<T> * tmp = head;
      while (tmp->next != head)
        {
          Node<T> * t = tmp;
          tmp = tmp->next;
          delete(t);
        }
      delete tmp;
      head = NULL;
    }
}

template <class T>
void CircularLinkedList<T>::addNode(T data)
{
  Node<T> * t = new Node<T>(data);

  if (head == NULL)
    {
      t->next = t;
      head = t;
      return;
    }

  Node<T> * tmp = head;
  while (tmp->next !=  head)
    {
      tmp = tmp->next;
    }

  tmp->next = t;
  t->next = head;
}

template <class T>
void CircularLinkedList<T>::deleteNode(T data)
{
  Node<T> * tmp = head;
  Node<T> * prev = NULL;
  while (tmp->next !=  head)
    {
      if (tmp->data == data) break;
      prev = tmp;
      tmp = tmp->next;
    }

  if (tmp == head)
    {
      while (tmp->next != head)
        {
          tmp = tmp->next;
        }
      tmp->next = head->next;
      delete head;
      head = tmp->next;
    }
  else
    {
      prev->next = tmp->next;
      delete tmp;
    }
}

