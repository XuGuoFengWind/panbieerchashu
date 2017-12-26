#include <stdio.h>
#include <stdlib.h>
//判别二叉搜索树是否相等 
typedef struct TreeNode *Tree;
struct TreeNode{
	int V;
	Tree Left,Right;
	int flag;
};
Tree NewNode(int v);
Tree MakeTree(int n);
Tree Insert(Tree T,int v);
int check(Tree T,int V); 
int Judge(Tree T,int N);
void ResetT(Tree T);
void FreeTree(Tree T);


int main(int argc, char *argv[]) {
	int N,L,i;
	Tree T;
	scanf("%d",&N);//读入节点数目
	while(N)
	{
		scanf("%d",&L);   //读入要比较的树的数目 
		T=MakeTree(N);   //读入后面的N个数据来建树 
		for(i=0;i<L;i++)
		{
			if(Judge(T,N))  //判别树是否相等 
			printf("Yes\n");
			else
			printf("No\n");
			ResetT(T);//清楚T中的flag标记 
		}
		FreeTree(T);//释放树中的节点信息 
		scanf("%d",&N);
		
	}
	return 0;
}
Tree MakeTree(int n){
	Tree T;
	int i,v;
	scanf("%d",&v);
	T=NewNode(v);
	for(i=1;i<n;i++)
	{
		scanf("%d",&v);
		T=Insert(T,v);
	}
	return T;
}
Tree NewNode(int v)//生成新节点 
{
	Tree T=(Tree)malloc(sizeof(struct TreeNode));
	T->V=v;
	T->Left=T->Right=NULL;
	T->flag=0;
	return T;
}
Tree Insert(Tree T,int v)//插入节点 
{
	if(!T)
	{
		T=NewNode(v);
	}
	else{
		if(v>T->V)
		T->Right=Insert(T->Right,v);
		else
		T->Left=Insert(T->Left,v);
	}
	return T;
}
int check(Tree T,int V)
{
	if(T->flag)
	{
		if(V<T->V)
		return check(T->Right,V);
		else if(V>T->V)
		return check(T->Right,V);
		else
		return 0;
	}
	else
	{
		if(V==T->V)
		{
			T->flag=1;
			return 1;
		}
		else
		return 0;
	}
}
int Judge(Tree T,int N)
{
	int i,v,flag=0;  //flag=0代表目前还一致，为1代表不一致 
	scanf("%d",&v);
	if(v!=T->V)
	flag=1;
	else
	T->flag=1;
	for(i=1;i<N;i++)
	{
		scanf("%d",&v);
		if((!flag) && (!check(T,v)))
		flag=1;
	}
	if(flag)
	return 0;
	else return 1;
}
void ResetT(Tree T)
{
	if(T->Left)
	ResetT(T->Left);
	if(T->Right)
	ResetT(T->Left);
	T->flag=0; 
}
void FreeTree(Tree T)
{
	if(T->Left)
	FreeTree(T->Left);
	if(T->Right)
	FreeTree(T->Right);
	free(T);
}