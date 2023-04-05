#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
typedef int element;
typedef struct {
	element* data;
	int capacity;
	int top;
}stacktype;

void init_stack(stacktype* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(stacktype* s)
{
	return (s->top == -1);
}
int is_full(stacktype* s)
{
	return (s->top == (s->capacity - 1));
}
void push(stacktype* s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}
element pop(stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Stack Empty\n");
		return;
	}
	else
		return s->data[(s->top)--];
}
int main(void)
{
	stacktype s;
	init_stack(&s);
	srand(time(NULL));
	int rand_num = rand() % 100 + 1;
	printf("------Using dynamic------\n");
	for (int i = 0; i < 30; i++)
	{
		if (rand_num % 2 == 0)
		{
			push(&s, rand_num);
			printf("[%d} Push %d\n", i + 1, rand_num);
		}
		if (rand_num % 2 == 1)
		{
			printf("[%d] Pop %d\n", i + 1, pop(&s));
		}
		rand_num = rand() % 100 + 1;
	}
	free(s.data);
	return 0;
}