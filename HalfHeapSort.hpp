#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP




// Function 'percDown' performs the percolate down operation in a heap.
void percDown(std::vector<int>&heap, std::vector<int>::size_type hole)
{
    int tmp = std::move(heap[hole]);                                  //storing 'hole' element into temporary value.              
    std::vector<int>::size_type child;                                // declare child nodes
    int s = heap.size() - 1;
    std::vector<int>::size_type k = hole * 2;
    for (; k < heap.size(); hole = child)                     
    {
        child = k;                                              //left child of 'hole' node
        if (child != s && heap[child+1 ] < heap[child])    
        {
            ++child;                                                   //if right child is less than leftchild, swap the 'hole' with right child
        }
        if (heap[child] < tmp)
        {
            heap[hole] = std::move(heap[child]);                       // if either left child or right child is smaller than the temporary value,swap its position with the 'hole' position.
        }
        else
        {
            break;
        }
        k=hole*2;
    }
    heap[hole] = std::move(tmp);
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
            std::swap(nums[0], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 0);                          //Maintain the heap property after swapping.

        }
    }
    if (a % 2 == 0)
    {
        for (int j = size; j >= s; --j)
        {
            std::swap(nums[0], nums[j]);               //Swaps the root of the heap (smallest element) with the last unsorted element.
            nums.pop_back();                            //Removes the sorted element 
            percDown(nums, 0);                          //Maintain the heap property after swapping.

        }
    }


    nums.erase(nums.begin());                        // erase empty index 0

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    duration = static_cast<int>(elapsed.count());
    
    return nums[0];                                  // return the root node, median element
    
  
}


#endif
