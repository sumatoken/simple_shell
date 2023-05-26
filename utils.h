#ifndef UTILS_H_
#define UTILS_H_

#include <unistd.h>
#include <stdbool.h>

bool _is_whitespace(char *str);
char *read_input(void);
void execute_command(char *command, char **environ);

#endif
