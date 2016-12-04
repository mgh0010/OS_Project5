//
// Created by michael on 12/3/16.
//

#include "address.h"

#include <stdio.h>
#include <limits.h>


/* This method determines the physical address from the given logical address
 * Reference:
 *      This method was heavily inspired by the genius Xiao Qin himself */
int getaddressinfo (log_addr_t logical_address) {
    page_t     page_num;
    offset_t   offset;
    frame_t    frame_num;
    phys_addr_t physical_address;

    page_num = logical_address.full_addr >> OFFSET_BITS;
    offset = logical_address.full_addr & OFFSET_MASK;

    printf("logical address: %d, page number: %d, offset: %d\n", logical_address.full_addr, page_num, offset);

#ifdef DEBUG
    printf("logical address: %s\n", itob(logical_address));
#endif
    printf("logical address: %s\n", itob16(logical_address.full_addr));

    printf("page number: %s\n", itob8(page_num));

    printf("offset: %s\n", itob8(offset));

    printf("Unit Testing: Now create physical address ...\n");

    frame_num = page_num;
    physical_address.full_addr = frame_num << OFFSET_BITS | offset;

    printf("frame number:%d, offset: %d, physical address: %d\n", frame_num, offset, physical_address.full_addr);

    return 0;
}

/*
 * convert machine number to human-readable binary string.
 * Returns: pointer to static string overwritten with each call.
 * Reference:
 * Xiao Qin through ->
 * https://bytes.com/topic/c/answers/621985-print-binary-representation
 * */
char *itob(int x)
{
    static char buff[sizeof(int) * CHAR_BIT + 1];
    int i;
    int j = sizeof(int) * CHAR_BIT - 1;

    buff[j] = 0;
    for(i=0;i<sizeof(int) * CHAR_BIT; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}

/*
 * Reference:
 *          Xiao Qin
 * This is a modified version of the above itob()
 * Only print 16 bits
 */
char *itob16(int x)
{
    static char buff[17];
    int i;
    int j = 15;

    buff[j] = 0;
    for(i=0;i<16; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}

/*
 * Xiao Qin:
 * This is a mofified version of the above itob()
 * Only print 8 bits
 */
char *itob8(int x)
{
    static char buff[9];
    int i;
    int j = 7;

    buff[j] = 0;
    for(i=0;i<8; i++) {
        if(x & (1 << i))
            buff[j] = '1';
        else
            buff[j] = '0';
        j--;
    }
    return buff;
}
