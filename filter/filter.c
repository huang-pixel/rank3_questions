/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:51:54 by hhuang2           #+#    #+#             */
/*   Updated: 2026/07/08 19:25:02 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>

char	*read_stdin(void)
{
	int		i;
	char	chunk[1024];
	ssize_t	byte_read;
	size_t	old_size = 0; // where do I paste the next chunk
	char	*buff;

	buff = malloc(1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';

	// read from stdin, put it in chunk, max 1024 bytes
	// every loop, read overwrites chunk
	while ((byte_read = read(STDIN_FILENO, chunk, 1024)) > 0)
	{
	// realloc takes existing data and expand more space
		buff = realloc(buff, old_size + byte_read + 1);
		if (!buff)
			return (NULL);
		// copy chunk into buff
		i = 0;
		while (i < byte_read)
		{
			buff[old_size + i] = chunk[i];
			i++;
		}
		old_size += byte_read;
		buff[old_size] = '\0';
	}
	if (byte_read < 0)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

int	is_match(char *str_read, char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] != str_read[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	char	*read;
	char	*target;
	int		read_len;
	int		tgt_len;
	int		i;
	int		j;

	if (ac != 2)
		return (1);

	read = read_stdin();
	if (!read)
	{
		perror("Error");
		return (1);
	}
	read_len = strlen(read);

	target = av[1];
	tgt_len = strlen(target);

	if (tgt_len > 0)
	{
		i = 0;
		while (i < read_len)
		{
			if (is_match(read + i, target))
			{
				j = 0;
				while (j < tgt_len)
				{
					read[i + j] = '*';
					j++;
				}
				i += tgt_len;
			}
			else
				i++;
		}
	}
	printf("%s", read);
	free(read);
	return (0);
}
