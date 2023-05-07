#include <iostream>
#include <vector>
#include <algorithm>

// Function Prototypes
void introduction();
int arraySize();
void printArray(int*, int);
int algorithmChoice();
void bubbleSort(int*, int);
void bucketSort(int*, int);
void countingSort(int*, int);
void heapSort(int*, int);
void insertionSort(int*, int);
void mergeSort(int*, int);
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
			heapSort(array, size);
			std::cout << "After Heap Sort:\n";
			printArray(array, size);
			break;
		case 4:
			insertionSort(array, size);
			std::cout << "After Insertion Sort:\n";
			printArray(array, size);
			break;
		case 5:
			mergeSort(array, size);
			std::cout << "After Merge Sort:\n";
			printArray(array, size);
			break;
		case 6:
			quickSort(array, size);
			std::cout << "After Quick Sort:\n";
			printArray(array, size);
			break;
		case 7:
			radixSort(array, size);
			std::cout << "After Radix Sort:\n";
			printArray(array, size);
			break;
		case 8:
			selectionSort(array, size);
			std::cout << "After Selection Sort:\n";
			printArray(array, size);
			break;
		case 9:
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

int algorithmChoice()
{
	int choice;
	std::cout << "Which algorithm would you like to use? Here are your choices:\nBubble Sort[0]\nBucket Sort[1]\nCounting Sort[2]\nHeap Sort[3]\nInsertion Sort[4]\nMerge Sort[5]\n"
			  << "Quick Sort[6]\nRadix Sort[7]\nSelection Sort[8]\nShell Sort[9]";
	std::cin >> choice;
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