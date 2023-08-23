#include "shell.h"

/**
 * new_process - start a new process
 * @data: data struct input
 * Return: void
 */

void new_process(data *data)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(data->av[0], data->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		data->last_exit_status = WEXITSTATUS(status);
	return;
free:
	perror(data->shell_name);
	free_array(data->av);
	free(data->cmd);
	exit(EXIT_FAILURE);
}

/**
 * handler_sigint - Signal handler function
 * @signal: int input
 * Return: void
 */

void handler_sigint(int signal)
{
	/*const char prompt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}

/**
 * _exec - exectute cmd
 * @data: data struct input
 * Return: void
 */

void _exec(data *data)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, handler_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(data);
		if (_strlen(data->cmd) != 0)
		{
			split(data, " ");
			if (!exec_builtin(data))
			{
				_which(data);
				if (access(data->av[0], F_OK) == -1)
				{
					perror(data->shell_name);
				}
				else
				{
					start_process(data);
				}
			}
			free_array(data->av);
		}
		free(data->cmd);
	}
}
