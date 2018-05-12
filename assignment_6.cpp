#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node * next;
	struct node * prev;
};
struct deque{
	struct node * head;
	struct node * tail;
};
void insertFront(int data, struct deque * arg){
	if(arg->head->next!=NULL){	
		struct node * temp=(struct node *)malloc(sizeof(struct node *));
		struct node * currhead=arg->head;
		temp->info=data;
		temp->next=currhead;
		temp->prev=NULL;
		currhead->prev=temp;
		arg->head=temp;
	}
	else {
		struct node * temp=(struct node *)malloc(sizeof(struct node *));
		temp->info=data;
		temp->next=arg->head;
		temp->prev=NULL;
		arg->head->prev=temp;
		arg->tail=arg->head;
		arg->head=temp;
	}
}
void insertEnd(int data, struct deque * arg){
	if(arg->head->next!=NULL){
		struct node * temp=(struct node *)malloc(sizeof(struct node *));
		struct node * currtail=arg->tail;
		temp->info=data;
		temp->next=NULL;
		temp->prev=currtail;
		currtail->next=temp;
		arg->tail=temp;
	}
	else{
		struct node * temp=(struct node *)malloc(sizeof(struct node *));
		temp->info=data;
		temp->next=NULL;
		temp->prev=arg->head;
		arg->head->next=temp;
		arg->tail=temp;

	}
}
void popFront(struct deque * arg){
	if(arg->head->next!=NULL){
		struct node * temp=arg->head;
		struct node * temp2=temp->next;
		temp2->prev=NULL;
		arg->head=temp2;
		free(temp);
	}
	else {
		printf("Cant delete last node");
	}
}
void popBack(struct deque * arg){
	if(arg->head->next!=NULL){
		struct node * temp=arg->tail;
		struct node * temp2=temp->prev;
		temp2->next=NULL;
		free(temp);
		arg->tail=temp2;
	}
	else {
		printf("Cant delete last node");
	}
}
void printDeque(struct deque * arg){
	struct node * temp=arg->head;
	while(temp!=NULL){
		printf("%d ",temp->info);
		temp=temp->next;
	}
}
struct deque * createDeque(int data){
	struct node * thead=(struct node *)malloc(sizeof(struct node *));
	struct node * ttail=(struct node *)malloc(sizeof(struct node *));
	struct deque * lol=(struct deque *)malloc(sizeof(struct deque *));
	thead->next=NULL;
	thead->prev=NULL;
	ttail->next=NULL;
	ttail->prev=NULL;
	thead->info=data;
	ttail->info=data;
	lol->head=thead;
	lol->tail=ttail;
	return lol;
}
int main(){
	//struct deque * lol=(struct deque *)malloc(sizeof(struct deque *));
	struct deque * abc=createDeque(1);
	printf("1:push_back \n 2:push_back \n 3:pop_back \n 4:pop_front\n ");
	while(1){
		printf("input:");
		int code;
		scanf("%d",&code);
		printf("\n");
		if(code==1){
			printf("Enter number to insert:");
			int n;
			scanf("%d",&n);
			insertEnd(n,abc);
		}
		else if(code==2){
			printf("Enter number to insert:");
			int n;
			scanf("%d",&n);
			insertFront(n,abc);	
		}
		else if (code==3){
			popBack(abc);
		}
		else if(code==4){
			popFront(abc);
		}
		else {
			return 0;
		}
		printf("\n");
		printDeque(abc);
		printf("\n");
	}
	return 0;
}