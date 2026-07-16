#include "rip.h"

void    get(char *buf, int n, int balance, int idx, int open, int close)
{
    if (idx == n)
    {
        if (balance == 0 && open == 0 && close == 0)
            puts(buf);
        return ;
    }

    char    c = buf[idx];
    if (c == '(')
    {
        if (open > 0)
        {
            buf[idx] = ' ';
            get(buf, n, balance, idx + 1, open - 1, close);
            buf[idx] = '(';
        }
        get(buf, n, balance + 1, idx + 1, open, close);
    }
    else if (c == ')')
    {
        if (close > 0)
        {
            buf[idx] = ' ';
            get(buf, n, balance, idx + 1, open, close - 1);
            buf[idx] = ')';
        }
        if (balance > 0)
            get(buf, n, balance - 1, idx + 1, open, close);
    }
    else
        get(buf, n, balance, idx + 1, open, close);
}

int main(int ac, char **av)
{
    int     n;
    char    *input;

    /*if (ac != 2)
    {
        write (1, "\n", 1);
        return (0);
    }*/
    if (ac != 2)
        return (1);
    input = av[1];
    n = 0;
    while (input[n])
        n++;
    if (n == 0)
    {
        write (1, "\n", 1);
        return (0);
    }

    char    buf[MAX_LEN];
    int     i;

    i = 0;
    while (i < n)
    {
        buf[i] = input[i];
        i++;
    }
    buf[n] = '\0';

    int open = 0;
    int close = 0;

    i = 0;
    while (i < n)
    {
        if (buf[i] == '(')
            open++;
        else if (buf[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
        i++;
    }
    get(buf, n, 0, 0, open, close);
    return (0);
}