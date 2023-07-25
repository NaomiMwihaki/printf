#include "main.h"
/**
 * build_inventory - builds variables inventory
 * @arguments: variadic arguments list
 * @format: format input string
 * Return: struct of arguments initialized
 */
inventory_t *build_inventory(va_list *arguments, const char *format)
{
	inventory_t *list;

	list = malloc(sizeof(inventory_t) * 1);

	if (list)
	{
		list->buffer = _calloc(BUFSIZE, sizeof(char));
		list->buf_index = 0;
		list->args = arguments;
		list->fmt = format;
		list->i = 0;
		list->flag = 0;
		if (!list->buffer)
			list->error = 1;
		else
			list->error = 0;
	}

	return (list);
}


/**
 * parse_specifiers - parses character that follow the % character
 * @list: the arguments inventory
 */
void parse_specifiers(inventory_t *list)
{
	int j, i = list->i + 1, space = 0;
	static const char flags[] = "hl+#";

	list->space = 0;
	while (list->fmt[i] == ' ')
		i++, list->i++, space = 1;

	list->c1 = list->fmt[i++];
	if (space && list->c1 != '+')
	{
		space = 0, list->space = 1, list->c0 = ' ';
		write_buffer(list);
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (list->c1 == flags[j])
		{
			while (list->fmt[i] == ' ')
				i++, list->i++, space = 1;
			if (space && list->c1 != '+')
			{
				list->c0 = ' ';
				write_buffer(list);
			}
			break;
		}
	}
	list->c2 = list->c1 ? list->fmt[i++] : '\0';
	list->c3 = list->c2 ? list->fmt[i] : '\0';
}

/**
* finalize_inventory - terminates _printf() in error cases
* @list: the arguments inventory with most commonly used arguments
* Return: -1 always
*/
Int finalize_inventory(inventory_t *list)
{
int ret_value;
if (list)
{
ret_value = list->error ? -1 : list->buf_index;
if (list->i)
puts_mod(list->buffer, list->buf_index);
va_end(*(list->arguments));
if (list->buffer)
free(list->buffer);
free(list);
}
else
ret_value = -1;
return (ret_value);
}

/* matchcases*/
/**
* get_specifier_func - matches specifier function for each conversion specifier
*
* @list: the arguments inventory with most commonly used arguments
* Return: pointer to the helper function or NULL
*/
void (*get_specifier_func(inventory_t *list))(inventory_t *)
{
int i = 0;
char check = list->ch1;
static get_t specifiers_list[] = {
{'d', print_int}, {'i', print_int}, {'x', print_lowhex}, {'X', print_uphex},
{'o', print_octal}, {'u', print_unsigned}, {'c', print_char}, {'s', print_string},
{'%', print_percent}, {'b', print_binary}, {'p', print_pointer},
{'r', print_rev_string}, {'R', print_rot13}, {'S', print_non_printable}, {'\0', NULL}
};
while (specifiers_list[i].ch != '0')
{
if (specifiers_list[i].ch == check)
{
list->i++;
return specifiers_list[i].func;
}
i++;
}
return NULL;
}
