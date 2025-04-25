#include <stdio.h>

#define INF -1
#define MAX 10

void createmat(int cost[MAX][MAX], int n){
    int i, j;
    printf("\nEnter the adjacency matrix (use %d for no direct path):\n", INF);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j) {
                cost[i][j] = 0;
            }else{
                printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
                scanf("%d", &cost[i][j]);
            }
        }
    }
}

void dijkstra(int cost[MAX][MAX],int start, int n){
    int i,j,w,count,min,u;
    int visited[MAX];
    int dist[MAX];
    for(i=0;i<n;i++){
        dist[i]=cost[start][i];
    }
    dist[start]=0;
    visited[start]=1;
    count=1;
    while(count<n){
        min=99999999;
        u=-1;
        for(w=0;w<n;w++){
            if(dist[w]!=INF && visited[w]!=1 && dist[w]<min){
                min=dist[w];
                u=w;
            }
        }
        if(u==-1)break;
        visited[u]=1;
        
        for(i=0;i<n;i++){
            if(!visited[i] && cost[u][i]!=INF){
                if(dist[i]==INF || dist[u]+cost[u][i]<dist[i]){
                    dist[i] = dist[u]+cost[u][w];
                }
            }
        }
        count++;
    }
    for(i=0;i<n;i++){
        if(dist[i]==INF){
            printf("vertex %d : unreachable\n",i+1);
        }
        else{
            printf("vertex %d : %d\n",i+1,dist[i]);
        }
    }

}
int main(){
    int cost[MAX][MAX], n, source;

    do{
        printf("Enter the number of vertices (1 to %d): ", MAX);
        scanf("%d", &n);
    }while (n < 1 || n > MAX);

    createmat(cost, n);

    do{
        printf("\nEnter the source vertex (1 to %d): ", n);
        scanf("%d", &source);
    }while (source < 1 || source > n);
    dijkstra(cost, source - 1, n);
    return 0;
}
