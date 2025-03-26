#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

//문자열 길이 n으로 세서 (n-1)/2만큼 먼저 push, (n+3)/2부터 n까지 pop 해서 emptyset이면 회문

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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