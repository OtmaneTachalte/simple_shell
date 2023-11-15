#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Function prototypes */
void display_prompt(void);
int execute_command(char *cmd);
void print_error(char *cmd);

#endif /* SHELL_H */
