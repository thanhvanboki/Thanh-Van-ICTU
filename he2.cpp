#include<iostream>
using namespace std;
//===============================STACK====================================
struct node{
	int data;
	struct node *pNext;
};
typedef struct node Node;

struct stack{
	Node *pTop;
	int count;
};
typedef struct stack Stack;

void khoiTao(Stack &s){
	s.pTop=NULL;
}
bool isEmpty(Stack s){
	if(s.pTop==NULL){
		return 1;
	}
	return 0;
}
Node *tao(int x){
	Node *p=new Node;
	if(p==NULL){
		return NULL;
	}
	else {
		p->data=x;
		p->pNext=NULL;
	}
}
void push(Stack &s,int x){
	Node *p=new Node;
	p=tao(x);
	if(isEmpty(s)==1){
		s.pTop=p;
	}
	else{
		p->pNext=s.pTop;
		s.pTop=p;
	}
	
}
void pop(Stack &s,int x){
	x=s.pTop->data;
	Node *i=s.pTop;
	s.pTop=s.pTop->pNext;
	delete i;
	
}
void chuyenhe(Stack &s,int coSo,int thapPhan){
	if(thapPhan!=0){
		int x=thapPhan%coSo;
		push(s,x);
		thapPhan/=coSo;
		chuyenhe(s,coSo,thapPhan);
	}
}
void xuat(Stack s){
	if(s.pTop!=NULL){
		cout<<s.pTop->data;
		s.pTop=s.pTop->pNext;
		xuat(s);
	}
}
void xoaBatki(Stack &s){
	int vitri;
	cout<<"\n nhap vitri :";
	cin>>vitri;
	
	
		Stack s1;
		khoiTao(s1);
	
		int tam=0;
		for(Node *i=s.pTop;i!=NULL;i=i->pNext){
			tam++;
			if(tam==vitri){
				int x;
				pop(s,x);	
			}
			else{
				push(s1,i->data);
				
			}
		}
		khoiTao(s);
		
		for(Node *j=s1.pTop;j!=NULL;j=j->pNext){
			push(s,j->data);
		}
		khoiTao(s1);
	
}
int main(){
	Stack s;
	khoiTao(s);
	chuyenhe(s,2,64);
//	push(s,1);
//	push(s,2);
//	push(s,3);
//	push(s,4);
//	push(s,5);
//	xoaBatki(s);
	xuat(s);
	
}














