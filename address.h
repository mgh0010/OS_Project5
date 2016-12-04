//
// Created by michael on 12/3/16.
//

#ifndef OS_PROJECT5_ADDRESS_H
#define OS_PROJECT5_ADDRESS_H

//#define DEBUG

/* offset is used to address the location within a page */
#define OFFSET_BITS 8

/* mask is used to extract the offset from a logical address */
#define OFFSET_MASK 0xFF

/* mem size is used to for the size of the physical memory */
#define PHYSICAL_MEM_SIZE 256

/* page table size is used to for the size of the page table size */
#define PAGE_TABLE_SIZE 256

/* Using this because there is no byte data type in C */
typedef unsigned char byte;

/* new data type of pages, frames, and offset */
typedef unsigned int page_t;
typedef unsigned int frame_t;
typedef unsigned int offset_t;

typedef struct logical_address_struct
{
    unsigned int full_addr;
    page_t page_num;
    offset_t offset;
}log_addr_t;

typedef struct physical_address_struct
{
    unsigned int full_addr;
    frame_t fram_num;
    offset_t offset;
}phys_addr_t;


void setuplogicaladdress(log_addr_t * la);

void setupphysicaladdress(phys_addr_t * pa, frame_t frame_num, unsigned int offset);


/*
 * In C there is no binary format in printf
 * Implementing these will print binary format
 * itob16() and itob8() are modified from itob() by Xiao Qin.
 */
char *itob(int x);
char *itob16(int x);
char *itob8(int x);



#endif //OS_PROJECT5_ADDRESS_H
