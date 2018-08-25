#include <limits.h>
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

	for (i = 0; i < array_length; ++i)
	{
		int min_value_index = i;

		int j;
		for (j = i; j < array_length; ++j)
		{
			if (array[min_value_index] > array[j])
			{
				min_value_index = j;
			}
		}

		swap(&array[i], &array[min_value_index]);
	}

	printf("Result:");
	for (i = 0; i < array_length; ++i)
	{
		printf(" %d", array[i]);
	}

	return 0;
}