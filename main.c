#include "shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv;
	int status;

	while (1)
	{
		printf("#cisfun$ ");  /* Display prompt */
		nread = getline(&line, &len, stdin);  /* Read command */
		if (nread == -1)
		{
			if (feof(stdin))
			{
				/* Handle EOF (Ctrl+D) */
				printf("\n");
				free(line);
				exit(EXIT_SUCCESS);
			} else
			{
				/* Handle other getline errors */
				perror("getline");
				continue;
			}
		}

		line[nread - 1] = '\0';  /* Remove newline character */
		argv = tokenize(line, " ");  /* Tokenize the input */

		if (argv[0] != NULL)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(argv[0]);
			}
		}

		free(argv);
	}

	free(line);
	return (0);
}
