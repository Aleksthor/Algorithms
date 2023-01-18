#include <iostream>

template<class T>
class DynamicArray
{
public:
	DynamicArray()
		: m_Size(0), m_Array(new T[0])
	{

	}


	DynamicArray(int size)
		: m_Array(new T[size]), m_Size(size)
	{

	}


	int Size() { return m_Size; }

	void Change(int index, T data);
	void InsertAt(int index, T data);
	void PushBack(T data);

	T GetData(int index);

	void RemoveLast();
	void RemoveAt(int index);
	void Remove(T data);

	void MemMove(T* Destination, T* Source, int size);

	void Print();

	void BubbleSort();
	void SelectionSort();
	void MergeSort(int const begin, int const end);
	void QuickSort(int low, int high);
	void HeapSort();

	void Randomize(T min, T max);



	T& operator[](int index)
	{
		if (index >= m_Size) 
		{
			std::cout << "Array index out of bound, exiting";
			exit(0);
		}
		return m_Array[index];
	}

private:
	void MemCopy(T* A, T* B);
	void MemCopy(int A, int B);

	void Merge(int const left, int const mid, int const right);
	int Partition(int low, int high);

	void Heapify(int n, int index);

private:
	T* m_Array;
	int m_Size;


};



template<class T>
void DynamicArray<T>::Change(int index, T data)
{
	if (index >= Size())
	{
		std::cout << "That index does not exist" << std::endl;
	}
	else
	{
		m_Array[index] = data;
	}
}

template<class T>
void DynamicArray<T>::InsertAt(int index, T data)
{

	int size = Size();
	if (index >= size)
	{
		std::cout << "Index is out of bounds" << std::endl;
		return;
	}

	T* Temp = new T[size + 1];

	int j{};
	for (int i{}; i < size + 1; i++)
	{
		if (i == index)
		{
			Temp[index] = data;
		}
		else
		{
			Temp[i] = m_Array[j];
			j++;
		}
	}


	delete[] m_Array;
	m_Array = Temp;
	m_Size++;
}

template<class T>
void DynamicArray<T>::PushBack(T data)
{
	int size = Size();
	T* Temp = new T[size + 1];

	for (int i{}; i < size; i++)
	{
		Temp[i] = m_Array[i];
	}
	Temp[size] = data;
	

	delete[] m_Array;
	m_Array = Temp;
	m_Size++;

}

template<class T>
T DynamicArray<T>::GetData(int index)
{
	return m_Array[index];
}



template<class T>
void DynamicArray<T>::RemoveLast()
{
	int size = Size();
	T* Temp = new T[size - 1];

	for (int i{}; i < size - 1; i++)
	{
		Temp[i] = m_Array[i];
	}

	delete[] m_Array;
	m_Array = Temp;
	m_Size--;

}

template<class T>
void DynamicArray<T>::RemoveAt(int index)
{
	int size = Size();
	if (index >= size)
	{
		std::cout << "Index does not exist" << std::endl;
		return;
	}


	T* Temp = new T[size - 1];

	int j{};
	for (int i{}; i < size; i++)
	{
	
		if (i != index)
		{
			Temp[j] = m_Array[i];
			j++;
		}

	}

	delete[] m_Array;
	m_Array = Temp;
	m_Size--;


}

template<class T>
void DynamicArray<T>::Remove(T data)
{
	int size = Size();
	int numOfElements{};
	for (int i{}; i < size; i++)
	{
		if (m_Array[i] == data)
		{
			numOfElements++;
		}
	}

	std::cout << "Removing " << numOfElements << " elements from array" << std::endl;
	std::cout << "Old array size: " << size << ", New array size: " << size - numOfElements << std::endl;

	T* Temp = new T[size - numOfElements];

	int j{};
	for (int i{}; i < size; i++)
	{

		if (m_Array[i] != data)
		{
			Temp[j] = m_Array[i];
			j++;
		}
	}

	delete[] m_Array;
	m_Array = Temp;
	m_Size -= numOfElements;

}



template<class T>
void DynamicArray<T>::Print()
{
	int size = Size();
	int tens{};
	if (size >= 10)
	{
		for (int i{}; i < size / 10; i++)
		{
			for (int j{}; j < 10; j++)
			{
				std::cout << m_Array[i * 10 + j] << ", ";
			}
			std::cout << std::endl;
			tens++;
		}
		if (tens % 10 == 0)
		{
			std::cout << std::endl << std::endl;
		}
	}
	for (int i{}; i < size % 10; i++)
	{
		std::cout << m_Array[tens * 10 + i] << ", ";
	}
	std::cout << std::endl;


	std::cout << "" << std::endl;
	std::cout << "Size" << size << std::endl;
}

template<class T>
void DynamicArray<T>::BubbleSort()
{
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (m_Array[j] > m_Array[j + 1])
			{
				MemCopy(&m_Array[j], &m_Array[j + 1]);
			}
		}
	}
}

template<class T>
void DynamicArray<T>::SelectionSort()
{
	int size = Size();

	int highest{};
	for (int i = 0; i < size; i++)
	{
		highest = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (m_Array[j] > m_Array[highest])
			{
				highest = j;
			}
		}
		MemCopy(&m_Array[highest], &m_Array[size - i - 1]);
	}
}

template<class T>
void DynamicArray<T>::MergeSort(int const begin, int const end)
{
	// exit point
	if (begin >= end) { return; }

	auto mid = (begin + (end - begin) / 2);

	MergeSort(begin, mid);
	MergeSort(mid + 1, end);
	Merge(begin, mid, end);
}

template<class T>
void DynamicArray<T>::Merge(int const left, int const mid, int const right)
{
	auto const RightArraySize = mid - left + 1;
	auto const LeftArraySize = right - mid;

	T* LeftArray = new T[LeftArraySize];
	T* RightArray = new T[RightArraySize];

	// Copy into temp arrays
	for (int i{}; i < LeftArraySize; i++)
	{
		LeftArray[i] = m_Array[i + mid + 1];
	}
	for (int i{}; i < RightArraySize; i++)
	{
		RightArray[i] = m_Array[i + left];
	}


	auto LeftArrayIndex = 0;
	auto RightArrayIndex = 0;
	int MergeArrayIndex = left;

	while (LeftArrayIndex < LeftArraySize && RightArrayIndex < RightArraySize)
	{
		if (LeftArray[LeftArrayIndex] <= RightArray[RightArrayIndex])
		{
			m_Array[MergeArrayIndex] = LeftArray[LeftArrayIndex++];
		}
		else
		{
			m_Array[MergeArrayIndex] = RightArray[RightArrayIndex++];
		}

		MergeArrayIndex++;
	}
	while (LeftArrayIndex < LeftArraySize)
	{
		m_Array[MergeArrayIndex++] = LeftArray[LeftArrayIndex++];
	}
	while (RightArrayIndex < RightArraySize)
	{
		m_Array[MergeArrayIndex++] = RightArray[RightArrayIndex++];
	}

	delete[] LeftArray;
	delete[] RightArray;
}

template<class T>
void DynamicArray<T>::QuickSort(int low, int high)
{
	if (low < high)
	{
		int PartitionIndex = Partition(low, high);

		// Sort Partition
		// PartitionIndex - 1 so we sort everything under the last pivot
		// PartitionIndex + 1 so we sort everything over the last pivot

		QuickSort(PartitionIndex + 1, high);
		QuickSort(low, PartitionIndex - 1);
	}
}

template<class T>
int DynamicArray<T>::Partition(int low, int high)
{
	/**
		Index High of array is saved as pivot point
		If any index of the partition is bigger than the pivot, swap position between i and
		Also swap Pivot to where its supposed to be
		Return new position of Pivot
	*/

	int i = low - 1;
	T Pivot = m_Array[high];

	for (int j = low; j <= high - 1; j++)
	{
		if (m_Array[j] < Pivot)
		{
			i++;
			MemCopy(j, i);
		}
	}
	MemCopy(&m_Array[high], &m_Array[i + 1]);
	return i + 1;
}

template<class T>
void DynamicArray<T>::HeapSort()
{
	int size = Size();
	for (int i = size / 2 + 1; i >= 0; i--)
	{
		Heapify(size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		MemCopy(&m_Array[0], &m_Array[i]);
		Heapify(i, 0);
	}
}


template<class T>
void DynamicArray<T>::Heapify(int n, int index)
{
	int max = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < n && m_Array[left] > m_Array[max])
	{
		max = left;
	}
	if (right < n && m_Array[right] > m_Array[max])
	{
		max = right;
	}

	if (max != index)
	{
		MemCopy(&m_Array[index], &m_Array[max]);
		Heapify(n, max);
	}
}




template<class T>
void DynamicArray<T>::MemCopy(T* A, T* B)
{

	T Temp = *A;
	*A = *B;
	*B = Temp;

}

template<class T>
void DynamicArray<T>::MemCopy(int A, int B)
{

	T Temp = m_Array[A];
	m_Array[A] = m_Array[B];
	m_Array[B] = Temp;

}

template<class T>
void DynamicArray<T>::MemMove(T* Destination, T* Source, int size)
{
	T* DestinationPointer = (T*)Destination;
	T* SourcePointer = (T*)Source;

	for (int i{}; i < size; i++)
	{
		DestinationPointer[i] = SourcePointer[i];
	}

}

template<class T>
void DynamicArray<T>::Randomize(T min, T max)
{
	int size = Size();
	for (int i{}; i < size; i++)
	{
		Change(i, std::rand() % (max - min) + min);
	}
}