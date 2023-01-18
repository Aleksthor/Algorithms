#pragma once
#include "Defines.h"
#include "HashTable.h"
#include "PathfindingController.h"
#include "BinaryTree.h"



// ------- Time Management --------- //
#include <chrono> 
// --------------------------------- //



class NeuralNetwork;

class Application
{
public:
	Application();

	void Run();
	void Draw(float deltaTime);
	void Input();
	static Application* GetInstance() { return s_Instance; }

private:
	void Init();

	void PrintOptions(int i, float deltaTime);

	void PrintSorting();
	void PrintChangeLastValue();
	void FruitsHashTable();
	void SearchHashTable();
private:
	bool m_IsRunning = true;
	int m_CurrentPointerPos;
	static Application* s_Instance;


	DynamicArray<int> m_DynamicArray;
	DoubleLinkedList<int> m_LinkedList;
	HashTable<DoubleLinkedList<int>, int> m_LLHashTable;
	HashTable<DynamicArray<int>, int> m_DAHashTable;
	HashTable<BinarySearchTree<int>, int> m_BSTHashTable;
	
	HashTable<DoubleLinkedList<Fruits>, Fruits> m_FruitTable;
	PathfindingController m_PathfindController;
	NeuralNetwork* m_NeuralNetwork;
	BinarySearchTree<int> m_BST;

	int m_ArraySize;
	int m_Options;
	float deltaTime;

	TimePoint m_LastFrameTime;

	bool m_DijkstraFound;
	TimePoint m_DijkstraStart;


};
