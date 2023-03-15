#include <iostream>
#include <ctime>

/*
	
	Task 2.
		Declare a pointer on the array of type integer and allocated memory for 12 elements.
		Necessary write a function which swap place pair and odd elements in the array.

*/

void SwapElements(int* ptrArr, const int sizePtrArr);

int main()
{
	srand(time(nullptr));

	const int sizePtrArr = 12;
	int* ptrArr = new int[sizePtrArr];

	for (int index = 0; index < sizePtrArr; index++)
		ptrArr[index] = rand() % 10 + 1;

	std::cout << "Array: ";
	for (int index = 0; index < sizePtrArr; index++)
		std::cout << ptrArr[index] << " ";

	SwapElements(ptrArr, sizePtrArr);

	std::cout << "Swapped array: ";
	for (int index = 0; index < sizePtrArr; index++)
		std::cout << ptrArr[index] << " ";

	delete[] ptrArr;
	ptrArr = 0;

	return 0;
}

void SwapElements(int* ptrArr, const int sizePtrArr)
{
	for (int index = 0; index < sizePtrArr; index++)
	{
		if(index % 2 == 0)
		{
			int temp = ptrArr[index];
			ptrArr[index] = ptrArr[index + 1];
			ptrArr[index + 1] = temp;
		}
	}

	std::cout << std::endl;
}
