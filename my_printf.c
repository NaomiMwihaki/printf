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

	/*build the inventory based on arguments and format*/
	va_start(arguments, format);
	list = build_inventory(&arguments, format);

	while (list && format[list->index] && !list->error)
	{
		/*get current character*/
		list->current_char = format[list->index];

		/*write to buffer if its not a %*/
		if (list->current_char != '%'et number

			write_to_buffer(list);
		else
		{
			/*parse and get the corresponding helper function*/
			parse_specifier(list);
			specifier_func = get_specifier_function(list);

			/*If there is a valid specifier function, it is called*/
			if (specifier_func)
				specifier_func(list);
			else if (list->next_char)
			{
				if (list->flag)
					list->flag = 0;
				/*Write the special character after % to buffer*/
				write_to_buffer(list);
			}
			else
			{
				/*Handle spaces, replaces it with '0' & set error flag*/
				 /* to indicate an invalid specifier*/
				if (list->space)
					list->buffer[--(list->buffer_index)] = '0';
				list->error = 1;
			}
		}
		list->index++;
	}
	/*Finalize and return the result*/
	return (finalize_inventory(list));
}
