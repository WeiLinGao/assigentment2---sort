#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP



int leftChild(int i)
{
    return 2 * i;
}
void percDown(std::vector<int>& a, int i)
{
    int child;
    int tmp;

    for (tmp = std::move(a[i]); leftChild(i) < a.size(); i = child)
    {
        child = leftChild(i);
        if (child < a.size() - 1 && a[child + 1] < a[child])
            ++child;
        if (tmp > a[child])
            a[i] = std::move(a[child]);
        else
            break;
    }
    a[i] = std::move(tmp);
}
// Function 'buildHeap' constructs a min-heap
void buildHeap(std::vector<int>& heap)
{
    int a = (heap.size() - 1) / 2;
    for (int i = a; i >= 1; --i)          // building a min heap, starting from the first non leaf node elemnt
    {
        percDown(heap, i);
    }


}
// Function 'halfHeapSort' sorts the first half of 'nums' using a heap sort algorithm.
int halfHeapSort(std::vector<int>& nums, int& duration) 
{
    auto start = std::chrono::steady_clock::now();
    nums.push_back(nums[0]);                          // move the first element to the back of the vector.
    int a = nums.size();                              //cuurent size of nums

    buildHeap(nums);                                  // performing build min-heap
    int s = nums.size() / 2+1;              // sorting half of the vector and pause
    int size = nums.size() - 1;
    if (a % 2 != 0)
    {
        for (int j = size; j > s; --j)
        {
            std::swap(nums[1], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 1);                          //Maintain the heap property after swapping.

        }
    }
    if (a % 2 == 0)
    {
        for (int j = size; j >= s; --j)
        {
            std::swap(nums[1], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 1);                          //Maintain the heap property after swapping.

        }
    }


    nums.erase(nums.begin());                        // erase empty index 0

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    duration = static_cast<int>(elapsed.count());
    
    return nums[0];                                  // return the root node, median element
    
  
}


#endif
