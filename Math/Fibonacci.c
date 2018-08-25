#include <limits>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000
static unsigned long long buffer[BUFFER_SIZE];

unsigned long long fibonacci(int index)
{
	if (buffer[index] == ULLONG_MAX)
	{
		return buffer[index] = fibonacci(index - 1) + fibonacci(index - 2);
	}
	else
	{
		return buffer[index];
	}
}

int main()
{
	memset(buffer, 0xFF, sizeof(unsigned long long) * BUFFER_SIZE);
	buffer[0] = 0;
	buffer[1] = 1;

	while (1)
	{
		printf("Index(Exit: -1): ");

		int index;
		scanf(" %d", &index);

		if (index == -1)
		{
			break;
		}

		printf("%llu\n", fibonacci(index));
	}

	return 0;
}