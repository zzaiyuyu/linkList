#include "linkList.h"
#include <stdio.h>
void test_interview(pNode *pHead);
int main()
{
	//所有测试函数传入的头指针
	pNode pHead = NULL;
	//linkListPushBack(&pHead, 5);
	//linkListPushBack(&pHead, 4);
	//linkListPushBack(&pHead, 3);
	//linkListPopBack(&pHead);
	//linkListPopBack(&pHead);
	//linkListPopBack(&pHead);
	//linkListPushFront(&pHead, 10);
	//linkListPushFront(&pHead, 9);
	//pNode tmp10 = findNode(pHead, 10);
	//pNode tmp9 = findNode(pHead, 9);
	//linkListInsert(&pHead, 7, tmp9);
	//linkListInsert(&pHead, 7, tmp10);
	//linkListErase(&pHead, findNode(pHead, 7));
	//linkListErase(&pHead, findNode(pHead, 7));
	//linkListPopFront(&pHead);
	//linkListPopFront(&pHead);
	//int ret = SListEmpty(pHead);
	//int tmp = SListSize(pHead);
	//SListDestroy(&pHead);

	test_interview(&pHead);	
}
//测试面试题函数
void test_interview(pNode *pHead)
{
	//在这个函数里，pHead是指向头指针的指针，*pHead是头指针
	linkListPushBack(pHead, 2);
	linkListPushBack(pHead, 4);
	linkListPushBack(pHead, 7);
	linkListPushBack(pHead, 3);
	linkListPushBack(pHead, 5);

	//链表倒序打印
	//pNode pNow = *pHead;
	//reverse_print(*pNow);

	//O（1）删除结点
	//erase_node(pHead, findNode(*pHead, 3));

	//O（1）插入结点
	//insert_node(pHead, 88, findNode(*pHead, 5));

	//约瑟夫
	//pNode pTail = findNode(pHead, 1);
	//pTail->pNext = *pHead;
	//int ret = joseph_circle(pHead, 1);

	//反转——三指针
	//reverse_llist(pHead);

	//反转——头插
	//pNode pNew = ReverseSListOP(*pHead);

	//冒泡
	//bubble_llist(pHead);

	//合并有序
	pNode pb = NULL;
	linkListPushBack(&pb, 1);
	linkListPushBack(&pb, 3);
	linkListPushBack(&pb, 5);
	pNode pNew = merge_llist(*pHead, pb);
	
	//查找中间结点
	//pNode pMid = FindMiddleNode(*pHead);

	//倒数第k个
	//pNode pLastK = FindLastKNode(*pHead, 6);

	//删除倒数第k个
	//pNode pNew = DeleteLastKNode(*pHead, 2);

	//判断是否相交
	//pNode pTail = findNode(pb, 5);
	//pTail->pNext = findNode(*pHead, 7);
	//int ret = IsSListCross(*pHead, pb);
	//pNode ret = GetCorssNode(*pHead, pb);

}