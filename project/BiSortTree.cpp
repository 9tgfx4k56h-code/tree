#include"BiSortTree.h"

void By_InOrder_True(BSTree* T)
{
	if (T == NULL)return;
	By_InOrder_True(T->left_child);
	printf("%d ", T->data);
	By_InOrder_True(T->right_child);
}
BSTree* Insert_BSTree(BSTree* T,int node)
{
	if (T == NULL)
	{
		T = new BSTree;
		T->data = node;
		T->left_child = NULL;
		T->right_child = NULL;
		return T;
	}
	else if (node < T->data)
	{
		T->left_child = Insert_BSTree(T->left_child, node);
	}
	else if (node > T->data)
	{
		T->right_child = Insert_BSTree(T->right_child, node);
	}
	return T;
}
BSTree* Create_BSTree(int* a,int n)
{
	BSTree* T = NULL;
	for (int i = 0;i < n;i++)
	{
		T = Insert_BSTree(T, a[i]);
	}
	return T;
}
BSTree* Delete_BSTree(BSTree* T,int node)
{
	BSTree* p = T;BSTree* pre = NULL;
	while (p != NULL && p->data != node)
	{
		pre = p;
		if (p->data > node)
			p = p->left_child;
		else 
			p = p->right_child;
	}
	if (p == NULL)return T;


	if (p->left_child==NULL && p->right_child == NULL)//1.删除的是叶子节点
	{
		if (pre == NULL)//叶子节点也是根节点的情况
		{
			delete p;
			return NULL;
		}
		if (pre->left_child == p)
			pre->left_child = NULL;
		else 
			pre->right_child = NULL;
		delete p;
		return T;
	}


	else if (p->left_child == NULL || p->right_child == NULL)//2.只有左或者右一个孩子
	{
		BSTree* child = (p->left_child != NULL) ? p->left_child : p->right_child;
		if (pre == NULL) // 若删除根节点
		{
			T = child;
			delete p;
			return T;
		}
		if (pre->left_child == p)
			pre->left_child = child;
		else 
			pre->right_child = child;
		delete p;
		return T;
	}


	else if (p->left_child != NULL && p->right_child != NULL)//3.有左右两个孩子
	{
		// 找左子树的最大值（前驱）
		BSTree* s = p->left_child;  // s是要替换的节点
		BSTree* s_parent = p;       // s的父节点
		while (s->right_child != NULL)//根据性质右孩子大于根节点
		{
			s_parent = s;
			s = s->right_child;
		}
		p->data = s->data;
		// 删除s节点（s最多只有左孩子）
		if (s_parent->left_child == s)
			s_parent->left_child = s->left_child;
		else 
			s_parent->right_child = s->left_child;//s最多只有左孩子
		delete s;
		return T;
	}
	return T;
}