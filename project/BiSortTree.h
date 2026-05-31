#pragma once
//5.30
#include"common.h"

typedef struct BiSortTree
{
	BST_ElemType data;
	struct BiSortTree* left_child;
	struct BiSortTree* right_child;
}BSTree;

void By_InOrder_True(BSTree* T);

BSTree* Insert_BSTree(BSTree* T, int node);
BSTree* Create_BSTree(int *a, int n);
BSTree* Delete_BSTree(BSTree* T, int node);