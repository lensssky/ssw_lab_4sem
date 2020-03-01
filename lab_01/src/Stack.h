
#include <iostream>
using namespace std;

template <class T>
struct Stack
{

	int* mass;
	int size;

	Stack(int nsize)
	{
		mass = new int[nsize];
		size = nsize;
		for (int i = 0; i < size; i++)
		{
			cin >> mass[i];
			cout << ' ';
		}
	};
	void StackOut();
	void StackPush( int b1);
	void StackPop();
	short StackPeek();
	short StackCount();
	void StackPositive();
	void StackRange( int d1, int f1);
	void StackComparison(int*& masss, int& size2, int& size);


};
template <typename T>
void Stack<T>::StackOut()
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
};
template <typename T>
void Stack <T>::StackPush( int b1)
{
	size++;
	int* newMass = new int[size];
	for (int i = 0; i < size-1; i++)
	{
		newMass[i] = mass[i];
	}
	newMass[size-1] = b1;
	delete[] mass;
	mass = newMass;
}
template <typename T>
void Stack <T>::StackPop()
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
short Stack <T>::StackPeek()
{
	return mass[size - 1];
}
template <typename T>
short Stack <T>::StackCount()
{
	return size;
}
template <typename T>
void Stack <T>::StackPositive()
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
void Stack <T>::StackRange( int d1, int f1)
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
void Stack <T>::StackComparison(int*& masss, int& size2, int& size)
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


