#include<stdio.h>
#define MAXSIZE 20
typedef struct {
    int data[MAXSIZE];
    int front, rear;
} QUEUE;
void initq(QUEUE *pq) {
    pq->front = pq->rear = -1;
}
int isempty(QUEUE *pq) {
    return (pq->rear == pq->front);
}
void addq(QUEUE *pq, int n) {
    pq->data[++pq->rear] = n;
}
int removeq(QUEUE *pq) {
    return pq->data[++pq->front];
}
void createmat(int mat[][10], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                mat[i][j]=0;
            }
            else{
                printf("Is there a edges between %d -> %d",i, j);
                scanf("%d",&mat[i][j]);
            }
        }
    }
}
void dismat(int mat[][10],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}
void degree(int mat[][10],int n){
    int i,v,sumin,sumout;
    printf("Vertices\n,Indegree\n,OutDegree\n,TotalDegree");
    for(v=0;v<n;i++){
        sumin=0;
        sumout=0;
        for(i=0;i<n;i++){
            sumin+=mat[i][v];
            sumout+=mat[v][i];
        }
        printf("%d\t, %d\t, %d\t, %d\n",i,sumin,sumout,sumin+sumout);
    }
}
void bfs(int m[][10], int n){
    QUEUE *q;
    int v = 0;
    visited[10] = {0};
    initq(&q);
    addq(&q,v)
    visited[v]=0;
    while(!isempty(&q)){
        v = removeq(&q);
        printf("%d",&v);
        for(int w=0;w<n;w++){
            if(m[v][w]==1 && visited[w]==0){
                addq(&q,w);
                visited[w]=1;
            }
        }
    }
    printf("\n")
}
void recdfs(int m[][10], int n, int v,int visited[10]) {
    printf("%d ", v + 1);
    visited[v] = 1;
    for (int w = 0; w < n; w++) {
        if (m[v][w] == 1 && visited[w] == 0) {
            recdfs(m, n, w, visited);
        }
    }
}
int main(){
    int m[MAX][MAX];
    int n,v,visited[10];
    printf("Enter the number of vertices - ");
    scanf("%d",&n);
    initialize(n,m);
    display(n,m);
    printDegree(n,m);
    bfs(m,n);
    recdfs(m,n,v,visited);
    return 0;
}






