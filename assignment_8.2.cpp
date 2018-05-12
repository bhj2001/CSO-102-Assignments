#include<stdio.h>
int n=0;
int adj[100][100]={0};
int vis[100]={0};
int stack[100];
int top=-1;
int pop(){
	if(top!=-1)return stack[top--];
	else return -1;
}
void push(int p){
	if(top!=99)stack[++top]=p;
}
void dfs( int node){
	push(node);
	vis[node]=1;
	printf("%d ",node);
	while(top!=-1){
		int v =pop();
		for(int i=0;i<n;i++){
			if(adj[v][i]==1 && vis[i]==0){
				push(i);
				vis[i]=1;
				printf("%d ",i);
			}
		}
	}
}

int main(){
	printf("input\n1)number of nodes\n2)number of edges\n3)each edge\n4)root node \n");
	int e;
	scanf("%d",&n);	
	scanf("%d",&e);
	for(int i=0;i<e;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		adj[t1][t2]=1;
	}
	int temp;
	scanf("%d",&temp);
	printf("\n");
	dfs(temp);
}