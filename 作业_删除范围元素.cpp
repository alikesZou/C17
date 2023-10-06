#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -2
#define MAXSIZE 100
typedef double ElemType;

//������ʵ��
//������
typedef struct Lnode{
	ElemType x;//������ 
	struct Lnode* next;//ָ���� 
}Lnode,*LinkList; 

//�����ʼ��
void Init_Lnode(LinkList &L){
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
} 

//��ͷ��ʼ����Ԫ�� 
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
//�ж����Ա�Ϊ��
int Empty_Lnode(LinkList L){
	if(L->next)
		return 0;
	else
		return 1;
} 
//������Ա�L
void Print_Lnode(LinkList L){
	if(Empty_Lnode(L) == 0){
		LinkList p = L->next;
		while(p){
			printf("%lf ",p->x);
			p = p->next;
		}
	}else{
		printf("��"); 
	}
} 

//ɾ��Ԫ��
void Delete_Lnode(LinkList &L,ElemType mink,ElemType maxk){
	LinkList p = L;
	//p��Ϊ����ָ�룬�ӵ�һ��Ԫ�ؿ�ʼ���� 
	while(p->next){
		if(p->next->x > mink && p->next->x < maxk){//���һ��Ԫ����mink��maxk֮�䣬��ɾ�����Ԫ�� 
			LinkList x = p->next;
		 	p->next = p->next->next;//ɾ����� 
		 	free(x);//�ͷ�ɾ���Ľ�� 
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
