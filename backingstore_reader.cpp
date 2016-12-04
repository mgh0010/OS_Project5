/*
 * Project 5: backingstore_reader.c
 * partially converted code provided initially by Xiao Qin.
 */

#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

//#define DEBUG

/* There is no byte data type in C */
typedef unsigned char byte;

int get_from_bs ( int argc, char *argv[] ) {
    const char backingstore[] = "BACKING_STORE";

    FILE *file;
    int i;
    int seek_position;
    fpos_t pos;
    int num_bytes_read;
    byte one_byte;

    /* argc should be 3 for correct execution */
    if ( argc != 3 ) {
        /* We print argv[0] assuming it is the program name */
        cout << "usage: " << argv[0] << ", <seek position>, <number of bytes to read>\n";
        return 0;
    }

    /*
     * Convert strings into seek_position and num_bytes_read
     * We assume argv[1] is seek_position and argv[2] is num_bytes_read
     */
    seek_position = stoi(argv[1]);
    num_bytes_read = stoi(argv[2]);

#ifdef DEBUG
    printf("seek_position =%d, num_bytes_read =%d\n", seek_position, num_bytes_read);
#endif

    file = fopen(backingstore, "r" );

    /* fopen returns 0, the NULL pointer, on failure */
    if ( file == 0 ) {
         printf( "Could not open file: %s.\n", backingstore);
    }
    else {
        /* SEEK_SET: reference position is the beginning of file */
        fseek(file, seek_position, SEEK_SET);
        fgetpos(file, &pos);
        printf("Reading from position: %d.\n", pos);

        /* Read and print data from backingstore */
        for (i = 0; i < num_bytes_read; i++) {
           fread(&one_byte, 1, 1, file);
           /* printf prints one byte as hex */
           printf("0x%x, %d", one_byte, one_byte);
           /*
            * Note: If one_byte's data type is int,
            * then we have to use a bit mask: one_byte&0xFF
            */
        }
        printf("\n");

        fclose( file );
    }
    return 0;
}
