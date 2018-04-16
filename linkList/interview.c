#include "linkList.h"
#include <stdio.h>
#include <assert.h>
//��β��ͷ��ӡ����
void reverse_print(pNode pHead)
{
	if (NULL == pHead) {
		return;
	}
	reverse_print(pHead->pNext);
	printf("%d", pHead->data);
}
//O��1��ɾ����β���
void erase_node(pNode *pHead, pNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos) {
		return;
	}
	//��Ϊͷɾ��ɾ����β����������
	if (pos == *pHead) {
		pNode pDel = *pHead;
		*pHead = (*pHead)->pNext;
		free(pDel);
	}
	else {
		pNode pDel = pos;
		pDel = pDel->pNext;
		if (pDel->pNext) {
			pos->data = pDel->data;
			pos->pNext = pDel->pNext;
			free(pDel);
		}
	}
}
//O��1��������
void insert_node(pNode *pHead, int data, pNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos) {
		return;
	}
	pNode pNew = NULL;
	pNew = (pNode)malloc(sizeof(Node));
	if (NULL == pNew) {
		return;
	}
	pNew->data = pos->data;
	pNew->pNext = pos->pNext;
	pos->data = data;
	pos->pNext = pNew;
}
//������Լɪ�򻷣��������һ��ʣ�µĽ��ֵ
int joseph_circle(pNode *pHead, int num)
{
	assert(pHead);
	if (NULL == *pHead || num <= 1) {
		return -1;
	}
	pNode pStr = *pHead;
	pNode pCur = NULL;
	pNode pDel = NULL;  //��Ҫ���޳��Ľ��
	while (pStr->pNext != pStr) {
		//����
		pCur = pStr;
		int count = num;
		while (--count) {
			pCur = pCur->pNext;
		}
		//�޳�
		pDel = pCur;
		pCur = pCur->pNext;
		pStr->pNext = pCur;
		pStr = pCur;
		free(pDel);
	}
	return pStr->data;
}
//��ת��������ָ��
void reverse_llist(pNode *pHead) {
	assert(pHead);
	if (NULL == *pHead) {
		return;
	}
	pNode pPre = NULL;
	pNode pCur = *pHead;
	pNode pNxt = pCur;
	while (pCur) {              //������жϱȽϾ�������pNxtΪ��������
		pNxt = pCur->pNext;		//������pcur�ı�֮ǰ��
		pCur->pNext = pPre;		//���������һ���ж������Ƚϸ���ʱ�����Ե������˳����ж�����
		pPre = pCur;
		pCur = pNxt;

	}
	*pHead = pPre;
}
//��ת����--ͷ�巨
pNode ReverseSListOP(pNode pHead)
{
	if (NULL == pHead) {
		return NULL;
	}
	pNode pNew = NULL;
	pNode pNxt = NULL;
	//�����һ�����
	pNew = pHead;
	pHead = pHead->pNext;
	pNew->pNext = NULL;		//������˳��ܹؼ����µĵ�һ��ͷ���Ҫָ�գ�
							//��Ϊ��ͷ�壬�����治���ٸĶ����
	while (pHead) {
		pNxt = pHead->pNext;
		pHead->pNext = pNew;
		pNew = pHead;
		pHead = pNxt;
	}
	return pNew;
}
//ð����������
void bubble_llist(pNode pHead) {
	if (NULL == pHead) {
		return;
	}
	//�ҵ�β���
	pNode pTail = pHead;
	while (pTail->pNext) {
		pTail = pTail->pNext;
	}
	pNode pCur = NULL;
	pNode pPre = NULL;
	//��ptailָ��ͷ˵��ֻ��һ���ڵ��ˣ�����Ҫ�Ƚ�
	while (pTail != pHead) {
		pCur = pHead;
		//ÿ�˱ȵ�pcur��ptailǰ�Ϳ����ˣ���Ϊpcur��pcur->nextֵ�Ƚ�
		while (pCur != pTail) {
			if ((pCur->data) > (pCur->pNext->data)) {
				int tmp;
				tmp = pCur->data;
				pCur->data = pCur->pNext->data;
				pCur->pNext->data = tmp;
			}
			pPre = pCur;		
			pCur = pCur->pNext;
		}
		pTail = pPre;		//ptailÿ�κ���һ��λ��
	}
}
//�ϲ�������������
pNode merge_llist(pNode pa, pNode pb)
{
	pNode pNew = NULL;
	//����ͷ���
	if (pa && (pa->data <= pb->data)) {
		pNew = pa;
		pa = pa->pNext;
	}
	else if(pb){
		pNew = pb;
		pb = pb->pNext;
	}
	pNode pNewHead = pNew;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pNew->pNext = pa;
			pa = pa->pNext;
		}
		else {
			pNew->pNext = pb;
			pb = pb->pNext;
		}
		pNew = pNew->pNext;
	}
	//�ߵ����pa����pbΪ��
	if (pa) {
		pNew->pNext = pa;
	}
	else {
		pNew->pNext = pb;
	}
	return pNewHead;
}
//����������м���
pNode FindMiddleNode(pNode pHead)
{
	if (NULL == pHead) {
		return NULL;
	}
	//���������������������ż�������
	pNode pLow = pHead;
	pNode pFst = pHead;
	pNode pPre = NULL;  //���ż������㣬���ؽ�С��
	while (pFst && pFst->pNext) {
		pPre = pLow;
		pLow = pLow->pNext;
		pFst = pFst->pNext->pNext;
	}
	//�ߵ�����pfst����ǿվ���ż�������
	if (NULL == pFst) {
		return pPre;
	}
	else {
		return pLow;
	}
}
//������K�����
pNode FindLastKNode(pNode pHead, int K)
{
	if (NULL == pHead || K <= 0) {
		return NULL;
	}
	pNode pFst = pHead;
	while (K--) {
		if (NULL == pFst) {	//�������һ������fst֮ǰ
			return NULL;		//һ�Ǳ�֤��ʹk�ܴ�Ҳ���˳�������֤pFst=NULL�����������ȥ
		}
		pFst = pFst->pNext;
	}
	pNode pLow = pHead;
	while (pFst) {
		pFst = pFst->pNext;
		pLow = pLow->pNext;
	}
	return pLow;
}
// ɾ������ĵ�����K�����
pNode DeleteLastKNode(pNode pHead, int K)
{
	if (NULL == pHead || K <= 0) {
		return NULL;
	}
	pNode pFst = pHead;
	while (K--) {
		if (NULL == pFst) {	//�������һ������fst֮ǰ
			return NULL;		//һ�Ǳ�֤��ʹk�ܴ�Ҳ���˳�������֤pFst=NULL�����������ȥ
		}
		pFst = pFst->pNext;
	}
	pNode pLow = pHead;
	pNode pPre = NULL;
	while (pFst) {
		pPre = pLow;
		pFst = pFst->pNext;
		pLow = pLow->pNext;
	}
	//���ﱣ֤�ҵ��˵�����K�����pLow,�����ǲ���ͷ���
	if (pHead == pLow) {
		pNode pNew = pHead->pNext;
		free(pHead);
		return pNew;
	}
	else {
		pPre->pNext = pLow->pNext;
		free(pLow);					//����ڱ�ĳ���ʹ��plow�����ڴ�й©��
		return pHead;
	}
}
// �ж������������Ƿ��ཻ---�������� 
int IsSListCross(pNode pHead1, pNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2) {
		return -1;
	}
	//��������������һ�����
	while (pHead1->pNext) {
		pHead1 = pHead1->pNext;
	}
	while (pHead2->pNext) {
		pHead2 = pHead2->pNext;
	}
	if (pHead1 == pHead2) {
		return 1;
	}
	else {
		return -1;
	}
}
//�������������ཻ�Ľ���--- ��������
pNode GetCorssNode(pNode pHead1, pNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2) {
		return NULL;
	}
	int len1 = 0;
	int len2 = 0;
	pNode pCur1 = pHead1;
	pNode pCur2 = pHead2;
	while (pCur1) {
		len1++;
		pCur1 = pCur1->pNext;
	}
	while (pCur2) {
		len2++;
		pCur2 = pCur2->pNext;
	}
	int diff = len1 - len2;
	while (0 != diff) {
		if (diff > 0) {
			pHead1 = pHead1->pNext;
			diff--;
		}
		else {
			pHead2 = pHead2->pNext;
			diff++;
		}
	}
	//�ߵ���������ָ����ཻ������ͬ����
	while (pHead1 != pHead2) {
		pHead1 = pHead1->pNext;
		pHead2 = pHead2->pNext;
	}
	return pHead1;
}
