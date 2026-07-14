#include "powerset.h"

void	print_subset(int *subset, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", subset[i]);
		if (i < size - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	generate_set(int *nums, int nums_len, int *subset, int tgt,
		int subset_size, int sum, int start_idx, int *flag)
{
	if (start_idx == nums_len)
	{
		if (sum == tgt)
		{
			if (subset_size > 0)
			{
				print_subset(subset, subset_size);
				*flag = 1;
			}
		}
		return ;
	}
	generate_set(nums, nums_len, subset, tgt, subset_size, sum,
			start_idx + 1, flag);
	subset[subset_size] = nums[start_idx];
	generate_set(nums, nums_len, subset, tgt, subset_size + 1,
			sum + nums[start_idx], start_idx + 1, flag);
}

int	main(int ac, char **av)
{
	int	i;
	int	tgt;
	int	nums_len;
	int	*nums;
	int	*subset;
	int	flag;

	if (ac < 3)
		return (1);
	tgt = atoi(av[1]);
	nums_len = ac - 2;
	nums = malloc(sizeof(int) * nums_len);
	if (!nums)
		return (1);
	i = 0;
	while (i < nums_len)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	subset = malloc(sizeof(int) * nums_len);
	if (!subset)
	{
		free(nums);
		return (1);
	}
	flag = 0;
	generate_set(nums, nums_len, subset, tgt, 0, 0, 0, &flag);
	if (tgt == 0 && !flag)
		printf("\n");
	free(nums);
	free(subset);
	return (0);
}
