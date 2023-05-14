#include <stdbool.h>
#include "main.h"
#include "utils.h"

#define INITIAL_BUFFER_SIZE 1024

/**
 * _strlen - counts the length of the string
 * @str: string
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t length = 0;

	while (*str++)
		length++;
	return (length);
}

/**
 * _is_whitespace - Check if a string equals only whitespaces
 *
 * @str: String to check
 *
 * Description: Iterates over every single character of a string and check if
 *				it is a whitespace.
 *
 * Return: boolean
 */
bool _is_whitespace(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			return (false);
		}
	}
	return (true);
}

/**
 * execute_command - Executes a command received from the user with execve
 * @command: The command to execute
 *
 * @environ: The environment variables passed to the new process
 *
 * Description: This function forks a new process and executes the
 *              provided command in the child process. It waits
 *              for the child process to finish execution before
 *              returning.
 *
 * Return: This is a void function so it does not return a value.
 *         It directly exits the program in case of an error.
 */
void execute_command(char *command, char **environ)
{
	pid_t pid;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(command);
		return;
	}
	if (pid == 0)
	{
		execve(command, args, environ);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	free(command);
}

/**
 * read_input - Prompts the user and gets their input
 *
 * Description: This function writes a prompt to the standard output,
 *              allocates memory for the user's input, and reads the
 *              user's input from the standard input. It then removes
 *              the trailing newline character if present.
 *
 * Return: Returns a pointer to the user's input string. In case of an error,
 *         it returns NULL.
 */
char *read_input(void)
{
	ssize_t read_bytes;
	char *command = NULL;
	size_t input_size = 0;

	write(STDOUT_FILENO, "$ ", 2);

	read_bytes = getline(&command, &input_size, stdin);

	if (read_bytes == -1 && feof(stdin))
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (read_bytes == -1)
	{
		printf("Failed to read user input.\n");
		free(command);
		return (NULL);
	}

	if (read_bytes > 0 && command[read_bytes - 1] == '\n')
	{
		command[read_bytes - 1] = '\0';
	}

	return (command);
}