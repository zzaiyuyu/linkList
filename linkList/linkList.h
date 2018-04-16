#pragma once
typedef int DataType;
//������pNodeΪָ��ṹ��ָ�������
typedef struct ListNode {
	struct ListNode * pNext;
	DataType data;
}Node, *pNode;

//��ʼ��
void SListInit(pNode* pHead);
//β��
void linkListPushBack(pNode * pHead, int data);
//βɾ
void linkListPopBack(pNode * pHead);
//ͷ��
void linkListPushFront(pNode * pHead, int data);
//ͷɾ
void linkListPopFront(pNode * pHead);
//����λ�ò���
void linkListInsert(pNode *pHead, int data, pNode pos);
//����λ��ɾ��
void linkListErase(pNode *pHead, pNode pos);
//Ѱ��ֵΪdata�Ľ��
pNode findNode(pNode pHead, int data);
//����������
int SListSize(pNode pHead);
// �ж������Ƿ�Ϊ�� 
int SListEmpty(pNode pHead);
// �������� 
void SListDestroy(pNode* pHead);

/******************************������**************************************/
void reverse_print(pNode pHead);//��β��ͷ��ӡ����

void erase_node(pNode *pHead, pNode pos);//O��1��ɾ�����

void insert_node(pNode *pHead, int data, pNode pos);//O��1��������

int joseph_circle(pNode *pHead, int num);//������Լɪ�򻷣��������һ��ʣ�µĽ��ֵ

void reverse_llist(pNode *pHead);//��ת��������ָ��

pNode ReverseSListOP(pNode pHead);	  //��ת����--ͷ�巨 

void bubble_llist(pNode  pHead); // ð����������

pNode merge_llist(pNode pa, pNode pb);//�ϲ���������

pNode FindMiddleNode(pNode pHead);// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 

pNode FindLastKNode(pNode pHead, int K);// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 

pNode DeleteLastKNode(pNode pHead, int K);// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
									  
int IsSListCross(pNode pHead1, pNode pHead2);// �ж������������Ƿ��ཻ---�������� 

pNode GetCorssNode(pNode pHead1, pNode pHead2);// �������������ཻ�Ľ���---�������� 