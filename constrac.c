#include "shell.h"

/**
 * exec_cons - check if built in and then exec
 * @d: data struct input
 * Return: 1 if built in, 0 if not
 */
int exec_cons(data *d)
{
	constrac constrac[] = {
		{"exit", constrac_exit},
		{"env", constrac_env},
		{"setenv", constrac_setenv},
		{"unsetenv", constrac_unsetenv},
		{"cd", constrac_cd},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; constrac[i].cmd; i++)
	{
		if (_strcmp(d->av[0], constrac[i].cmd) == 0)
		{
			constrac[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * constrac_exit - exits the shell
 * @d: data struct input
 * Return: void
 */
void constrac_exit(data *d)
{
	const char *errorString = "./hsh: 1: exit: Illegal number: ";

	if (d->av[1])
	{
		if (d->av[1][0] != '-' && _isnumber(d->av[1]))
			d->last_exit_status = atoi(d->av[1]);
		else
		{
			write(STDERR_FILENO, errorString, strlen(errorString));
			write(STDERR_FILENO, d->av[1], strlen(d->av[1]));
			write(STDERR_FILENO, "\n", 1);
			d->last_exit_status = 2;
		}
	}
	free_array(d->av);
	free(d->cmd);
	if (d->flag_setenv)
		free_array(environ);
	exit(d->last_exit_status);
}

/**
 * constrac_env - prints the current environment
 * @d: data struct input
 * Return: void
 */
void constrac_env(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}
/**
 * constrac_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @data: data struct input
 * Return: void
 */

void constrac_setenv(data *data)
{
	(void)data;
	if (data->av[1] && data->av[2])
	{
		if (_setenv(data, data->av[1], data->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * constrac_unsetenv - Remove an environment variable
 * @data: data struct input
 * Return: void
 */
void constrac_unsetenv(data *data)
{
	int i, j;
	int len;

	(void)data;
	if (!data->av[1] || !_getv(data->av[1]))
	{
		_perror(data->shell_nm, "variable not found.");
		return;
	}
	len = strlen(data->av[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], data->av[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}
