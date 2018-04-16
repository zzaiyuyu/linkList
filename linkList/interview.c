#include "linkList.h"
#include <stdio.h>
#include <assert.h>
//从尾到头打印链表
void reverse_print(pNode pHead)
{
	if (NULL == pHead) {
		return;
	}
	reverse_print(pHead->pNext);
	printf("%d", pHead->data);
}
//O（1）删除非尾结点
void erase_node(pNode *pHead, pNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos) {
		return;
	}
	//分为头删和删除非尾结点两种情况
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
//O（1）插入结点
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
//单链表约瑟夫环，返回最后一个剩下的结点值
int joseph_circle(pNode *pHead, int num)
{
	assert(pHead);
	if (NULL == *pHead || num <= 1) {
		return -1;
	}
	pNode pStr = *pHead;
	pNode pCur = NULL;
	pNode pDel = NULL;  //需要被剔除的结点
	while (pStr->pNext != pStr) {
		//报数
		pCur = pStr;
		int count = num;
		while (--count) {
			pCur = pCur->pNext;
		}
		//剔除
		pDel = pCur;
		pCur = pCur->pNext;
		pStr->pNext = pCur;
		pStr = pCur;
		free(pDel);
	}
	return pStr->data;
}
//反转链表——三指针
void reverse_llist(pNode *pHead) {
	assert(pHead);
	if (NULL == *pHead) {
		return;
	}
	pNode pPre = NULL;
	pNode pCur = *pHead;
	pNode pNxt = pCur;
	while (pCur) {              //这个题判断比较精妙，如果以pNxt为条件不妥
		pNxt = pCur->pNext;		//这句放在pcur改变之前！
		pCur->pNext = pPre;		//当觉得最后一次判断条件比较复杂时，尝试调整语句顺序和判断条件
		pPre = pCur;
		pCur = pNxt;

	}
	*pHead = pPre;
}
//反转链表--头插法
pNode ReverseSListOP(pNode pHead)
{
	if (NULL == pHead) {
		return NULL;
	}
	pNode pNew = NULL;
	pNode pNxt = NULL;
	//处理第一个结点
	pNew = pHead;
	pHead = pHead->pNext;
	pNew->pNext = NULL;		//这两步顺序很关键，新的第一个头结点要指空，
							//因为是头插，到后面不会再改动这个
	while (pHead) {
		pNxt = pHead->pNext;
		pHead->pNext = pNew;
		pNew = pHead;
		pHead = pNxt;
	}
	return pNew;
}
//冒泡排序链表
void bubble_llist(pNode pHead) {
	if (NULL == pHead) {
		return;
	}
	//找到尾结点
	pNode pTail = pHead;
	while (pTail->pNext) {
		pTail = pTail->pNext;
	}
	pNode pCur = NULL;
	pNode pPre = NULL;
	//当ptail指向头说明只有一个节点了，不需要比较
	while (pTail != pHead) {
		pCur = pHead;
		//每趟比到pcur在ptail前就可以了，因为pcur与pcur->next值比较
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
		pTail = pPre;		//ptail每次后退一个位置
	}
}
//合并两个有序链表
pNode merge_llist(pNode pa, pNode pb)
{
	pNode pNew = NULL;
	//处理头结点
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
	//走到这里，pa或者pb为空
	if (pa) {
		pNew->pNext = pa;
	}
	else {
		pNew->pNext = pb;
	}
	return pNewHead;
}
//查找链表的中间结点
pNode FindMiddleNode(pNode pHead)
{
	if (NULL == pHead) {
		return NULL;
	}
	//考虑两种情况，奇数个和偶数个结点
	pNode pLow = pHead;
	pNode pFst = pHead;
	pNode pPre = NULL;  //如果偶数个结点，返回较小的
	while (pFst && pFst->pNext) {
		pPre = pLow;
		pLow = pLow->pNext;
		pFst = pFst->pNext->pNext;
	}
	//走到这里pfst如果是空就是偶数个结点
	if (NULL == pFst) {
		return pPre;
	}
	else {
		return pLow;
	}
}
//倒数第K个结点
pNode FindLastKNode(pNode pHead, int K)
{
	if (NULL == pHead || K <= 0) {
		return NULL;
	}
	pNode pFst = pHead;
	while (K--) {
		if (NULL == pFst) {	//这个条件一定在走fst之前
			return NULL;		//一是保证即使k很大也能退出，二保证pFst=NULL的情况正常出去
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
// 删除链表的倒数第K个结点
pNode DeleteLastKNode(pNode pHead, int K)
{
	if (NULL == pHead || K <= 0) {
		return NULL;
	}
	pNode pFst = pHead;
	while (K--) {
		if (NULL == pFst) {	//这个条件一定在走fst之前
			return NULL;		//一是保证即使k很大也能退出，二保证pFst=NULL的情况正常出去
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
	//这里保证找到了倒数第K个结点pLow,考虑是不是头结点
	if (pHead == pLow) {
		pNode pNew = pHead->pNext;
		free(pHead);
		return pNew;
	}
	else {
		pPre->pNext = pLow->pNext;
		free(pLow);					//如果在别的程序使用plow存在内存泄漏？
		return pHead;
	}
}
// 判断两个单链表是否相交---链表不带环 
int IsSListCross(pNode pHead1, pNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2) {
		return -1;
	}
	//找两个链表的最后一个结点
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
//求两个单链表相交的交点--- 链表不带环
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
	//走到这里两个指针距相交点有相同距离
	while (pHead1 != pHead2) {
		pHead1 = pHead1->pNext;
		pHead2 = pHead2->pNext;
	}
	return pHead1;
}
