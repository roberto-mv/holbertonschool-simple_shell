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
	int fd;

	(void) av;
	/* Ensure that three file descriptors are open */
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
	while (getcmd(&line) >= 0)
	{
		if (isabuiltin(line) == BUILTIN_FAIL)
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
