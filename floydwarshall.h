#define MAX 10
#define INFINITY 9999

void floydWarshall (int G[][],int n, char locations[][20])
{
    /*
      dist[][] will be the output matrix that will finally have the shortest
      distances between every pair of vertices
    */
    int dist[MAX][MAX], i, j, k,m,startnode;
    int p[n][n],d[n],pred[n] ;             //stores the predecessor of each node
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
                p[i][j] = i ;
        }
     }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = G[i][j];

    for (k = 0; k < n; k++){
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n; j++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[k][j] ;
                }
            }
        }
    }

    for(m=0; m<n; m++){
        startnode =  m ;
        for(k=0; k<n; k++){
            d[k] = dist[m][k] ;
            pred[k] = p[m][k] ;
        }
        printf("\nFrom city : %s",locations[m]) ;
        for(i=0;i<n;i++)
            if(i!=startnode)
		   {
			printf("\nDistance of %s = %d",locations[i],d[i]);
			printf("\nPath= %s",locations[i]);

			j=i;
			do
			{
				j=pred[j];
				printf(" <- %s",locations[j]);
			}while(j!=startnode);
	       }
         printf("\n")  ;
    }
}
