#include "shell.h"

/*
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[] = {NULL, NULL};

	while (1) {
		printf("#cisfun$ ");  /* Display prompt */
		nread = getline(&line, &len, stdin);  /* Read command */
		if (nread == -1) {
			break;  /* Handle EOF (Ctrl+D) */
		}

		line[nread - 1] = '\0';  /* Remove newline character */
		argv[0] = line;  /* Set command for execution */

		if (execve(line, argv, environ) == -1) {
			perror(line);  /* Print error if command execution fails */
		}
	}

	free(line);
	return 0;
}
