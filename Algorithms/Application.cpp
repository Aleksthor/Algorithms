#pragma once
#include "Application.h"
#include <conio.h>
#include "NeuralNetwork.h"


Application* Application::s_Instance = nullptr;


Application::Application()
{
	s_Instance = this;
	m_CurrentPointerPos = 7;

	m_DynamicArray = DynamicArray<int>();
	m_LinkedList = DoubleLinkedList<int>();
	m_LLHashTable = HashTable<DoubleLinkedList<int>, int>(5);
	m_DAHashTable = HashTable<DynamicArray<int>, int>(5);
	m_BSTHashTable = HashTable<BinarySearchTree<int>, int>(5);


	m_FruitTable = HashTable<DoubleLinkedList<Fruits>, Fruits>(2);
	
	m_BST = BinarySearchTree<int>();

	m_PathfindController = PathfindingController(20, 20);
	m_NeuralNetwork = new NeuralNetwork();

	m_ArraySize = 20;
	m_Options = 12;
	m_DijkstraFound = false;
	Init();
}


void Application::Run()
{
	while (m_IsRunning)
	{
		// DeltaTime
		TimePoint time = SteadyClock_Now;
		float deltaTime = GetMicroSeconds(time, m_LastFrameTime) / 1000000.f;
		m_LastFrameTime = time;



		if (m_PathfindController.GetIsDijkstraRunning())
		{
			m_DijkstraFound = m_PathfindController.RunningDijsktra();
			
			startprint "" endprint << "Delta Time : " << deltaTime << " Seconds " endprint;

			if (m_DijkstraFound)
			{
				TimePoint DjikstraDone = SteadyClock_Now;
				startprint "Total Time : " << GetMicroSeconds(DjikstraDone, m_DijkstraStart) / 1000000.f << " Seconds " endprint;
				m_PathfindController.Print();
				system("pause");
			}
		}
		else
		{
			system("cls");
			Draw(deltaTime);
			Input();
		}

		

		
	}
}


void Application::Draw(float deltaTime)
{
	for (int i{}; i < m_Options; i++)
	{
		if (m_CurrentPointerPos == i)
		{
			std::cout << "->";
			PrintOptions(i, deltaTime);

		}
		else
		{
			std::cout << "  ";
			PrintOptions(i, deltaTime);
		}
		
	}

}


void Application::Input()
{
	int input = _getch();
	
	switch (input)
	{
	case Key_W:
		m_CurrentPointerPos = m_CurrentPointerPos - 1;
		if (m_CurrentPointerPos == -1)
		{
			m_CurrentPointerPos = m_Options - 1;
		}
		break;
	case Key_S:
		m_CurrentPointerPos = m_CurrentPointerPos + 1 ;
		if (m_CurrentPointerPos == m_Options)
		{
			m_CurrentPointerPos = 0;
		}
		break;
	case Key_w:
		m_CurrentPointerPos = m_CurrentPointerPos - 1;
		if (m_CurrentPointerPos == -1)
		{
			m_CurrentPointerPos = m_Options - 1;
		}
		break;
	case Key_s:
		m_CurrentPointerPos = m_CurrentPointerPos + 1;
		if (m_CurrentPointerPos == m_Options)
		{
			m_CurrentPointerPos = 0;
		}
		break;
	case Key_Enter:
		switch (m_CurrentPointerPos)
		{
		case 0:
			PrintSorting();
			system("pause");
			break;
		case 1:
			PrintChangeLastValue();
			system("pause");
			break;
		case 2:
			m_DynamicArray.Print();
			system("pause");
			break;
		case 3:
			m_LinkedList.Print();
			system("pause");
			break;
		case 4:
			startprint "LinkedList Hashtable  :" endprint endprint;
			m_LLHashTable.Print();


			startprint "DynamicArray Hashtable:" endprint endprint;
			m_DAHashTable.Print();

			startprint "Binary Search Tree Hashtable:" endprint endprint;
			m_BSTHashTable.Print();
			system("pause");
			break;
		case 5:
			m_DynamicArray.QuickSort(0, m_DynamicArray.Size());
			m_LinkedList.SelectionSort();
			m_LLHashTable.SelectionSort();
			m_DAHashTable.QuickSort();
			break;
		case 6:
			m_DynamicArray.Randomize(10,100);
			m_LinkedList.Randomize(10,100);
			break;
		case 7:
			FruitsHashTable();
			system("pause");
			break;
		case 8:
			SearchHashTable();
			system("pause");
			break;
		case 9:
			m_DijkstraStart = SteadyClock_Now;
			m_PathfindController.StartDijkstra();
			break;
		case 10:
			startprint "The Neural Network Guessed: " << m_NeuralNetwork->WhatNumberAmI() endprint;
			system("pause");
			break;
		case 11:
			m_IsRunning = false;
			break;
		default:
			break;

		}
		break;
	default:
		startprint "Input: " << input endprint;
		break;
	}
}


void Application::Init()
{
	for (int i{}; i < m_ArraySize; i++)
	{
		m_DynamicArray.PushBack(std::rand() % (100 - 10) + 10);
		m_LinkedList.PushBack(std::rand() % (100 - 10) + 10);
		m_LLHashTable.PushBack(std::rand() % (100 - 10) + 10);
		m_DAHashTable.PushBack(std::rand() % (100 - 10) + 10);
		m_BSTHashTable.PushBack(std::rand() % (100 - 10) + 10);
	}


	m_FruitTable.PushBack(Fruits("Banana", 1));
	m_FruitTable.PushBack(Fruits("Mango", 5));
	m_FruitTable.PushBack(Fruits("Pineapple", 15));
	m_FruitTable.PushBack(Fruits("Apple", 3));
	m_FruitTable.PushBack(Fruits("Pear", 4));
	m_FruitTable.PushBack(Fruits("Grape", 2));


	m_BST.PushBack(10);
	m_BST.PushBack(12);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(20);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(30);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(40);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(35);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(25);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(15);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(50);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(45);
	m_BST.Print();
	startprint "" endprint endprint endprint endprint;
	m_BST.PushBack(60);


	m_BST.Print();
	m_BST.PrintInOrder();
	startprint "" endprint;
	m_BST.PrintPreOrder();
	startprint "" endprint;
	m_BST.PrintPostOrder();
	startprint "" endprint;
	m_BST.PrintBackwards();
	system("pause");
}

void Application::PrintOptions(int i, float deltaTime)
{
	switch (i)
	{
	case 0:
		startprint "Sorting Timers       |" << "Size : " << m_ArraySize endprint;
		break;
	case 1:
		if (deltaTime > 20)
		{
			startprint "Change Last Value    |" << "Delta Time : " << deltaTime << " seconds" << "(LOL slow much?)" endprint;
		}
		else
		{
			startprint "Change Last Value    |" << "Delta Time : " << deltaTime << " seconds" endprint;
		}
		

		break;
	case 2:
		startprint "Print Dynamic Array  |" endprint;
		break;
	case 3:
		startprint "Print Linked List    |" endprint;
		break;
	case 4:
		startprint "Print Hash Table     |" endprint;
		break;
	case 5:
		startprint "Sort All             |" endprint;
		break;
	case 6:
		startprint "Randomize All        |" endprint;
		break;
	case 7:
		startprint "Fruits HashTable     |" endprint;
		break;
	case 8:
		startprint "Search HashTables    |" endprint;
		break;
	case 9:
		startprint "Dijkstra             |" endprint;
		break;
	case 10:
		startprint "Test Neural Network  |" endprint;
		break;
	case 11:
		startprint "Exit Application     |" endprint;
		break;
	default:
		startprint "" endprint ;
		break;

	}
	
}

void Application::PrintSorting()
{
	const int iterations = 20;

	int bubbleSortTotal{};
	int selectionSortTotal{};
	int mergeSortTotal{};
	int quickSortTotal{};
	int heapSortTotal{};


	for (int i{}; i < iterations; i++)
	{
		TimeFunction(bubbleSortStart, m_DynamicArray.BubbleSort(), bubbleSortEnd);
		bubbleSortTotal += (int)GetMicroSeconds(bubbleSortEnd, bubbleSortStart);
		m_DynamicArray.Randomize(10, 100);

		// Selection Sort
		TimeFunction(selectionSortStart, m_DynamicArray.SelectionSort(), selectionSortEnd);
		selectionSortTotal += (int)GetMicroSeconds(selectionSortEnd, selectionSortStart);
		m_DynamicArray.Randomize(10, 100);

		// Merge Sort
		TimeFunction(mergeSortStart, m_DynamicArray.MergeSort(0, m_DynamicArray.Size() - 1), mergeSortEnd);
		mergeSortTotal += (int)GetMicroSeconds(mergeSortEnd, mergeSortStart);
		m_DynamicArray.Randomize(10, 100);

		// Quick Sort
		TimeFunction(QuickSortStart, m_DynamicArray.QuickSort(0, m_DynamicArray.Size() - 1), QuickSortEnd);
		quickSortTotal += (int)GetMicroSeconds(QuickSortEnd, QuickSortStart);
		m_DynamicArray.Randomize(10, 100);

		// Heap Sort
		TimeFunction(heapSortStart, m_DynamicArray.HeapSort(), heapSortEnd);
		heapSortTotal += (int)GetMicroSeconds(heapSortEnd, heapSortStart);
		m_DynamicArray.Randomize(10, 100);
	}


	startprint "Dynamic Array BubbleSort Average   : " << bubbleSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array SelectionSort Average: " << selectionSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array MergeSort Average    : " << mergeSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array QuickSort Average    : " << quickSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array HeapSort Average     : " << heapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint " " endprint endprint;







	int LLbubbleSortTotal{};
	int LLselectionSortTotal{};
	int LLmergeSortTotal{};
	int LLquickSortTotal{};
	int LLheapSortTotal{};

	for (int i{}; i < iterations; i++)
	{
		TimeFunction(LinkedListBubbleSortStart, m_LinkedList.BubbleSort(), LinkedListBubbleSortEnd);
		m_LinkedList.Randomize(10, 100);
		LLbubbleSortTotal += (int)GetMicroSeconds(LinkedListBubbleSortEnd, LinkedListBubbleSortStart);

		TimeFunction(LinkedListSelectionSortStart, m_LinkedList.SelectionSort(), LinkedListSelectionSortEnd);
		m_LinkedList.Randomize(10, 100);
		LLselectionSortTotal += (int)GetMicroSeconds(LinkedListSelectionSortEnd, LinkedListSelectionSortStart);

		TimeFunction(LinkedListMergeSortStart, m_LinkedList.MergeSort(0, m_LinkedList.Size() - 1), LinkedListMergeSortEnd);
		m_LinkedList.Randomize(10, 100);
		LLmergeSortTotal += (int)GetMicroSeconds(LinkedListMergeSortEnd, LinkedListMergeSortStart);

		TimeFunction(LinkedListQuickSortStart, m_LinkedList.QuickSort(0, m_LinkedList.Size() - 1), LinkedListQuickSortEnd);
		m_LinkedList.Randomize(10, 100);
		LLquickSortTotal += (int)GetMicroSeconds(LinkedListQuickSortEnd, LinkedListQuickSortStart);

		TimeFunction(LinkedListHeapSortStart, m_LinkedList.HeapSort(), LinkedListHeapSortEnd);
		LLheapSortTotal += (int)GetMicroSeconds(LinkedListHeapSortEnd, LinkedListHeapSortStart);
		m_LinkedList.Randomize(10, 100);
	}

	startprint "LinkedList BubbleSort Average   : " << LLheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "LinkedList SelectionSort Average: " << LLselectionSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "LinkedList MergeSort Average    : " << LLmergeSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "LinkedList QuickSort Average    : " << LLquickSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "LinkedList HeapSort Average     : " << LLheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint " " endprint endprint;



	int HTbubbleSortTotal{};
	int HTselectionSortTotal{};
	int HTmergeSortTotal{};
	int HTquickSortTotal{};
	int HTheapSortTotal{};

	for (int i{}; i < iterations; i++)
	{
		TimeFunction(HTBubbleSortStart, m_LLHashTable.BubbleSort(), HTBubbleSortEnd);
		m_LLHashTable.Randomize(10, 100);
		HTbubbleSortTotal += (int)GetMicroSeconds(HTBubbleSortEnd, HTBubbleSortStart);

		TimeFunction(HTSelectionSortStart, m_LLHashTable.SelectionSort(), HTSelectionSortEnd);
		m_LLHashTable.Randomize(10, 100);
		HTselectionSortTotal += (int)GetMicroSeconds(HTSelectionSortEnd, HTSelectionSortStart);

		TimeFunction(HTMergeSortStart, m_LLHashTable.MergeSort(), HTMergeSortEnd);
		m_LLHashTable.Randomize(10, 100);
		HTmergeSortTotal += (int)GetMicroSeconds(HTMergeSortEnd, HTMergeSortStart);

		TimeFunction(HTQuickSortStart, m_LLHashTable.QuickSort(), HTQuickSortEnd);
		m_LLHashTable.Randomize(10, 100);
		HTquickSortTotal += (int)GetMicroSeconds(HTQuickSortEnd, HTQuickSortStart);

		TimeFunction(HTHeapSortStart, m_LLHashTable.HeapSort(), HTHeapSortEnd);
		HTheapSortTotal += (int)GetMicroSeconds(HTHeapSortEnd, HTHeapSortStart);
		m_LLHashTable.Randomize(10, 100);
	}

	startprint "Linked List HashTable BubbleSort Average   : " << HTheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Linked List HashTable SelectionSort Average: " << HTselectionSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Linked List HashTable MergeSort Average    : " << HTmergeSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Linked List HashTable QuickSort Average    : " << HTquickSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Linked List HashTable HeapSort Average     : " << HTheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint " " endprint endprint;



	int DAHTbubbleSortTotal{};
	int DAHTselectionSortTotal{};
	int DAHTmergeSortTotal{};
	int DAHTquickSortTotal{};
	int DAHTheapSortTotal{};

	for (int i{}; i < iterations; i++)
	{
		TimeFunction(DAHTBubbleSortStart, m_DAHashTable.BubbleSort(), DAHTBubbleSortEnd);
		m_DAHashTable.Randomize(10, 100);
		DAHTbubbleSortTotal += (int)GetMicroSeconds(DAHTBubbleSortEnd, DAHTBubbleSortStart);

		TimeFunction(DAHTSelectionSortStart, m_DAHashTable.SelectionSort(), DAHTSelectionSortEnd);
		m_DAHashTable.Randomize(10, 100);
		DAHTselectionSortTotal += (int)GetMicroSeconds(DAHTSelectionSortEnd, DAHTSelectionSortStart);

		TimeFunction(DAHTMergeSortStart, m_DAHashTable.MergeSort(), DAHTMergeSortEnd);
		m_DAHashTable.Randomize(10, 100);
		DAHTmergeSortTotal += (int)GetMicroSeconds(DAHTMergeSortEnd, DAHTMergeSortStart);

		TimeFunction(DAHTQuickSortStart, m_DAHashTable.QuickSort(), DAHTQuickSortEnd);
		m_DAHashTable.Randomize(10, 100);
		DAHTquickSortTotal += (int)GetMicroSeconds(DAHTQuickSortEnd, DAHTQuickSortStart);

		TimeFunction(DAHTHeapSortStart, m_DAHashTable.HeapSort(), DAHTHeapSortEnd);
		DAHTheapSortTotal += (int)GetMicroSeconds(DAHTHeapSortEnd, DAHTHeapSortStart);
		m_DAHashTable.Randomize(10, 100);
	}

	startprint "Dynamic Array HashTable BubbleSort Average   : " << DAHTheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array HashTable SelectionSort Average: " << DAHTselectionSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array HashTable MergeSort Average    : " << DAHTmergeSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array HashTable QuickSort Average    : " << DAHTquickSortTotal / iterations << " - MicroSeconds" endprint;
	startprint "Dynamic Array HashTable HeapSort Average     : " << DAHTheapSortTotal / iterations << " - MicroSeconds" endprint;
	startprint " " endprint endprint;

}

void Application::PrintChangeLastValue()
{
	TimeFunction(ArrayChangeStart, m_DynamicArray[m_DynamicArray.Size() - 1] = 100, ArrayChangeEnd);
	TimeFunction(LinkedListChangeStart, m_LinkedList.Change(m_LinkedList.Size() - 1, 100), LinkedListChangeEnd);

	startprint "Array Change : " << (int)GetNanoSeconds(ArrayChangeEnd, ArrayChangeStart) << " - NanoSeconds" endprint;
	startprint "Linked List Change : " << (int)GetNanoSeconds(LinkedListChangeEnd, LinkedListChangeStart) << " - NanoSeconds" endprint;
}

void Application::FruitsHashTable()
{
	m_FruitTable.PrintFruitsTable();
}

void Application::SearchHashTable()
{
	std::cout << "Did we find nr 50 ?       - "; 
	if (m_LLHashTable.Search(50))
	{ 
		std::cout << "YES" endprint; 
	}
	else 
	{ 
		std::cout << "NO" endprint; 
	}
	std::cout << "Did we find one Banana?   - ";
	if (m_FruitTable.Search(Fruits("Banana", 0)))
	{
		std::cout << "YES" endprint;
	}
	else
	{
		std::cout << "NO" endprint;
	}
}



Application* CreateApplication() { return new Application(); }