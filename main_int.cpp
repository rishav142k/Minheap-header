#include "minheap.h" // including the header file
#include <iostream>

using namespace std;

int main() 
{
	// For integers, you can use the minheap wihtout any preparation. Simply go ahead andcreate a minheap by :
	int arr[10] = {1, 2, 11, 2, 10, 6};
	
	minheap<int> m1(arr, 6, 10);
	
	cout << m1.extract_min() << "\n";
	m1.heap_increase_key(1, -10);
	cout << m1.extract_min() << "\n";
	
	
	
return 0;
}
