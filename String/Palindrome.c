#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 100

int main()
{
	char string[STRING_SIZE];
	scanf("%s", string);

	const size_t string_length = strlen(string);

	size_t i;
	for (i = 0; i < string_length / 2; ++i)
	{
		if (tolower(string[i]) != tolower(string[string_length - i - 1]))
		{
			printf("Word \"%s\" isn't Palindrome.\n", string);
			return 0;
		}
	}

	printf("Word \"%s\" is Palindrome.\n", string);
	return 0;
}