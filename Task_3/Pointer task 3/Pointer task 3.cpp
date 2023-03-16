#include <iostream>
#include <ctime>

/*

	Task 3.
		Declare and fill a two-dimensional dynamic array random numbers from 10 to 50.
		Show it in the console. For fill and show in the console wrote separate functions.
		Count of rows and columns is chosen by the user.

*/

void FillArray(int** arr, int row, int column);
void ShowArray(int** arr, int row, int column);

int main()
{
	srand(time(nullptr));
	
	int countOfRow = 0;
	int countOfColumn = 0;

	std::cout << "Input count of row: ";
	std::cin >> countOfRow;

	std::cout << "Input count of column: ";
	std::cin >> countOfColumn;

	int** arr = new int* [countOfRow];

	for (int indexRow = 0; indexRow < countOfRow; indexRow++)
		arr[indexRow] = new int[countOfColumn];

	FillArray(arr, countOfRow, countOfColumn);

	std::cout << std::endl;

	ShowArray(arr, countOfRow, countOfColumn);

	for (int indexRow = 0; indexRow < countOfRow; indexRow++)
		delete[] arr[indexRow];

	delete[] arr;

	return 0;
}

void FillArray(int** arr, int row, int column)
{
	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			arr[indexRow][indexColumn] = 10 + rand() % 41;
		}
	}
}

void ShowArray(int** arr, int row, int column)
{
	std::cout << "Array: \n";

	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			std::cout << arr[indexRow][indexColumn] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}
