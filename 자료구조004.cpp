#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//스택 초기화 함수

void init_stack(StackType* s)
{
	s->top = -1;

}

//공백상태검출함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

//포화 상태 검출

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;


	}

	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}



//n글자의 배열에서 기호를 전부 제외함, n-1/2를 한 위치까지 push하고 (n-1/2)+1은 제외 그 뒤는 pop해서 empty검사

int check_matching(const char* k)
{
	StackType s;
	char ch,open_ch;
	
	int i, n = strlen(k);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = k[i];
		switch (ch) {
		case'.': case ',': case'"': case'\'':
			push(&s, ch);
			break;

			if (is_empty(&s))
			{
				return 0;
			}
			else {
				open_ch = pop(&s);
				if ((open_ch == '(') || (open_ch == ',') || open_ch == '\'')
					return 0;

			}
			break;
		}
		if (!is_empty(&s))
			return 0;
		
			

		
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
	char input[MAX_STACK_SIZE];
	printf("문자열을 입력하십시오:");
	scanf_s("%s", input);
	
	if (check_matching(input)==0) {
		printf("회문이 아닙니다");

	}
	else {
		printf("회문입니다");
	}
}