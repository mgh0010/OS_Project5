/*
 * Project 5: backingstore_reader.c
 * partially converted code provided initially by Xiao Qin.
 */

#include <string>
#include <iostream>
#include <stdio.h>
#include "address.h"
#include "backingstore_reader.h"

#include <sstream>


/* There is no byte data type in C */
typedef unsigned char byte;

//get value and bytes from
void getfrombs(page_t page_num, unsigned char &ret_value, frame_t &ret_frame_num)
{
    const char backingstore[] = "BACKING_STORE";
    byte value = 0;

    FILE *file;
    int i;
    int seek_position;
    fpos_t pos;
    int num_bytes_read;
    byte one_byte;

    seek_position = page_num;
    num_bytes_read = 256;

    file = fopen(backingstore, "r" );

    /* fopen returns 0, the NULL pointer, on failure */
    if ( file == 0 )
    {
         printf( "Could not open file: %s.\n", backingstore);
    }
    else
    {
        /* SEEK_SET: reference position is the beginning of file */
        fseek(file, seek_position, SEEK_SET);
        fgetpos(file, &pos);

        /* Read and print data from backingstore */

        fread(&value, 1, 1, file);
        ret_frame_num += value;
        for (i = 1; i < num_bytes_read; i++)
        {
           fread(&one_byte, 1, 1, file);
            ret_frame_num += one_byte;
        }

        fclose( file );
    }
}
