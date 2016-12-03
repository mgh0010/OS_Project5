//
// Created by michael on 12/3/16.
//

#ifndef OS_PROJECT5_ADDRESS_H
#define OS_PROJECT5_ADDRESS_H

#include <stdio.h>
#include <limits.h>
#include "address.h"
//#define DEBUG

/* offset is used to address the location within a page */
#define OFFSET_BITS 8

/* mask is used to extract the offset from a logical address */
#define OFFSET_MASK 0xFF

/* Using this because there is no byte data type in C */
typedef unsigned char byte;

/* new data type of pages, frames, and offset */
typedef unsigned int page_t;
typedef unsigned int frame_t;
typedef unsigned int offset_t;
typedef unsigned int log_addr_t;
typedef unsigned int phys_addr_t;


int getaddressinfo (log_addr_t logical_address);

/*
 * In C there is no binary format in printf
 * Implementing these will print binary format
 * itob16() and itob8() are modified from itob() by Xiao Qin.
 */
char *itob(int x);
char *itob16(int x);
char *itob8(int x);



#endif //OS_PROJECT5_ADDRESS_H
