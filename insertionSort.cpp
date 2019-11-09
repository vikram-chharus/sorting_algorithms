#include<iostream>
using namespace std;
void display(int arr[])
{
	for(int i=0;i<10;i++)//printing the array
	{
		cout<<arr[i]<<" ";
	}
}
void insertionSort(int array[],int low ,int high)
{
	for(int i=low;i<high;i++)//
	{
		int currentNumber=array[i];//taking an element of the array
		int j=i-1;//using this to detact the elements before the current number
		while(j>=0 && array[j]>currentNumber)//if j is left behind the current number's index and value at index 'j' is greater than current number
		{									//then shift all the number from jth index to the current number's index						
			array[j+1]=array[j];
			j=j-1;//decrease the value of j or point to the next element
		}
		array[j+1]=currentNumber;//swap the values of current number with j+1th index
		display(array);
		cout<<endl;
	}
}
int main()
{
	int array[10]={89, 45, 98, 12, 45, 36, 11, 18, 23, 66 };//array with predefined values
	insertionSort(array,0,9);//calling insertion sort funtion to sort the array with providing array , base_index and highest index of the array as funtion parameters
	display(array);
	return 0;
}
