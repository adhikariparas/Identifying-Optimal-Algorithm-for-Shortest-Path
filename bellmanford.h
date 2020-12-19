#define MAX 10
#define INFINITY 9999

void Bellman_Ford(int G[MAX][MAX] , int V, int E, int edge[20][2],int  startnode,char locations[][20])
{
    int i,j,u,v,k,distance[20],parent[20],S= startnode,flag=1;

    for(i=0;i<V;i++){
        distance[i] = INFINITY ;
        parent[i] = -1 ;
    }

    distance[S]=0 ;

    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] ;
            v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v]){
                distance[v] = distance[u] + G[u][v] ;
                parent[v]=u ;
            }
        }
    }

    for(k=0;k<E;k++){
        u = edge[k][0] ;
        v = edge[k][1] ;
        if(distance[u]+G[u][v] < distance[v])
        flag = 0 ;
    }

    if(flag){
        for(i=0;i<V;i++){
            if(i!=S){
                printf("\nDistance of %s = %d",locations[i],distance[i]);
			    printf("\nPath= %s",locations[i]);

		     	j=i;
			    do{
				j=parent[j];
				printf(" <- %s",locations[j]);
			    }while(j!=S);
	        }
        }
    }
}
