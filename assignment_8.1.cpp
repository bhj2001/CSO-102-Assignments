#include<stdio.h>
int n=0;
int adj[1000][1000]={0};
int vis[1000]={0};

#define N 1005

int queue[N];
int front = 0;
int rear = -1;
int size = 0;

bool empty() {
   return size == 0;
}

bool full() {
   return size == N;
}

void push_back(int data) {
   if(!full()) {
	
      if(rear == N-1) {
         rear = -1;            
      }       

      queue[++rear] = data;
      size++;
   }
}

int pop() {
   int data = queue[front++];
	
   if(front == N) {
      front = 0;
   }
	
   size--;
   return data;  
}

void bfs(int node){
	push_back(node);
	vis[node]=1;
	printf("%d ",node);
	while(empty()==false){
		int v=pop();
		for(int i=0;i<n;i++){
			if(adj[v][i]==1 && vis[i]==0){
				push_back(i);
				vis[i]=1;
				printf("%d ",i );
			}
		}
	}
}

int main(){
	printf("input\n1)number of nodes\n2)number of edges\n3)each edge\n4)root node \n");
	int e;
	scanf("%d",&n);	
	scanf("%d",&e);
	for(int i=1;i<=e;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		adj[t1][t2]=1;
		adj[t2][t1]=1;
	}
	int root;
	scanf("%d",&root);
	printf("\n");
	bfs(root);
}