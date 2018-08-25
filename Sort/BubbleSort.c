#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int array_length;
	scanf("%d", &array_length);

	int* array = (int*)malloc(sizeof(int) * array_length);
	int i;
	for (i = 0; i < array_length; ++i)
	{
		scanf(" %d", &array[i]);
	}

	for (i = 0; i < array_length - 1; ++i)
	{
		int j;
		for (j = 0; j < array_length - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}

	printf("Result:");
	for (i = 0; i < array_length; ++i)
	{
		printf(" %d", array[i]);
	}

	return 0;
}