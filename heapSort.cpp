#include<iostream>
using namespace std;
void swap(int *i, int *j)//swapping two numbers only
{
	int t=*i;
	*i=*j;
	*j=t;
}
int getGreaterInChildren(int array[],int i,int j)//getting index of child whose value is large
{
	return array[i]>array[j]?i:j;//return first element's index if it is greater otherwise second's
}
void display(int array[],int size)//printing the values of the array
{
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void heap(int array[] , int size)//rearranging the elements of array to make array a heap(max heap)
{
	bool isChange=true;//to check if something has changed in arranging process or not
	while(isChange)//untill there is a change ,keep arranging
	{
		isChange=false;//set change to false by default
		for(int i=size-1;i>0;i-=2)//
		{
			int parent=(i-1)/2;//getting a parent element's index from array as a parent element always present at ((i-1)/2)th index
			int greaterChildIndex=getGreaterInChildren(array,i,i-1);//getting the index of child whose value is large in both the left and right child
			if(array[greaterChildIndex] > array[parent] )//if child has larger value than its parent then swap the values
			{
				swap(&array[greaterChildIndex] ,&array[parent]);//swapping parent and child
				isChange=true;//changing has changed value to true as we have made some changes in the array
			}
		}
	}	
}
void reArrangeHeap(int array[], int size)//rearranging the array to sort the unsorted array to make it a max heap
{
	bool isChange=true;//to check if there is any change or not in arranging process 
	int parentIndex=0;//taking first element as a parent element
	while(isChange)//if there is any change then check again
	{
		isChange=false;//set has changed to false to make sure that if we did not encountered with any change then loop must got terminated
		int leftChild=2*parentIndex+1;//getting index of the left child of parent element
		int rightChild=2*parentIndex+2;//getting index of the right child of the parent element
		int  greaterChildIndex;//to store the index of the child who has larger value
		if(leftChild<=size)//if there is actually a left child of the parent element then
		{
			if(rightChild<=size)//if there is actually a right child of the parent element then
			{
				greaterChildIndex=getGreaterInChildren(array,leftChild,rightChild);//check wheather the left child is greater or right child and get the index
			}
			else//if there is no more right child then left child will always be the larger one as it is the only child that parent has
			{
				greaterChildIndex=leftChild;//assign the index of left child to greaterChildIndex
			}
			if( array[parentIndex] < array[greaterChildIndex] )//check if the child has larger value than its parent or not and if has then
			{
				swap(&array[parentIndex],&array[greaterChildIndex]);//swap the values of child and parent
				isChange=true;//set has changed to true as we have made some changes in the array
			}
		}
		else//if there is no left child of the parent it means we have reached to the bottom of the heap or last level
		{
			isChange=false;//as we did'nt made any changes
			break;//stop the current executing loop
		}
		parentIndex=greaterChildIndex;//now set the greater child index to parent as we have shifted the parent's value to its child 
	}
}
void heapSort(int array[],int size)//sort the heap
{
	int heapSize=size-1;//set heapSize to 1 less than the actuall size of the array as we will be using the last space to store the maximum value that array has
	bool isChange=true;//to check if we made any changes or not, set true by default as we will swap the first element with the last element
	while(heapSize>0)//continue untill we have left only 1 element in the heap
	{
		swap(&array[0],&array[heapSize--]);//swap the first element of the heap with the last element of the array
		reArrangeHeap(array,heapSize);//rearrange the unsorted heap and make it max heap
	}
}
int main()
{
	int array[11]={23,56,11,90,6,-56,0,670,22,7,45},size=sizeof(array)/sizeof(array[0]);//array and its size
	cout<<"Before creating heap : "; display(array,size);
	heap(array,size);
	cout<<"After creating heap : "; display(array,size);
	heapSort(array,size);
	cout<<"After HeapSort : "; display(array,size);
	return 0;
}
