#include "main.h"

/**
 * free_tree - frees the command tree
 * @cmd: pointer to the tree of type struct cmd
 *
 * Return: nothing
 */
void free_tree(struct cmd *cmd)
{
	struct execcmd *ecmd;
	struct listcmd *lcmd;

	switch (cmd->type)
	{
		case EXEC:
			ecmd = (struct execcmd *)cmd;
			if (ecmd->argv[0] != NULL)
				free(ecmd->argv[0]);
			free(ecmd);
			break;

		case LIST:
			lcmd = (struct listcmd *)cmd;
			if (lcmd->left != NULL)
				free_tree(lcmd->left);
			if (lcmd->right != NULL)
				free_tree(lcmd->right);
			free(lcmd);
			break;
	}
}

/**
 * safe_free - frees the given pointer and sets it to NULL
 * @ps: pointer to the string
 *
 * Return: nothing
 */
void safe_free(char **ps)
{
	if (ps && *ps)
	{
		free(*ps);
		*ps = NULL;
	}
}
