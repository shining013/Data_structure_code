#include<ctype.h>
#include<stdio.h>
#pragma warning(disable:4996)
/*문자열 입력 프로그램*/
int read_line_with_compression(char compressed[], int limit);
int main(void)
{
	char line[80] = "";
	while (1)
	{
		printf("$ ");
		int length = read_line_with_compression(line, 80);
		printf("%s:%d\n", line, length);
	}
	return 0;
}

int read_line_with_compression(char compressed[], int limit)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
	{
		if (i < limit - 1 && (!isspace(ch) || i > 0 && !isspace(compressed[i - 1])))
		{
			compressed[i++] = ch;
		}
	}
	if (i > 0 && isspace(compressed[i - 1]))
	{
		i--;
	}
	compressed[i] = '\0';
	return i;
}

