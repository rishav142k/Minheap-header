# Minheap-header

This is a project in an attempt to extend the functionality of minHeap in C++ STL. This header file consists of various important functions such as update values, etc. This header file is made in C++. Another thing which is implemented here is the code is kept as generic as possible to enable the use of other user defined data types as well as built-in data types as well. See the detailed implementation of how to use the user defined data type is given in ```main_otherdatatypes.cpp```



Different functions of this header file : 

1. `void swap(T&, T&);`
<b>Swaps two nodes in heap. Private function. </b>


2.  `int insert(T element);`
<b>Insert an element in the heap</b>

3.  `int get_capacity();`
<b> Number of elements the heap can accomodate</b>

4.  `int get_size();`
<b>Number of elements already in the heap</b>

5.  `int extract_min();`
<b>Extracts minimum in the heap and heapifies the heap as well.</b>

6.  `int heap_decrease_key(int elem_position, int new_value);`
<b>Update element by a lower value in the heap</b>

7.  `int heap_increase_key(int elem_position, int new_value);`
<b>Update element by a higher value </b>

8.  `int heap_sort(T* array);`
<b> Sorts the array using heap sort and stores the result in the array provided in the parameter </b>

9.  `int show_element(int elem_position);`
<b>Displays element at a particular position</b>

10. `int heapify(int elem_position);`
<b> Heapifies the heap. Private function. </b>


Special attention is given to make the code readable and easy to follow.
Use of comments is also done to understand the funcitonality of each function.

