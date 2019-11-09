#include<iostream>
using namespace std;
void display(int array[])
{
	for(int i=0;i<5;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void swap(int *i,int *j)
{
	int t=*i;
	*i=*j;
	*j=t;
}
int partition(int array[],int low,int high)
{
	int swapIndex=low,pivot=array[high];
	for(int i=low;i<high;i++)
	{
		if(array[i] < pivot)
		{
			swap(&array[swapIndex++],&array[i]);
		}
	}
	swap(&array[swapIndex],&array[high]);
	return swapIndex;
}

void quickSort(int array[],int low,int high)
{
	if(low<high)
	{
		int p=partition(array,low,high);
		quickSort(array,low,p-1);
		quickSort(array,p+1,high);
	}
}
int main()
{
	int array[5]={5,4,3,2,1};
	quickSort(array,0,4);
	display(array);
	return 0;
}
