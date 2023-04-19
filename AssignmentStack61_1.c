#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *First = NULL;

void Push(int No)
{
    struct node *newn = (struct node*)malloc(sizeof(struct node));

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    printf("%d :gets pushed in the stack succesfully\n",newn->data);
}
int Pop()
{
    struct node *temp;
    if(First == NULL)
    {
        return -1;
    }
    else
    {
        First = First->next;
        free(temp);
    }
    return First->data;
}
void Display()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = First;

    printf("The elemets of stack are :\n");
    while(temp != NULL)
    {
        printf("| %d |->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int iRet = 0;
    Push(101);
    Push(51);
    Push(21);
    Push(11);

    Display();

    iRet = Pop();
    printf("The poped elemets is :%d\n",iRet);

    iRet = Pop();
    printf("The poped elemets is :%d\n",iRet);

    Display();
    return 0;
}