#include "linkList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
//����Ĵ����½ڵ㷽ʽ
//Node buyNewNode(int data)		
//{
//	Node newNode;				
//	newNode.data = data;
//	newNode.pNext = NULL;
//	return newNode;
//}

void SListInit(pNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}
//�����½ڵ�
pNode buyNode(int data)
{
	pNode pNew = NULL;
	pNew = (pNode)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf("������ʧ��");
		return NULL;
	}
	pNew->data = data;
	pNew->pNext = NULL;
	return pNew;
}

void linkListPushBack(pNode * pHead, int data)
{
	//��֤�������
	assert(pHead);
	pNode pCur = NULL;
	//���������������ͷǿ�
	if (NULL == *pHead) {
		*pHead = buyNode(data);
	}
	else {
		pCur = *pHead;
		while (NULL != (pCur)->pNext ) {
			pCur = pCur->pNext;
		}
		pCur->pNext = buyNode(data);
	}
}
void linkListPopBack(pNode * pHead) 
{
	assert(pHead);
	if (NULL == *pHead) {
		return;
	}
	pNode pPre = NULL;
	pNode pDel = NULL;
	pDel = *pHead;
	//ֻ��ͷ�ڵ����1�����ϵĽ��
	if (NULL == pDel->pNext) {
		free(*pHead);
		*pHead = NULL;
	}
	else {
		while (NULL != pDel->pNext) {
			pPre = pDel;
			pDel = pDel->pNext;
		}
		free(pDel);
		pPre->pNext = NULL;
	}
}

void linkListPushFront(pNode * pHead, int data)
{
	assert(pHead);
	if (NULL == *pHead) {
		*pHead = buyNode(data);
	}
	else {
		pNode pNew = buyNode(data);
		pNew->pNext = *pHead;
		(*pHead)= pNew;
	}
}

void linkListPopFront(pNode * pHead)
{
	assert(pHead);
	if(NULL == *pHead){
		return;
	}
	else {
		pNode pDel = *pHead;
		(*pHead) = (*pHead)->pNext;
		free(pDel);
	}
}

void linkListInsert(pNode *pHead, int data, pNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos) {
		return;
	}
	//���������ͷ���������λ�ò���
	if ((*pHead == pos)) {
		pNode pNew = buyNode(data);
		pNew->pNext = *pHead;
		*pHead = pNew;
	}
	else {
		pNode pCur = *pHead;
		pNode pPre = NULL;
		while (pCur && pCur != pos) {
			pPre = pCur;
			pCur = pCur->pNext;
		}
		//�ҵ���û�ҵ�pos�������
		if (pCur) {
			pNode pNew = buyNode(data);
			pNew->pNext = pCur;
			pPre->pNext = pNew;
		}
	}

}

void linkListErase(pNode *pHead,pNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos) {
		return;
	}
	if (*pHead == pos) {
		pNode pDel = *pHead;
		*pHead = (*pHead)->pNext;
		free(pDel);
	}
	else {
		pNode pPre = NULL;
		pNode pCur = *pHead;
		while (pCur && pCur != pos) {
			pPre = pCur;
			pCur = pCur->pNext;
		}
		if(pCur){
			pPre->pNext = pCur->pNext;
			free(pCur);
		}
		
	}
}

pNode findNode(pNode pHead, int data)
{
	if (NULL == pHead) {
		return NULL;
	}
	while (pHead) {
		if (pHead->data == data) {
			return pHead;
		}
		pHead = pHead->pNext;
	}
	return NULL;
}

int SListSize(pNode pHead)
{
	if (NULL == pHead) {
		return 0;
	}
	int count = 0;
	while (pHead) {
		pHead = pHead->pNext;
		count++;
	}
	return count;
}

int SListEmpty(pNode pHead)
{
	return pHead ? 1 : 0;
}

void SListDestroy(pNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead) {
		return;
	}
	pNode pDel = NULL;
	//��Ϊ���*pHeadһ����NULL,������Ұָ��
	while (*pHead) {
		pDel = *pHead;
		*pHead = (*pHead)->pNext;
		free(pDel);
	}
}