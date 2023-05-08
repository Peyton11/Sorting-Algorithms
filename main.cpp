#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

/*
TO DO by 5/13/2023:
Visualize algorithms.
Modify README.
*/


// Function Prototypes
void introduction();
int arraySize();
void printArray(int*, int);
int algorithmChoice();
void bubbleSort(int*, int);
void bucketSort(int*, int);
void countingSort(int*, int);
void countingSort(int*, int , int);
void insertionSort(int*, int);
void quickSort(int*, int);
void radixSort(int*, int);
void selectionSort(int*, int);
void shellSort(int*, int);

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

	int choice = algorithmChoice();
	switch(choice)
	{
		case 0:
			bubbleSort(array, size);
			std::cout << "After Bubble Sort:\n";
			printArray(array, size);
			break;
		case 1:
			bucketSort(array, size);
			std::cout << "After Bucket Sort:\n";
			printArray(array, size);
			break;
		case 2:
			countingSort(array, size);
			std::cout << "After Counting Sort:\n";
			printArray(array, size);
			break;
		case 3:
			insertionSort(array, size);
			std::cout << "After Insertion Sort:\n";
			printArray(array, size);
			break;
		case 4:
			quickSort(array, size);
			std::cout << "After Quick Sort:\n";
			printArray(array, size);
			break;
		case 5:
			radixSort(array, size);
			std::cout << "After Radix Sort:\n";
			printArray(array, size);
			break;
		case 6:
			selectionSort(array, size);
			std::cout << "After Selection Sort:\n";
			printArray(array, size);
			break;
		case 7:
			shellSort(array, size);
			std::cout << "After Shell Sort:\n";
			printArray(array, size);
			break;
	}

	delete[] array; // Delete array to avoid memory leakage.
	system("pause");
	return 0;
}

void introduction()
{
	std::cout << "Welcome to the program! This program will ask you to make an array of random integers "
			  << "and will have you choose which sorting algorithms you would like to perform!\n";
}

int arraySize()
{
	int size;
	bool invalid = true;
	// Input validation to ensure size is an int > 0 and <= 30.
	do
	{
		std::cout << "How many elements would you like in the array? Input a number 2-30: ";
		std::cin >> size;
		if (std::cin.fail() || size <= 1 || size > 30)
		{
			std::cout << "Please enter an integer value that is between 2 and 30.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else 
		{
			invalid = false; // Breaks out of loop.
		}
	}
	while (invalid);

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

int algorithmChoice()
{
	int choice;
	std::cout << "Which algorithm would you like to use? Here are your choices:\nBubble Sort [0]\nBucket Sort [1]\nCounting Sort [2]\nInsertion Sort [3]\n"
			  << "Quick Sort [4]\nRadix Sort [5]\nSelection Sort [6]\nShell Sort [7]\n";
	std::cout << "Algorithm: ";
	std::cin >> choice;
	std::cout << std::endl;
	return choice;
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

void bucketSort(int* array, int size)
{
	// Determins the range of values.
	int  minValue = array[0];
	int maxValue = array[0];
	for(int i = 1; i < size; i++)
	{
		if (array[i] < minValue)
		{
			minValue = array[i];
		}
		else if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}

	// Calculates how many buckets.
	int numBuckets = maxValue - minValue + 1;

	// Creates a vector that has numBuckets number of buckets inside.
	std::vector<std::vector<int>> buckets(numBuckets);

	// Puts elements into the buckets.
	for (int i = 0; i < size; i++)
	{
		int bucketIndex = array[i] - minValue;
		buckets[bucketIndex].push_back(array[i]);
	}

	// Sorts each bucket and concatenates the sorted buckets.
	int index = 0;
	for (int i = 0; i < numBuckets; i++)
	{
		std::sort(buckets[i].begin(), buckets[i].end());
		for (int j = 0; j < buckets[i].size(); j++)
		{
			array[index] = buckets[i][j];
			index++;
		}
	}
}

void countingSort(int* array, int size)
{
	// Finds the range of values in the array.
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[i] < minValue)
		{
			minValue = array[i];
		}
		else if (array[i] > maxValue)
		{
			maxValue = array[i];
		}
	}

	// Creates counting array
	int* countingArray = new int[maxValue - minValue + 1];

	// Initialize counting array to all zeros.
	for (int i = 0; i < (maxValue - minValue + 1); i++)
	{
		countingArray[i] = 0;
	}
	// Counts the occurrences of each element.
	for (int i = 0; i < size; i++)
	{
		countingArray[array[i] - minValue]++;
	}

	// Modifies countingArray to show the number of elements smaller than i.
	for (int i = 1; i < (maxValue - minValue + 1); i++)
	{
		countingArray[i] += countingArray[i - 1];
	}

	// Creates new array with sorted elements.
	int* sortedArray = new int[size];

	// Adds values to sorted array in reverse order.
	for (int i =  size - 1; i >= 0; i--)
	{
		sortedArray[countingArray[array[i] - minValue] - 1] = array[i];
		countingArray[array[i] - minValue]--;
	}

	// Copies the sorted array back to the original array
	for (int i = size - 1; i >= 0; i--)
	{
		array[i] = sortedArray[i];
	}

	// Deletes dynamic arrays.
	delete[] countingArray;
	delete[] sortedArray;
}

void countingSort(int* array, int size, int exponent)
{
	int* output = new int[size];
	int i;
	int count[10] = {0};

	// Count occurrences of each digit.
	for (i = 0; i < size; i++)
	{
		count[(array[i] / exponent) % 10]++;
	}

	// Change count[i] so that it contains the acutal position of this digit in ouput[];
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	// Build ouput array.
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exponent) % 10] - 1] = array[i];
		count[(array[i] / exponent) % 10]--;
	}

	// Copy the output array to the input array.
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	delete[] output;
}

void insertionSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		// Stores current element in a temporary variable.
		int current = array[i];
		int j = i - 1;
		// Move larger element to the right until correct position is found.
		while (j >= 0 && array[j] > current)
		{
			array[j + 1] = array[j]; // Moves the jth element one position.
			j--; // Decrements j to compare next element to the left.
		}
		// Inserts the current element in its correct position.
		array[j + 1] = current; 
	}
}

void quickSort(int* array, int size)
{
	int pivot = array[size / 2]; // Choose pivot element.
	int i = 0;
	int j = size - 1;

	// Array is already sorted.
	if (size == 1)
	{
		return;
	}

	while (i <= j)
	{
		while (array[i] < pivot)
		{
			i++; // Find element on left to swap.
		}
		while (array[j] > pivot)
		{
			j--; // Find element on right to swap.
		}
		if (i <= j)
		{
			std::swap(array[i], array[j]);
			i++;
			j--;
		}
	}

	// Recursively sort the two halves.
	quickSort(array, j + 1);
	quickSort(array + j, size - j - 1);
}

void radixSort(int* array, int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	for (int exponent = 1; max / exponent > 0; exponent *= 10)
	{
		countingSort(array, size, exponent);
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

void shellSort(int* array, int size)
{
	// Start with a large gap and reduce it in each iteration.
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		// Do gapped insertion sort for this gap size.
		for (int i = gap; i < size; i++)
		{
			// Save the value to be inserted in the sorted portion.
			int temp = array[i];

			// Shift elements i the sorted portion to create space for new element.
			int j;
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			// Insert the saved value in the correct position.
			array[j] = temp;
		}
	}
}