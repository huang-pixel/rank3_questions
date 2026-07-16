#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int is_match(char *read, char *target)
{
    int i;

    i = 0;
    while (target[i])
    {
        if (target[i] != read[i])
            return (0);
        i++;
    }
    return (1);
}

char    *read_stdin(void)
{
    int     i;
    char    *buff;
    char    chunk[1024];
    ssize_t byte_read;
    size_t  total = 0;

    buff = malloc(1);
    if (!buff)
        return (NULL);
    buff[0] = '\0';

    while ((byte_read = read(STDIN_FILENO, chunk, 1024)) > 0)
    {
        buff = realloc(buff, total + byte_read + 1);
        if (!buff)
            return (NULL);
        i = 0;
        while (i < byte_read)
        {
            buff[i + total] = chunk[i];
            i++;
        }
        total += byte_read;
        buff[total] = '\0';
    }
    if (byte_read < 0)
    {
        free(buff);
        return (NULL);
    }
    return (buff);
}

int main(int ac, char **av)
{
    char    *read;
    char    *target;
    int     i;
    int     j;
    int     r_len;
    int     t_len;

    if (ac != 2)
        return (1);
    read = read_stdin();
    if (!read)
    {
        perror("Error");
        return (1);
    }
    r_len = strlen(read);

    target = av[1];
    t_len = strlen(target);

    if (t_len > 0)
    {
        i = 0;
        while (i < r_len)
        {
            if (is_match(read + i, target))
            {
                j = 0;
                while (j < t_len)
                {
                    read[i + j] = '*';
                    j++;
                }
                i += t_len;
            }
            else
                i++;
        }
    }
    printf("%s", read);
    free(read);
    return (0);
}