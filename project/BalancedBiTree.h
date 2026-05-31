#pragma once
#include "common.h"

typedef struct BalancedBiTree
{
	Bal_ElemType data;
	int height;
	struct BalancedBiTree* left_child;
	struct BalancedBiTree* right_child;
}BalBTree;

int Get_Height(BalBTree* T);
int Get_BalancedFactor(BalBTree* T);
void updata_Height(BalBTree* T);

BalBTree* LL(BalBTree* T);
BalBTree* RR(BalBTree* T);

BalBTree* Insert_BalancedBiTree(BalBTree* T, int n);

int check_BalBiTree(BalBTree* T);
void is_balanced(BalBTree* T);

void By_InOrder_True_Bal(BalBTree* T);

BalBTree* Delete_like_BiSort(BalBTree* T, int n);
BalBTree* Delete_BalBiTree(BalBTree* T, int n);

