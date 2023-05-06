#include <iostream>

// Function Prototypes
void introduction();
int arraySize();
void printArray(int*, int);
void bubbleSort(int*, int);
//bucket sort
//counting sort
// heap sort
// insertion sort
//merge sort
//quick sort
//radix sort
void selectionSort(int*, int);
// shell sort

int main()
{
	introduction();

	// Creates array at runtime. Size is specified by user in arraySize() function.
	int size = arraySize();
	int* array = new int[size];

	// User creates each individual element.
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter element " << i + 1 << ": ";
		std::cin >> array[i];
	}

	// Prints original array
	std::cout << "Original array:\n";
	printArray(array, size);

	delete[] array; // Delete array to avoid memory leakage.
	system("pause");
	return 0;
}

void introduction()
{
	std::cout << "Welcome to the program! This program will ask you to make an array of random integers "
			  << "and will have you choose which sorting algorithms you would like to perform!\n\n";
}
int arraySize()
{
	int size;
	std::cout << "How many elements would you like in the array? ";
	std::cin >> size;
	return size;
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

// The smallest elements will "bubble" its way to the top.
void bubbleSort(int* array, int size)
{
	// Iterates through array and swaps values out of order.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				// Swap the two elements.
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		// Find the index with the smallest elements in the unsorted part of array.
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		// Swap the smallest element with the first element in unsorted part of array.
		if(minIndex != i)
		{
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}