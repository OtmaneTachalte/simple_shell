#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @cmd: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *cmd)
{
	pid_t pid;
	int status;
	char *argv[64]; /* Array to hold arguments */
	char *token;
	int i = 0;

	/* Split cmd into arguments */
	token = strtok(cmd, " \t\n");
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL; /* Null terminate the array of arguments */

	if (argv[0] == NULL)
	{
		/* Empty command */
		return (0);
	}

	pid = fork();
	if (pid == -1)
	{
		/* Forking failed */
		perror("Error");
		return (-1);
	} else if (pid == 0)
	{
		/* Child process */
		if (execvp(argv[0], argv) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	} else {
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
