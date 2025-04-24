#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
  int vertex;
  struct NODE *next;
}NODE;

NODE *list[10];

void adjmat(int mat[][10], int n){
    NODE *temp, *newnode;
    int i,j;
    for(i=0;i<n;i++){
        list[i]=0
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][v]==1){ 
                newnode=(NODE)malloc(sizeof(NODE));
                newnode->next=NULL;
                newnode->vertex=j+1
            }

            if(list[i]==NULL){
                list[i]=newnode;
            }
            temp=list[i]
            else{
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newnode;
            }

        }
    }
}
void display(int n){
    NODE *temp;
    int i;
    printf("The Adjacent list is = ");
    for(i=0;i<n;i++){
        printf("vertices %d ->",i+1);
        temp=list[i];
        while(temp->next!=NULL){
            printf("%d",temp->vertex);
            temp=temp->next;
        }
    }
}
void degree(int mat[][10], int n){
    int indegree[10]={0}, outdegree[10]={0};
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]==1){
                indegree[i]++;
                outdegree[j]++;
            }
        }
    }
    printf("\n\nVERTEX INDEGREE OUTDEGREE TOTAL DEGREE\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",i+1,indeg[i],outdeg[i],indeg[i]+outdeg[i]);
    }
}
int main(){
    int m[10][10],n,i,j;
    printf("Enter the number of vertices - ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
        m[i][j]=0;
        if(i!=j){
            printf("Is there an edge between %d->%d (1/0)? ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    adjmat(m, n);
    display(n);
    degree(m, n);
}