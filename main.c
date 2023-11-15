#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or appropriate exit code
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		display_prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			if (feof(stdin))
			{
				/* EOF received (Ctrl+D) */
				putchar('\n');
				exit(EXIT_SUCCESS);
			}
			else
			{
				/* Some other error occurred */
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		line[nread - 1] = '\0'; /* Remove newline character */
		if (execute_command(line) == -1)
			print_error(line);
	}

	free(line);
	return (0);
}
