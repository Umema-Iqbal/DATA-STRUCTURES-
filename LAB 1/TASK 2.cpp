#include<iostream>
using namespace std;
template <typename T, int N>
void printarray(T(&arr)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
}
template <typename T, int N>
void selectionSort(T(&A)[N])
{
	for (int i = 0; i + 1 < N; i++)
	{
		int smallhub = i;
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] < A[smallhub])
				smallhub = j;
		}
		T temp = A[i];
		A[i] = A[smallhub];
		A[smallhub] = temp;
	}

}
int main()
{
	int intarray[5] = { 64,25,12,22,11 };
	cout << "original outer array" << endl;
	printarray(intarray);
	selectionSort(intarray);
	cout << "sorted integer array =" << endl;
	printarray(intarray);
	cout << endl;
	string stringarray[4] = { "apple","orange","banana ","grapes" };

	cout << "original string array" << endl;
	printarray(stringarray);
	selectionSort(stringarray);
	cout << "sorted string array =" << endl;
	printarray(stringarray);
	cout << endl;
	return 0;
}