#pragma once

#include "LinkedList.h"
#include <vector>
#include "DataBaseTables.h"
#include "DynamicArray.h"


template <class T, class V>
class HashTable
{
public:
	HashTable<T, V>();
	HashTable<T, V>(int value);

	void PushBack(V value);
	void Remove(V value);

	void Print();
	void PrintFruitsTable();

	void BubbleSort();
	void SelectionSort();
	void MergeSort();
	void QuickSort();
	void HeapSort();

	void Randomize(int min, int max);

	// Main search
	bool Search(V value);

private:
	int HashFunction(int x) const;
	int HashFunction(Fruits x) const;
private:
	int m_Bucket;
	std::vector<T> m_BucketList;

};

template<class T, class V>
HashTable<T, V>::HashTable()
	: m_Bucket(0), m_BucketList(0)
{
}

template<class T, class V>
HashTable<T, V>::HashTable(int value)
	: m_Bucket(value), m_BucketList(value)
{
	
}

template<class T, class V>
void HashTable<T, V>::PushBack(V value)
{
	int index = HashFunction(value);
	m_BucketList[index].PushBack(value);
}

template<class T, class V>
void HashTable<T, V>::Remove(V value)
{
	int index = HashFunction(value);
	m_BucketList[index].Remove(value);
}


template<class T, class V>
void HashTable<T, V>::Print()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		std::cout << "----- Bucket Nr. " << i << " -----" << std::endl;
		m_BucketList[i].Print();
		std::cout << "------------------------" << std::endl;
	}
}

template<class T, class V>
void HashTable<T, V>::PrintFruitsTable()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		std::cout << "----- Bucket Nr. " << i << " -----" << std::endl;
		m_BucketList[i].PrintFruitsTable();
		std::cout << "------------------------" << std::endl;
	}
}

template<class T, class V>
void HashTable<T, V>::BubbleSort()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].BubbleSort();
	}
}

template<class T, class V>
void HashTable<T, V>::SelectionSort()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].SelectionSort();
	}
}

template<class T, class V>
void HashTable<T, V>::MergeSort()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].MergeSort(0, m_BucketList[i].Size() - 1);
	}
}

template<class T, class V>
void HashTable<T, V>::QuickSort()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].QuickSort(0, m_BucketList[i].Size() - 1);
	}
}

template<class T, class V>
void HashTable<T, V>::HeapSort()
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].HeapSort();
	}
}

template<class T, class V>
void HashTable<T, V>::Randomize(int min, int max)
{
	size_t size = m_BucketList.size();


	for (size_t i{}; i < size; i++)
	{
		m_BucketList[i].Randomize(min, max);
	}
}

template<class T, class V>
bool HashTable<T, V>::Search(V value)
{
	int index = HashFunction(value);

	return m_BucketList[index].Search(value);
}



template<class T, class V>
int HashTable<T, V>::HashFunction(int x) const
{
	return x % m_Bucket;
}

template<class T, class V>
int HashTable<T, V>::HashFunction(Fruits x) const
{
	return (x.GetName()[0] - 13) % m_Bucket;
}
