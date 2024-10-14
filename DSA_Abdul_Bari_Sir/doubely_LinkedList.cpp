#include<iostream>
using namespace std;

struct Node{
	Node* prev;
	int data;
	Node *next;
};

Node *first = NULL;

void create_doubley_LL(int A[],int size){
	Node *nn = new Node;
	Node*temp;
	
	nn->data = A[0];
	nn->prev = NULL;
	nn->next = NULL;
	first = temp = nn;
	
	for(int i=1;i<size;i++){
		Node *nn = new Node;
		nn->prev= temp;
		nn->next = temp->next;
		nn->data = A[i];
		temp->next=nn;
		temp=nn;
		
	} 
	 	
}


void Display(Node *p){
	cout<<"Data in LL:"<<endl;
	while(p!=NULL){
		cout<<p->data<<endl;
		p = p->next;
	}
}

int Length(Node *p){
	int len=0;
	while(p){
		len++;
		p=p->next;
	}
	return len;
}

void insert_DLL(Node*p,int value, int index)
{	Node* nn = new Node;
	
	if(index<0 || index>Length(p))
	{
		cout<<"Index is not valid!"<<endl;
		return;
	}
	if(index==0){
		nn->prev = NULL;
		nn->data = value;
		nn->next = first;
		first->prev = nn;
		first = nn;
	}
	else{
	
	for(int i=0;i<index-1;i++){
		p=p->next;
	}
	nn->prev = p;
	nn->data = value;
	nn->next = p->next;
	if(p->next)
	p->next->prev=nn;
	p->next=nn;
}
}

int main(){
	int A[] = {1,2,3};
	int l;
	create_doubley_LL(A,3);
	insert_DLL(first,4,3);
	l = Length(first);
	cout<<"length of LL: "<<l<<endl;
	Display(first);
}
