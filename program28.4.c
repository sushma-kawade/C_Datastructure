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
    int iMax = 0;
    iMax = First->data;

    while(First != NULL)
    {
       if(First->data > iMax)
       {
        iMax = First->data;
       } 
       First = First -> next;
    }

    return iMax;
}
int main()
{
    PNODE Head = NULL;
    int No = 0,iRet = 0;
    InsertATFirst(&Head,240);
    InsertATFirst(&Head,320);
    InsertATFirst(&Head,230);
    InsertATFirst(&Head,110);
    Display(Head);
    iRet = Addition(Head);
    printf("Maximum is : %d\n",iRet);
    return 0;
}
    