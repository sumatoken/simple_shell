#ifndef UTILS_H_
#define UTILS_H_

#include <unistd.h>

size_t _strlen(char *str);
bool _is_whitespace(char *str);
char *read_input(void);
void execute_command(char *command, char **environ);
char *read_input_0_2(void);
void execute_command_0_2(char **args, char **environ);

#endif
