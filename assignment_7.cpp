#include <stdio.h>
#include <stdlib.h>
struct node{
	char info;
	struct node * l;
	struct node * r;
};
struct node *root=NULL;
struct node * insert (char data){
	struct node * temp=(struct node * )malloc(sizeof(struct node *));
	temp->info=data;
	temp->l=NULL;
	temp->r=NULL;
	struct node * curr, * temp2;
	if(root==NULL){
		root=temp;
	}
	else{
		curr=root;
		while(curr!=NULL){
			temp2=curr;
			if(curr->info > data)curr=curr->l;
			else curr=curr->r;
		}
		if(temp2->info > data)temp2->l=temp;
		else temp2->r=temp;
	}
}
void search(char key){
	struct node * curr=root;
	while(curr!=NULL){
		if(curr->info==key){
			printf("Element exists");
			return;
		}
		else if(curr->info >key)curr=curr->l;
		else curr=curr->r;
	}
	printf("Element not found");
}
void inorder(struct node * arg){
	struct node * curr=arg;
	if(curr==NULL)return;
	inorder(curr->l);
	printf("%c ",curr->info);
	inorder(curr->r);
	return;
}
void postorder(struct node * arg){
	struct node * curr=arg;
	if(curr==NULL)return;
	postorder(curr->l);
	postorder(curr->r);
	printf("%c ",curr->info );
	return;
}
void preorder(struct node * arg){
	struct node * curr=arg;
	if(curr==NULL)return;
	printf("%c ",curr->info);
	preorder(curr->l);
	preorder(curr->r);
	return;
}
int main(){
	printf(" 1:Insert Element \n 2:View Tree in Inorder \n 3:View tree in postorder \n 4:View tree in preorder \n 5:Check if an element exists \n ");
	while(1){
		printf("input");
		int code;
		char inp;
		scanf("%d",&code);
		if(code==1){
			printf("\nEnter the character:\n");
			//char c;
			scanf(" %c",&inp);
			insert(inp);
		}
		else if(code==2){
			printf("\n");
			inorder(root);
		}
		else if(code ==3){
			printf("\n");
			postorder(root);
		}
		else if(code ==4){
			printf("\n");
			preorder(root);
		}
		else if(code ==5){
			printf("\nEnter the character:");
			scanf(" %c",&inp);
			search(inp);
		}
		else {
			exit(0);
		}
		printf("\n");
	}
	return 0;

}