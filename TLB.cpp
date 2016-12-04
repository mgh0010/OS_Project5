//
// Created by michael on 12/3/16.
//

#include "TLB.h"




void setuptlb(TLB * tlb)
{
    for(int i = 0; i < TLB_LENGTH; ++i)
    {
        std::vector<unsigned int> page_frame_num;
        page_frame_num.push_back(0);
        page_frame_num.push_back(0);
        tlb->page_frame_nums.push_back(page_frame_num);
    }
}