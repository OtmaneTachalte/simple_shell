#include "shell.h"

/**
 * tokenize - Splits a string into tokens
 * @line: The string to tokenize
 * @delim: The delimiter to use for splitting the string
 *
 * Return: Array of tokens
 */
char **tokenize(char *line, const char *delim)
{
	char **tokens = malloc(sizeof(char *) * TOKEN_BUF_SIZE);
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("Failed to allocate tokens");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;  /* NULL terminate the array */

	return (tokens);
}
