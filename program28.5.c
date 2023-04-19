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


int Minimum(PNODE First)
{
    int iMin = 0;
    if(First == NULL)
    {
        printf("Linked list is empty\n");
        return 0;
    }
    
    iMin = First->data;

    while(First != NULL)
    {
       if(First->data < iMin)
       {
        iMin = First->data;
       } 
       First = First -> next;
    }

    return iMin;
}
int main()
{
    PNODE Head = NULL;
    int No = 0,iRet = 0;
    InsertATFirst(&Head,640);
    InsertATFirst(&Head,240);
    InsertATFirst(&Head,20);
    InsertATFirst(&Head,230);
    InsertATFirst(&Head,110);
    Display(Head);
    iRet = (Head);
    printf("Minimum is : %d\n",iRet);
    return 0;
}
    