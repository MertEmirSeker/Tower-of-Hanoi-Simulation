
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct Stack    //our stack
{
    int maxsize;
    int *array;
    int currentsize;
};

struct Stack *
createStack(int maxsize)        //stack function
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->maxsize = maxsize;
    stack->currentsize = -1;
    stack->array = (int *)malloc(stack->maxsize * sizeof(int));
    return stack;
}

int isEpty(struct Stack *stack)     //checking is empty
{
    return stack->currentsize == -1;
}

int isFull(struct Stack *stack)
{
    return stack->currentsize == stack->maxsize - 1;
}

int push(struct Stack *stack, int d)    //push function
{
    if (isFull(stack))
    {
        return 0;
    }
    stack->array[++stack->currentsize] = d;
}

int pop(struct Stack *stack)    //pop function
{
    if (isEpty(stack))
    {
        return 0;
    }
    return stack->array[stack->currentsize--];
}

void printdisk(int fp, int sp, int disk)        //printing function
{
    printf("Move the disk %d from '%d' to '%d'\n" , disk , fp , sp);
}

void movedisk(struct Stack *a, struct Stack *b, int fp, int sp)     //moving function
{
    int pole1 = pop(a);
    int pole2 = pop(b);

    // when pole 1 is empty
    if (pole1 == 0)
    {
        push(a, pole2);
        printdisk(sp, fp, pole2);
    }
    // when pole 2 is empty
    else if (pole2 == 0)
    {
        push(b, pole1);
        printdisk(fp, sp, pole1);
    }
    // when the top of disk pole1 > top of disk pole2
    else if (pole1 > pole2)
    {
        push(a, pole1);
        push(a, pole2);
        printdisk(sp, fp, pole2);
    }
    // when the top of disk pole2 > top of disk pole1
    else
    {
        push(b, pole2);
        push(b, pole1);
        printdisk(fp, sp, pole1);
    }
}

void toh(int towersize , struct Stack *a , struct Stack *b , struct Stack *c)
{
    int i , totalmove;
    int fp = 1 , sp = 2 , tp = 3;  //first pole , second pole , third pole
    if(towersize % 2 == 0)
    {
        int temp = tp;
        tp = sp;
        sp = temp;
    }
    totalmove = pow(2 , towersize) - 1;

    for( i = towersize ; i >= 1 ; i--)
    {
        push(a , i);
    }
    for( i = 1; i <= totalmove ; i++)
    {
        if(i % 3 == 1)
        {
            movedisk(a , c , fp , tp);
        }
        else if(i % 3 == 2)
        {
            movedisk(a , b ,fp , sp);
        }
        else if(i % 3 == 0)
        {
            movedisk(b , c , sp , tp);
        }
    }
}

int main()
{
    int towersize;
    printf("Enter Tower size: ");
    scanf("%d" , &towersize);
    struct Stack *a , *b, *c;

    a = createStack(towersize);
    c = createStack(towersize);
    b = createStack(towersize);
   

    toh(towersize , a , b , c);
    return 0;
}