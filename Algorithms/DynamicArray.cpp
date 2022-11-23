#include "DynamicArray.h"
#include <iostream>

template<class T>
void DynamicArray<T>::Insert(int index, T data)
{
	if (index > Size() - 1)
	{
		std::cout << "That index does not exist" << std::endl;
	}
	else
	{
		m_Array[index] = data;
	}
}

template<class T>
void DynamicArray<T>::PushBack(T data)
{

}

template<class T>
T DynamicArray<T>::GetData(int index)
{
	if (index > Size() - 1)
	{
		std::cout << "That index does not exist" << std::endl;
		return NULL;
	}
	else
	{
		return m_Array[index];
	}

	
}

template<class T>
void DynamicArray<T>::MemMove(T Source, int Index)
{
}

template<class T>
void DynamicArray<T>::MemMove(T* Destination, T* Source, size_t size)
{
}

template<class T>
void DynamicArray<T>::Print()
{
	int tens{};
	for (int i{}; i < Size() / 10; i++)
	{
		for (int j{}; j < 10; i++)
		{
			std::cout << m_Array[i * 10 + j] << ", ";
		}
		std::cout << std::endl;
		tens++;
	}
	for (int i{}; i < Size() % 10; i++)
	{
		std::cout << m_Array[tens * 10 + i] << ", ";
	}
	std::cout << std::endl;
}
