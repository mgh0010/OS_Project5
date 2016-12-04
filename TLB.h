//
// Created by michael on 12/3/16.
//

#ifndef OS_PROJECT5_TLB_H
#define OS_PROJECT5_TLB_H


#include <vector>
#include "address.h"

#define TLB_LENGTH 16

typedef struct TLB_struct
{
    std::vector<std::vector<unsigned int>> page_frame_nums;

}TLB;

void setuptlb(TLB_struct * tlb);


#endif //OS_PROJECT5_TLB_H
