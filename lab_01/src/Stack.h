#ifndef Stack_h
#define Stack_h

#include <iostream>
using namespace std;


struct Stack
{
	explicit Stack(int nsize)
	{
		if (nsize < 0)
		{
			throw invalid_argument("Neverno");
		}
		else
		{
			size = nsize;
			mass = new int[nsize];
		}
	};

	Stack()
	{
		size = 0;
		mass = new int[size];
	}

	~Stack()
	{
		delete[] mass;
	}


	void Out();
	void Push( int b1);
	void Pop();
	int Peek();
	int Count();
	void Negative();
	void Range( int d1, int f1);
	void Fill();

	bool operator<(const Stack& b); // comparison functions
	bool operator>(const Stack& b);
	bool operator==(const Stack& b);
	bool operator!=(const Stack& b);
	bool operator<=(const Stack& b);
	bool operator>=(const Stack& b);
	

private:
	int* mass{ nullptr };
	size_t size{ 0 };


};

void Stack::Fill()
{

	for (size_t i = 0; i < size; i++)
	{
		cin >> mass[i];
	}
}

void Stack::Out()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
};

void Stack::Push( int b1)
{
	size++;
	auto* newMass = new int[size];
	for (size_t i = 0; i < size-1; i++)
	{
		newMass[i] = mass[i];
	}
	newMass[size-1] = b1;
	delete[] mass;
	mass = newMass;
}

void Stack::Pop()
{
	if (size <= 0)
	{
		throw out_of_range("Neverno");
	}
	else
	{
		size--;
		auto* newMass = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			newMass[i] = mass[i];
		}
		delete[] mass;
		mass = newMass;
	}
}

int Stack::Peek()
{
	if (size > 0)
	{
		return mass[size - 1];
	}
	else
	{
		throw out_of_range("Neverno");
	}
}

int Stack::Count()
{
	return size;
}

void Stack::Negative()
{
	size_t s = 0;
	size_t z = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (mass[i] < 0) s++;
	}

	auto* newMass = new int[size - s];
	for (size_t i = 0; i < size; i++)
	{

		if (mass[i] > 0)
		{
			newMass[z] = mass[i];
			z++;
		}
	}
	delete[] mass;
	mass = newMass;
	size = size - s;
}

void Stack::Range( int left, int right)
{
	size_t RangeCount = 0;
	size_t z = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((mass[i] >= left) && (mass[i] <= right))
		{
			RangeCount++;
		}
	}
	size -= RangeCount;
	auto* newMass = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		if ((mass[i + z] >= left) && (mass[i + z] <= right))
		{
			z++;
			i--;
		}
		else
			newMass[i] = mass[i + z];

	}
	delete[] mass;
	mass = newMass;
}

bool Stack::operator<(const Stack& b)
{
	if (size > b.size)
	{
		size_t ss = 0;

		do
		{
			if (mass[ss] < b.mass[ss]) return true;

			else if (mass[ss] > b.mass[ss]) return false;

			ss++;

		} while (ss < b.size);
	}
	else if (size <= b.size)
	{
		size_t ss = 0;
		do
		{
			if (mass[ss] < b.mass[ss]) return true;

			if (mass[ss] > b.mass[ss]) return false;

			ss++;

		} while (ss < size);
		if (size < b.size) return true;
	}
	return false;
}

bool Stack::operator>(const Stack& b)
{
	if (size >= b.size)
	{
		size_t ss = 0;

		do
		{
			if (mass[ss] < b.mass[ss]) return false;

			else if (mass[ss] > b.mass[ss]) return true;

			ss++;

		} while (ss < b.size);
		if (size > b.size) return true;
	}
	else if (size < b.size)
	{
		size_t ss = 0;
		do
		{
			if (mass[ss] < b.mass[ss]) return false;

			else if (mass[ss] > b.mass[ss]) return true;

			ss++;

		} while (ss < size);
	}
	return false;
}
bool Stack::operator==(const Stack& b)
{
	if (size == b.size)
	{
		size_t ss = 0;
		do
		{
			if (mass[ss] != b.mass[ss]) return false;
			ss++;

		} while (ss < size);
		return true;
	}
	else return false;
}

bool Stack::operator!=(const Stack& b)
{
	return !(*this == b);
}

bool Stack::operator<=(const Stack& b)
{
	return !(*this > b);
}

bool Stack::operator>=(const Stack& b)
{
	return !(*this < b);
}

#endif
