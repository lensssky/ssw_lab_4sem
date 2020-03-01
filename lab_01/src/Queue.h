
#include <iostream>
using namespace std;

template <class T>
struct Queue
{

	int* mass;
	int size;
	


	Queue(int nsize)
	{
		mass = new int[nsize];
		size = nsize;
		for (int i = 0; i < size; i++)
		{
			cin >> mass[i];
			cout << ' ';
		}
	};
	void QueueOut();
	void QueuePush( int b1);
	void QueuePop();
	short QueuePeek();
	short QueueCount();
	void QueuePositive();
	void QueueRange(int d1, int f1);
	void QueueComparison(int*& masss, int& size2, int& size);


};
template <typename T>
void Queue<T>::QueueOut()
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
};
template <typename T>
void Queue <T>::QueuePush( int b1)
{
	int* newMass = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newMass[i + 1] = mass[i];
	}
	newMass[0] = b1;
	size++;
	delete[] mass;
	mass = newMass;
}
template <typename T>
void Queue <T>::QueuePop()
{
	size--;
	int* newMass = new int[size];
	for (int i = 0; i < size; i++)
	{
		newMass[i] = mass[i];
	}
	delete[] mass;
	mass = newMass;
}
template <typename T>
short Queue <T>::QueuePeek()
{
	return mass[size - 1];
}
template <typename T>
short Queue <T>::QueueCount()
{
	return size;
}
template <typename T>
void Queue <T>::QueuePositive()
{
	int s = 0;
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < 0) s++;
	}

	int* newMass = new int[size - s];
	for (int i = 0; i < size; i++)
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
template <typename T>
void Queue <T>::QueueRange(int d1, int f1)
{
	int z = 0;
	size = (f1 - d1 + 1);
	int* newMass = new int[size];
	for (int i = d1 - 1; i < size; i++)
	{

		newMass[z] = mass[i];
		z++;

	}
	delete[] mass;
	mass = newMass;
}
template <typename T>
void Queue <T>::QueueComparison(int*& masss, int& size2, int& size)
{
	int q = -1;
	int w = -1;
	if (size > size2) size = size2;
	for (int i = size - 1; i > -1; i--)
		if (mass[i] > masss[i]) q = i;
		else if (mass[i] < masss[i]) w = i;
	if ((q == -1) and (w == -1)) cout << "Ravno";
	else if (q > w) cout << "1 bolshe";
	else cout << "2 bolshe";
}

