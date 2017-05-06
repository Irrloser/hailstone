#include<stdio.h>
#define N 5
#define M 5
void std_average(int *s, char *name, double a);
void below_average(int s[][M], char sub[][20], double *a);
void fail(int s[][M], char sub[][20]);
void perfect(int s[][M], char sub[][20]);
int getsub(char *s, int limit)
{
	char c;
	int i = 0;
	for (i = 0; i < limit - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)	//ÈôµÚn¸ö×Ö·ûÎª\n i=n
		s[i] = c;
	if (c == '\n')
	{
		s[i] = '\0';
		i++;
	}
	return i - 1;
}
int main()
{
	char sub[N][20], name[N][10];
	char c;
	int i, j;
	int score[N][M];
	double stduent[M], subject[N];
	int temp = 0;
	//input names of subjects
	for (i = 0; i < N; i++)
	{
		j = 0;
		while ((c = getchar()) != ' '&&c != '\n')
		{
			sub[i][j] = c;
			j++;
		}
		if (c == ' ' || c == '\n')
		{
			sub[i][j] = '\0';
		}
	}
	//input students' name and grade
	for (i = 0; i < M; i++)
	{
		getsub(name[i], 10);
		for (j = 0; j < N; j++)
			scanf("%d", &score[i][j]);
		getchar();
	}
	//output each student's average score
	for (i = 0; i < N; i++)
		std_average(score[i], name[i], stduent[i]);
	//output each subject's average score;
	for (j = 0; j < N; j++)
	{
		temp = 0;
		for (i = 0; i < M; i++)
		{
			temp += score[i][j];
		}
		subject[j] = temp / 5.0;
		printf("Average score of %s is %.2lf\n", sub[j], subject[j]);
	}
	below_average(score, sub, subject);
	fail(score, sub);
	perfect(score, sub);
}
void std_average(int *s, char *name, double a)
{
	int sum = 0;
	int i;
	for (i = 0; i < N; i++)
		sum += s[i];
	a = sum / 5.0;
	printf("Average score of %s is %.2lf\n", name, a);
}
void below_average(int s[][M], char sub[][20], double *a)
{
	int i, j;
	int count[5] = { 0 };
	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			if ((s[i][j]) < a[j])
				count[j]++;
		}
	}
	for (i = 0; i<N; i++)
		printf("Number of students lower than avg of %s is %d\n", sub[i], count[i]);

}
void fail(int s[][M], char sub[][20])
{
	int count = 0;
	int i, j;
	for (j = 0; j <M; j++)
	{
		count = 0;
		for (i = 0; i < N; i++)
		{
			if (s[i][j] < 60)
				count++;
		}
		printf("Number of students %s fail is %d\n", sub[j], count);
	}
}
void perfect(int s[][M], char sub[][20])
{
	int count = 0;
	int i, j;
	for (j = 0; j < M; j++)
	{	
		count = 0;
		for (i = 0; i < N; i++)
		{
			if (s[i][j] >= 90)
				count++;
		}
		printf("Number of students %s perfect is %d\n", sub[j], count);
	}
}
