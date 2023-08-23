#ifndef SHELL_H
#define SHELL_H


#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - holds the main data.
 * @av: Array of tokens to pass
 * @cmd: The user input
 * @shell_name: name of the shell program
 * @last_exit_status: last command executed
 * @flag_setenv: 1 if user did exec setences
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} data;

/**
 * struct constrac - holds the main data.
 * @cmd: built in cmd
 * @f: function cmd
 */
typedef struct constrac
{
	const char *cmd;
	void (*f)(data *d);
} constrac;

/** constrac.c **/
int exec_cons(data *d);
void constrac_exit(data *d);
void constrac_env(data *d);
void constrac_setenv(data *data);
void constrac_unsetenv(data *data);
void constrac_cd(data *data);


/** help0.c **/
void _printf(const char *str);
void free_array(char **array);
void spliter(data *d, const char *delim);
void init_data(data *d, const char *shell_nm);
void put_cmd(data *d);

/** help1.c **/
void _printstr(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/** app.c **/
void new_process(data *data);
void handler_sigint(int signal);
void _exec(data *data);

/** paths.c **/
char *_getv(char *nm);
int _which(data *data);
int _setenv(data *data, char *nm, char *value);

/** string0.c **/
unsigned int _strlen(char *str);
int _strcmp(const char *sa, const char *sb);
int _strncmp(const char *sa, const char *sb, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


/** string1.c **/
char *_strdup(const char *st);
int _isnumber(const char *stat);
int _isdigit(int c);

/** endline.c **/
#define READ_BUF_SIZE 1024

ssize_t endline(char **linep, size_t *n, FILE *stream);


#endif
