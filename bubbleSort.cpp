#include<iostream>
using namespace std;
void bubbleSort(int array[],int size)//taking an array and its size as funtion arguments
{
	for(int i=0;i<size;i++)//use this to compare a single element of the array with the rest of the elements of the array which are present at greater index
	{
		for(int j=i+1;j<size;j++)//use this to get elements of array which are present after the comparing element
		{
			if(array[i]>array[j])//if the outer loop or comparing element is greater than the inner loop element or next element than swap there values
			{
				//swapping the values
				int t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
		}
	}
}
void display(int array[],int size)//taking an array and its size as funtion arguments
{
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";//printing every index's value 
	}
	cout<<endl;
}
int main()
{
	int array[5]={5,4,3,2,1},size=(sizeof(array)/sizeof(array[0]));//array with predefined values
	bubbleSort(array,size);//sorting array with bubble sort
	display(array,size);
	return 0;
}
