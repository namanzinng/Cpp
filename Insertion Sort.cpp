#include <iostream>
using namespace std;
void iSort(int arr[], int nElements)
{

int x, key, y;
for (x = 1; x < nElements; x++)

{
key = arr[x];
y = x - 1;
while (y >= 0 && arr[y] > key)
{
arr[y + 1] = arr[y];
y = y - 1;
}
arr[y + 1] = key;
}
}
void printArray(int arr[], int n)
{
int i;
for (i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
}
int main()
{
int arr[] = { 141,182,194,162,171,191,135};
int n = sizeof(arr) / sizeof(arr[0]);
iSort(arr, n);
printArray(arr, n);
return 0;
}

