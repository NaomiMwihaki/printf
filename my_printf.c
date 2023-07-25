#include "main.h"

/**
 * _printf - replication of some of the features from C function printf()
 * @format: character string of directives, flags, modifiers, & specifiers
 * Description: This function uses the variable arguments functionality and is
 * supposed to resemble printf().
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list arguments;
    inventory_t *list;
    void (*specifier_func)(inventory_t *);

    if (!format)
        return (-1);

    va_start(arguments, format);
    list = build_inventory(&arguments, format);// Build the inventory based on arguments and format

    while (list && format[list->index] && !list->error)
    {
        list->current_char = format[list->index];// Getting the current character

        if (list->current_char != '%')// If its not a % write it to the buffer
            write_to_buffer(list);
        else
        {
            parse_specifier(list);// Parse function
            specifier_func = get_specifier_function(list);// Getting the corresponding helper function

            if (specifier_func)// If there is a valid specifier function
                specifier_func(list);// Calling the specifier function
            else if (list->next_char)
            {
                if (list->flag)
                    list->flag = 0;
                write_to_buffer(list);// Write the special character after % to buffer
            }
            else
            {
                if (list->space)// Handle the 'spac'e case
                    list->buffer[--(list->buffer_index)] = '0';// Replace the space with '0'
                list->error = 1;// Set error flag to indicate an invalid specifier
            }
        }

        list->index++;
    }

    return (finalize_inventory(list)); // Finalize and return the result
}
