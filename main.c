#include <stdio.h>
#include <stdlib.h>

int find_min_vertex(int distance[],int visited[],int n)     // finding min vertex
{
    int min_vertex =-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 &&(min_vertex==-1 || distance[i]<distance[min_vertex]))
        {
            min_vertex=i;
        }
    }
    return min_vertex;
}


int main()
{
    printf("--------------------------------WELCOME TO DIJKSTRA ALGORITHM---------------------------------\n");
    int n,e;
    printf("Vertex size and edge size of the graph\n");
    scanf("%d%d",&n,&e);

    int edges[n][n]; // initializing all the edges to be zero

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    printf("consider your vertex to be 0,1,2....(If it is in A,B,C,D....) change it respectively\n");
    for(int i=0;i<e;i++)
    {
        printf("Value of f,s,weight\n");
        int f,s,weight;
        scanf("%d%d%d",&f,&s,&weight);
        edges[f][s] = weight;               // adjacency matrix of the edges this will connect all the vertex
        edges[s][f] = weight;               // their given weight.
    }

    int distance[n];
    int visited[n];

    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;          // Initializing distance and visited array as infinite and zero respectively.
        visited[i] = 0 ;
    }
    printf("Enter the valid starting vertex\n");
    int s;
    scanf("%d",&s);
    distance[s]=0;

    for(int i=0;i<n-1;i++)
    {
        int min_vertex = find_min_vertex(distance,visited,n); // for finding the min_vertex
        visited[min_vertex] = 1;
        for(int j=0;j<n;j++)
        {
            if(edges[min_vertex][j]!=0 && visited[j]==0)
            {
                int dist = distance[min_vertex] + edges[min_vertex][j];
                if(dist<distance[j])
                {
                    distance[j]=dist;   // updating the new distance
                }
            }
        }
    }

    for(int i=0;i<n;i++)        // printing the distance with their weight
    {
        printf("Distance from %d to %d is %d \n",s,i,distance[i]);
    }
    printf("------------------------------------------THANK YOU-----------------------------------------------");
}
