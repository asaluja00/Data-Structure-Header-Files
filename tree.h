//
//  tree.h
//  Linkedlist
//
//  Created by Anmol Saluja on 17/04/22.
//

#ifndef trees_h
#define trees_h

#endif /* trees_h */
#include<iostream>
using namespace std;
struct tree{
    int data;
    struct tree * lchild , * rchild;
};
struct queue{
    struct tree * data;
    struct queue * link;
}*top=NULL;
struct stack{
    struct tree * data;
    struct stack * link;
}*start=NULL;
//Functions Declarations
struct tree * create();//1
//Functions For queue
struct queue * enqueue(struct queue * top , struct tree * p);//2
struct tree * dequeue( struct queue * t);//3
bool isemptyqueue(struct queue * t);//4
//Functions for Stack
bool isemptystack(struct stack * front);//5
void push(struct tree * a);//6
struct tree * pop();//7
// Functions For Tree Traversal
void preorder (struct tree * t);//8
void leverorder(struct tree* t);//9
void inorder(struct tree *t);//10
void postorder(struct tree *t);//11

//Functions Definations

struct tree * create(){
    struct tree * t=new(tree),*p;
    cout<<"Enter Node Value";
    int data;
    cin>>data;
    t->data=data;
    t->rchild=0;
    t->lchild=0;
    top=enqueue(top,t);
    while(!isemptyqueue(top)){
        p=dequeue(top);
        cout<<"Enter Left Child "<<p->data<<"\n";
        cin>>data;
        if(data!=-1){
            struct tree  *k= new (tree);
            k->data=data;
            k->rchild=0;
            k->lchild=0;
            p->lchild=k;
            top=enqueue(top, k);
        }
        cout<<"Enter Right Child "<<p->data<<"\n";
        cin>>data;
        if(data!=-1){
            struct tree  *k= new (tree);
            k->data=data;
            k->rchild=0;
            k->lchild=0;
            p->rchild=k;
            top=enqueue(top, k);
        }
    }
    return t;
}//1
//Functions For queue

struct queue * enqueue(struct queue * top , struct tree * p){
    struct queue * temp = new (queue);
    temp->data=p;
    temp->link=NULL;
    if(top==NULL){
        top=temp;
    }
    else if(top->link==NULL){
        top->link=temp;
    }
    else{
        struct queue * k=top;
        while(k->link!=NULL){
            k=k->link;
        }
        temp->data=p;
        temp->link=NULL;
        k->link=temp;
    }
    return top;
}//2
struct tree * dequeue( struct queue * t){
    if(t!=NULL){
        struct tree *k=t->data;
        struct  queue *temp=top;
        delete(temp);
        top=top->link;
        return k;
    }
    return 0;
}//3
bool isemptyqueue(struct queue *t){
    if(t==NULL){
        return true;
    }
    else{
        return false;
    }
}//4

//Stack Functions

bool isemptystack ( struct stack * front){
    if(front ==NULL){
        return true;
    }
    else{
        return false;
    }
}//5
void  push(struct tree *a){
    struct stack * temp=new(stack);
    struct stack * ptr=start;
    temp->data=a;
    if(start==NULL){
        start=temp;
        start->link=NULL;
    }
    else if(start->link==NULL){
        start->link=temp;
        temp->link=NULL;
    }
    else{
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
        temp->link=NULL;
    }
}//6
struct tree * pop(){
    struct stack * ptr= start,*ptr2=ptr->link;
    while(ptr2->link!=NULL){
        ptr=ptr2;
        ptr2=ptr2->link;
    }
    ptr->link=NULL;
    struct tree * temp=ptr->data;
    free(ptr2);
    return temp;
}//7

// Functions for Tree Traversals
void preorder(struct tree *t){
    if(t!=NULL){
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
  
    }
}//8
void postorder(struct tree *t){
    if(t!=NULL){
        preorder(t->lchild);
        preorder(t->rchild);
        cout<<t->data<<" ";
    }
}//9
void levelorder(struct tree * t){
    if(t==NULL){
        cout<<"Empty Tree\n";
    }
    else{
        cout<<t->data<<" ";
        top=enqueue(top, t);
        while(!isemptyqueue(top)){
            struct tree * p=dequeue(top);
            if(p->lchild!=NULL){
                cout<<p->lchild->data<<" ";
                top=enqueue(top,p->lchild);
            }
            if(p->rchild!=NULL){
                cout<<p->rchild->data<<" ";
                top=enqueue(top,p->rchild);
            }
        }
    }
}//10
void inorder(struct tree * t){
    if(t!=NULL){
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}//11



