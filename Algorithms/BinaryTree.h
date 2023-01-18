#pragma once
#include <iostream>


template<class T>
class BSTNode
{
public:
	BSTNode()
		: m_LeftNode(nullptr), m_RightNode(nullptr), m_Value(NULL)
	{

	}

	BSTNode(T value)
		: m_Value(value), m_LeftNode(nullptr), m_RightNode(nullptr)
	{

	}

	void SetLeftNode(BSTNode* node) { m_LeftNode = node; }
	void SetRightNode(BSTNode* node) { m_RightNode = node; }
	void SetValue(T value) { m_Value = value; }

	T GetValue() { return m_Value; }
	BSTNode* GetLeftNode() { return m_LeftNode; }
	BSTNode* GetRightNode() { return m_RightNode; }

public:
	T m_Value;

private:
	

	BSTNode* m_LeftNode;
	BSTNode* m_RightNode;
};




template<class T>
class BinarySearchTree
{
public:
	BinarySearchTree()
		: m_Size(0), m_Root(nullptr)
	{

	}

	BinarySearchTree(T value)
		: m_Size(0), m_Root(new BSTNode<T>(value))
	{
	
	}

	void PushBack(T value);
	void Remove(T value);

	void Print();
	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();
	void PrintBackwards();



	bool Search(T value);
	int Size() { return m_Size; }

private:

	void RightRotation();
	void LeftRotation();
	void Deletify(BSTNode<T>* p, BSTNode<T>* previous, BSTNode<T>* d, int value, int height);
	void PrintUtil(BSTNode<T>* root, int space);
	void PrintInOrderUtil(BSTNode<T>* node, int* i);
	void PrintPreOrderUtil(BSTNode<T>* node, int* i);
	void PrintPostOrderUtil(BSTNode<T>* node, int* i);
	void PrintBackwardsUtil(BSTNode<T>* node, int* i);
	void MemCopy(T* A, T* B);

	BSTNode<T>* GetRoot() { return m_Root; }
private:
	int m_Size;
	BSTNode<T>* m_Root;
};

template<class T>
void BinarySearchTree<T>::PushBack(T value)
{
	if (GetRoot() == nullptr)
	{
		m_Root = new BSTNode<T>(value);
		m_Size++;
		return;
	}

	BSTNode<T>* p = GetRoot();

	bool inserted = false;
	int height{};
	while (!inserted)
	{
		if (value >= p->GetValue())
		{
			if (p->GetRightNode() == nullptr)
			{
				BSTNode<T>* t = new BSTNode<T>(value);
				p->SetRightNode(t);
				inserted = true;
				m_Size++;
			}
			else
			{
				p = p->GetRightNode();
			}
			height++;
		}
		else 
		{
			if (p->GetLeftNode() == nullptr)
			{
				BSTNode<T>* t = new BSTNode<T>(value);
				p->SetLeftNode(t);
				inserted = true;
				m_Size++;
			}
			else
			{
				p = p->GetLeftNode();
			}
			height++;
		}
	}



	int minheight = log2(Size());

	if (height - minheight > 0)
	{
		if (value >= GetRoot()->GetValue())
		{
			LeftRotation();
		}
		else
		{
			RightRotation();
		}
	}
	
}

template<class T>
void BinarySearchTree<T>::Remove(T value)
{
	BSTNode<T>* p = GetRoot();

	if (p->GetValue() == value)
	{
		Deletify(m_Root, nullptr, m_Root, value, 0);

	}

	BSTNode<T>* previous = new BSTNode<T>();
	int height{};

	bool found = false;
	while (!found)
	{
		if (value >= p->GetValue())
		{
			
			if (p->GetRightNode() == nullptr)
			{
				return;
			}
			else
			{
				if (p->GetRightNode()->GetValue() == value)
				{
					previous = p;
					found = true;
				}
				height++;
				p = p->GetRightNode();
			}
		}
		else if (value < p->GetValue())
		{
			if (p->GetLeftNode() == nullptr)
			{
				return;
			}
			else
			{
				if (p->GetLeftNode()->GetValue() == value)
				{
					previous = p;
					found = true;
				}
				height++;
				p = p->GetLeftNode();
				
			}
		}
	}

	Deletify(p, previous, p, value, height);




}

template<class T>
void BinarySearchTree<T>::Print()
{

	PrintUtil(m_Root, 0);
}

template<class T>
void BinarySearchTree<T>::PrintUtil(BSTNode<T>* _root, int _space)
{

	if (_root == NULL)
		return;

	BSTNode<T>* root = _root;
	int space = _space;

	space += 10;


	PrintUtil(root->GetRightNode(), space);


	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	std::cout << root->GetValue() << std::endl;


	PrintUtil(root->GetLeftNode(), space);
}

template<class T>
void BinarySearchTree<T>::PrintInOrder()
{
	int* i = new int{};
	PrintInOrderUtil(m_Root, i);
}



template<class T>
void BinarySearchTree<T>::PrintInOrderUtil(BSTNode<T>* node, int* _i)
{
	int* i = _i;
	if (node == nullptr)
	{
		return;
	}

	if (*i % 10 == 0 && *i != 0)
	{
		std::cout << std::endl;
	}

	PrintInOrderUtil(node->GetLeftNode(), i);

	*i = *i + 1;
	std::cout << node->GetValue() << ", ";

	PrintInOrderUtil(node->GetRightNode(), i);
}


template<class T>
void BinarySearchTree<T>::PrintPreOrder()
{
	int* i = new int{};
	PrintPreOrderUtil(m_Root, i);
}



template<class T>
void BinarySearchTree<T>::PrintPreOrderUtil(BSTNode<T>* node, int* _i)
{
	int* i = _i;
	if (node == nullptr)
	{
		return;
	}

	if (*i % 10 == 0 && *i != 0)
	{
		std::cout << std::endl;
	}

	*i = *i + 1;
	std::cout << node->GetValue() << ", ";


	PrintPreOrderUtil(node->GetLeftNode(), i);
	PrintPreOrderUtil(node->GetRightNode(), i);


}



template<class T>
void BinarySearchTree<T>::PrintPostOrder()
{
	int* i = new int{};
	PrintPostOrderUtil(m_Root, i);
}


template<class T>
void BinarySearchTree<T>::PrintPostOrderUtil(BSTNode<T>* node, int* _i)
{
	int* i = _i;
	if (node == nullptr)
	{
		return;
	}

	PrintPostOrderUtil(node->GetLeftNode(), i);
	PrintPostOrderUtil(node->GetRightNode(), i);

	if (*i % 10 == 0 && *i != 0)
	{
		std::cout << std::endl;
	}

	*i = *i + 1;
	std::cout << node->GetValue() << ", ";

}



template<class T>
void BinarySearchTree<T>::PrintBackwards()
{
	int* i = new int{};
	PrintBackwardsUtil(m_Root, i);
}


template<class T>
void BinarySearchTree<T>::PrintBackwardsUtil(BSTNode<T>* node, int* _i)
{
	int* i = _i;
	if (node == nullptr)
	{
		return;
	}

	if (*i % 10 == 0 && *i != 0)
	{
		std::cout << std::endl;
	}

	PrintBackwardsUtil(node->GetRightNode(), i);

	*i = *i + 1;
	std::cout << node->GetValue() << ", ";

	PrintBackwardsUtil(node->GetLeftNode(), i);


}

template<class T>
bool BinarySearchTree<T>::Search(T value)
{
	BSTNode<T>* p = GetRoot();

	if (p->GetValue() == value)
	{
		return true;
	}


	while (true)
	{

		if (p->GetValue() == value)
		{
			return true;
		}
		if (value >= p->GetValue())
		{

			if (p->GetRightNode() == nullptr)
			{
				return false;
			}
			else
			{
				p = p->GetRightNode();

			}
		}
		else if (value < p->GetValue())
		{
			if (p->GetLeftNode() == nullptr)
			{
				return false;
			}
			else
			{
				p = p->GetLeftNode();

			}
		}
	}

}

template<class T>
void BinarySearchTree<T>::RightRotation()
{
	BSTNode<T>* A = GetRoot();
	BSTNode<T>* B = A->GetLeftNode();

	BSTNode<T>* T1 = B->GetLeftNode();
	BSTNode<T>* T2 = B->GetRightNode();
	BSTNode<T>* T3 = A->GetRightNode();

	m_Root = B;
	m_Root->SetLeftNode(T1);
	m_Root->SetRightNode(A);
	A->SetLeftNode(T2);
	A->SetRightNode(T3);

}

template<class T>
void BinarySearchTree<T>::LeftRotation()
{
	BSTNode<T>* A = GetRoot();
	BSTNode<T>* B = A->GetRightNode();

	BSTNode<T>* T1 = A->GetLeftNode();
	BSTNode<T>* T2 = B->GetLeftNode();
	BSTNode<T>* T3 = B->GetRightNode();


	m_Root = B;
	m_Root->SetLeftNode(A);
	m_Root->SetRightNode(T3);
	A->SetLeftNode(T1);
	A->SetRightNode(T2);
}

template<class T>
void BinarySearchTree<T>::Deletify(BSTNode<T>* _p, BSTNode<T>* _previous, BSTNode<T>* _d, int value, int _height)
{
	BSTNode<T>* p = _p;
	BSTNode<T>* previous = _previous;
	BSTNode<T>* d = _d;

	int children{};
	int height = _height;

	if (p->GetLeftNode() != nullptr)
	{
		children++;
	}
	if (p->GetRightNode() != nullptr)
	{
		children++;
	}

	switch (children)
	{
	case 0:
		if (previous == nullptr)
		{
			delete p;
			m_Size--;
			return;
		}
		if (previous->GetLeftNode() != nullptr)
		{
			if (previous->GetLeftNode()->GetValue() == d->GetValue() || previous->GetLeftNode()->GetValue() == value)
			{
				previous->SetLeftNode(nullptr);
				delete p;
				m_Size--;

				int minheight = log2(Size());

				if (height - minheight > 0)
				{
					if (value >= GetRoot()->GetValue())
					{
						LeftRotation();
					}
					else
					{
						RightRotation();
					}
				}
			}
		}
		if (previous->GetRightNode() != nullptr)
		{
			if (previous->GetRightNode()->GetValue() == d->GetValue() || previous->GetRightNode()->GetValue() == value)
			{
				previous->SetRightNode(nullptr);
				delete p;
				m_Size--;

				int minheight = log2(Size());

				if (height - minheight > 0)
				{
					if (value >= GetRoot()->GetValue())
					{
						LeftRotation();
					}
					else
					{
						RightRotation();
					}
				}
			}
		}
		break;
	case 1:
		if (previous == nullptr)
		{
			if (p->GetLeftNode() != nullptr)
			{
				p->SetValue(p->GetLeftNode()->GetValue());
				previous = p;
				p = p->GetLeftNode();
				previous->SetLeftNode(nullptr);
				delete p;
				m_Size--;
				return;
			}
			else if (p->GetRightNode() != nullptr)
			{
				p->SetValue(p->GetRightNode()->GetValue());
				previous = p;
				p = p->GetRightNode();
				previous->SetRightNode(nullptr);
				delete p;
				m_Size--;
				return;
			}

		}
		if (p->GetRightNode() != nullptr)
		{
			if (previous->GetLeftNode() != nullptr)
			{
				if (previous->GetLeftNode()->GetValue() == d->GetValue() || previous->GetLeftNode()->GetValue() == value)
				{
					previous->SetLeftNode(p->GetRightNode());
					delete p;
					m_Size--;

					int minheight = log2(Size());

					if (height - minheight > 0)
					{
						if (value >= GetRoot()->GetValue())
						{
							LeftRotation();
						}
						else
						{
							RightRotation();
						}
					}
				}
			}
			if (previous->GetRightNode() != nullptr)
			{
				if (previous->GetRightNode()->GetValue() == d->GetValue() || previous->GetRightNode()->GetValue() == value)
				{
					previous->SetRightNode(p->GetRightNode());
					delete p;
					m_Size--;

					int minheight = log2(Size());

					if (height - minheight > 0)
					{
						if (value >= GetRoot()->GetValue())
						{
							LeftRotation();
						}
						else
						{
							RightRotation();
						}
					}
				}
			}
		}
		else if (p->GetLeftNode() != nullptr)
		{
			if (previous->GetLeftNode() != nullptr)
			{
				if (previous->GetLeftNode()->GetValue() == d->GetValue() || previous->GetLeftNode()->GetValue() == value)
				{
					previous->SetLeftNode(p->GetLeftNode());
					delete p;
					m_Size--;

					int minheight = log2(Size());

					if (height - minheight > 0)
					{
						if (value >= GetRoot()->GetValue())
						{
							LeftRotation();
						}
						else
						{
							RightRotation();
						}
					}
				}
			}
			if (previous->GetRightNode() != nullptr)
			{
				if (previous->GetRightNode()->GetValue() == d->GetValue() || previous->GetRightNode()->GetValue() == value)
				{
					previous->SetRightNode(p->GetLeftNode());
					delete p;
					m_Size--;

					int minheight = log2(Size());

					if (height - minheight > 0)
					{
						if (value >= GetRoot()->GetValue())
						{
							LeftRotation();
						}
						else
						{
							RightRotation();
						}
					}
				}
			}
		}
		break;
	case 2:
		previous = p;
		p = p->GetRightNode();
		while (p->GetLeftNode() != nullptr)
		{
			previous = p;
			p = p->GetLeftNode();
			height++;
		}
		d->SetValue(p->GetValue());
		Deletify(p, previous, d, value, height);

		break;
	default:
		break;
	}
}



template<class T>
void BinarySearchTree<T>::MemCopy(T* A, T* B)
{
	T Temp = *A;
	*A = *B;
	*B = Temp;
}


