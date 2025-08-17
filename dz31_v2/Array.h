#pragma once
#include <iostream>
template <class T>

class Array
{
	T* m_array;
	int m_grow{};
	int m_capacity{};
	int m_size{};
public:
	Array(int size, int grow = 1) : m_size{ size },  m_grow { grow }
	{
		m_capacity = (size);
		m_array = new T[m_capacity]{};
	}


	void printArray()
	{
		for (int i{}; i < m_capacity; ++i)
		{
			std::cout << "Element [" << i << "]: " << m_array[i] << std::endl;
		}

	}
	int getSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		if (m_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void setSize(int capacity, int grow)
	{
		m_grow = grow;
		if (capacity > m_capacity)
		{
			resize(capacity+grow);
		}
		else if (capacity < m_capacity)
		{
			m_size = m_size < capacity ? m_size : capacity;
			T* newArr = new T[m_size]{};
			for (int i{}; i < m_size; ++i)
			{
				newArr[i] = m_array[i];
			}
			delete[] m_array;
			m_array = newArr;
			m_capacity = capacity;
		}
	}

	int getUpperBound()
	{
		return m_size - 1;
	}
	void freeExtra()
	{
		T* newArr = new T[m_size]{};
		for (int i{}; i < m_size; ++i)
		{
			newArr[i] = m_array[i];
		}
		delete[] m_array;
		m_array = newArr;
		m_capacity = m_size;

	}
	void removeAll()
	{
		m_size = 0; // Если просто m_size = 0, то при выводе массива все равно видно, что элементы не удалились
		for (int i{}; i < m_capacity; ++i)
		{
			m_array[i] = 0;
		} 
	}

	void addElement(T number)
	{
		if (m_size >= m_capacity)
		{
			resize(m_capacity+m_grow);
		}
		m_array[m_size] = number;
		++m_size;
	}
	void resize(int capacity)
	{
		T* newArr = new T[capacity]{};
		for (int i{}; i < m_size; ++i)
		{
			newArr[i] = m_array[i];
		}
		delete[] m_array;
		m_array = newArr;
		m_capacity = capacity;

	}

	int getCapacity()
	{
		return m_capacity;
	}
	int setAt(int index, T number)
	{
		if (index < 0 || index > m_capacity - 1)
		{
			std::cout << "Error! Index must be at least 0 and maximum of " << m_capacity - 1 << std::endl;
			return -1;
		}
		m_array[index] = number;
		return 0;
	}

	void append(Array& array1, Array& array2)
	{
		T* newArray = new T[array1.m_capacity + array2.m_capacity]{};
		for (int i{}; i < array1.m_size; ++i)
		{
			newArray[i] = array1.m_array[i];
		}
		for (int i = array1.m_size, j = 0; i < array1.m_size + array2.m_size && j < array2.m_size; ++i, ++j)
		{
			newArray[i] = array2.m_array[j];
		}
		delete[] array1.m_array;
		array1.m_array = newArray;
		array1.m_size += array2.m_size;
		array1.m_capacity += array2.m_capacity;
	}
	//T getAt(int index) // то же самое, что и T& operator[](int index)
	//{
	//	return m_array[index];
	//}
	T& operator[](int index)
	{
		return m_array[index];
	}
	void getData()
	{
		std::cout << "\nArray address: " << &m_array[0] << std::endl;

	}
	int insterAt(int index, T number)
	{
		if (index < 0 || index > m_capacity - 1)
		{
			std::cout << "Error! Index must be at least 0 and maximum of " << m_capacity - 1 << std::endl;
			return -1;
		}
		T* newArray = new T[m_capacity+=1]{};
		if (m_size >= index)
		{
			for (int i{}; i < index; ++i)
			{
				newArray[i] = m_array[i];
			}
			newArray[index] = number;
			for (int i = index+1, j = index; i < m_size+1 && j < m_size; ++i, ++j)
			{
				newArray[i] = m_array[j];
			}
		}
		delete[] m_array;
		m_array = newArray;
		++m_size;
		return 0;
	}
	int removeAt(int index)
	{
		if (index < 0 || index > m_size - 1)
		{
			std::cout << "Error! Index must be at least 0 and maximum of " << m_size - 1 << std::endl;
			return -1;
		}
		for (int i{ index }; i < m_size - 1 ; ++i)
		{
			m_array[i] = m_array[i + 1];
		}
		--m_size;
		return 0;
	}

	~Array()
	{
		delete[] m_array;
		m_array = nullptr;
	}
};

