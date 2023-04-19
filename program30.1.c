/*write a program which Display Reverse each of elemets from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  Reverse()  
// Description   :  Reverse each elemets From Singly Linear Linked List
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

void Reverse(PNODE First)
{
    int newn = 0, iDigit = 0;

    while(First != NULL)
    {
        if(First == NULL)
        {
            return;
        }

        newn = 0;

        while(First -> data > 0)
        {
            iDigit = First -> data % 10;
            {
                newn = newn * 10 + iDigit;
            }
            First -> data = First -> data / 10;
        }
        printf("| %d |->", newn);
        First = First -> next;
    }
}

int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,89);
    InsertATFirst(&Head,6);
    InsertATFirst(&Head,41);
    InsertATFirst(&Head,17);
    InsertATFirst(&Head,28);
    InsertATFirst(&Head,11);
    Display(Head);

    Reverse(Head);

    return 0;
}
