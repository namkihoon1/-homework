#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

//���ڿ� ���� n���� ���� (n-1)/2��ŭ ���� push, (n+3)/2���� n���� pop �ؼ� emptyset�̸� ȸ��

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int check_matching(const char* k)
{
	StackType s;
	char ch;
	int i, n = strlen(k);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = k[i];
		switch (ch) {
		case'.': case ',': case'"': case'\'':
			push(&s, ch);
			break;

		
		}
	}
	
	for (i = 0; i < (n - 1) / 2; i++)
	{
		ch = k[i];
		push(&s, ch);
	}

	for (i = (n + 1) / 2; i < n; i++) {
		ch = k[i];
		pop(&s);
	}
	if (!is_empty(&s))
		return 0;
	else
		return 1;
}

int main(void)
{
	
}