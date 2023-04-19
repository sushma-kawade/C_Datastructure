/*write a program which serch first occurance of perticular elements from sigly linearlink list*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertATFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));      

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL) 
    {
        *First = newn;
    }
    else                
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}


int Addition(PNODE First)
{
    int iSum = 0;
    while(First != NULL)
    {
        iSum = iSum +(First -> data);
        First = First -> next;
    }
    return iSum;
    

}
int main()
{
    PNODE Head = NULL;
    int No = 0,iRet = 0;
    InsertATFirst(&Head,40);
    InsertATFirst(&Head,30);
    InsertATFirst(&Head,20);
    InsertATFirst(&Head,10);
    Display(Head);
    iRet = Addition(Head);
    printf("Addition is : %d\n",iRet);
    return 0;
}
    