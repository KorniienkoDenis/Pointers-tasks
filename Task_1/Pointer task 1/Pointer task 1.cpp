#include <iostream>
#include <ctime>

/*
	
	Task 1.
		Declare a pointer on the array of type double and offer
		the user choose it size. Next write four functions:
			1. The first must allocate memory for the array;
			2. The second - fill the array elements;
			3. The third - show data in the console;
			4. The fourth - to free memory;
		A program must proposes the user continue the work
		(created new dynamic arrays) or exit from the program.

*/

double* AllocateMemory(double* ptrArr, int sizePtr);
void FillArray(double* ptrArr, int sizePtr);
void ShowArray(double* ptrArr, int sizePtr);
double* ToFreeMemory(double* ptrArr);

int main()
{
	srand(time(nullptr));

	double* arr = 0;
	char userAnswer;
	
	do
	{
		int sizeOfArray = 0;

		std::cout << "Input size of the array: ";
		std::cin >> sizeOfArray;

		arr = AllocateMemory(arr, sizeOfArray);

		FillArray(arr, sizeOfArray);
		ShowArray(arr, sizeOfArray);

		arr = ToFreeMemory(arr);

		std::cout << std::endl;
		std::cout << "Continue (1). Exit (0): ";
		std::cin >> userAnswer;

	} while (userAnswer != '0');

	return 0;
}

double* AllocateMemory(double* ptrArr, int sizePtr)
{
	ptrArr = new double[sizePtr];
	return ptrArr;
}

void FillArray(double* ptrArr, int sizePtr)
{
	for (int index = 0; index < sizePtr; index++)
		ptrArr[index] = rand() % 10 + 1;
}

void ShowArray(double* ptrArr, int sizePtr)
{
	std::cout << "Dynamic array: ";

	for (int index = 0; index < sizePtr; index++)
		std::cout << ptrArr[index] << " ";

	std::cout << std::endl;
}

double* ToFreeMemory(double* ptrArr)
{
	delete[] ptrArr;
	ptrArr = 0;

	return ptrArr;
}
