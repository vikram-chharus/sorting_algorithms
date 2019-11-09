#include<iostream>
using namespace std;
void selectionSort(int array[],int size)
{
	int smallestNumber_s_index;
	for(int i=0;i<size;i++)
	{
		smallestNumber_s_index=i;
		for(int j=i+1;j<size;j++)
		{
			if(array[smallestNumber_s_index]>array[j])
			{
				smallestNumber_s_index=j;
			}
		}
		int t=array[i];
		array[i]=array[smallestNumber_s_index];
		array[smallestNumber_s_index]=t; 
	}
}
int main()
{
	int array[5]={5,4,3,2,1};
	selectionSort(array,5);
	for(int i=0;i<5;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
