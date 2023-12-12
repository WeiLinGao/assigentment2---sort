
#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP




// Function 'percDown' performs the percolate down operation in a heap.
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole)
{
    int tmp = std::move(heap[hole]);                    // Store 'hole' element into temporary value.
    std::vector<int>::size_type child;

                                                         // Continue percolating down while there is at least one left child.
    while (hole * 2 < heap.size())
    {
        child = hole * 2;                                  // Left child of 'hole' node.

                                     
        if (child != heap.size() - 1 && heap[child + 1] < heap[child])     // Compare left and right child, if right child is smaller, move to right child.                 
        {
            ++child;
        }

        // If the child is smaller than the temporary value, move the child up.
        if (heap[child] < tmp)
        {
            heap[hole] = std::move(heap[child]);
        }
        else
        {
            break;                                     // If neither child is smaller, break out of the loop.
        }

        hole = child;                                 // Move down to the child level.
    }

    heap[hole] = std::move(tmp);                           // Place the temporary value in its correct position.
}


// Function 'buildHeap' constructs a min-heap
void buildHeap(std::vector<int>& heap)
{
    for (int i = (heap.size() - 1) / 2; i >= 1; --i)          // building a min heap, starting from the first non leaf node elemnt
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
    int s = nums.size() / 2 + 1;              // sorting half of the vector and pause

    if (a % 2 != 0)
    {
        for (int j = nums.size() - 1; j > s; --j)
        {
            std::swap(nums[0], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 0);                          //Maintain the heap property after swapping.

        }
    }
    if (a % 2 == 0)
    {
        for (int j = nums.size() - 1; j >= s; --j)
        {
            std::swap(nums[0], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 0);                          //Maintain the heap property after swapping.

        }
    }

    nums.erase(nums.begin());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    duration = static_cast<int>(elapsed.count());

    return nums[0];                                  // return the root node, median element


}


/*
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
        if (child < a.size()-1 && a[child+1] < a[child ])
            ++child;
        if (tmp > a[child])
            a[i] = std::move(a[child]);
        else
            break;
    }
    a[i] = std::move(tmp);
}
*/
#endif
