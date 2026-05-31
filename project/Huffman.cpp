#include"Hufffman.h"

void SelectMin(HTNode* T,int n)
{
	int min1 = 0, min2 = 0;
	int i = 0;
	for (i = 1;i <= n;i++)
	{
		if (T[i].parent != 0)continue;
		if (min1==0 || T[min1].weight > T[i].weight)
		{
			min2 = min1;
			min1 = i;
		}
		else if (min2 == 0 || T[min2].weight > T[i].weight)
		{
			min2 = i;
		}
	}
	T[min1].parent = i;T[min2].parent = i;
	T[i].leftc = min1;T[i].rightc = min2;
	T[i].weight = T[min1].weight + T[min2].weight;
}

HTNode* Create_HufArray(int* weight,int n)
{
	if (n <= 1)return NULL;
	int m = 2 * n - 1;
	HTNode* T = new HTNode[m + 1];
	for (int i = 1;i <= m;i++)
	{
		T[i].weight = 0;
		T[i].parent = 0;T[i].leftc = 0;T[i].rightc = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		T[i].weight = weight[i-1];
	}
	for (int i = n + 1;i <= m;i++)
	{
		SelectMin(T, i - 1);
	}
	return T;
}
void FromRoot(HTNode* T,int root,int depth,char code[])//dfs
{
	if (T[root].leftc == 0 && T[root].rightc == 0)
	{
		code[depth] = '\0';
		printf(" %-3d: %s\n", T[root].weight, code);
		return;
	}
	code[depth] = '0';
	FromRoot(T, T[root].leftc, depth + 1, code);
	code[depth] = '1';
	FromRoot(T, T[root].rightc, depth + 1, code);
}