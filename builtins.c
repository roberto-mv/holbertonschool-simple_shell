#include "main.h"

/**
 * bin_exit - exits the program whit a status
 * @ps: pointer to string
 *
 * Return: nothing
 */
int bin_exit(char **ps)
{
	char *temp;
	char *exit_status;
	char whitespace[] = " \t\n\r\v";
	int i, status;

	temp = strtok(*ps, whitespace);
	temp = strtok(NULL, whitespace);
	if (temp == NULL)
	{
		safe_free(ps);
		exit(0);
	}

	exit_status = temp;
	for (i = 0; exit_status[i] != '\0'; i++)
	{
		if (exit_status[i] < '0' || exit_status[i] > '9')
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", temp);
			safe_free(ps);
			exit(2);
		}
	}

	temp = strtok(NULL, whitespace);
	if (temp != NULL)
	{
		fprintf(stderr, "./hsh: 1: exit: too many arguments\n");
		return (BUILTIN_FAIL);
	}

	if (isatty(STDIN_FILENO))
		printf("exit\n");
	status = atoi(exit_status);
	safe_free(ps);
	exit(status);
}

/**
 * bin_cd - change directory
 * @ps: pointer to string
 *
 * Return: nothing
 */
int bin_cd(char **ps)
{
	char *temp, *leftovers;
	char whitespace[] = " \t\n\r\v";

	temp = strtok(*ps, whitespace);
	temp = strtok(NULL, whitespace);
	if (temp == NULL)
		return (1);

	leftovers = strtok(NULL, whitespace);
	if (leftovers != NULL)
	{
		fprintf(stderr, "hsh: cd: too many arguments\n");
		return (1);
	}

	if (chdir(temp) < 0)
	{
		fprintf(stderr, "hsh: cd: %s: No such file or directory\n", temp);
		return (1);
	}

	return (BUILTIN_SUCCESS);
}

/**
 * bin_env - prints the current environment
 * @ps: pointer to string
 *
 * Return: nothing
 */
int bin_env(char **ps)
{
	char **env = environ;
	int i;

	(void) ps;
	if (env == NULL)
		return (BUILTIN_FAIL);

	for (i = 0; env[i] != NULL; i++)
		printf("%s\n", env[i]);

	return (BUILTIN_SUCCESS);
}
