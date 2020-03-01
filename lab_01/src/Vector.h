
#include <iostream>
using namespace std;

template <class T>
struct Vector
{

    int* mass;
	int size;

	Vector(int nsize)
	{
		mass = new int[nsize];
		size = nsize;
		for (int i = 0; i < size; i++)
		{
			cin >> mass[i];
			cout << ' ';
		}
	};
	void VectorOut();
	void VectorPush( int b1);
	void VectorPop();
	short VectorPeek();
	short VectorCount();
	short &  VectorAt(short c1);
	void VectorPositive();
	void VectorRange(int d1, int f1);
	void VectorComparison(int*& masss, int& size2, int& size);

	
};
template <typename T>
void Vector<T>::VectorOut()
{
	for (int i = 0; i < size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
};
template <typename T>
void Vector <T>::VectorPush( int b1)
{
	int* newMass = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newMass[i] = mass[i];
	}
	newMass[size] = b1;
	size++;
	delete[] mass;
	mass = newMass;
}
template <typename T>
void Vector <T>::VectorPop()
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
short Vector <T>::VectorPeek()
{
	return mass[size-1];
}
template <typename T>
short Vector <T>::VectorCount()
{
	return size;
}
template <typename T>
short & Vector <T>::VectorAt(short c1)
{
	return (short&)mass[c1-1 ];
}
template <typename T>
void Vector <T>::VectorPositive()
{
	int s = 0;
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		if  (mass[i] < 0) s++;
	}

	int* newMass = new int[size-s];
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
void Vector <T>::VectorRange( int d1, int f1)
{
	int z = 0;
	size =  (f1 - d1+1);
	int* newMass = new int[size];
	for (int i = d1-1; i < size; i++)
	{

			newMass[z] = mass[i];
			z++;
	
	}
	delete[] mass;
	mass = newMass;
}
template <typename T>
void Vector <T>::VectorComparison(int*& masss, int& size2, int& size)
{
	
	if (size > size2) size = size2;
	int q = size;
	int w = size;
	for (int i = size - 1; i >=0; i--)
		if (mass[i] > masss[i]) q = i;
			else if (mass[i] < masss[i]) w=i;
	if ((q == size) and (w == size)) cout << "Ravno";
	else if (q < w) cout << "1 bolshe";
	else cout << "2 bolshe";
}
