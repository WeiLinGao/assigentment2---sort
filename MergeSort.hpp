#include<iostream>
#include<vector>
#include <algorithm>
#include <chrono>
#ifndef MERGESORT_HPP
#define MERGESORT_HPP

void mergeSortHelp(std::vector<int>& nums, int& duration, std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) > 1)
	{
		auto mid = start + distance(start, end) / 2;            // Calculates the midpoint of the current range to divide it into two halves.
		mergeSortHelp(nums, duration, start, mid);              // Recursively calls mergeSortHelp to sort the left and right halves of the range.
		mergeSortHelp(nums, duration, mid, end);
		std::vector<int>a(std::distance(start, end));           // Creates a temporary vector 'a' to store the merged result of two sorted halves.
		std::merge(start, mid, mid, end, a.begin());            // Merges the two sorted halves into vector 'a'.
		std::copy(a.begin(), a.end(), start);                  // Copies the merged result back into the original range.
	}

	
}

int mergeSort(std::vector<int>& nums, int& duration)
{
	auto start = nums.begin();
	auto end = nums.end();
	auto startTime = std::chrono::steady_clock::now();
	// Initiates the merge sort process.
	mergeSortHelp(nums, duration, start, end);
	auto endTime = std::chrono::steady_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

	// Returns the median or the element before it for even-sized vectors.
	if (nums.size() % 2 == 0)
	{
		return nums[(nums.size() / 2) - 1];
	}
	return nums[(nums.size() / 2)];
}
#endif
