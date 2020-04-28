#include<iostream>
using namespace std;
int adj[10][10];
int dist[10][10];
int n,i,j,k;
void get_data();
void warshall();
void print();


void get_data()
{
  cout<<"\nEnter the number of vertices: ";
  cin>>n;
  cout<<"\nEnter the adjacency matrix : \n";
  for(i=1;i<=n;i++)
  {
       for(j=1;j<=n;j++)
       {
             cin>>adj[i][j];
       }
  }
}

void warshall()
{

   for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        {
             dist[i][j]=adj[i][j];
        }
   }

  for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


}

void print()
{

  cout<<"\n\nThe distance matrix is: \n\n";
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=n;j++)
      {
          cout<<"\t"<<dist[i][j];
      }
      cout<<"\n";
  }
}


int main()
{

    get_data();
    warshall();
    print();
    return 0;
}
