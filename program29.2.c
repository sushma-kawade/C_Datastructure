/*write a program which display all elementc which are prime from sigly linearlink list*/
//////////////////////////////////////////////////////////////////////////////
//
// Function Name :  DisplayPrime()  
// Description   :  find Prime number From Singly Linear Linked List
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

void DisplayPrime(PNODE First)
{

    int iNo = 0, iCnt = 0; // 2 Variables gatle for % and + sathi

    while (First != NULL)
    {
        iNo = 0;
        for(iCnt = 2; iCnt < First -> data; iCnt++)
        {
            if(First -> data % iCnt == 0)
            {
                iNo = 1;
                break;
            }
        }
        if(iNo == 0)
        {
            printf("%d\t", First -> data);
        }
        First = First -> next;
    }

}


int main()
{
    PNODE Head = NULL;
    int iNo = 0,iRet = 0;

    InsertATFirst(&Head,89);
    InsertATFirst(&Head,22);
    InsertATFirst(&Head,41);
    InsertATFirst(&Head,17);
    InsertATFirst(&Head,20);
    InsertATFirst(&Head,11);
    Display(Head);
    DisplayPrime(Head);

    return 0;
}
