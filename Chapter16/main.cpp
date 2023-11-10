//Hung Anh Ho
//11-9-2023
//Chapter 17

#include<iostream>
#include "input.h"
#include <vector>
#include "TestScores.h"
#include "SimpleVector.h"
#include "SimpleVector.cpp"
#include "SearchVect.h"

using namespace std;
int menuOption();
void Challenge3();
void Challenge4();
void Challenge6();

void Challenge7();
void evalScores(TestScores &, const int);

void Challenge8();

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0: exit(1); break;
		case 3: Challenge3(); break;
		case 4: Challenge4(); break;
		case 6: Challenge6(); break;
		case 7: Challenge7(); break;
		case 8: Challenge8(); break;
			// case 12: Challenge12(); break; //10 pts extra
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}



int menuOption()
{
	system("cls");
	cout << "\n\tChapter 16 - assignments";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\t3. challenge 3 - Maximun/ Minimum";
	cout << "\n\t3. challenge 4 - Absolute value";
	cout << "\n\t6. challenge 6 - In Array";
	cout << "\n\t7. challenge 7 - TestScores Class";
	cout << "\n\t8. challenge 8 - SimpleVector Modification";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\t0. exit";
	cout << "\n\t" << string(60, char(196));

	return inputInteger("\n\toption: ", 0, 12);
}

//precondition: datatype MUST support '>' operator
//postcondition: return the 'larger' of x or y
template <class T>
T maximum(T x, T y)
{
	return x > y ? x : y;
}

//precondition: datatype MUST support '<' operator
//postcondition: return the 'smaller' of x or y
template <class T>
T minimum(T x, T y)
{
	return x < y ? x : y;
}

void Challenge3()
{
	int x = inputInteger("\nEnter an x int value: ");
	int y = inputInteger("\nEnter an y int value: ");
	cout << "\nmaximum: " << maximum(x, y);
	cout << "\nminimum: " << maximum(x, y);


	double dx = inputDouble("\nEnter an x double value: ");
	double dy = inputDouble("\nEnter an y double value: ");
	cout << "\nmaximum: " << maximum(dx, dy);
	cout << "\nminimum: " << maximum(dx, dy);


	string sx = inputString("\nEnter an x string value: ", false);
	string sy = inputString("\nEnter an y string value: ", false);
	cout << "\nmaximum: " << maximum(sx, sy);
	cout << "\nminimum: " << maximum(sx, sy);
}

//precondition: datatype MUST support '>' operator
//postcondition: return the 'larger' of x or y
template <class T>
T absoluteValue(T x)
{
	return abs(x);
}

void Challenge4()
{
	int x = inputDouble("\nEnter an x value: ");
	cout << "\nAbsolute value of" << x << ": " << absoluteValue(x);
}

//template<class T>
class Array
{
private:
	vector<int> array;

public:
	class outOfBound
	{};
	Array()
	{
		array.clear();
	}

	//input new value slot
	void insert(int value)
	{
		array.push_back(value);
	}

	//Set new value
	void setValue(int value, int index)
	{
		array[index] = value;
	}

	//Return value with index
	int getValue(int index) const
	{
		if (index < 0 || index > array.size() - 1)
			throw outOfBound();
		else
			return array[index];
	}

	//display array
	void display() const
	{
		for (int i = 0; i < array.size(); i++)
			cout << array[i] << '\n';
	}

	//Friend function to display
	friend ostream& operator<<(ostream& out, const Array& obj)
	{
		try
		{
			int index = inputInteger("\nEnter an index: ");
			out << "at : " << obj.getValue(index) << '\n';
		}
		catch (Array::outOfBound)
		{
			out << "\nYou just access an out-of-bound element from the vector.\n";
		}

		return out;
	}
	
};


void Challenge6()
{
	Array test;
	test.insert(666);
	test.insert(111);
	test.insert(777);
	test.insert(888);
	test.display();

	//Test print
	cout << test;
}


void Challenge7()
{
	const int SIZE = 5;
	const int studentNumber = 3;
	double   score = 0.0;

	const string studentNames[studentNumber]{ "Jimmy", "Thanh", "Babayaga" };

	TestScores scoreArr(SIZE);

	cout << "\n\tSanta ana college's average score calculator\n\n";

	for (int index = 0; index < studentNumber; index++)
	{
		cout << "\n\tStudent Name: " << studentNames[index] << "\n\n";

		for (int count = 0; count < SIZE; count++)
		{
			cout << "\n\tTest-Score #" << (count + 1) << "\n";
			scoreArr[count] = inputInteger("Enter score:", 0, 100);
		}

		evalScores(scoreArr, SIZE);

		cout << "\n\tThe average score of this student is: " << scoreArr.getAverageScore() << "\n";
	}

	cout << "\n";
}


//precondition: accepts obj &, const int
//postcondition: return catched error for invalid score
void evalScores(TestScores &scoreArr, const int size)
{
	bool tryAgain = true;

	while (tryAgain)
	{
		try
		{
			scoreArr.calcAverage();
			tryAgain = false;
		}
		catch (TestScores::OutOfRange score)
		{
			cout << "\nInvalid Score: " << scoreArr[score.getErrSubscript()] << "\n";
			scoreArr[score.getErrSubscript()] = inputInteger("Enter a valid score: ", 0, 100);
		}
	}
}

void Challenge8()
{
	const int SIZE = 10;
	SimpleVector<int> intTable(SIZE);
	SimpleVector<double> doubleTable(SIZE);

	// Store values in the vectors.
	for (int x = 0; x < SIZE; x++)
	{
		intTable[x] = (x * 2);
		doubleTable[x] = (x * 2.14);
	}
	// Display the values in the vectors.
	cout << "These values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << " ";
	cout << "\n";

	cout << "These values are in doubleTable:\n";

	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << " ";
	cout << "\n";

	// Now search for values in the vectors.
	int result;
	cout << "Searching for 6 in intTable.\n";

	result = intTable.search(6);

	if (result == -1)
		cout << "6 was not found in intTable.\n";
	else
		cout << "6 was found at subscript " << result << "\n";

	cout << "Searching for 12.84 in doubleTable.\n";

	result = doubleTable.search(12.84);

	if (result == -1)
		cout << "12.84 was not found in doubleTable.\n";
	else
		cout << "12.84 was found at subscript " << result << "\n";
}