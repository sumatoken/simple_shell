#include <stdbool.h>
#include "utils.h"

/**
 * _is_whitespace - Check if a string equals only whitespaces
 *
 * @str: String to check
 *
 * Description: Iterates over every single character of a string and check if
 *				it is a whitespace.
 *
 * Return: boolean
 */
bool _is_whitespace(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			return (false);
		}
	}
	return (true);
}
