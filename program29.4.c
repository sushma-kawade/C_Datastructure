/*write a program which return second maximum number from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  SecMaximum()  
// Description   :  Written second maximum elemets From Singly Linear Linked List
// Input         :  Integer
// Output        :  Integer
// Author        :  Sushma Kawade
// Date          :  5 feb 2023
//
////////////////////////////////////////////////////////////////////////////


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

int SecMaximum(PNODE First)
{
    int Max = First -> data; // int Max = 0;
    int Min = First -> data;

    while(First != NULL)
    {
        if(First -> data > Max)
        {
            Min = Max;
            Max = First -> data;
        }
        else if(First -> data > Min)
        Min = First -> data;
        First = First -> next;
    }
    return Min;
}

int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,240);
    InsertATFirst(&Head,320);
    InsertATFirst(&Head,230);
    InsertATFirst(&Head,110);
    Display(Head);

    iRet = SecMaximum(Head);
    printf("second maximum elemet is :%d\n",iRet);

    return 0;
}
