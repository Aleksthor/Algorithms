#pragma once
#include <iostream>

class Fruits;

template <class T>
class LinkedListNode
{
public:
	LinkedListNode<T>()
		: m_NextNode(NULL), m_PreviousNode(NULL)
	{

	}
	LinkedListNode<T>(T Data, LinkedListNode<T>* next, LinkedListNode<T>* previous)
		: m_Data(Data), m_NextNode(next), m_PreviousNode(previous)
	{

	}
	


	void SetData(T data) { m_Data = data; }
	void SetNext(LinkedListNode<T>* next) { m_NextNode = next; }
	void SetPrevious(LinkedListNode<T>* previous) { m_PreviousNode = previous; }

	T GetData() { return m_Data; }
	LinkedListNode<T>* GetNext() { return m_NextNode; }
	LinkedListNode<T>* GetPrevious() { return m_PreviousNode; }
public:
	T m_Data;
private:
	LinkedListNode<T>* m_NextNode;
	LinkedListNode<T>* m_PreviousNode;

};


template <class T>
class DoubleLinkedList
{
public:
	DoubleLinkedList<T>()
		: m_Head(new LinkedListNode<T>()), m_Tail(new LinkedListNode<T>()), m_Size(0)
	{
		m_Head = m_Tail;
	}

	void PushBack(T data);
	void InsertAt(int index, T data);
	void Change(int index, T data);

	void RemoveLast();
	void RemoveFirst();
	void RemoveAt(int index);
	void Remove(T data);

	T GetData(int index);
	int Size() { return m_Size; }

	void Print();
	void PrintBackwards();
	void PrintFruitsTable();

	void BubbleSort();
	void SelectionSort();
	void MergeSort(int const begin, int const end);
	void QuickSort(int low, int high);
	void HeapSort();
	void Randomize(int low, int high);

	bool Search(T value);
private:
	void Merge(int const left, int const mid, int const right);
	int Partition(int low, int high);
	void Heapify(int n, int index);

	void MemCopy(T* A, T* B);

	LinkedListNode<T>* GetHead() { return m_Head; }
	LinkedListNode<T>* GetTail() { return m_Tail; }
	LinkedListNode<T>* GetNode(int index);
private:
	int m_Size;
	LinkedListNode<T>* m_Head;
	LinkedListNode<T>* m_Tail;
};

template<class T>
void DoubleLinkedList<T>::PushBack(T data)
{
	if (m_Head == m_Tail && Size() == 0)
	{
		LinkedListNode<T>* newNode = new LinkedListNode<T>(data, NULL, NULL);
		m_Head = newNode;
		m_Tail = newNode;
		m_Size++;
		return;
	}
	if (m_Head == m_Tail)
	{
		LinkedListNode<T>* newNode = new LinkedListNode<T>(data, NULL, m_Head);
		m_Tail = newNode;
		m_Head->SetNext(m_Tail);
		m_Size++;
		return;
	}

	LinkedListNode<T>* p = GetTail();

	LinkedListNode<T>* newNode = new LinkedListNode<T>(data, NULL, p);
	m_Tail = newNode;
	p->SetNext(m_Tail);
	m_Size++;
}

template<class T>
void DoubleLinkedList<T>::InsertAt(int index, T data)
{
	LinkedListNode<T>* p = GetHead();
	int i = 0;

	if (index == 0)
	{
		LinkedListNode<T>* newNode;
		if (m_Tail == m_Head)
		{
			newNode = new LinkedListNode<T>(data, NULL, NULL);
			m_Head = newNode;
			m_Tail = newNode;
		}
		else
		{
			newNode = new LinkedListNode<T>(data, p, NULL);
			m_Head = newNode;
		}
		
		m_Size++;
		return;
	}
	

	while (p->GetNext() != NULL && i < index - 1)
	{
		i++;
		p = p->GetNext();
	}


	if (p->GetNext() == NULL)
	{
		LinkedListNode<T>* newNode = new LinkedListNode<T>(data, NULL, p);
		m_Tail = newNode;
		p->SetNext(newNode);
		m_Size++;
		return;
	}

	LinkedListNode<T>* newNode = new LinkedListNode<T>(data, p->GetNext(), p);
	p->GetNext()->SetPrevious(newNode);
	p->SetNext(newNode);
	m_Size++;

}

template<class T>
void DoubleLinkedList<T>::Change(int index, T data)
{
	LinkedListNode<T>* p = GetHead();
	int i = 0;

	while (i < index && p != NULL)
	{

		i++;
		p = p->GetNext();
	}
	if (p != NULL)
	{
		p->SetData(data);
	}
}

template<class T>
void DoubleLinkedList<T>::RemoveLast()
{
	LinkedListNode<T>* p = GetTail();
	m_Tail = p->GetPrevious();
	m_Tail->SetNext(NULL);
	delete p;
	m_Size--;
}

template<class T>
void DoubleLinkedList<T>::RemoveFirst()
{
	LinkedListNode<T>* p = GetHead();
	if (p->GetNext() != NULL)
	{
		m_Head = p->GetNext();
		m_Head->SetPrevious(NULL);
		delete p;
		m_Size--;
		return;
	}
	delete p;
	m_Head = new LinkedListNode<T>();
	m_Tail = m_Head;
	m_Size--;

}

template<class T>
void DoubleLinkedList<T>::RemoveAt(int index)
{
	//If index == 0, remove the first node
	if (index == 0)
	{
		RemoveFirst();
		return;
	}

	LinkedListNode<T>* t = GetHead();
	int i = 0;

	//Find next index
	while (t != NULL && i < index)
	{
		i++;
		t = t->GetNext();
	}
	if (t == NULL)
	{
		return;
	}

	//Remove the node at last index
	if (t->GetNext() == NULL)
	{
		RemoveLast();
		return;
	}

	LinkedListNode<T>* n = t->GetNext();
	LinkedListNode<T>* p = t->GetPrevious();
	n->SetPrevious(p);
	p->SetNext(n);

	delete t;
	m_Size--;
}

template<class T>
void DoubleLinkedList<T>::Remove(T data)
{
	LinkedListNode<T>* t = GetHead();

	int i{};
	bool removeNode = false;
	while (t->GetNext() != NULL)
	{
		removeNode = false;
		if (t->GetData() == data)
		{
			//Remove the first node
			if (i == 0)
			{
				RemoveFirst();
			}
			else
			{
				//Remove the last node
				if (t->GetNext() == NULL)
				{
					RemoveLast();
				}

				//Remove the node at any other index
				else
				{
					LinkedListNode<T>* n = t->GetNext();
					LinkedListNode<T>* p = t->GetPrevious();

					n->SetPrevious(p);
					p->SetNext(n);

					removeNode = true;
				}
			}
		}

		if (removeNode)
		{
			LinkedListNode<T>* d = t;
			t = t->GetNext();

			delete d;
			m_Size--;
		}
		else
		{
			t = t->GetNext();
		}

		i++;
	}


	//Remove the last node
	if (t->GetNext() == NULL)
	{
		if (t->GetData() == data)
		{
			RemoveLast();
		}
	}
}

template<class T>
T DoubleLinkedList<T>::GetData(int index)
{
	LinkedListNode<T>* p = GetHead();
	int i{};

	while (p != NULL && i < index)
	{
		i++;
		p = p->GetNext();
	}
	if (p != NULL)
		return p->GetData();

	return NULL;
}

template<class T>
LinkedListNode<T>* DoubleLinkedList<T>::GetNode(int index)
{
	LinkedListNode<T>* p = GetHead();
	int i{};

	while (p != NULL && i < index)
	{
		i++;
		p = p->GetNext();
	}
	if (p != NULL)
		return p;

	return NULL;
}

template<class T>
void DoubleLinkedList<T>::Print()
{
	LinkedListNode<T>* p = GetHead();

	int i{};
	while (p != NULL)
	{
		if (i % 10 == 0 )
		{
			std::cout << std::endl;
		}
		if (i % 100 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
		std::cout << p->GetData() << ", ";

		i++;
		p = p->GetNext();
	}


	std::cout << std::endl << std::endl;

	std::cout << "Size" << Size() << std::endl;
}

template<class T>
void DoubleLinkedList<T>::PrintBackwards()
{
	LinkedListNode<T>* p = GetTail();

	int i{};
	while (p != NULL)
	{
		if (i % 10 == 0)
		{
			std::cout << std::endl;
		}
		if (i % 100 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << p->GetData() << ", ";

		i++;
		p = p->GetPrevious();
	}

	std::cout << "" << std::endl;
	std::cout << "Size" << Size() << std::endl;
}

template<class T>
void DoubleLinkedList<T>::PrintFruitsTable()
{
	LinkedListNode<T>* p = GetHead();

	int i{};
	while (p != NULL)
	{
		if (i % 10 == 0)
		{
			std::cout << std::endl;
		}
		if (i % 100 == 0 && i != 0)
		{
			std::cout << std::endl;
		}

		T fruit = p->GetData();

		if (Size() > 0)
			std::cout << "(" << fruit.GetName() << ", " << fruit.GetIndex() << ")";

		i++;
		p = p->GetNext();
	}


	std::cout << std::endl << std::endl;

	std::cout << "Size" << Size() << std::endl;
}

template<class T>
void DoubleLinkedList<T>::BubbleSort()
{
	LinkedListNode<T>* p = GetHead();
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		p = GetHead();
		for (int j = 0; j < size - i - 1; j++)
		{
			LinkedListNode<T>* n = p->GetNext();
			if (p->GetData() > n->GetData())
			{
				MemCopy(&p->m_Data, &n->m_Data);
			}
			p = p->GetNext();
		}
	}
}

template<class T>
void DoubleLinkedList<T>::SelectionSort()
{
	LinkedListNode<T>* p = GetHead();
	int size = Size();
	for (int i = 0; i < size; i++)
	{
		p = GetHead();
		LinkedListNode<T>* best = p;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (p->GetData() > best->GetData())
			{
				best = p;
			}

			p = p->GetNext();
		}
		if (p->GetData() > best->GetData())
		{
			best = p;
		}
		MemCopy(&p->m_Data, &best->m_Data);
		
	}

}

template<class T>
void DoubleLinkedList<T>::MergeSort(int const begin, int const end)
{
	// exit point
	if (begin >= end) { return; }

	auto mid = (begin + (end - begin) / 2);

	MergeSort(begin, mid);
	MergeSort(mid + 1, end);
	Merge(begin, mid, end);

}


template<class T>
void DoubleLinkedList<T>::Merge(int const left, int const mid, int const right)
{
	auto const RightArraySize = mid - left + 1;
	auto const LeftArraySize = right - mid;

	DoubleLinkedList<T> LeftLinkedList = DoubleLinkedList<int>();
	DoubleLinkedList<T> RightLinkedList = DoubleLinkedList<int>();

	// Copy into temp arrays
	for (int i{}; i < LeftArraySize; i++)
	{
		LeftLinkedList.InsertAt(i, GetData(i + mid + 1));
	}
	for (int i{}; i < RightArraySize; i++)
	{
		RightLinkedList.InsertAt(i, GetData(i + left));
	}


	auto LeftArrayIndex = 0;
	auto RightArrayIndex = 0;
	int MergeArrayIndex = left;

	while (LeftArrayIndex < LeftArraySize && RightArrayIndex < RightArraySize)
	{
		if (LeftLinkedList.GetData(LeftArrayIndex) <= RightLinkedList.GetData(RightArrayIndex))
		{
			Change(MergeArrayIndex, LeftLinkedList.GetData(LeftArrayIndex++));
		}
		else
		{
			Change(MergeArrayIndex, RightLinkedList.GetData(RightArrayIndex++));
		}

		MergeArrayIndex++;
	}
	while (LeftArrayIndex < LeftArraySize)
	{
		Change(MergeArrayIndex++, LeftLinkedList.GetData(LeftArrayIndex++));
	}
	while (RightArrayIndex < RightArraySize)
	{
		Change(MergeArrayIndex++, RightLinkedList.GetData(RightArrayIndex++));
	}

}


template<class T>
void DoubleLinkedList<T>::QuickSort(int low, int high)
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
int DoubleLinkedList<T>::Partition(int low, int high)
{
	/**
	Index High of array is saved as pivot point
	If any index of the partition is bigger than the pivot, swap position between i and
	Also swap Pivot to where its supposed to be
	Return new position of Pivot
*/

	int i = low - 1;
	T Pivot = GetData(high);

	for (int j = low; j <= high - 1; j++)
	{
		if (GetData(j) < Pivot)
		{
			i++;
			LinkedListNode<T>* a = GetNode(j);
			LinkedListNode<T>* b = GetNode(i);
			MemCopy(&a->m_Data, &b->m_Data);
		}
	}
	LinkedListNode<T>* a = GetNode(high);
	LinkedListNode<T>* b = GetNode(i + 1);
	MemCopy(&a->m_Data, &b->m_Data);
	return i + 1;
}

template<class T>
void DoubleLinkedList<T>::HeapSort()
{
	int size = Size();
	for (int i = size / 2 + 1; i >= 0; i--)
	{
		Heapify(size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		LinkedListNode<T>* a = GetNode(0);
		LinkedListNode<T>* b = GetNode(i);
		MemCopy(&a->m_Data, &b->m_Data);
		Heapify(i, 0);
	}
}

template<class T>
void DoubleLinkedList<T>::Heapify(int n, int index)
{
	int max = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < n && GetData(left) > GetData(max))
	{
		max = left;
	}
	if (right < n && GetData(right) > GetData(max))
	{
		max = right;
	}

	if (max != index)
	{
		LinkedListNode<T>* a = GetNode(index);
		LinkedListNode<T>* b = GetNode(max);
		MemCopy(&a->m_Data, &b->m_Data);
		Heapify(n, max);
	}
}

template<class T>
void DoubleLinkedList<T>::Randomize(int low, int high)
{
	int size = Size();
	LinkedListNode<T>* p = GetHead();

	for (int i{}; i < size - 1; i++)
	{
		p->SetData(std::rand() % (high - low) + low);
		p = p->GetNext();
	}
	p->SetData(std::rand() % (high - low) + low);
}

template<class T>
bool DoubleLinkedList<T>::Search(T value)
{
	LinkedListNode<T>* p = GetHead();

	while (p != NULL)
	{
		T data = p->GetData();
		if (data == value)
		{
			return true;
		}
		p = p->GetNext();
	}
	return false;
}



template<class T>
void DoubleLinkedList<T>::MemCopy(T* A, T* B)
{

	T Temp = *A;
	*A = *B;
	*B = Temp;

}


