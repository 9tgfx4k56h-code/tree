#pragma once
//5.28
#include"common.h"

typedef struct BTNode
{
	BT_ElemType data;
	struct BTNode* left_child;
	struct BTNode* right_child;
}BTNode;

void PreOrderTraverse(BTNode* T);
void InOrderTraverse(BTNode* T);
void PostOrderTraverse(BTNode* T);
void LevelOrderTraverse(BTNode* T);
void print_OrderTraverse(BTNode* T);

void InitBTree(BTNode* root);

BTNode* Pre_Create_BTree(CAinfo* str);