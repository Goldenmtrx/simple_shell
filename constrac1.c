#include "shell.h"

/**
 * constrac_cd - change directory
 * @data: data struct input
 * Return: void
 */
void constrac_cd(data *data)
{
	char *dir = data->av[1];
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	_setenv(data, "PWD", cwd);
	if (!dir)
		dir = _getv("HOME");
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		_setenv(data, "OLDPWD", _getv("PWD"));
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd() error");
		_setenv(data, "PWD", cwd);
	}
}
