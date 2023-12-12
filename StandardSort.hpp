#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

int standardSort(std::vector<int>& nums, int& duration)
{
    auto start = std::chrono::steady_clock::now();
    std::sort(nums.begin(), nums.end());            // using standard sort to sort all elements.
    auto end = std::chrono::steady_clock::now(); 

    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    auto low = nums.begin();
    auto high = nums.end() - 1;
    auto mid = low + std::distance(low, high) / 2;             // Calculates the middle index.
    // Returns the middle element for both even and odd-sized vectors.
    if (nums.size() % 2 != 0)
    {
        return *(mid);
    }

    return *(mid);
}

#endif 