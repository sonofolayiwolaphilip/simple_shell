#ifndef JGMAIN_H
#define JGMAIN_H

#define MAX_ARGS 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

extern char **environ;

typedef struct
{
	char **env;
} Shell;

void display_prompt(void);
void JGread(char *command, size_t size);
void JGexecute(const char *command);
void JGexit(const char *status);
void JGprint(const char *message);
int _putchar(char c);
void JGcd(const char *path);
void JGhelp(void);
void handle_builtin(const char *command);
void JGprint_environment(const char *env[]);
void JGset_environment(Shell *shell, const char *variable, const char *value);
void JGunset_environment(Shell *shell, const char *variable);
void execute_external_command(char *const args[]);
char **parse_command(const char *command);
void redirect_input(const char *input_file);
void redirect_output(const char *output_file);
void execute_command(const char *command);
void JGenv(Shell *shell);
const char *JGgetenv(const Shell *shell, const char *variable);
void JGpopulate_env_list(Shell *shell);
void execute_child_process(const char *command);
void JGexecute_with_path(const char *command);
int search_in_path(const char *command, const char *path, char *full_path);
char **tokenize_input(const char *input);
void free_tokens(char **tokens);
void print_tokens(char **tokens);
void interactive_mode(void);
void handle_commands(const char *input);
void handle_logical_operators(const char *input);
void handle_variables(char *input, int status);
void handle_comments(char *input);
void create_pipe(int pipe_fds[2]);
void execute_pipeline(char **pipeline);
void handle_pipeline(const char *command);
void execute_commands_from_file(const char *file_path);
int main(int argc, char *argv[]);

#endif
