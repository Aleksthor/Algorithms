

template<class T>
class DynamicArray
{
public:
	DynamicArray()
	{

	}


	DynamicArray(int size)
		: m_Array(new T[size])
	{

	}


	int Size() { return sizeof(m_Array) / sizeof(T); }

	void Insert(int index, T data);
	void PushBack(T data);

	T GetData(int index);


	void MemMove(T Source, int Index);
	void MemMove(T* Destination, T* Source, size_t size);

	void Print();

private:

private:
	T* m_Array;


};


