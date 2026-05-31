#pragma once
//5.30
#include"common.h"

typedef struct HuffNOde
{
	Huff_ElemType weight;
	int parent, leftc, rightc;
}HTNode;

void SelectMin(HTNode* T, int n);
HTNode* Create_HufArray(int* weight, int n);

void FromRoot(HTNode* T, int root, int depth, char code[]);
