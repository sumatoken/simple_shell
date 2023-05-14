#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utils.h"
#include "main.h"

#define INITIAL_BUFFER_SIZE 1024
#define INPUT_EOF ((char *)-1)

extern char **environ;

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
	ssize_t bytesRead;
	char *command = malloc(INITIAL_BUFFER_SIZE);

	if (command == NULL)
	{
		write(2, "Memory allocation failed\n", 24);
		return (NULL);
	}

	write(STDOUT_FILENO, "$ ", 2);

	bytesRead = read(STDIN_FILENO, command, INITIAL_BUFFER_SIZE - 1);
	if (bytesRead > 0)
	{
		command[bytesRead] = '\0';
	}
	else if (bytesRead == 0 && command[0] == '\0')
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		free(command);
		return (NULL);
	}

	if (_strlen(command) > 0 && command[_strlen(command) - 1] == '\n')
	{
		command[_strlen(command) - 1] = '\0';
	}

	return (command);
}

/**
 * execute_command - Executes a command received from the user with execve
 * @command: The command to execute
 *
 * Description: This function forks a new process and executes the
 *              provided command in the child process. It waits
 *              for the child process to finish execution before
 *              returning.
 *
 * Return: This is a void function so it does not return a value.
 *         It directly exits the program in case of an error.
 */
void execute_command(char *command)
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
 * simple_shell_0_1 - The main function for the shell
 *
 * Description: This function continually gets user input and executes
 *              the corresponding command until an error occurs or the
 *              user quits the shell. It handles memory allocation errors
 *              and read errors.
 *
 * Return: This is a void function so it does not return a value.
 */
void simple_shell_0_1(void)
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

		execute_command(command);
	}
}
