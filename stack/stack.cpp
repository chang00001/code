// stack.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <malloc.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node	 * pnext;
}Node, *pNode;
typedef struct stack
{
	pNode pTop;
	pNode Pbottom;

}stack,* pStack;
void intlist(pStack);
void push(pStack,int);
void show(pStack);
bool pop(pStack, int *);
void clear(pStack);
int main()
{
	stack s;
	int val;
	pStack ps;
	ps = &s;
	intlist(ps);
	
	push(ps, 1);
	push(ps, 2);
	push(ps, 3);
	push(ps, 4);
	show(ps);
	pop(ps, &val);
	show(ps);
	printf("val的值是%d", val);
	clear(ps);
	show(ps);
	return 0;
}
void  intlist(pStack s) {
	s->Pbottom= (pNode)malloc(sizeof(node));
	if (s->Pbottom== NULL)
	{
		printf("内存分配失败！");
		exit(-1);
	}
	s->pTop = s->Pbottom;
	s->pTop->pnext = NULL;
	
}
void push(pStack s,int val) {
	pNode pNew = (pNode)malloc(sizeof(Node));
	pNew->data = val;
	pNew->pnext =s->pTop;
	s->pTop = pNew;


}
void show(pStack ps){
	pNode p = ps->pTop;
	while (p!=ps->Pbottom)
	{
		printf("%d \n", p->data);
		p = p->pnext;
	}

}
bool pop(pStack ps, int * pval) {
	if (ps->pTop == ps->Pbottom) {
		return false;
	}
	pNode p = ps->pTop;
	ps->pTop = ps->pTop->pnext;
	*pval = p->data;
	free(p);
	return true;
}
void clear(pStack ps) {
	pNode p = ps->pTop;
    while(p!=ps->Pbottom){
		//p = ps->pTop;
		ps->pTop = ps->pTop->pnext;

		free(p);
		p = ps->pTop;
	}
	
}



