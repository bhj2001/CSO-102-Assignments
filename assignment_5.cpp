//author::bhj2001
//time::SunFeb 11, 22:45:35
//subject::CS102 ass5
#include<stdio.h>
#include<stdlib.h>
struct node{
	int value=-1;//means::val not allocated
	struct node * link=NULL;//means::points to nothing
};
struct node *start_link,*temp;
struct node* create(struct node *pre_link,int data)
{
	 pre_link->link=(struct node*)malloc(sizeof(struct node));
	 struct node* cur_link=pre_link->link;
	 cur_link->value=data;
	 cur_link->link=NULL; 
	 return cur_link;
}
void print_it()
{
	temp=start_link->link;
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp=temp->link;
	}
	printf("\n");
}
void delete_it(int del)
{
	temp=start_link->link;
	struct node *temp2=start_link;
	int flag=0;
	while(temp!=NULL)
	{
		int flag2=0;
		if(temp->value==del)
		{
			flag2=1;
			flag++;
			temp2->link=temp->link;
			temp=temp->link;
		}	
		if(flag2==0)
		{
			temp=temp->link;
			temp2=temp2->link;
		}
	}
	if(flag==0)
	{
		printf("node not found\n");
		return ;
	}
	printf("node %d deleted %d times\n",del,flag);

}
void add_it(int add)
{
	temp=start_link;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=(struct node *)malloc(sizeof(struct node));
	temp->link->value=add;
	printf("node %d added\n",add);
}
int main()
{
	printf("enter number of nodes\n");
	int n;
	scanf("%d",&n);
	printf("enter %d integers\n",n);
	int i;
	start_link=(struct node*)malloc(sizeof(struct node));
	start_link->value=69;
	temp=start_link;
	for(i=0;i<n;i++)
		{
			int bkj;
			scanf("%d",&bkj);
			temp=create(temp,bkj);
		}
	printf("\n1. DISPLAY LINKED LIST\n2. DELETE NODE\n3. ADD NODE AT LAST\n");
	int s;
	while(scanf("%d",&s))
	{
		switch(s)
		{
			case 1:
			print_it();
			break;
			case 2:
			printf("enter node to be deleted: ");
			int del;
			scanf("%d",&del);
			delete_it(del);
			break;
			case 3:
			printf("enter node to be added: ");
			int add;
			scanf("%d",&add);
			add_it(add);
			break;
		}
	}
	return 0;
}