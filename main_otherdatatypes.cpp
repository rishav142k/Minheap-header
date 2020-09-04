#include "minheap.h"
#include <iostream>

using namespace std;

class Class
{
	public:
	int value;
	char a;
	
	operator int() 
	{
		return value;
	}
	
	operator = (int x)
	{
		value=x;
	}
	/*
	operator int () is for type casting an object of heapNode to int. 
	operator = (int x) is to overload '=' operator. 
	With this operator we can assign object1.value to object2.value of this class.
	These two functions are mandatory for every user defined entities because internally minheap deals with int only.
	*/
};


int main()
{
	
	
	Class c1, c2, c3, c4;
	c1.value=10;
	c2.value=9;
	c3.value=1;
	c4.value=0;
	
	Class Class_array[3]={c1, c2, c3};//capacity=3
	
	minheap<Class> m2(Class_array, 3, 3); //all 3 places filled out of maximum 3 places
	//put respective data type inside < > brackets
	
	/*All the heap operations below can be applied to any data-types irrespective of them being user defined or built in data type */
	/*In case of user defined classes, appropriate overloading needs to be done */
	
	cout<<m2.get_capacity()<<endl; //gives 3 as o/p
	cout<<m2.extract_min()<<endl; //gives 1 as o/p b'coz 1 is min of {10, 9, 1}. It also decrements size
	cout<<m2.get_size()<<endl; //gives 2 as o/p b'coz extract_min() extracted 1 out of {1, 9, 10} with only {9, 10} remaining
	m2.insert(c4); //it'll insert c4 into {c3, c2, c1} i.e 0 into {1, 9, 10}
	
	
	//new arrays to store sorted values rendered by heap sort
	int int_sorted_array[10];
	Class Class_sorted_array[3]; 
	
	
	m2.heap_sort(Class_sorted_array);
	
	cout<<endl<<"Some random class sorted values by heap sort:"<<endl;
	for(int i=0; i<m2.get_size(); i++)
	{
		cout<<Class_sorted_array[i]<<endl;
	}
}

