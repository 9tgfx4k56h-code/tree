#include"BalancedBiTree.h"
//叶子节点高度为1 空节点高度为0
int Get_Height(BalBTree* T)
{
	if (T == NULL)return 0;
	return T->height;
}

int Get_BalancedFactor(BalBTree* T)
{
	if (T == NULL)return 0;
	return Get_Height(T->left_child) - Get_Height(T->right_child);
}

void updata_Height(BalBTree* T)
{
	if (T == NULL)return;
	int lefth = Get_Height(T->left_child);
	int righth = Get_Height(T->right_child);
	T->height = (lefth > righth ? lefth : righth) + 1;
}

BalBTree* LL(BalBTree* T)//以 node 为轴心向右旋转right
{
	BalBTree* T_lchild = T->left_child;
	BalBTree* T_lrchild = T_lchild->right_child;
	T_lchild->right_child = T;
	T->left_child= T_lrchild;
	updata_Height(T);
	updata_Height(T_lchild);
	return T_lchild;
}
BalBTree* RR(BalBTree* T)//以 node 为轴心向左旋转left
{
	BalBTree* T_rchild = T->right_child;
	BalBTree* T_rlchild = T_rchild->left_child;
	T_rchild->left_child = T;
	T->right_child = T_rlchild;
	updata_Height(T);
	updata_Height(T_rchild);
	return T_rchild;
}
BalBTree* Insert_BalancedBiTree(BalBTree* T,int n)
{
	if (T == NULL)
	{
		BalBTree* p = new BalBTree;
		p->height = 1;
		p->data = n;
		p->left_child = p->right_child = NULL;
		return p;
	}


	if (n < T->data)//类二叉排序树
	{
		T->left_child = Insert_BalancedBiTree(T->left_child, n);
	}
	else if (n > T->data)
	{
		T->right_child = Insert_BalancedBiTree(T->right_child, n);
	}
	else return T;


	updata_Height(T);


	int balance = Get_BalancedFactor(T);
	if (balance > 1 && n < T->left_child->data)//LL
	{
		return LL(T);
	}
	if (balance <-1 && n > T->right_child->data)//RR
	{
		return RR(T);
	}
	if (balance > 1 && n > T->left_child->data)//LR
	{
		T->left_child = RR(T->left_child);
		return LL(T);
	}
	if (balance <-1 && n < T->right_child->data)//RL
	{
		T->right_child = LL(T->right_child);
		return RR(T);
	}
	return T;
}
int check_BalBiTree(BalBTree* T)//-1表示失去平衡
{
	if(T==NULL)return 0;
	int lefth = check_BalBiTree(T->left_child);
	int righth= check_BalBiTree(T->right_child);
	if (abs(lefth - righth) > 1)return -1;
	if (lefth == -1 || righth == -1)return -1;
	return (lefth > righth ? lefth : righth)+1;
}
void is_balanced(BalBTree* T)
{
	if (check_BalBiTree(T) != -1)
	{
		printf("is\n");
	}
	else printf("not\n");
}
void By_InOrder_True_Bal(BalBTree* T)
{
	if (T == NULL)return;
	By_InOrder_True_Bal(T->left_child);
	printf("%d ", T->data);
	By_InOrder_True_Bal(T->right_child);
}
BalBTree* Delete_like_BiSort(BalBTree* T,int n)
{
	if (T == NULL) return NULL;

	BalBTree* p = T;
	BalBTree* pre = NULL;

	while (p != NULL && p->data != n)
	{
		pre = p;
		if (p->data > n)
			p = p->left_child;
		else
			p = p->right_child;
	}

	if (p == NULL) return T;  // 未找到

	// 1. 叶子节点
	if (p->left_child == NULL && p->right_child == NULL)
	{
		if (pre == NULL)  // 根节点
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
	// 2. 只有一个孩子
	else if (p->left_child == NULL || p->right_child == NULL)
	{
		BalBTree* child = (p->left_child != NULL) ? p->left_child : p->right_child;
		if (pre == NULL)  // 根节点
		{
			delete p;
			return child;
		}
		if (pre->left_child == p)
			pre->left_child = child;
		else
			pre->right_child = child;
		delete p;
		return T;
	}
	// 3. 有两个孩子
	else
	{
		BalBTree* s = p->left_child;
		BalBTree* s_parent = p;
		while (s->right_child != NULL)
		{
			s_parent = s;
			s = s->right_child;
		}
		p->data = s->data;

		//s最多只有左孩子
		if (s_parent->left_child == s)
			s_parent->left_child = s->left_child;
		else
			s_parent->right_child = s->left_child;
		delete(s);
		return T;
	}
	return T;
}
BalBTree* Delete_BalBiTree(BalBTree* T, int n)
{
	BalBTree* p = T;
	if (T == NULL)return NULL;
	if (n < p->data)
	{
		p->left_child = Delete_BalBiTree(p->left_child, n);
	}
	else if (n > p->data)
	{
		p->right_child = Delete_BalBiTree(p->right_child, n);
	}
	else 
	{
		return Delete_like_BiSort(T, n);
	}
	// 更新高度并调整平衡
	updata_Height(p);
	int balance = Get_BalancedFactor(p);

	if (balance > 1)
	{
		if (Get_BalancedFactor(p->left_child) >= 0)//LL
			return LL(p);
		else
		{
			p->left_child = RR(p->left_child);//LR
			return LL(p);
		}
	}
	if (balance < -1)
	{
		if (Get_BalancedFactor(p->right_child) <= 0)//RR
			return RR(p);
		else
		{
			p->right_child = LL(p->right_child);//RL
			return RR(p);
		}
	}
	return T;
}