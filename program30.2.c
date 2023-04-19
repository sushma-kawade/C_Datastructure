/*write a program which Display all palindrome  of elemets from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplayPalindrome()  
// Description   :  Display palindrome each elemets From Singly Linear Linked List
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

void DisplayPallindrome(PNODE First)
{

    int iDigit = 0, iRev = 0, iTemp = 0; 

    while(First != NULL)
    {
        if(First == NULL)
        {
            return;
        }

        iRev = 0;
        iTemp = First -> data;

        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            {
                iRev = iRev * 10 + iDigit;
            }
            iTemp = iTemp / 10;
        }
        
        if(First -> data == iRev)
        {
            printf("%d\t", iRev);
        }
        First = First -> next;
    }
}


int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,89);
    InsertATFirst(&Head,6);
    InsertATFirst(&Head,414);
    InsertATFirst(&Head,17);
    InsertATFirst(&Head,28);
    InsertATFirst(&Head,11);
    Display(Head);

    DisplayPallindrome(Head);

    return 0;
}
