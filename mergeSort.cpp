#include<iostream>
using namespace std;
void mergeSubArrays(int array[], int low, int mid, int high) 
{ 
	int index=0;
	int t_array[high-low];
	int l_i=low;
	int r_i=mid+1;
	while(l_i<=mid && r_i<=high)
	{
		if(array[l_i]<array[r_i])
		{
			t_array[index++]=array[l_i++];
		}
		else
		{
			t_array[index++]=array[r_i++];
		}
	}
	while(l_i<=mid)
	{
		t_array[index++]=array[l_i++];	
	} 
	while(r_i<=high)
	{
		t_array[index++]=array[r_i++];
	}
	for(int i=low;i<=high;i++)
	{
		array[i]=t_array[i-low];	
	}
} 
  
void mergeSort(int array[],int low,int high)//sorting the array's values using merge sort algorithm
{
	if(low<high)//untill base_index is smaller then last_index or array has some values 
	{
		int midPoint=(low+high)/2;//get mid point of the current subarray
		mergeSort ( array, low, midPoint );//call mergeSort for the left sub array
		mergeSort ( array, midPoint+1, high);//call mergeSort for the right sub array
		mergeSubArrays(array, low, midPoint, high);//merge the left and right sub arrays
	}
}
int main()
{
	int array[7]={5,4,3,2,1};//array
	mergeSort(array,0,4);//calling mergeSort funtion with array ,array's base_index and last index
	for(int i=0;i<5;i++)//printing all the elements of the array
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
