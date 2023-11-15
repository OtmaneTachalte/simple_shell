#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* Define buffer sizes for tokenization and line reading */
#define READ_BUF_SIZE 1024
#define TOKEN_BUF_SIZE 64  /* Adjust as needed */

extern char **environ;

/* Function Prototypes */
char **tokenize(char *line, const char *delim);

#endif /* _SHELL_H_ */
