// Display Linked List

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

// Creating Linked List using array elements
void create(int A[], int n){
    int i;
    struct Node *next_node, *last;
    first= new Node[sizeof(Node)];
    first->data = A[0];
    first->next=NULL;
    last =first;


    for(i=1;i<n;i++){
        next_node = new Node[sizeof(Node)];
        next_node->data = A[i];
        next_node->next = NULL;
        last->next = next_node;
        last = next_node;
    }
}

// Display all the elements in linked list using iterative loop
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

// Recursion Display
void RDisplay(struct Node *p){
    if(p!=NULL){
        RDisplay(p->next);
        cout<<p->data;
    }
}

// length of linked list using iterative loop
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

// Recursion count
int Rcount(struct Node *p){
    if(p!=NULL)
    return Rcount(p->next)+1;
    else return 0;
}

// Sum of elements of linkedlist using iterative loop
int sum(struct Node* p){
    int sum = 0;
    while(p!=NULL){
        sum = sum+p->data;
        p=p->next;
    }
    return sum;
}

// Recursive sum function
int Rsum(struct Node* p){
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int max(struct Node*p){
    int max = -32756;
    while(p!=NULL){
        if(p->data>max)
        max = p->data;
        p = p->next;
    }
    return max;
}

int Rmax(Node *p){
    int x=0;
    if(p==NULL)
        return -32457;
    x = Rmax(p->next);
    return x>p->data?x:p->data;
}


// Linear Search not binary search why?
// In LL we can only travse nodes sequentially but in binary search we divide at middle of LL.
// To imporve Linear search we have two methods: 1. Transposition 2. Move to Head
// Transposition: interchanging the data between two nodes but we don't prefer in LL's instead we move that node to head
// Move to Head: Moving the node to head position.

Node* search(Node* p, int key){
    while(p!=NULL){
        if(key==p->data)
        return p;
        p=p->next;
    }
    return NULL;
}

// Improve Linear search with Move to head

Node* search_move_to_head(Node *p,int key){
    Node* q=NULL;

    while(p!=NULL){
        
    if(key==p->data){
    
            q->next = p->next;
            p->next = first;
            first = p;
        }
    
    q = p; // q is following p, and p is moving to next.
    p=p->next;
    }
}
Node* Rsearch(Node *p,int key){
    if(p==NULL)
        return NULL;
    while(key==p->data){
        return p;
    }
    return Rsearch(first,3);
}


void insert(Node* p, int position, int value)
{
    if(position<0 || position>count(p)){
    cout<<"Give valid position"<<endl;
    return;}

    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    cout<<newNode;
    if(newNode==NULL)
        cout<<"memory not allcoated for newNode"<<endl;
    
    newNode->data = value;
    
    if(position==0){
        newNode->next = first;
        first=newNode;
        cout<<"Inserted at position 0"<<endl;
    }
    else{
        for(int i=0;i<position-1;i++)
        {
          p=p->next;  
        }
        newNode->next = p->next;
        p->next = newNode;
    }
}

void insert_in_sorted_LL(Node *p,int value){
    Node *nn = new Node;

    while(p){
         if(p->data<value){
            if(p->next!=NULL){
                if(p->next->data<value){
                p=p->next;}
                else break;
            }
            else break;
         }
    }
    nn->data = value;
    nn->next = p->next;
    p->next = nn;
}

int delete_LL(Node*p,int index){
    Node *temp, *q;
    int rv;
    if(index==0){
        rv = first->data;
        first = p->next;
        delete p;
        return rv;
    }
    else{
        for(int i=1;i<=index;i++){
            q=p;
            p=p->next;
        }
        rv = p->data;
        q->next = p->next;
        delete p;
        return rv;
    }
}

// void check_sorted(Node *p){
//     while(p->next!=NULL){
//         if
//     }
// }
int main(){
    int A[] = {3,4,6};
    create(A,3);

    // cout<<"Length of the LL: "<<Rcount(first)<<endl;
    // cout<<"Sum of data in LL: "<<Rsum(first)<<endl;
    // cout<<"Maximum value of the LL: "<<Rmax(first)<<endl;
    // cout<<"Address of 10 in LL: "<<Rsearch(first,10)<<endl;
    //insert(first,0,13);
    int v;
    //insert_in_sorted_LL(first,10);
    v = delete_LL(first,2);
    cout<<"Deleted value:"<<v<<endl;
    Display(first);
} 