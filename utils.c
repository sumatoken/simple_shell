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
 * _strcpy - string copy
 * @dest: dest string
 * @src: source string
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

    while (*src)
        *ptr++ = *src++;
    *ptr = *src;

    return (dest);
}