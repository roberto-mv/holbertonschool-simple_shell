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
	char *line = NULL;
	struct cmd *cmd_tree;

	(void) av;
	while (getcmd(&line) >= 0)
	{
		if (isabuiltin(line) != -1)
			continue;

		cmd_tree = parsecmd(line);
		if (cmd_tree == NULL)
		{
			if (!isatty(STDIN_FILENO))
			{
				safe_free(&line);
				exit(127);
			}
			else
			{
				continue;
			}
		}

		if (forking() == 0)
			runcmd(cmd_tree);
		wait(0);
		free_tree(cmd_tree);
	}
	return (EXIT_SUCCESS);
}
