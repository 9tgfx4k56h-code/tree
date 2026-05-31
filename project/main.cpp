#include"BiTree.h"
#include"BiThrTree.h"
#include"Hufffman.h"
#include"BiSortTree.h"
#include"BalancedBiTree.h"

void BiTree_text()
{
	char a[20] = "ABC##DE#G##F###";
	CAinfo info = { a,0 };
	print_OrderTraverse(Pre_Create_BTree(&info));
}
void BiThrTree_text()
{
	char b[20] = "124##5##3#6##";
	CAinfo info = { b,0 };
	BThrNode* T = Pre_Create_BThrTree(&info);
	Create_InOrder_BiThrTree(T);
	print_OrderTraverse_BThr(T);
}
void HuffmanTree_text()
{
	int weight[8] = { 5,29,7,8,14,23,3,11 };
	HTNode* T = Create_HufArray(weight, 8);
	for (int i = 1;i < 16;i++)
	{
		printf("%-4d %-4d %-4d %-4d\n", 
			T[i].weight,T[i].parent, T[i].leftc, T[i].rightc);
	}
	printf("\n");
	char a[20] = "";
	FromRoot(T, 2 * 8 - 1, 0, a);
}
void BiSortTree_text()
{
	int a[7] = { 50, 30, 70, 20, 40, 80, 45 };
	BSTree* T = Create_BSTree(a, 7);
	By_InOrder_True(T);printf("\n");
	Delete_BSTree(T, 20);By_InOrder_True(T);printf("\n");
	Delete_BSTree(T, 40);By_InOrder_True(T);printf("\n");
	Delete_BSTree(T, 50);By_InOrder_True(T);printf("\n");
	Insert_BSTree(T,90);Insert_BSTree(T, 32);
	By_InOrder_True(T);printf("\n");
}
void BalancedBiTree_text()
{
	BalBTree* T = NULL;
	T=Insert_BalancedBiTree(T, 31);
	T = Insert_BalancedBiTree(T, 25);
	T = Insert_BalancedBiTree(T, 16);//LL
	By_InOrder_True_Bal(T);
	is_balanced(T);delete(T);
	T = NULL;
	T = Insert_BalancedBiTree(T, 31);
	T = Insert_BalancedBiTree(T, 47);
	T = Insert_BalancedBiTree(T, 69);//RR
	By_InOrder_True_Bal(T);
	is_balanced(T);delete(T);
	T = NULL;
	T = Insert_BalancedBiTree(T, 31);
	T = Insert_BalancedBiTree(T, 25);
	T = Insert_BalancedBiTree(T, 28);//LR
	By_InOrder_True_Bal(T);
	is_balanced(T);delete(T);
	T = NULL;
	T = Insert_BalancedBiTree(T, 31);
	T = Insert_BalancedBiTree(T, 47);
	T = Insert_BalancedBiTree(T, 40);//RL
	By_InOrder_True_Bal(T);
	is_balanced(T);delete(T);
	T = NULL;
	T = Insert_BalancedBiTree(T, 31);
	T = Insert_BalancedBiTree(T, 47);
	T = Insert_BalancedBiTree(T, 25);
	T = Insert_BalancedBiTree(T, 16);
	T = Insert_BalancedBiTree(T, 28);
	By_InOrder_True_Bal(T);is_balanced(T);
	T = Delete_BalBiTree(T, 16);
	By_InOrder_True_Bal(T);is_balanced(T);delete(T);
}
int main()
{
	//BiTree_text();
	//BiThrTree_text();
	//HuffmanTree_text();
	//BiSortTree_text();
	BalancedBiTree_text();
	return 0;
}