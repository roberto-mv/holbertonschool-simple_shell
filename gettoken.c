#include "main.h"

/**
 * gettoken - searchs for tokens
 * @ps: pointer to string
 * @es: end of string
 * @q: pointer to argument string
 *
 * Return: the token found
 */
int gettoken(char **ps, char *es, char **q)
{
	char *s;
	char delim[] = " \t\r\v", sym[] = ";\n";
	int token;

	s = *ps;
	while (s < es && strchr(delim, *s))
		s++;
	if (q)
		*q = s;
	token = *s;
	switch (*s)
	{
		case 0:
			break;
		case '\n':
		case ';':
			s++;
			break;
		default:
			token = 'a';
			while (s < es && !strchr(delim, *s) && !strchr(sym, *s))
				s++;
			break;
	}
	while (s < es && strchr(delim, *s))
		s++;
	*ps = s;
	return (token);
}
