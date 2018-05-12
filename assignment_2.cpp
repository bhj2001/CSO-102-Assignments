#include<stdio.h>
#include<stdlib.h>

struct arrayStack
{
  int top1,top2,capacity;
  int* array;
};

struct arrayStack* createStack(int cap)
{
  struct arrayStack* temp;
  temp=(struct arrayStack*)malloc(sizeof(struct arrayStack));
  temp->capacity=cap;
  temp->top1=-1;
  temp->top2=cap;
  temp->array=(int*)malloc(sizeof(int)*cap);
  return(temp);
}

void push1(struct arrayStack* stack,int data)
{
  if(stack->top2==stack->top1+1)
  {
    printf("Both Stacks are full");
    return;
  }
  stack->top1++;
  stack->array[stack->top1]=data;
}

void push2(struct arrayStack* stack,int data)
{
  if(stack->top2-1==stack->top1)
  {
    printf("Both Stacks are full");
    return;
  }
  stack->top2--;
  stack->array[stack->top2]=data;
}

int pop1(struct arrayStack* stack)
{
  if(stack->top1==-1)
  {
    printf("Stack 1 is empty");
    return -1;
  }
  int data;
  data=stack->array[stack->top1];
  stack->top1--;
  return(data);
}

int pop2(struct arrayStack* stack)
{
  if(stack->top2==stack->capacity)
  {
    printf("Stack 2 is empty");
    return -1;
  }
  int data;
  data=stack->array[stack->top2];
  stack->top2++;
  return(data);
}

void print(struct arrayStack* stack)
{
  int top;
  printf("Stack 1 contains");
  for(top=stack->top1;top>=0;top--)
  {
    printf(" %d",stack->array[top]);
  }
  printf("\nStack 2 contains");
  for(top=stack->top2;top<stack->capacity;top++)
  {
    printf(" %d",stack->array[top]);
  }
  printf("\n");
}

int main()
{
  int cap,s,item;
  printf("Input Size\n");
  scanf("%d",&cap);
  struct arrayStack* stack=createStack(cap);
  while(1)
  {
    printf("Choose any option\n1. Push in Stack 1\n2.  Push in Stack 2\n3.  Pop from Stack 1\n4.  Pop from Stack 2\n5.  Print Stacks\n6.  Exit\n");
    scanf("%d",&s);
    switch(s)
    {
      case 1:
        printf("Input Data\n");
        scanf("%d",&item);
        push1(stack,item);
        break;
      case 2:
        printf("Input Data\n");
        scanf("%d",&item);
        push2(stack,item);
        break;
      case 3:
        item=pop1(stack);
        if(item!=-1)
        printf("%d",item);
        break;
      case 4:
        item=pop2(stack);
        if(item!=-1)
        printf("%d",item);
        break;
      case 5:
        print(stack);
        break;
      case 6:
        exit(0);
    }
    printf("\n");
  }
  return 0;
}