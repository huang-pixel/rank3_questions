#include "n_queens.h"

#define MAX_N 20

void    print(int *tab, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        fprintf(stdout, "%d", tab[i]);
        if (i < n - 1)
            fprintf(stdout, " ");
        i++;
    }
    fprintf(stdout, "\n");
}

int is_safe(int *tab, int col, int row)
{
    int i;

    i = 0;
    while (i < col)
    {
        if (tab[i] == row || (tab[i] - row == i - col) || (tab[i] - row == col - i))
            return (0);
        i++;
    }
    return (1);
}

void    solve(int *tab, int col, int n)
{
    if (col == n)
    {
        print(tab, n);
        return ;
    }
    int row = 0;
    while (row < n)
    {
        if (is_safe(tab, col, row))
        {
            tab[col] = row;
            solve(tab, col + 1, n);
        }
        row++;
    }
}

int main(int ac, char **av)
{
    int n;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    n = atoi(av[1]);
    if (n < 1 || n > MAX_N)
    {
        write(1, "\n", 1);
        return (0);
    }
    int tab[MAX_N];
    solve(tab, 0, n);
    return (0);
}
