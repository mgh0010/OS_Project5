//
// Created by michael on 12/3/16.
//

#include "TLB.h"




void setuptlb(TLB * tlb)
{
    for(int i = 0; i < TLB_LENGTH; ++i)
    {
        TLB_row * tlb_row =  new TLB_row();
        tlb_row->age = 0;
        tlb_row->page_num = 0;
        tlb_row-> frame_num = 0;
        tlb->rows.push_back(*tlb_row);
    }
}

bool pagenotintlb(log_addr_t * la, TLB * tlb)
{
    for(int i = 0; i < TLB_LENGTH; ++i)
    {
        if(tlb->rows[i].page_num == la->page_num)
        {
            return false;
        }
    }
    return true;
}
