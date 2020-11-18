#include <stdio.h> 
#include <limits.h> 
 
int V;


void dijkstra(int graph[V+1][V+1], int src) 
{ 
    int cost[V+1][V+1],dist[V+1],visited[V+1],parent[V+1]; 
    int i, j, count, mindist, nextnode;
    for (i = 1; i <= V; i++) 
    { 
      for(j = 1; j <= V; j++)
      {
          if(graph[i][j] == 0)
          {
              cost[i][j] = 999;
          }
          else
          {
              cost[i][j] = graph[i][j];
          }
      }
    }
    
      for(i = 1; i <= V; i++)
      {
          dist[i] = cost[src][i];
          parent[i] = src;
          visited[i] = 0;
      }
      
      dist[src] = 0;
      visited[src] = 1;
      count = 1;
      
      while(count < V)
      {
          mindist = 999;
          for(i = 1; i <= V; i++)
          {
              if((dist[i] < mindist) && !visited[i])
              {
                  mindist = dist[i];
                  nextnode = i;
              }
          }
          visited[nextnode] = 1;
          for(i = 1; i <= V; i++)
          {
              if(!visited[i])
              {
                  if( ( mindist + cost[nextnode][i] ) < dist[i])
                  {
                      dist[i] = mindist + cost[nextnode][i];
                      parent[i] = nextnode;
                  }
              }
          }
          count++;
      }
      for(i = 1; i <= V; i++)
      {
          if(i != src)
          {
              printf("Distance from %d to %d is %d\n",src,i,dist[i]);
              int *printer=(int *)malloc(sizeof(int)*V);
              j = i;
              int temp=0;
              do
              {
                  j = parent[j];
                  printer[temp++]=j;
              }while(j != src);
          while(temp>0)
          {
              printf("%d->",printer[--temp]);
          }
          printf("%d\n",i);
          }
          else
          {
              printf("Distance from %d to %d is 0\n%d\n",src,src,src);
          }
      }
} 



int main()
{
    scanf("%d",&V);
    int adjmat[V+1][V+1],i,j,src;
    for(i=1;i<=V;i++)
    {
        for(j=1;j<=V;j++)
        {
            scanf("%d",&adjmat[i][j]);
        }
    }
    scanf("%d",&src);
    dijkstra(adjmat,src);
}