/******************************************************** 
 *    #####   #    #    ##     ####    #   #    ##      *
 *    #    #  #    #   #  #   #    #    # #    #  #     *
 *    #####   ######  #    #  #          #    #    #    *
 *    #    #  #    #  ######  #  ###     #    ######    *
 *    #    #  #    #  #    #  #    #     #    #    #    *
 *    #####   #    #  #    #   ####      #    #    #    *                                                   
 ********************************************************/
#include<stdio.h>
char stack[6969];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int prec(char x)
{
    if(x=='(')
        return 0;
    if(x=='+')
        return 1;
    if(x=='-')
        return 1;
    if(x=='*')
        return 2;
    if(x=='/')
        return 2;
}
int isdigit(char t)
{
    if(t-'0'>=0&&t-'0'<=9)
        return 1;
    return 0;
}
////////////////////
int intstack[6969],inttop=-1;
void intpush(int x)
{
    intstack[++inttop] = x;
}

int intpop()
{
    if(inttop == -1)
        return -1;
    else
        return intstack[inttop--];
}
main()
{
    //printf("+ OR\n* XOR\nP AND\n- >>\n");
    char exp[6969];
    char *e, x;
    printf("enter infix => ");
    scanf("%s",exp);
    e = exp;
    char postfix[6969];
    int cur=0;
    while(*e != '\0')
    {
        if(isdigit(*e))
            postfix[cur++]=*e;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                postfix[cur++]=x;
        }
        else
        {
            while(prec(stack[top]) >= prec(*e))
                postfix[cur++]=pop();
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        postfix[cur++]=pop();
    }
    printf("postfix => %s\n",postfix);

    for(int i=0;i<cur;i++)
    {
        char temp=postfix[i];
        if(isdigit(temp))
            intpush(temp-'0');
        else
        {
            int q1=intpop(),q2=intpop();
            if(temp=='+') intpush(q1+q2);
            if(temp=='-') intpush(q2-q1);
            if(temp=='*') intpush(q1*q2);
            if(temp=='/') intpush(q2/q1);
        }
    }
    printf("evaluated value => %d",intstack[0]);
    return 0;
}