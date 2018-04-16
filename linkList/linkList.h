#pragma once
typedef int DataType;
//重命名pNode为指向结构体指针的类型
typedef struct ListNode {
	struct ListNode * pNext;
	DataType data;
}Node, *pNode;

//初始化
void SListInit(pNode* pHead);
//尾插
void linkListPushBack(pNode * pHead, int data);
//尾删
void linkListPopBack(pNode * pHead);
//头插
void linkListPushFront(pNode * pHead, int data);
//头删
void linkListPopFront(pNode * pHead);
//任意位置插入
void linkListInsert(pNode *pHead, int data, pNode pos);
//任意位置删除
void linkListErase(pNode *pHead, pNode pos);
//寻找值为data的结点
pNode findNode(pNode pHead, int data);
//返回链表长度
int SListSize(pNode pHead);
// 判断链表是否为空 
int SListEmpty(pNode pHead);
// 销毁链表 
void SListDestroy(pNode* pHead);

/******************************面试题**************************************/
void reverse_print(pNode pHead);//从尾到头打印链表

void erase_node(pNode *pHead, pNode pos);//O（1）删除结点

void insert_node(pNode *pHead, int data, pNode pos);//O（1）插入结点

int joseph_circle(pNode *pHead, int num);//单链表约瑟夫环，返回最后一个剩下的结点值

void reverse_llist(pNode *pHead);//反转链表——三指针

pNode ReverseSListOP(pNode pHead);	  //反转链表--头插法 

void bubble_llist(pNode  pHead); // 冒泡排序链表

pNode merge_llist(pNode pa, pNode pb);//合并有序链表

pNode FindMiddleNode(pNode pHead);// 查找链表的中间结点，要求只能遍历一次链表 

pNode FindLastKNode(pNode pHead, int K);// 查找链表的倒数第K个结点，要求只能遍历一次链表 

pNode DeleteLastKNode(pNode pHead, int K);// 删除链表的倒数第K个结点，要求只能遍历一次链表 
									  
int IsSListCross(pNode pHead1, pNode pHead2);// 判断两个单链表是否相交---链表不带环 

pNode GetCorssNode(pNode pHead1, pNode pHead2);// 求两个单链表相交的交点---链表不带环 