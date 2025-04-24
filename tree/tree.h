#define MAX 5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    struct node *left;
    int info;
    struct node *right;
}NODE;
typedef struct{
    NODE *data[MAX];
    int front, rear;
}QUEUE;

void init(QUEUE *q){
    q->front = q->rear = -1;
}
void enqueue(QUEUE *q, NODE *treenode){
    q->data[++q->rear]=treenode;
}
NODE *dequeue(QUEUE *q){
    return (q->data[++q->front]);
}
int isEmpty(QUEUE *q){
    return (q->front==q->rear);
}
int isFull(QUEUE *q){
    return (q->rear == MAX -1);
}
NODE *createbst(NODE *root){
    NODE *newnode, *temp, *parent;
    int i, n, num;
    printf("How many nodes ? - ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode = (NODE*)malloc(sizeof(NODE));
        printf("Enter the node value: ");
        scanf("%d",&num);
        newnode->info=num;
        newnode->left=newnode->right=NULL;
        if(root==NULL){
            root=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL){
            parent=temp;
            if(num<temp->info){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        if(num<parent->info){
            parent->left=newnode;
        }
        else{
            parent->right=newnode;
        }

    }
    return root;
}

void preorder(NODE *root){
    NODE *temp=root;
    if(temp!=NULL){
        printf("%d ",temp->info);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(NODE *root){
    NODE *temp=root;
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d ",temp->info);
        inorder(temp->right);
    }
}
void postorder(NODE *root){
    NODE *temp=root;
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->info);
    }
}
void levelorder(NODE *root){
    int level = 0;
    NODE *temp, *marker = NULL;
    QUEUE q;
    init(&q);
    enqueue(&q,root);
    enqueue(&q,marker);
    printf("\nLevel %d --->", level);
    while(!isEmpty(&q)){
        if(temp==marker){
            if(!isEmpty(&q)){
                level++;
                enqueue(&q,marker);
                printf("\nLevel %d --->", level);
            }
        }
        else{
            printf("%d\t",temp->info);
            if(temp->left)
                enqueue(&q,temp->left);
            if(temp->right)
                enqueue(&q, temp->right);
        }
    }
}
NODE *search(NODE *root,int key){
NODE *temp=root;
while(temp!=NULL){
    if(key==temp->info)
        return temp;
    if(key<temp->info)
        temp=temp->left;
    else
        temp=temp->right;
    }
    return NULL;
}
int countnodes(NODE *root){
static int count =0;
NODE *temp=root;
if(temp!=NULL){
    count++;
    countnodes(temp->left);
    countnodes(temp->right);
}
return count;
}
int countleaf(NODE *root){
    static int leaf=0;
    NODE *temp=root;
    if(temp!=NULL){
        if((temp->left==NULL)&&(temp->right==NULL)){
            leaf++;
        }
        countleaf(temp->left);
        countleaf(temp->right);
    }
    return leaf;
}




