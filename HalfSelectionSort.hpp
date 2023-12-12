
#include <iostream>
#include<vector>
#include <chrono>

#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

/*
CSCI335 Fall 2023
Assignment 2 – HalfSelectionSort
WeiLin Gao
12/12/2023
HalfSelectionSort.hpp: Finding the median using  HalfSelectionSort
Iterate through the list, finding the smallest element, then 2nd smallest, and so on until you find the median. This is essentially a selection sort, stopped halfway through. This method will take too long on very large lists, so for inputs of size >50,000 do not use this method, and instead print a message saying that the input was too big for selection sort.
*/
std::vector<int>::iterator findSmallest(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (start == end)                           // passing the current index of nums and nums.end();
    {
        return start;
    }

    auto smallest = start;

    for (auto it = start + 1; it != end; it++)   // finding the samllest element and swap with currrent index.
    {
        if (*it < *smallest)
        {
            smallest = it;
        }
    }

    return smallest;
}


int halfSelectionSort(std::vector<int>& nums, int& duration)
{
    // If input size is too big, selection sort isn't performed and an error message is displayed.
    if (nums.size() >= 50000)
    {
        std::cout << "Input size is too big for selection sort" << std::endl;
        return -1;
    }

    int half = nums.size() / 2;

    auto start = std::chrono::steady_clock::now();

    // Loop through the first half of the vector, finding the smallest element and swapping it.
    for (auto a = nums.begin(); a != nums.begin() + half + 1; a++)  // iterate through first half of the vector then stop.
    {
        auto smallest = findSmallest(a, nums.end());
        int temp = *a;
        *a = *smallest;
        *smallest = temp;
    }
    auto end = std::chrono::steady_clock::now();


    std::chrono::duration<double, std::micro> elapsed = end - start;
    // Calculate and set the duration of the sorting operation
    duration = static_cast<int>(elapsed.count());

    if (nums.size() % 2 == 0)            // Return the median element or the one before it for even-sized vectors.
    {
        return nums[half - 1];
    }


    return nums[half];


}

#endif
