#include <limits.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000
static unsigned long long buffer[BUFFER_SIZE];

unsigned long long factorial(int number)
{
	if (buffer[number] == ULLONG_MAX)
	{
		return buffer[number] = number * factorial(number - 1);
	}
	else
	{
		return buffer[number];
	}
}

int main()
{
	memset(buffer, 0xFF, sizeof(unsigned long long) * BUFFER_SIZE);
	buffer[0] = 0;
	buffer[1] = 1;

	while (1)
	{
		printf("Number(Exit: -1): ");

		int number;
		scanf(" %d", &number);

		if (number == -1)
		{
			break;
		}

		printf("%llu\n", factorial(number));
	}

	return 0;
}