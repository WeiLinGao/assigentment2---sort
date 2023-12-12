#include <iostream>
#include<vector>
#include<algorithm>
#include <chrono>
#include "QuickSelect.hpp"

#ifndef WORSTCASEQUICKSELECT_HPP
#define WORSTCASEQUICKSELECT_HPP

/*
CSCI335 Fall 2023
Assignment 2 – WorstCaseQuickSelect
WeiLin Gao
12/12/2023
WorstCaseQuickSelect.hpp: creating a worse case input and test it on quickselect
*/
std::vector<int> worstCaseQuickSelect()
{
    int duration;

    std::vector<int> worstCaseQuickSelect;
   
    for (int i = 1; i <= 20000; ++i)              // fill the vector with value from 1-20000
    {
        worstCaseQuickSelect.push_back(i);
    }
 
    return worstCaseQuickSelect;
  
  
}




#endif
