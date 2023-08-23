#include "shell.h"

/**
 * _strlen - return the nuber of char in strings
 * @str: input
 * Return: number of char.
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - compares two strings.
 *
 * @sa: input constant string
 * @sb: input constant string
 *
 * Return: returns an indicating result of the comparison,
 *	as follows:
 *		• 0, if the sa and sb are equal
 *		• a negative value if sa is less than sb
 *		• a positive value if sa is greater than sb
 */
int _strcmp(const char *sa, const char *sb)
{
	int i;
	int res = 0;

	for (i = 0; sa[i] != '\0' && sb[i] != '\0'; i++)
	{
		if (sa[i] != sb[i])
		{
			res = sa[i] - sb[i];
			break;
		}
	}

	return (res);
}

/**
 * _strncmp - compares two strings.
 *
 * @sa: input constant string
 * @sb: input constant string
 * @n: input int
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the sa and sb are equal
 *		• a negative value if sa is less than sb
 *		• a positive value if sa is greater than sb
 */
int _strncmp(const char *sa, const char *sb, int n)
{
	int i;
	int res = 0;

	for (i = 0; sa[i] != '\0' && sb[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (sa[i] != sb[i])
		{
			res = sa[i] - sb[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy srcs to dest .
 *
 * @dest: input char *
 * @src: input const char *
 *
 * Return: char *
 */
char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcat - appends the src string to the dest string,
 *
 * @dest: input string
 * @src: input const string
 *
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
