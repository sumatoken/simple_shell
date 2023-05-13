#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "utils.h"
#include "main.h"
/**
 * simple_shell_0_1 - simple shell interface
 *
 * Description: Prompts the user to input a command and executes it
 *
 * Return: No return value
 */

#define INITIAL_BUFFER_SIZE 1024

void simple_shell_0_1(void)
{
	bool status = true;
	ssize_t bytesRead;
	pid_t pid;
	char *args[2];
	args[1] = NULL;

	while (status == true)
	{
		char *command = malloc(INITIAL_BUFFER_SIZE);
		if (command == NULL)
		{
			write(2, "Memory allocation failed\n", 24);
			return;
		}

		write(STDOUT_FILENO, "$ ", 2);

		bytesRead = read(STDIN_FILENO, command, INITIAL_BUFFER_SIZE - 1);
		if (bytesRead >= 0)
		{
			command[bytesRead] = '\0';
		}
		else
		{
			write(2, "Read error\n", 11);
			free(command);
			return;
		}

		if (_strlen(command) > 0 && command[_strlen(command) - 1] == '\n')
		{
			command[_strlen(command) - 1] = '\0';
		}

		args[0] = command;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(command);
			return;
		}
		if (pid == 0)
		{
			execve(command, args, NULL);
			perror("execv");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}

		free(command);
	}
}
