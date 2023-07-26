#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_binary - Print an integer as binary
 * @list: The arguments inventory
 */
void print_binary(inventory_t *list)
{
    unsigned int num = va_arg(*(list->arguments), unsigned int); // Get the integer argument from the list
    char buffer[33]; // Buffer to hold the binary representation (32 bits + '\0')

    // Convert the integer to its binary representation
    int i = 31;
    buffer[i] = '\0'; // Null-terminate the string
    do {
        buffer[--i] = '0' + (num & 1); // Convert the least significant bit to '0' or '1'
        num >>= 1; // Shift the number right by one bit
    } while (num > 0 && i > 0);

    // Write the binary string to the output buffer
    while (buffer[i] != '\0') {
        if (list->buf_index >= BUFSIZE) {
            write_buffer(list);
        }
        list->buffer[list->buf_index++] = buffer[i++];
    }
}
