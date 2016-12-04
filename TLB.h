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
bool pagenotintlb(log_addr_t * la, TLB * tlb);


#endif //OS_PROJECT5_TLB_H
