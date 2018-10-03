#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t min(size_t a, size_t b);
int has_lf(char* string, size_t length);
size_t count_vowels(char* string);

int main()
{
	char* str = (char*)calloc(101, sizeof(char));
	char* p = str;
	size_t str_cap = 101;
	size_t str_total_len = 0;

	while (1)
	{
		fgets(p, 101, stdin);
		size_t str_len = min(strlen(p), 6);
		str_total_len += str_len;

		if (has_lf(p, str_len)) break;

		p = str = (char*)realloc(str, (str_cap += 100));
		p += str_total_len;
	}

	str[--str_total_len] = '\0';

	size_t max_vowel = 0, max_cons = 0;
	char *max_vowel_p = NULL, *max_cons_p = NULL;

	p = strtok(str, " ");

	do
	{
		const size_t len = strlen(p);
		const size_t vowel = count_vowels(p);
		const size_t cons = len - vowel;

		if (vowel > max_vowel)
		{
			max_vowel = vowel;
			max_vowel_p = p;
		}
		if (cons > max_cons)
		{
			max_cons = cons;
			max_cons_p = p;
		}
	} while (p = strtok(NULL, " "));

	printf("Max Consonant: %s (%d)\n", max_cons_p, (int)max_cons);
	printf("Max Vowel: %s (%d)\n", max_vowel_p, (int)max_vowel);

	free(str);
	str = NULL;

	return 0;
}

size_t min(size_t a, size_t b)
{
	return a >= b ? b : a;
}

int has_lf(char* string, size_t length)
{
	size_t i;

	for (i = 0; i < length; ++i)
	{
		if (string[i] == '\n') return 1;
	}

	return 0;
}

size_t count_vowels(char* string)
{
	size_t result = 0;

	for (; *string; ++string)
	{
		if (*string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u' ||
			*string == 'A' || *string == 'E' || *string == 'I' || *string == 'O' || *string == 'U')
		{
			++result;
		}
	}

	return result;
}