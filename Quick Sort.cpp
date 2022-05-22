#include <iostream>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main()
{
	const int num = 10;
	int arr[num] = {9,4,19,2,7,9,5,15,23,3};

	cout << "Before sorting" << endl;
	for (int i=0; i<num; i++)
		cout << arr[i] << " ";

	qsort(arr,num,sizeof(int),compare);
	cout << endl << endl;
	cout << "After sorting" << endl;

	for (int i=0; i<num; i++)
		cout << arr[i] << " ";

	return 0;
}
