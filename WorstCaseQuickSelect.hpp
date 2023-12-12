#include <iostream>
#include<vector>
#include<algorithm>
#include "QuickSelect.hpp"

#ifndef WORSTCASEQUICKSELECT_HPP
#define WORSTCASEQUICKSELECT_HPP


std::vector<int> worstCaseQuickSelect()
{
    int duration;
    std::vector<int> worstCaseQuickSelect;
    for (int i = 1; i <= 20000; ++i) 
    {
        worstCaseQuickSelect.push_back(i);
    }
 
    return worstCaseQuickSelect;
  
  
}




#endif