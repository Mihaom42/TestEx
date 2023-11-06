// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.

void StartApp(const vector<int> NumberVector)
{
	vector<int> DiffVector = GetDifferences(NumberVector);

	if (AreTheElementsSame(DiffVector))
	{
		Func1(NumberVector, DiffVector);
	}
	else
	{
		Func2(NumberVector, DiffVector);
	}
}

vector<int> GetDifferences(const vector<int> NumberVector)
{
	vector<int> Differences;

	for (int i = 1; i < NumberVector.size(); i++)
	{
		Differences.push_back(NumberVector[i] - NumberVector[i - 1]);
	}

	return Differences;
}

bool AreTheElementsSame(const vector<int> Numbers)
{
	if (equal(Numbers.begin() + 1, Numbers.end(), Numbers.begin()))
	{
		return true;
	}

	return false;
}


void Func1(const vector<int> NumberVector, const vector<int> Differences)
{
	vector<int> FinalVector;
	int DiffSum = 0;

	for (int i = 0; i < Differences.size() - 1; i++)
	{
		DiffSum += Differences[i];
		FinalVector.push_back(NumberVector[NumberVector.size() - 1] + DiffSum);	
	}

	OutputResult(FinalVector);
}

void Func2(const vector<int> NumberVector, const vector<int> Differences)
{
	int LastDiffElem = Differences[Differences.size() - 1];
	vector<int> DiffVector = GetDifferences(Differences);

	vector<int> FinalVector = FillFinalVector(NumberVector, DiffVector, FinalVector, LastDiffElem);

	OutputResult(FinalVector);
}

vector<int> FillFinalVector(const vector<int> NumberVector, const vector<int> DiffVector, vector<int> FinalVector, int LastDiffElem)
{
	int Elem = NumberVector[NumberVector.size() - 1];
	int DiffSum = 0;

	if (DiffVector.size() == 1)
	{
		DiffSum += DiffVector[0];
		Elem += LastDiffElem + DiffSum;

		FinalVector.push_back(Elem);

		return FinalVector;
	}

	for (int i = 0; i < DiffVector.size() - 1; i++)
	{
		DiffSum += DiffVector[i];
		Elem += LastDiffElem + DiffSum;

		FinalVector.push_back(Elem);
	}

	return FinalVector;
}

void OutputResult(const vector<int> FinalVector)
{
	cout << "\nOutput: ";

	if (FinalVector.size() == 1)
	{
		cout << FinalVector[0] << '\n';
		return;
	}

	for (int i = 0; i < FinalVector.size(); i++)
	{
		cout << FinalVector[i] << ' ';
	}

	cout << '\n';
}