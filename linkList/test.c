#include "linkList.h"
#include <stdio.h>
void test_interview(pNode *pHead);
int main()
{
	//���в��Ժ��������ͷָ��
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
//���������⺯��
void test_interview(pNode *pHead)
{
	//����������pHead��ָ��ͷָ���ָ�룬*pHead��ͷָ��
	linkListPushBack(pHead, 2);
	linkListPushBack(pHead, 4);
	linkListPushBack(pHead, 7);
	linkListPushBack(pHead, 3);
	linkListPushBack(pHead, 5);

	//�������ӡ
	//pNode pNow = *pHead;
	//reverse_print(*pNow);

	//O��1��ɾ�����
	//erase_node(pHead, findNode(*pHead, 3));

	//O��1��������
	//insert_node(pHead, 88, findNode(*pHead, 5));

	//Լɪ��
	//pNode pTail = findNode(pHead, 1);
	//pTail->pNext = *pHead;
	//int ret = joseph_circle(pHead, 1);

	//��ת������ָ��
	//reverse_llist(pHead);

	//��ת����ͷ��
	//pNode pNew = ReverseSListOP(*pHead);

	//ð��
	//bubble_llist(pHead);

	//�ϲ�����
	pNode pb = NULL;
	linkListPushBack(&pb, 1);
	linkListPushBack(&pb, 3);
	linkListPushBack(&pb, 5);
	pNode pNew = merge_llist(*pHead, pb);
	
	//�����м���
	//pNode pMid = FindMiddleNode(*pHead);

	//������k��
	//pNode pLastK = FindLastKNode(*pHead, 6);

	//ɾ��������k��
	//pNode pNew = DeleteLastKNode(*pHead, 2);

	//�ж��Ƿ��ཻ
	//pNode pTail = findNode(pb, 5);
	//pTail->pNext = findNode(*pHead, 7);
	//int ret = IsSListCross(*pHead, pb);
	//pNode ret = GetCorssNode(*pHead, pb);

}