#include<iostream>
#include<vector>
#include <algorithm>
#include <chrono>
#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP
/*
CSCI335 Fall 2023
Assignment 2 – InPlaceMergeSort
WeiLin Gao
12/12/2023
InPlaceMergeSort.hpp: Finding the median using InPlaceMergeSort
Same as merge sort, except use std::inplace_merge.
*/
void mergeSortHelp1(std::vector<int>& nums, int& duration, std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) > 1)
	{
		auto mid = start + distance(start, end) / 2;                 // Calculates the midpoint of the current range to divide it into two halves.
		mergeSortHelp1(nums, duration, start, mid);                 // Recursively calls mergeSortHelp1 to sort the left and right halves of the range.
		mergeSortHelp1(nums, duration, mid, end);
		std::inplace_merge(start, mid, end);                       // Performs an in-place merge to merge the sorted left and right halves back into the original range.
	}
	
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration)
{
	auto start = nums.begin();
	auto end = nums.end();
	auto startTime = std::chrono::steady_clock::now();
	// Initiates the inplace merge sort process.
	mergeSortHelp1(nums, duration, start, end);

	auto endTime = std::chrono::steady_clock::now(); 

	std::chrono::duration<double, std::micro> elapsed = endTime - startTime;
	duration = static_cast<int>(elapsed.count());


	// Returns the median or the element before it for even-sized vectors.
	if (nums.size() % 2 == 0)
	{
		return nums[(nums.size() / 2) - 1];
	}
	return nums[(nums.size() / 2)];
}

#endif 
