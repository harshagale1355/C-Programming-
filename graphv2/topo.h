#include<stdio.h>
#define MAXSIZE 20
typedef struct {
int data[MAXSIZE];
int top;
} STACK;
void pushs(STACK *ps, int n) {
ps->data[++ps->top] = n;
}
int pops(STACK *ps) {
return ps->data[ps->top--];
}
void inits(STACK *ps) {
ps->top = -1;
}
int isemptys(STACK *ps) {
return (ps->top == -1);
}
void createmat(int m[][10],int n){
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                m[i][j] = 0; // No self-loops
            else {
            printf("Is there an edge between %d -> %d (1/0): ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
            }
        }
    }
}
void dispmat(int m[][10],int n){
    int i,j;
    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}
void topo(int m[MAXSIZE][MAXSIZE], int n){
    int visited[20] = {0};
    int i,j,v,w,count=0;
    int indeg[10] = {0};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            indeg[i]+=m[j][i];
        }
    }
    STACK s;
    inits(&s);
    for(v=0;v<n;v++){
        if(indeg[v]==0){
            pushs(&s,v);
            visited[v]=1;
        }
    }
    while(!isemptys(&s)){
        v = pops(&s);
        printf("v%d",v+1);
        count++;
        for(w=0;w<n;w++){
            if(m[v][w]==1){
                indeg[w]--;
                if(indeg[w]==0 && visited[w]==0){
                    pushs(&s,w);
                    visited[w]=1;
                }
            }
        }
    }
    if(count!=n){
        printf("\nGraph has a cycle! Topological sorting not possible.\n");
    }
}
void main(){
    int m[MAXSIZE][MAXSIZE];
    int i,j, n;
    printf("How many vertices: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
        m[i][j]=0;
        if(i!=j){
      printf("Is there an edge between %d->%d (1/0)? ",i+1,j+1);
      scanf("%d",&m[i][j]);
        }
      }
  
    topo(m,n);
    printf("\n");
}
    
    