#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class TestScores
{
private:
    int *scorePtr;
    int arraySize;
    int averageScore;

public:
    // Exception class
    class OutOfRange
    {
    private:
        int errScore;

    public:
        OutOfRange(int subscript)
        {
            errScore = subscript;
        }

        int getErrSubscript() const
        {
            return errScore; 
        }
    };

    TestScores(int);
    TestScores(const TestScores &);
    ~TestScores();

    // Accessor function
    void calcAverage();

    // Mutator function
    int getAverageScore() const
    {
        return averageScore; 
    }

    // Overloaded operator functions
    const TestScores operator = (const TestScores &);
    int &operator [](const int &sub);
};

