# Sorting-Algorithms

This C++ program allows the user to create an array that is any size they like. Once created, they can randomly assign integers to each index. Then, they can choose from a selection of sorting algorithms.

I created this project to learn about different sorting algorithms and their time complexities. I want to expand my knowledge of a variety of different data structures and algorithms. 

## Features

This project uses **dynamic memory allocation** to create an array at runtime. A dynamic array is necessary if the user wants to specify its length.

There are eight different sorting algorithms with a variety of different time complexities used in this program, including: 
* **Bubble Sort**- O(n^2) in the worst case.
* **Bucket Sort**- O(n^2) in the worst case.
* **Counting Sort**- O(n+k), where k is the range of data.
* **Insertion Sort**- O(n^2) in the worst case.
* **Quick Sort**- O(n^2) in the worst case, but typically O(nlogn) on average.
* **Radix Sort**- O(d*(n+k)), where d is the number of digits in the largest number and k is the range of data.
* **Selection Sort**- O(n^2) in the worst case.
* **Shell Sort**- O(n^2) in the worst case.

## Installation

To run this program, download the executable file (.exe) and run it. If you would like to make changes to the code, download the .cpp file and use your favorite text editor or IDE. If using a text editor, be sure to have a compatible compiler installed to run the program. 

## Usage

The command line interface will prompt you to input how many elements you would like in the array. After that, provide the elements that you wish to add to each index. Preferably, they should not be in order so that the program can showcase the sorting algorithms!

Once the array is created, a list of the algorithms will be shown. Simply input the number that corresponds to the desired algorithm. You can run these algorithms as many times as you would like. 

## Acknowledgements

The idea for this project began while I was taking an introductory computer science course in my first year of college. 

I would also like to credit the book 'A Common-Sense Guide to Data-Structures and Algorithms, Second Edition' by Jay Wengrow.
