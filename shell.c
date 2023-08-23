#include "shell.h"

/**
 * main - init data
 * @argc: input size of @argv
 * @argv: input array of command line arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	data data;
	(void)argc;
	init_data(&data, argv[0]);
	_exec(&data);

	return (0);
}
