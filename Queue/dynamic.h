#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct{
    NODE *front,*rear; 
}QUEUE;

void initq(QUEUE *q){
    q->front=q->rear=NULL;
}
void addq(QUEUE *q,int num){
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=num;
    newnode->next=NULL;
    if(q->front==NULL){
        q->front=q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
int removeq(QUEUE *q){
    NODE *temp=q->front;
    int num;
    num=temp->data;
    q->front=q->front->next;
    free(temp);
    if(q->front==NULL){
        q->rear=NULL;
    }
    return num;
}
int peek(QUEUE *q){
    return(q->front->data);
}
