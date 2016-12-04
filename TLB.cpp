//
// Created by michael on 12/3/16.
//

#include <clocale>
#include "TLB.h"

void setuptlb(TLB * tlb)
{
    for(int i = 0; i < TLB_LENGTH; ++i)
    {
        TLB_row * tlb_row =  new TLB_row();
        tlb_row->age = 0;
        tlb_row->page_num = NULL;
        tlb_row-> frame_num = NULL;
        tlb->rows.push_back(*tlb_row);
    }
}

frame_t getframefromtlb(log_addr_t *la, TLB *tlb)
{
    for(int i = 0; i < TLB_LENGTH; ++i)
    {
        if(tlb->rows[i].page_num == la->page_num)
        {
            return tlb->rows[i].frame_num;
        }
    }
    return NULL;
}

frame_t getframefrompagetable(log_addr_t *la, std::vector<page_t> page_table)
{
    for(int i = 0; i < PAGE_TABLE_SIZE; ++i)
    {
        if(page_table[i] == la->page_num)
        {
            return page_table[i];
        }
    }

    return NULL;
}

void resetage(TLB * tlb, frame_t frame_num)
{
    for (int i = 0; i < TLB_LENGTH; ++i)
    {
        if(tlb->rows[i].frame_num == frame_num)
        {
            tlb->rows[i].age = 0;
        }
    }
}
