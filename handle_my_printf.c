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
