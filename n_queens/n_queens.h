#ifndef N_QUEENS_H
# define N_QUEENS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    print(int *tab, int n);
int     is_safe(int *tab, int col, int row);
void    solve(int *tab, int col, int n);

#endif