#include "TestScores.h"

//Sets the size of the array and allocates memory for it.
TestScores::TestScores(int size)
{
    averageScore = 0;

    arraySize = size;
    scorePtr = new int[size];

    for (int count = 0; count < arraySize; count++)
    {
        *(scorePtr + count) = 0;
    }
}

 //Copy Constructor  
TestScores::TestScores(const TestScores &obj)
{
    arraySize = obj.arraySize;
    scorePtr = new int[arraySize];

    for (int count = 0; count < arraySize; count++)
    {
        *(scorePtr + count) = *(obj.scorePtr + count);
    }
}

//Destructor
TestScores::~TestScores()
{
    if (arraySize > 0)
    {
        delete [] scorePtr;
    }
}

//function performs a self-assignment validation.
const TestScores TestScores::operator = (const TestScores &right)
{
    if (this != &right)
    {
        delete [] scorePtr;

        arraySize = right.arraySize;
        scorePtr = new int[arraySize];

        for (int count = 0; count < arraySize; count++)
        {
            *(scorePtr + count) = *(right.scorePtr + count);
        }
    }

    return *this;
}

/*
TestScores::calcAverage()
This function calculates the average of all test scores.
If a score is lower 0 or greater 100, the OutOfRange
exception is thrown. Otherwise the score is accumulated,
and the average score is calculated..
*/

void TestScores::calcAverage()
{
    int sumTotal = 0;

    for (int count = 0; count < arraySize; count++)
    {
        if (*(scorePtr + count) < 0 || *(scorePtr + count) > 100)
        {
            throw OutOfRange(count);
        }
        else
        {
            sumTotal += *(scorePtr + count);
        }
    }

    averageScore = (sumTotal / arraySize);
}

/*
Returns a reference to the element in the array indexed by the subscript.
 */

int &TestScores::operator [](const int &sub)
{
    return scorePtr[sub];
}

