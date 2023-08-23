#include "shell.h"

/**
 * endline_helper - getline helper function
 * @lineptr: string input
 * @n: int input
 * Return: int
 */
int endline_helper(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * endline - reads the input from FILE
 * @linep: string input
 * @n: int input
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t endline(char **linep, size_t *n, FILE *stream)
{
	ssize_t bytesRead = 0;
	size_t position = 0, newSize;
	static char buf[READ_BUF_SIZE];
	static size_t bufSize, bufPos;
	char *newBuffer;

	if (linep == NULL || n == NULL || stream == NULL
		|| endline_helper(linep, n) == -1)
		return (-1);
	while (1)
	{
		if (bufPos >= bufSize)
		{
			bytesRead = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytesRead <= 0 && position == 0)
				return (-1);
			else if (bytesRead <= 0)
				break;
			bufSize = bytesRead;
			bufPos = 0;
		}
		if (position >= *n - 1)
		{
			newSize = *n * 2;
			newBuffer = realloc(*linep, newSize);
			if (newBuffer == NULL)
				return (-1);
			*linep = newBuffer;
			*n = newSize;
		}
		(*linep)[position++] = buf[bufPos++];
		if ((*linep)[position - 1] == '\n')
			break;
	}
	(*linep)[position] = '\0';
	return (position);
}
