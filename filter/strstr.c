// Source - https://stackoverflow.com/a/7500951
// Posted by Robert S. Barnes, modified by community. See post 'Timeline' for change history
// Retrieved 2026-06-26, License - CC BY-SA 3.0

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "sdfadabcGGGGGGGGG";
	char *result = strstr(str, "abc");
	int position = result - str;
	printf("substring index is %d\n", position);
	int substringLength = strlen(str) - position;
	printf("substring length is %d\n", substringLength);
	return (0);
}

