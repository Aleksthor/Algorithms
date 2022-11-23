#include "DynamicArray.h"


void main()
{
	DynamicArray<int> IntArray = DynamicArray<int>(12);

	IntArray.Insert(0, 5);
	IntArray.Insert(1, 15);
	IntArray.Insert(2, 25);
	IntArray.Insert(3, 35);
	IntArray.Insert(4, 45);
	IntArray.Insert(5, 55);
	IntArray.Insert(6, 45);
	IntArray.Insert(7, 35);
	IntArray.Insert(8, 25);
	IntArray.Insert(9, 15);

	IntArray.Insert(10, 125);
	IntArray.Insert(11, 75);

	IntArray.Print();


}

