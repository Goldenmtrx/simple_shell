#include "shell.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @st: string input
 *
 * Return: pointer
 */
char *_strdup(const char *st)
{
	int i, len = 0;
	char *result;

	if (st == NULL)
		return (NULL);

	while (st[len] != '\0')
		len++;

	result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = st[i];

	return (result);
}


/**
 * _isnumber - check if a string is a number
 * @stat: string to be checked
 * Return: void
 */
int _isnumber(const char *stat)
{
	if (stat == NULL || stat[0] == '\0')
		return (0);
	while (*stat)
	{
		if (!_isdigit(*stat))
			return (0);
		stat++;
	}
	return (1);
}


/**
 * _isdigit - check if char is number
 * @c: char
 * Return: 1 if its a digit 0 if not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

