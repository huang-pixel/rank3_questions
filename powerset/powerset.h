#ifndef POWERSET_H
# define POWERSET_H

#include <stdlib.h>
#include <stdio.h>

void	print_subset(int *subset, int size);
void	generate_set(int *nums, int nums_len, int *subset, int tgt,
		int subset_size, int sum, int start_idx, int *flag);

#endif

