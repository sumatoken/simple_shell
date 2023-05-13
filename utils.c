#include <stdbool.h>
#include "utils.h"
/**
 * _strlen - counts the length of the string
 * @str: string
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t length = 0;

	while (*str++)
		length++;
	return (length);
}

/**
 * _is_whitespace - Check if a string equals only whitespaces
 * @description: Iterates over every single character of a string and check if it a whitespace
 * @str: String to check
 * Return: string
 */
bool _is_whitespace(char *str)
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			return false;
		}
	}
	return true;
}