#ifndef RIP_H
# define RIP_H

#include <unistd.h>
#include <stdio.h>

# define MAX_LEN 4096

void    get(char *buf, int n, int balance, int idx, int open, int close);

#endif