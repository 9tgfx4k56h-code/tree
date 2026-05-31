#include"BiThrTree.h"

BThrNode* pre = NULL;//能否不使用全局变量pre

BThrNode* Pre_Create_BThrTree(CAinfo* str)
{
	if (str == NULL || str->arr == NULL) return NULL;
	if (str->arr[str->index] == '\0') return NULL;
	char ch = str->arr[str->index++];
	if (ch == '#')return NULL;
	BThrNode* root = new BThrNode;
	root->data = ch;
	root->left = Pre_Create_BThrTree(str);
	root->right = Pre_Create_BThrTree(str);
	return root;
}
void InOrder_BThr(BThrNode* T)
{
	if (T == NULL)return;
	InOrder_BThr(T->left);
	if (T->left==NULL)
	{
		T->Ltag = 1;
		T->left = pre;
	}
	else T->Ltag = 0;
	if (pre != NULL && pre->right==NULL)
	{
		pre->Rtag = 1;
		pre->right = T;
	}
	else if(pre!=NULL)pre->Rtag = 0;
	pre = T;
	InOrder_BThr(T->right);

}
void Create_InOrder_BiThrTree(BThrNode* T)
{
	if (!T)return;
	InOrder_BThr(T);
	if (pre!=NULL && pre->right==NULL)pre->Rtag = 1;
}
BThrNode* Most_leftOrder(BThrNode* T)
{
	if (!T)return NULL;
	while (T->right && T->Ltag == 0)T = T->left;
	return T;
}
BThrNode* Node_next(BThrNode* T)
{
	if (T->Rtag == 1)return T->right;
	else return Most_leftOrder(T->right);
}
void print_OrderTraverse_BThr(BThrNode* T)
{
	if (!T)return;
	BThrNode* p = Most_leftOrder(T);
	if (!p)return;
	while (p!=NULL)
	{
		printf("%c ", p->data);
		p = Node_next(p);
	}
}
