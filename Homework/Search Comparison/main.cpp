/*=========================================================
	Author: Brendon Quaintance
	Description: Compare bubble, selection, heap, merge and quicksort. 
	Date: 12/11/2014
=========================================================*/

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void heapsort(int *a, int n);
void build_maxheap(int *a, int n);
void merge(int*,int*,int,int,int);
void mergesort(int *a, int*b, int low, int high);
void quickSort(int arr[], int left, int right) ;
void printElements(int *array,int length);

int main()
{
	//Bubble Sort
	int a[]={9,6,5,23,2,6,2,7,1,8};  
	cout<<"Elements before bubble sort:\n";
    printElements(a,10);               
	cout<<endl;

    bubbleSort(a,10);                 

	cout<<"Elements after bubble sort:\n";
    printElements(a,10);            
    cout<<endl<<endl;

	//Selection Sort
	int b[]={9,6,5,23,2,6,2,7,1,8}; 
	cout<<"\nElements before Selection sort:\n";
    printElements(b,10);            
    cout<<endl;

	selectionSort(b,10);
	cout<<"Elements after Selection sort:\n";
    printElements(b,10);            
    cout<<endl<<endl;

	//Heap Sort
	int h[20]={9,6,5,23,2,6,2,7,1,8}; 
	cout<<"\nElements before Heap sort:\n";
    printElements(h,10);            
    cout<<endl;

	build_maxheap(h,10);
    heapsort(h, 10);

	cout<<"Elements after Heap sort:\n";
    printElements(h,10);            
    cout<<endl<<endl;


	//Merge Sort
	int d[]={9,6,5,23,2,6,2,7,1,8}; 
	cout<<"\nElements before Merge sort:\n";
    printElements(d,10);            
    cout<<endl;

    int e[10];
    mergesort(d,e,0,10-1);

	cout<<"Elements after Merge sort:\n";
    printElements(d,10);            
    cout<<endl<<endl;

	//Quick Sort
	int c[]={9,6,5,23,2,6,2,7,1,8}; 
	cout<<"\nElements before Quick sort:\n";
    printElements(c,10);            
    cout<<endl;

	quickSort(c,0,9);

	cout<<"Elements after Quick sort:\n";
    printElements(c,10);            
    cout<<endl<<endl;

}

void bubbleSort(int arr[], int n) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
}

void printElements(int *array,int length) //print array elements
{
    int i=0;
    for(i=0;i< 10;i++)
    cout<< array[i]<< " ";
}

void selectionSort(int arr[], int n) {
      int i, j, minIndex, tmp;    
      for (i = 0; i < n - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}
void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}
