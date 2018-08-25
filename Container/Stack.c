#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
	int* data;
	int length;
	int capacity;
} stack;

stack create_stack()
{
	stack stack;
	stack.data = NULL;
	stack.length = 0;
	stack.capacity = 0;

	return stack;
}

void delete_stack(stack* stack)
{
	if (stack && stack->data)
	{
		free(stack->data);

		stack->data = NULL;
		stack->length = 0;
		stack->capacity = 0;
	}
}

int reserve(stack* stack, int new_capacity)
{
	if (!stack) return FALSE;
	if (stack->length > new_capacity) return FALSE;
	if (stack->capacity == new_capacity) return TRUE;

	stack->data = realloc(stack->data, sizeof(int) * new_capacity);

	if (!stack->data)
	{
		stack->length = 0;
		stack->capacity = 0;

		return FALSE;
	}

	stack->capacity = new_capacity;

	return TRUE;
}

int shrink_to_fit(stack* stack)
{
	if (!stack) return FALSE;

	if (stack->length != stack->capacity)
	{
		stack->data = realloc(stack->data, sizeof(int) * stack->length);

		if (!stack->data)
		{
			stack->length = 0;
			stack->capacity = 0;

			return FALSE;
		}

		stack->capacity = stack->length;
	}

	return TRUE;
}

int push(stack* stack, int value)
{
	if (!stack) return FALSE;

	if (stack->length == stack->capacity && !reserve(stack, stack->capacity + 16))
	{
		return FALSE;
	}

	stack->data[stack->length++] = value;
	return TRUE;
}

int pop(stack* stack)
{
	assert(stack);
	assert(stack->length != 0);

	return stack->data[--stack->length];
}

int is_empty(stack* stack)
{
	if (!stack) return TRUE;

	return stack->length == 0;
}

int main()
{
	printf("1: Push\n2: Pop\n3: Get Length\n4: Get Capacity\n5: Reserve\n6: Shrink To Fit\nOther numbers: Exit\n");

	stack stack = create_stack();
	
	while (1)
	{
		printf(">>> ");

		int input;
		scanf(" %d", &input);

		switch (input)
		{
		case 1:
			printf("Value: ");
			scanf(" %d", &input);
			push(&stack, input);
			break;

		case 2:
			printf("Value: %d\n", pop(&stack));
			if (is_empty(&stack))
			{
				printf("Empty!\n");
			}
			break;

		case 3:
			printf("Length: %d\n", stack.length);
			break;

		case 4:
			printf("Capacity: %d\n", stack.capacity);
			break;

		case 5:
			printf("New Capacity: ");
			scanf(" %d", &input);
			reserve(&stack, input);
			break;

		case 6:
			shrink_to_fit(&stack);
			break;

		default:
			goto exit;
		}
	}

exit:
	delete_stack(&stack);
	return 0;
}