#include "SimpleVector.h"

//************************************************************************
// The Default Constructor for SimpleVector class. Sets the size of the  *
// array and allocates memory for it.                                    *
//************************************************************************
template<class T>
SimpleVector<T>::SimpleVector()
{
	aptr = 0; arraySize = 0;
}

//************************************************************
// Constructor for SimpleVector class. Sets the size of the  *
// array and allocates memory for it.                        *
//************************************************************
template < class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template < class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;

	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//**************************************************
// Destructor for the SimpleVector Class           *
//**************************************************
template < class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}

//**************************************************
// Accessor for the arraySize attribute            *
//**************************************************
template<class T>
int SimpleVector<T>::size() const
{
	return arraySize;
}

template<class T>
void SimpleVector<T>::push_back(T item)
{
	SimpleVector<T> copy(*this);

	aptr = new T[arraySize + 1];

	arraySize += 1;

	for (int i = 0; i < copy.arraySize(); i++)
	{
		aptr[i] = copy[i];
	}
	
	aptr[arraySize] = item;

}

//*****************************************************
// The pop_back function accept no argument           *
// and remove the last element from the array         *
//*****************************************************
template<class T>
void SimpleVector<T>::pop_back()
{
	SimpleVector temp(*this);

	aptr = new T[arraySize - 1];

	arraySize -= 1;

	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = temp[i];
	}
}

//*****************************************************
// The linear search function                         *
//*****************************************************
template<class T>
int SimpleVector<T>::search(T item)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (aptr[i] == item)
			return i;
	}

	return -1;
}

//********************************************************
// memError function. Displays an error message and      *
// terminates the program when memory allocation fails.  *
//********************************************************
template < class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//************************************************************
// subError function. Displays an error message and          *
 // terminates the program when a subscript is out of range.  *
 //************************************************************
template < class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the        *
// subcript in the array.                               *
//*******************************************************
template < class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//********************************************************
// Overloaded [] operator. The argument is a subscript.  *
// This function returns a reference to the element      *
// in the array indexed by the subscript.                *
//********************************************************
template < class T>
T& SimpleVector<T>::operator[](const int& sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}