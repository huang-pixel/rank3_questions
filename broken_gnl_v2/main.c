#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **argv)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
