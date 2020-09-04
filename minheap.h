#ifndef MINHEAP_H
#define MINHEAP_H

#include <climits>

template<class T> 
class minheap { // main Minheap class
	private:
	
		int size;
		int capacity;
		T* array;
	
		int heapify(int elem_position); // private; to be accessed only by other member functions.
		void swap(T&, T&); // swap 2 nodes in heap
	
	public :
		minheap(T* array, int size , int capacity) {
			
			this->array = array;
			this->size = size;
			this->capacity=  capacity;
			
			
			if(size >= capacity)
				return;
				
				
			for(int i = (size-1)>>1; i >= 0; i--) {
				heapify(i); // heap creation : O(n)
			}
			
		}
			
		int insert(T element); // insert an element in the heap : O(logn)
		int get_capacity(); // number of elements that can be inserted in the heap
		int get_size(); // number of elements actually in the heap
		int extract_min(); // minimum in heap.
		
		int heap_decrease_key(int elem_position, int new_value); // update element by a lower value
		int heap_increase_key(int elem_position, int new_value); // update element by a higher value
		
		int heap_sort(T* array); // sorts heap and stores it in array.
		int show_element(int elem_position);
		
		~minheap() {
			delete(array);
		}	
};

template<class T>
int minheap<T>::get_capacity() {
	return capacity;
}

template<class T>
int minheap<T>::get_size() {
	return size;
}

template<class T>
void minheap<T>:: swap(T& elem1, T& elem2) {
	T temp = elem1;
	elem1 = elem2;
	elem2 = temp;
}

template<class T>
int minheap<T>::heapify(int element_position)
{
	int right_child_position=(element_position+1)<<1; 
	int left_child_position=right_child_position-1;


	int smallest_element_position=element_position;
	
	if (array[left_child_position] < array[smallest_element_position] && left_child_position<size)
	{
		smallest_element_position = left_child_position;
	}
	
	if (array[right_child_position] < array[smallest_element_position] && right_child_position<size)
	{
		smallest_element_position = right_child_position;
	}
	
	if(smallest_element_position != element_position)
	{
		swap(array[smallest_element_position], array[element_position]);
		heapify(smallest_element_position);
	}
	return 0;
}

template<class T>
int minheap<T>::extract_min()//root is the min. It is returned back
{
		
	if(size < 1)
	{
		return INT_MIN; // size less than 1.
	}
	
	int min= array[0];//min=root
	swap(array[0], array[size-1]);//last element is swapped with the root
	
	size--;//heap size is decreased coz root no longer belongs to the heap
	
	heapify(0);//the new root is heapified. This way there will be a new min root.
	
	
	return min;
}


template<class T>
int minheap<T> :: heap_decrease_key(int element_position, int new_value)
{
	if(size < 1)
	{
		return INT_MIN; // size less than 1
	}
	
	if(element_position > size-1)
	{
		return size ; // Position greater than heap size
	}
	
	if(element_position < 0)
	{
		return -1; // Position less than zero		
	}
	
	if(new_value > array[element_position])//if an attempt to increase the value of the element
	{
		return heap_increase_key(element_position, new_value);
	}
	
	array[element_position]=new_value;
	
	int parent_position=(element_position+1>>1)-1;


	while((array[parent_position] > array[element_position]) && (parent_position>=0))
	{
		swap(array[parent_position], array[element_position]);
		element_position = parent_position;
		parent_position=(parent_position-1)>>1;
	} 
	return 0;
}

template<class T>
int minheap<T> :: heap_increase_key(int element_position, int new_value)
{
	if(size < 1)
	{
		return INT_MIN; // size less than 1
	}
	
	if(element_position > size-1)
	{
		return size; // position greater than heap size
	}
	
	if(element_position < 0)
	{
		return -1; // position less than 0		
	}
	
	if(new_value < array[element_position]) //if an attempt to decrease the value of the element
	{
		return heap_decrease_key(element_position, new_value); 
	}
	
	array[element_position]=new_value;
	
	heapify(element_position);
}

template<class T>
int minheap<T> :: heap_sort(T *output_array)
{
	if(size < 1)
	{
		return INT_MIN; // size less than 1
	}
	
	
	int max_loop_count=size; //extract_min will decrease 'size' each time
	
	for (int i=0; i<max_loop_count; i++)
	{
		output_array[i]=extract_min();
	}
	
	
}


template<class T>
int minheap<T>::show_element(int element_position)
{
	if(element_position>size-1)
	{
		return size; // Position greater  than heap size.
	}
	
	return array[element_position];
}


#endif