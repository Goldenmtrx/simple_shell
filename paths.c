#include "shell.h"

/**
 * _getv - retrieves the value of an environment variable.
 * @nm: string input
 * Return: value of an environment variable
 */

char *_getv(char *nm)
{
	int i = -1;
	size_t nm_len;

	if (nm == NULL || *nm == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	nm_len = _strlen(nm);

	while (environ[++i])
	{
		if (!_strncmp(environ[i], nm, nm_len) && environ[i][nm_len] == '=')
		{
			return (environ[i] + nm_len + 1);
		}
	}
	return (NULL);
}

/**
 * _which - locate the executable file associated with a given command.
 * @data: string input
 * Return: void
 */
int _which(data *data)
{
	char *token, *path,
		*paths = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t token_len;
	int find = -1;

	if (!_getenv("PATH"))
		goto step_out;
	_strcpy(paths, _getenv("PATH"));
	if (paths == NULL)
		goto step_out;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _strlen(token) + _strlen(data->av[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, data->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(data->av[0]);
			data->av[0] = _strdup(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
step_out:
	free(paths);
	return (find);
}

/**
 * create_new_entry - Initialize a new environment variable,
 *  or modify an existing one
 * @nm: variable name
 * @value: variable value
 * Return: void
 */
char *create_new_entry(char *nm, char *value)
{
	size_t new_len = strlen(nm) + strlen(value) + 2;
	char *new_entry = malloc(new_len);

	if (new_entry == NULL)
		return (NULL);

	strcpy(new_entry, nm);
	strcat(new_entry, "=");
	strcat(new_entry, value);

	return (new_entry);
}
/**
 * _new_environ - Initialize a new environment variable,
 *  or modify an existing one
 * @nm: variable name
 * @value: variable value
 * Return: void
 */
char **_new_environ(char *nm, char *value)
{
	int env_len = 0, i = 0;
	char *new_entry;
	char **new_environ;

	while (environ[env_len])
		env_len++;
	new_entry = create_new_entry(nm, value);
	if (new_entry == NULL)
		return (NULL);
	new_environ = _getenv(nm) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!new_environ)
	{
		free(new_entry);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(strlen(environ[i]) + 1);
		if (!new_environ[i])
		{
			free_array(new_environ);
			free(new_entry);
			return (NULL);
		}
		if (strncmp(environ[i], nm, strlen(nm)) == 0
		&& environ[i][strlen(nm)] == '=')
			strcpy(new_environ[i], new_entry);
		else
			strcpy(new_environ[i], environ[i]);
	}
	if (!_getenv(nm))
	{
		new_environ[env_len] = new_entry;
		new_environ[env_len + 1] = NULL;
	}
	else
		new_environ[env_len] = NULL;
	return (new_environ);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @data: to use the flag
 * @name: variable name
 * @value: variable value
 * Return: void
 */
int _setenv(data *data, char *nm, char *value)
{
	char **new_environ;

	if (!name || !value)
		return (-1);

	new_environ = _new_environ(nm, value);
	if (!new_environ)
		return (-1);
	environ = new_environ;
	data->flag_setenv = 1;

	return (0);
}
