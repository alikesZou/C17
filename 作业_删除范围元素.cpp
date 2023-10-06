#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -2
#define MAXSIZE 100
typedef double ElemType;

//用链表实现
//定义结点
typedef struct Lnode{
	ElemType x;//数据域 
	struct Lnode* next;//指针域 
}Lnode,*LinkList; 

//链表初始化
void Init_Lnode(LinkList &L){
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
} 

//从头开始存入元素 
void Save_Lnode(LinkList &L){
	LinkList p = L;
	char c;
	do{
		LinkList s;
		Init_Lnode(s);
		scanf("%lf",&s->x);
		p->next = s;
		p = p->next;
	}while((c = getchar()) != '\n');
}
//判断线性表为空
int Empty_Lnode(LinkList L){
	if(L->next)
		return 0;
	else
		return 1;
} 
//输出线性表L
void Print_Lnode(LinkList L){
	if(Empty_Lnode(L) == 0){
		LinkList p = L->next;
		while(p){
			printf("%lf ",p->x);
			p = p->next;
		}
	}else{
		printf("无"); 
	}
} 

//删除元素
void Delete_Lnode(LinkList &L,ElemType mink,ElemType maxk){
	LinkList p = L;
	//p作为遍历指针，从第一个元素开始遍历 
	while(p->next){
		if(p->next->x > mink && p->next->x < maxk){//如果一个元素在mink与maxk之间，则删除这个元素 
			LinkList x = p->next;
		 	p->next = p->next->next;//删除结点 
		 	free(x);//释放删除的结点 
		}else{
				p = p->next;
		}
	
		if(p->x > maxk) break;
	}
} 
int main(){
	ElemType mink,maxk;
	scanf("%lf %lf",&mink,&maxk);
	LinkList L;
	Init_Lnode(L);
	Save_Lnode(L);
	Delete_Lnode(L,mink,maxk);
	Print_Lnode(L);
} 
