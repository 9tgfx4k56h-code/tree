#pragma once
//5.28
#include"common.h"

typedef struct BThrNode
{
	BThr_ElemType data;
	struct BThrNode* left;
	struct BThrNode* right;
	int Ltag;
	int Rtag;
}BThrNode;

BThrNode* Pre_Create_BThrTree(CAinfo* str);

void InOrder_BThr(BThrNode* T, BThrNode* pre);
void Create_InOrder_BiThrTree(BThrNode* T);

BThrNode* Most_leftOrder(BThrNode* T);
BThrNode* Node_next(BThrNode* T);
void print_OrderTraverse_BThr(BThrNode* T);

