#include "main.h"
#include "utils.h"

#define INITIAL_BUFFER_SIZE 1024

/**
 * parse_command - Splits a command string into an array of tokens/arguments.
 * @command: The command string to split.
 *
 * Description: This function takes a command string, splits it into an array
 *              of tokens using space and special characters as delimiters,
 *              and returns a pointer to the array. The array is dynamically
 *              allocated and must be freed by the caller.
 *
 * Return: Returns a pointer to the array of tokens. In case of an error,
 *         it prints an error message to stderr and exits.
 */
char **parse_command(char *command)
{
	int buffer_size = 64;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[position] = token;

		position++;
		if (position >= buffer_size)
		{
			buffer_size += buffer_size;
			tokens = realloc(tokens, buffer_size * sizeof(char *));

			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[position] = NULL;

	return (tokens);
}

/**
 * execute_command_0_2 - Executes a command with potential arguments received
 *from the user with execve
 *
 * @environ: The environment variables passed to the new process
 * @args: The arguments to pass to the command
 * Description: This function forks a new process and executes the
 *              provided command in the child process. It waits
 *              for the child process to finish execution before
 *              returning.
 *
 * Return: This is a void function so it does not return a value.
 *         It directly exits the program in case of an error.
 */
void execute_command_0_2(char **args, char **environ)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(args);
		return;
	}
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	free(args);
}

/**
 * read_input_0_2 - Prompts the user and gets their input
 *
 * Description: This function writes a prompt to the standard output,
 *              allocates memory for the user's input, and reads the
 *              user's input from the standard input. It then removes
 *              the trailing newline character if present.
 *
 * Return: Returns a pointer to the user's input string. In case of an error,
 *         it returns NULL.
 */
char *read_input_0_2(void)
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

/**
 * simple_shell_0_2 - The main function for the shell
 *
 * @environ: The environment variables passed to the new process
 *
 * Description: This function continually gets user input and executes
 *the corresponding command with potential arguments until
 *an error occurs or the user quits the shell.
 *It handles memory allocation errors and read errors.
 *
 * Return: This is a void function so it does not return a value.
 */
void simple_shell_0_2(char **environ)
{
	bool status = true;
	struct stat st;

	while (status == true)
	{
		char *command = read_input_0_2();
		char **args = parse_command(command);
		char *command_name = args[0];

		if (command == NULL)
		{
			free(args);
			free(command);
			return;
		}
		if (_is_whitespace(command))
		{
			free(command);
			free(args);
			continue;
		}
		if (stat(command_name, &st) == -1)
		{
			write(STDOUT_FILENO, command_name, strlen(command_name));
			write(STDOUT_FILENO, ": NOT FOUND\n", 12);
			free(command);
			free(args);
			continue;
		}

		execute_command_0_2(args, environ);
		free(command);
	}
}
