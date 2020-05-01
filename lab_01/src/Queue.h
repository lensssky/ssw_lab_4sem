#ifndef Queue_h
#define Queue_h

#include <iostream>
using namespace std;

struct Queue
{
	explicit Queue(int nsize)
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

	Queue()
	{
		size = 0;
		mass = new int[size];
	}

	~Queue()
	{
		delete[] mass;
	}

	void Out();
	void Push(int b1);
	void Pop();
	int Peek();
	int Count();
	void Negative();
	void Range(int d1, int f1);
	void Fill();


	bool operator<(const Queue& b); // comparison functions
	bool operator>(const Queue& b);
	bool operator==(const Queue& b);
	bool operator!=(const Queue& b);
	bool operator<=(const Queue& b);
	bool operator>=(const Queue& b);

private:
	int* mass{ nullptr };
	size_t size{ 0 };

};
void Queue::Fill()
{

	for (size_t i = 0; i < size; i++)
	{
		cin >> mass[i];
	}
}

void Queue::Out()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
};
void Queue::Push( int b1)
{
	auto* newMass = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newMass[i] = mass[i];
	}
	newMass[size] = b1;
	size++;
	delete[] mass;
	mass = newMass;
}

void Queue::Pop()
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
			newMass[i] = mass[i + 1];
		}
		delete[] mass;
		mass = newMass;
	}
}

int Queue::Peek()
{
	return mass[0];
}

int Queue::Count()
{
	return size;
}

void Queue::Negative()
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

void Queue::Range(int left, int right)
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

bool Queue::operator<(const Queue& b)
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

bool Queue::operator>(const Queue& b)
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
bool Queue::operator==(const Queue& b)
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

bool Queue::operator!=(const Queue& b)
{
	return !(*this == b);
}

bool Queue::operator<=(const Queue& b)
{
	return !(*this > b);
}

bool Queue::operator>=(const Queue& b)
{
	return !(*this < b);
}


#endif
