#include "main.h"

/**
 * main - entry point
 * @ac: arguments counter
 * @av: arguments vector
 *
 * Return: always EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)), char **av)
{
	/* Buffer that will store the user's input */
	char *line = NULL;
	struct cmd *cmd_tree;

	(void) av;
	signal(SIGINT, &handle_sigint);

	/* Read and run input commands */
	while (getcmd(&line) >= 0)
	{
		if (isabuiltin(line) == BUILTIN_FAIL)
			continue;

		cmd_tree = parsecmd(line);
		if (cmd_tree == NULL)
			continue;

		if (forking() == 0)
			runcmd(cmd_tree);
		wait(0);
		free_tree(cmd_tree);
	}

	return (EXIT_SUCCESS);
}
