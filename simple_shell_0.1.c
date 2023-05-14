#include "main.h"

/**
 * simple_shell_0_1 - The main function for the shell
 *
 * @environ: The environment variables passed to the new process
 *
 * Description: This function continually gets user input and executes
 *              the corresponding command until an error occurs or the
 *              user quits the shell. It handles memory allocation errors
 *              and read errors.
 *
 * Return: This is a void function so it does not return a value.
 */
void simple_shell_0_1(char **environ)
{
	bool status = true;
	struct stat st;

	while (status == true)
	{
		char *command = read_input();

		if (command == NULL)
		{
			return;
		}
		if (_is_whitespace(command))
		{
			free(command);
			continue;
		}

		if (stat(command, &st) == -1)
		{
			write(STDOUT_FILENO, command, _strlen(command));
			write(STDOUT_FILENO, ": NOT FOUND\n", 12);
			free(command);
			continue;
		}

		execute_command(command, environ);
	}
}
