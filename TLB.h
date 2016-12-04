//
// Created by michael on 12/3/16.
//

#ifndef OS_PROJECT5_TLB_H
#define OS_PROJECT5_TLB_H


#include <vector>
#include "address.h"

#define TLB_LENGTH 16

typedef struct TLB_row_struct
{
    page_t page_num;
    frame_t frame_num;
    int age;
}TLB_row;

typedef struct TLB_struct
{
    std::vector<TLB_row> rows;

}TLB;

void setuptlb(TLB * tlb);

frame_t getframefromtlb(log_addr_t *la, TLB *tlb);

frame_t getframefrompagetable(log_addr_t *la, std::vector<page_t> page_table);

void resetage(TLB * tlb, frame_t frame_num);


#endif //OS_PROJECT5_TLB_H
