#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//定义结点，其中为编号和密码 
typedef struct Lnode{
	ElemType code;//记录密码 
	int number;//记录编号 
	struct Lnode *next;
}Lnode,*LinkList;

//初始化链表
void init_Lnode(LinkList &L){
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
} 
//存入数据
void save_Lnode(LinkList &L,int n){
	LinkList p = L;
//	init_Lnode(p);
	L->number = 1;
	scanf("%d",&L->code);
	for(int i = 2;i <= n;i++){
		LinkList s;
		init_Lnode(s);
		scanf("%d",&s->code);
		s->number = i;
		p->next = s;
		p = p->next;
	}

} 


//将L链表构成循环
void cir_Lnode(LinkList &L){
	LinkList p = L;
	while(p->next) p = p->next;
	p->next = L;

} 


//删除p所指向的元素（结点）
void delete_Lnode(LinkList &p){
	LinkList p1 = p;
	while(p1->next != p) p1 = p1->next;
	p1->next = p->next;
	LinkList s = p;
	p = p->next;
	free(s);
} 


//在循环链表中指，输出，并删除所指元素，返回密码 
int goal_Lnode(LinkList &p,int goal){
	for(int i = 1;i < goal;i++){
		p = p->next;
	}
	printf("%d ",p->number);
	goal = p->code;
	delete_Lnode(p);
	return goal;
} 


int main(){
	int n,goal;

	scanf("%d%d",&n,&goal);
	LinkList L;	init_Lnode(L);

	LinkList p;// init_Lnode(p);//此指针用来作为箭头 
	p = L; 
	if(n > 0){
		
	save_Lnode(L,n);}
	cir_Lnode(L);//将链表循环化 
	for(int i = 0;i < n;i++){
		goal = goal_Lnode(p,goal);
	}

}

