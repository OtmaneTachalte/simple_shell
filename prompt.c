#include "shell.h"

/**
 * display_prompt - Displays the command prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
