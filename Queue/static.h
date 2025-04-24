#include<stdio.h>
#define MAXSIZE 5
typedef struct{
  int items[MAXSIZE];
  int front, rear;
}Queue;

void initQ(Queue *q){
  q->front=q->rear=-1;
}

void enqueue(Queue *q, int num){
  q->items[++q->rear]=num;
  printf("Enqueued - %d",num);
}

int  dequeue(Queue *q){
  return q->items[++q->front]; 
}

int isfull(Queue *q){
  return q->rear==MAXSIZE -1;
}

int isempty(Queue *q){
  return q->front==q->rear;
}

void display(Queue *q){
  int i;
  for(i=q->front+1;i<=q->rear;i++){
    printf("%d\t",q->items[i]);
  }
}

int peek(Queue *q){
  return q->items[q->front+1];
}