
#include<stdio.h>
#include<stdlib.h>
 
struct SListNode 
{
	int data;
	struct SListNode* next;
};

void AddNode(struct SListNode **head,int data)
{
    struct SListNode *newNode;
    struct SListNode *temp;
    newNode = (struct SListNode*)malloc(sizeof(struct SListNode));//申请内存空间，创建节点
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }

    printf("内存分配成功\n");

    newNode->data = data;

    if (*head != NULL)
    {
        temp = *head;
        printf("不是空链表\n");

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        
    }
    else
    {
        printf("是空链表\n");
        *head = newNode;
        newNode->next = NULL;
    }
}

void InsertNode(struct SListNode *head,int data,int inpData)
{
    struct SListNode *dataH;
    dataH = head;

    struct SListNode *newNode;
    newNode = (struct SListNode*)malloc(sizeof(struct SListNode));//申请内存空间，创建节点
    newNode->data = inpData;
    newNode->next = NULL;


    while (dataH != NULL && dataH->data != data)
    {
        dataH = dataH->next;
    }
    if (dataH == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
    newNode->next = dataH->next;
    dataH->next=newNode;
    }
    

}

void PrintfStruct(struct SListNode *head)
{
    struct SListNode *dataH;
    dataH = head;

    printf("输入的数据为：\n");

    while (dataH != NULL)
    {
        printf("%d ",dataH->data);
        dataH = dataH->next;
    }
    printf("\n");
    
}

int main()
{

    struct SListNode *head = NULL;
    int inpData;
    while (1)
    {
        printf("输入数值(-1结束):\n");
        scanf("%d",&inpData);
        if (inpData == (-1)) break;
        
        AddNode(&head,inpData);
        
    }
    PrintfStruct(head);

    printf("在哪一个数字后插入\n");
    int operation;
    scanf("%d",&operation);
    printf("插入什么");
    scanf("%d",&inpData);
    InsertNode(head,operation,inpData);

    PrintfStruct(head);
    

    return 0;
}



