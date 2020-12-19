#define MAX 10
#define INFINITY 9999

void Dijkstra(int G[MAX][MAX],int n,int startnode, char locations[][20])
{

	int cost[MAX][MAX] ;      //cost between vertexes
    int pred[n] ;             //stores the predecessor of each node
    int distance[n] ;         //distance[i] will hold the shortest distance from starting node to i
    int visited[n] ;          //hold 1 if vertex i is included in shortest path
    int count ;               //gives the number of nodes visited
    int i,j,k,mindistance,nextnode ;

	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];  // storing the cost of vertices from source
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++){
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
        visited[nextnode]=1;
        for(i=0;i<n;i++){       // performs relaxation( check if a better path exists through next node )
            if(!visited[i]){
                if(mindistance+cost[nextnode][i]<distance[i]){
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %s = %d",locations[i],distance[i]);
			printf("\nPath= %s",locations[i]);

			j=i;
			do
			{
				j=pred[j];
				printf(" <- %s",locations[j]);
			}while(j!=startnode);
	    }
}
