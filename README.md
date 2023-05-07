# Sorting-Algorithms

This C++ program allows the user to create an array that is any size they would like. After this, they can randomly add integers to each index. Then, they will be able to choose which sorting algorithm they would like to use.

I made this project to learn more about different sorting algorithms and their time complexities. I want to expand my knowledge on a variety of different data structures and algorithms. 

## Features

This project uses **dynamic memory allocation** to create an array at runtime. A dynamic array is needed if the user wants to specify the length of it. 

There are then 10 different sorting algorithms with a variety of different time complexities. 
The algorithms used and their time complexites:
* Bubble Sort- O(n^2).
* Bucket Sort- O(n^2).
* Counting Sort- O(n+k), where k is the range of data.
* Heap Sort-O(nlogn).
* Insertion Sort- O(n^2).
* Merge Sort- O(nlogn).
* Quick Sort- O(n^2) in the worst case, but typically O(nlogn) on average.
* Radix Sort- O(d*(n+k)), where d is the number of digits in the largest number and k is the range of data.
* Selection Sort- O(n^2).
* Shell Sort- O(n^2).

## Installation

To run this program, download the executable file (.exe) and run it. If you would like to make changes to the code, download the .cpp file and use your favorite text editor or IDE. If using a text editor, be sure to have a compatible compiler installed to run the program. 

## Usage

The command line interface will ask you to input how many elements you would like in the array. After that, provide the elements that you wish to add to each index. Preferably, they should not be in order so that the program can showcase the sorting algorithms!

Once the array is made, a list of the algorithms will be shown. Just input the number that is next to the corresponding array. You can run these algorithms as many times as you would like. 

## Acknowledgements

The idea of this project started while I was taking an introductory computer science course in my first year of college. 

I would also like to give credit to this book: A Common-Sense Guide to Data-Structures and Algorithms, Second Edition by Jay Wengrow.
