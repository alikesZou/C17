#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//�����㣬����Ϊ��ź����� 
typedef struct Lnode{
	ElemType code;//��¼���� 
	int number;//��¼��� 
	struct Lnode *next;
}Lnode,*LinkList;

//��ʼ������
void init_Lnode(LinkList &L){
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
} 
//��������
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


//��L������ѭ��
void cir_Lnode(LinkList &L){
	LinkList p = L;
	while(p->next) p = p->next;
	p->next = L;

} 


//ɾ��p��ָ���Ԫ�أ���㣩
void delete_Lnode(LinkList &p){
	LinkList p1 = p;
	while(p1->next != p) p1 = p1->next;
	p1->next = p->next;
	LinkList s = p;
	p = p->next;
	free(s);
} 


//��ѭ��������ָ���������ɾ����ָԪ�أ��������� 
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

	LinkList p;// init_Lnode(p);//��ָ��������Ϊ��ͷ 
	p = L; 
	if(n > 0){
		
	save_Lnode(L,n);}
	cir_Lnode(L);//������ѭ���� 
	for(int i = 0;i < n;i++){
		goal = goal_Lnode(p,goal);
	}

}

