#include "permutations.h"

void	perm(int n, int *tab, int depth, char *buf)
{
	if (depth == n)
	{
		buf[n] = '\0';
		puts(buf);
		return ;
	}
	int	c = 0;
	while (c < 256)
	{
		if (tab[c])
		{
			buf[depth] = (char)c;
			tab[c]--;
			perm(n, tab, depth + 1, buf);
			tab[c]++;
		}
		c++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ac == 2 && av[1][0])
	{
		int		tab[256] = {0};
		int		n;
		int		i;
		char	*buf;

		n = strlen(av[1]);
		buf = malloc(n + 1);
		if (!buf)
			return (1);
		i = 0;
		while (i < n)
		{
			tab[(unsigned char)av[1][i]]++;
			i++;
		}
		perm(n, tab, 0, buf);
		free(buf);
	}
	return (0);
}