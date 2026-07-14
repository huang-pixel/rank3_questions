#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	to_copy[200] = "";
	char	src[] = "hello world";

	// printf("size of to copy: %lu\n", sizeof(to_copy));
	// printf("size of src: %lu\n", sizeof(src));
	memcpy(to_copy, src, 8);
	printf("string to copy is %s\n", to_copy);
	return (0);
}

/*void *ft_memcpy(void *dest, const void *src, size_t n)
{
  while(--n > 0)
    ((char *)dest)[n - 1] = ((char *)src)[n - 1];
  return dest;
}*/

/*int	main(void)
{
	char	to_copy[200] = "";
	char	src[] = "hello world";

	ft_memcpy(to_copy, src, 8);
	printf("string to copy is %s\n", to_copy);
	return (0);
}*/
