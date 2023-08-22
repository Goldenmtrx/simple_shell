#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

char *get_path(char *cmd);
void exe_cmd(char **args);
int shell(int ac, char **av);

#endif /* SHELL_H */
