#include <iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

std::vector<int>::iterator medianofthree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator mid)
{
	int arr[] = { *low, *mid, *high };
	std::sort(std::begin(arr), std::end(arr));
	return std::find(nums.begin(), nums.end(), arr[1]);
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	auto mid = low + std::distance(low, high) / 2;                  // declare an median element and pass it into medianofthree function
	std::vector<int>::iterator pivot = medianofthree(nums, low, high, mid);  // choose the pivot using median of three method

	std::iter_swap(pivot, high);                             // swap the chosen pivot with the last element
	pivot = high;                                               // pivot is now pointing to last element
	std::vector<int>::iterator i = low;                     // declare an iterator i and point to first element
	std::vector<int>::iterator j = pivot - 1;                  // delcar an iterator j and point to second to last element


	while (true)
	{
		while (*i < *pivot)                                // while element i is less than pivot element
		{
			i++;                                            //increment i position
		}
		while (*j > *pivot && j > low)                      //while element j is greater than pivot element
		{
			j--;                                            //decrement j position
		}

		if (i >= j)                                          // if i surpass j, break the while loop
		{
			break;
		}

		std::iter_swap(i, j);                                 // Else: if i is greater than pivot and j is less than pivot
		// swap i with j
		i++;                                                   //increment i               
		j--;                                                   //decrement j
	}
	std::iter_swap(i, pivot);                                 // swap the pivot with the i at the end when i>=j
	pivot = i;                                                 // 

	return pivot;                                             //return pivot iterator
}

int quickSelect1(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator median)
{


	while (low <= high)
	{

		std::vector<int>::iterator pivot = hoarePartition(nums, low, high);   // Find the pivot using hoare partition

		if (pivot == median)                                    // if pivot position is equal to median position , return the current pivot element(median element)
		{
			return *pivot;
		}
		else if (pivot > median)                               // if pivot position is greater than median , recurse on the left side;
		{

			high = pivot - 1;
		}
		else                                                   // if pivot position is less than median, recurse on the right side;
		{
			low = pivot + 1;
		}
	}

	return -1;

}

int quickSelect(std::vector<int>& nums, int& duration)
{

	std::vector<int>::iterator low = nums.begin();
	std::vector<int>::iterator high = nums.end() - 1;
	std::vector<int>::iterator median = low + std::distance(low, high) / 2;
	auto start = std::chrono::steady_clock::now();
	int result = quickSelect1(nums, low, high, median);                //store the median element into result;

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double, std::micro> elapsed = end - start;
	duration = static_cast<int>(elapsed.count());


	return result;                                             //return median element



}
#endif
