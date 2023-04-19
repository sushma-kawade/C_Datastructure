/*write a program which return addition of even number from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  AdditionEven()  
// Description   :  Written addition of all even number From Singly Linear Linked List
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

int AdditionEven(PNODE First)
{

    int iNo = 0, iSum = 0; // 2 Variables gatle for % and + sathi

    while (First != NULL) 
    {
        if(First -> data % 2 == 0)
        {
            iSum = iSum + First -> data;
        }
        First = First -> next;
    }
    return iSum;
}

int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,41);
    InsertATFirst(&Head,32);
    InsertATFirst(&Head,20);
    InsertATFirst(&Head,11);
    iRet = AdditionEven(Head);
    printf("Addition of all even elemets is :%d\n",iRet);
    Display(Head);

    return 0;
}
