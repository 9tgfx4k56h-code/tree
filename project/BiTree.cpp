#include"BiTree.h"

void PreOrderTraverse(BTNode* T)
{
	if (T == NULL)return;
	printf("%c ", T->data);
	PreOrderTraverse(T->left_child);
	PreOrderTraverse(T->right_child);
}
void InOrderTraverse(BTNode* T)
{
	if (T == NULL)return;
	InOrderTraverse(T->left_child);
	printf("%c ", T->data);
	InOrderTraverse(T->right_child);
}
void PostOrderTraverse(BTNode* T)
{
	if (T == NULL)return;
	PostOrderTraverse(T->left_child);
	PostOrderTraverse(T->right_child);
	printf("%c ", T->data);
}
void LevelOrderTraverse()
{
	
}
void print_OrderTraverse(BTNode* T)
{
	PreOrderTraverse(T);printf("\n");
	InOrderTraverse(T);printf("\n");
	PostOrderTraverse(T);printf("\n");printf("\n");
}
void InitBTree(BTNode* root)
{
	root = new BTNode;
	root->data = NULL;
	root->left_child = NULL;
	root->left_child = NULL;
}
BTNode* Pre_Create_BTree(CAinfo* str)
{
	if (str == NULL || str->arr == NULL) return NULL;//检查空指针
	if (str->arr[str->index] == '\0') return NULL;//递归结束条件
	char ch = str->arr[str->index++];//存储当前index位置的值，后index后移动
	if (ch == '#')return NULL;
	BTNode* root = new BTNode;
	root->data = ch;
	root->left_child = Pre_Create_BTree(str);//递归左右孩子
	root->right_child = Pre_Create_BTree(str);
	return root;
}