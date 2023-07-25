#ifndef MAIN_H
#define MAIN_H

/*begin standard C header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/* macros */

#define BUFSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE
#define LOWHEX 0
#define UPHEX 1

/* structs */
/**
 * struct inventory_s - inventory of common variables needed
 * @fmt: the input format string
 * @i: index to traverse the format string
 * @args: the variadic arguments list of input arguments
 * @buffer: buffer to be written to before writing to stdout
 * @buf_index: index to traverse the buffer, also total chars written
 * @flag: notifies if there was a modifier flag
 * @space: notifies if space was printed
 * @ch0: character to be written to buffer
 * @ch1: character checking after % character
 * @ch2: character to check 2 spaces after % symbol
 * @error: indicates error or not (0 no error, 1 error)
 */
typedef struct inventory_s
{
	const char *fmt;
	int i;
	va_list *arguments;
	char *buffer;
	int buf_index;
	int flag;
	int space;
	char ch0;
	char ch1;
	char ch2;
	int error;
} inventory_t;

/**
 * struct get_s - printf specifiers and paired function
 * @ch: the specifier
 * @func: pointer to the conversion specifier function
 */
typedef struct get_s
{
	char ch;
	void (*func)(inventory_t *list);
} get_t;

/* initializing and ending functions */
int _printf(const char *format, ...);
inventory_t *build_inventory(va_list *arguments, const char *format);

/* custom memory allocation and buffer */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(inventory_t *list);
void puts_buffer(inventory_t *list, char *str);

/* string functions */
int _putchar(char c);
void puts_mod(char *str, unsigned int l);

/* parse and match functionality */
void parse_specifiers(inventory_t *list);
int finalize_inventory(inventory_t *list);
void (*get_specifier_func(inventory_t *list))(inventory_t);

/* hexadecimal */

/* integers */
void print_int(inventory_t *list)

/* octals */


#endif /* end include guard for header files */
