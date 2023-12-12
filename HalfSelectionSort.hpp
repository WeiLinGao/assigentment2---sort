
#include <iostream>
#include<vector>
#include <chrono>

#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

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

    int half = nums.size() / 2+1;

    auto start = std::chrono::steady_clock::now();

    // Loop through the first half of the vector, finding the smallest element and swapping it.
    for (auto a = nums.begin(); a != nums.begin() + half; a++)  // iterate through first half of the vector then stop.
    {
        auto smallest = findSmallest(a, nums.end());
        int temp = *a;
        *a = *smallest;
        *smallest = temp;
    }
    auto end = std::chrono::steady_clock::now(); 

  

    // Calculate and set the duration of the sorting operation
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    if (nums.size() % 2 == 0)            // Return the median element or the one before it for even-sized vectors.
    {
        return nums[half-1];
    }


    return nums[half];


}

#endif






