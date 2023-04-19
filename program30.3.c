/*write a program which Display product of all digit  of all elemets from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplayProduct()  
// Description   :  Display product of all digit all elemets From Singly Linear Linked List
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

void DisplayProduct( PNODE First)
{
    int iDigit = 0, Sum = 0;
    while (First != NULL)
    {
        Sum = 1;
        while (First -> data > 0)
        {
            iDigit = First -> data % 10;
            {
                Sum = Sum * iDigit;
            }
            First -> data = First -> data / 10;
        }
        printf("%d\t", Sum);
        First = First -> next;
    }
}


int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,41);
    InsertATFirst(&Head,32);
    InsertATFirst(&Head,21);
    InsertATFirst(&Head,11);
    Display(Head);

    DisplayProduct(Head);

    return 0;
}
