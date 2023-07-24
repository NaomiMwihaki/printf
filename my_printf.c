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
    list = build_inventory(&arguments, format);

    while (list && format[list->index] && !list->error)
    {
        list->current_char = format[list->index];

        if (list->current_char != '%')
            write_to_buffer(list);
        else
        {
            parse_specifier(list);
            specifier_func = get_specifier_function(list);

            if (specifier_func)
                specifier_func(list);
            else if (list->next_char)
            {
                if (list->flag)
                    list->flag = 0;
                write_to_buffer(list);
            }
            else
            {
                if (list->space)
                    list->buffer[--(list->buffer_index)] = '0';
                list->error = 1;
            }
        }

        list->index++;
    }

    return (finalize_inventory(list));
}
