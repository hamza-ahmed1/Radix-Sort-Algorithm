// Radix Sort Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int GetMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			int temp = arr[i];
			arr[i] = max;
			max = temp;
		}
	}
	return max;
}
void CountSort(int arr[], int n, int pas)
{
	int b[10] = { 0 };
	int count[10] = { 0 };

	//loop1:
	for (int  i = 0; i < n; i++)
	{
		++count[(arr[i]/pas)%10];
	}
	//loop2
	for (int  i = 1; i <10; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	//loop3
	for (int i = n-1; i >=0; i--)
	{
		b[--count[(arr[i] / pas) % 10]] = arr[i];
	}
	//loop4
	for (int i = 0; i < n; i++)
	{
		arr[i] = b[i];
	}
}

void RadixSort(int arr[], int n) {
	int max = GetMax(arr, n);
	// if max has k digits, the loop will run k times
	for (int pas = 1; max / pas > 0; pas *= 10) {
		CountSort(arr, n, pas);
	}
}
int main()
{
	int arr[5] = { 700,240,200,600,300};
	RadixSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "  ";
	}
}

