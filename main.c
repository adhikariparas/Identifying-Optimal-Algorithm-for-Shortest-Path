#include <stdio.h>
#include <time.h>
#include "dijkstra.h"
#include "bellmanford.h"
#include "floydwarshall.h"


int main(){
 clock_t t1,t2,t3;
 int i,j,n,k=0 ;

 printf("Enter the number of locations: ") ;
 scanf("%d",&n) ;

 if(n>2){

 char locations[n][20] ;               // stores the names of locations
 printf("Enter Locations name-\n") ;
 for(i=0; i<n; i++)
    scanf("%s",&locations[i]) ;

 // Initialize the adjacency matrix
 int G[MAX][MAX] ;
 for(i = 0; i<n; i++){
    for(j = 0; j<n ; j++){
            if(i!=j && i<j){
                printf("Enter distance between %s and %s: \n",locations[i],locations[j]) ;
                scanf("%d",&G[i][j])  ;
            }
            else if(i == j)
                G[i][j] = 0 ;
            else if(i>j)
                G[i][j] = G[j][i] ;
            else
                G[i][j] = 0 ;
    }
 }

 // initialize edges for (required in Bellman-Ford Algorithm)
 int edge[20][2] ;
 for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
                if(G[i][j]!=0){
                edge[k][0]=i   ;
                edge[k++][1]=j ;
               }
        }
 }

 //print the adjacency matrix
 printf("\n") ;
 for(i=0; i<n; i++){
    for(j=0; j<n; j++){
        printf("%d ",G[i][j]) ;
    }
    printf("\n") ;
 }

 //Running the Dijkstra's Algorithm as all pair
 printf("\n//////////Running Dijkstra's Algorithm//////////\n") ;
 t1=clock() ;
 for(i=0; i<n; i++){
        printf("\nFrom city : %s",locations[i]);
        Dijkstra(G,n,i,locations);
        printf("\n\n") ;
	}
 t1=clock()-t1 ;

 printf("-----------------------------------------------------") ;

 //Running the Bellman-Ford Algorithm as all pair
 printf("\n\n//////////Running Bellman-Ford Algorithm//////////\n") ;
 t2=clock() ;
 for(i=0; i<n; i++){
        printf("\nFrom city : %s",locations[i]);
        Bellman_Ford(G,n,k,edge,i,locations);
        printf("\n\n") ;
	}
 t2=clock()-t2 ;

 printf("-----------------------------------------------------") ;
 //Running Floyd-Warshall Algorithm
 printf("\n\n//////////Running Floyd-Warshall Algorithm//////////\n") ;
 t3=clock() ;
 floydWarshall(G,n,locations) ;
 t3=clock()-t3 ;

 printf("\n-------------------------------------------------------") ;
 //Computing the time for Dijkstra's Algorithm
 double time_taken_dijkstra = ((double)t1)/CLOCKS_PER_SEC;
 printf("\nDijkstra's Algorithm took %f seconds to execute ", time_taken_dijkstra);

 //Computing the time for Bellman-Ford Algorithm
 double time_taken_bellman = ((double)t2)/CLOCKS_PER_SEC;
 printf("\nBellman-Ford Algorithm took %f seconds to execute", time_taken_bellman);

 //Computing the time for Floyd Warshall Algorithm
 double time_taken_floyd = ((double)t3)/CLOCKS_PER_SEC;
 printf("\nFloyd Warshall Algorithm took %f seconds to execute ", time_taken_floyd);

 printf("\n--------------------------------------------------------") ;
 if(time_taken_dijkstra < time_taken_bellman && time_taken_dijkstra < time_taken_floyd)
    printf("\nDijkstra's Algorithm consume minimum time") ;
 else if(time_taken_bellman < time_taken_dijkstra && time_taken_bellman < time_taken_floyd)
    printf("\nBellman-Ford Algorithm consume minimum time") ;
 else
    printf("\nFloyd-Warshall Algorithm consume minimum time") ;
 printf("\n--------------------------------------------------------") ;

 }else{
  printf("Number of vertexes should at least be two.") ;
 }

 return 0;

}


