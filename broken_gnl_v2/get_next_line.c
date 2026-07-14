#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
  /*int i = 0;
  while(s[i] != c)
    i++;
  if (s[i] == c)
    return s + i;
  else
    return NULL;*/
		
	int	i;

	i = 0;
	// real strchr does not check if s is NULL
	// not sure if I have to check that in gnl
	while (s[i])
	{
		if ((char)c == s[i])
			return (s + i);
		i++;
	}
	// c is '\0', return pointer to string terminator
	if ((char)c == s[i])
		return (s);
	return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
  /*while(--n > 0)
    ((char *)dest)[n - 1] = ((char *)src)[n - 1];
  return dest;*/
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
  /*size_t res = 0;
  while (*s)
  {
    s++;
    res++;
  }
  return res;*/
	size_t	i;
	size_t	res;

	res = 0;

	// check if s is NULL
	// do I have to check str = "" ? later
	if (!s)
		return (res);
	i = 0;
	while (s[i])
	{
		i++;
		res++;
	}
	return (res);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  /*size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1;*/
	size_t	size1;
	char	*tmp;

	if (*s1)
		size1 = ft_strlen(*s1);
	else
		size1 = 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
  /*if (dest > src)
    return ft_memmove(dest, src, n);
  else if (dest == src)
    return dest;
  size_t i = ft_strlen((char *)src) - 1;
  while (i >= 0)
  {
    ((char *)dest)[i] = ((char *)src)[i];
    i--;
  }
  return dest;*/
	size_t	i;
	char	*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		d = d + n;
		s = s + n;
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

char *get_next_line(int fd)
{
  /*static char b[BUFFER_SIZE + 1] = "";
  char *ret = NULL;
  char *tmp = ft_strchr(b, '\n');
  while(!tmp)
  {
    if (!str_append_str(&ret, b))
      return (NULL);
    int read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret == -1)
      return (NULL);
    b[read_ret] = 0;
  }
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  return ret;*/
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret = NULL;
	char		*tmp;
	int			read_ret;

	while (1)
	{
		tmp = ft_strchr(b, '\n');
		if (tmp)
		{
			if (!str_append_mem(&ret, b, tmp - b + 1))
				return (free(ret), NULL);
			ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
			return (ret);
		}
		if (!str_append_str(&ret, b))
				return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			b[0] = '\0';
			if (ret && *ret)
				return (ret);
			free(ret);
			return (NULL);
		}
		b[BUFFER_SIZE] = '\0';
	}
}
