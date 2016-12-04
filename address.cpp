//
// Created by michael on 12/3/16.
//

#include "address.h"

#include <stdio.h>
#include <limits.h>

void setuplogicaladdress(log_addr_t * la)
{
    la->page_num = la->full_addr >> OFFSET_BITS;
    la->offset = la->full_addr & OFFSET_MASK;

    printf("logical address: %d, page number: %d, offset: %d\n", la->full_addr, la->page_num, la->offset);
}


void setupphysicaladdress(phys_addr_t * pa, frame_t frame_num, unsigned int offset)
{
    pa->full_addr = frame_num << OFFSET_BITS | offset;
    // offsets should be the same
    pa->offset = offset;

    printf("frame number:%d, offset: %d, physical address: %d\n", frame_num, offset, pa->full_addr);
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
