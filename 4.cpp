#include<iostream>
using namespace std;

int i;

class Node
{
public:
    int v;
    string city[10];
    int adj[10][10];

    void create();
    void display();
    void mst();
}e;

void Node::create()
{
    cout<<"Enter the number of cities you want to enter:";
    cin>>v;
    
    cout<<"Enter the names of "<<v<<" cities:";
    for(int i=0;i<v;i++)
    {
        cout<<"\nEnter the city "<<i+1<<"'s name:";
        cin>>city[i];
    }
    
    cout<<"\nEnter the fuel required to travel one city to another:";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
            }
            else if(j>i)
            {
                cout<<"\nEnter fuel required to travel from "<<city[i]<<" to "<<city[j]<<" : ";
				cin>>adj[i][j];
            }
            else
            {
                adj[i][j] = adj[j][i];
            }
        }
    }
}

void Node::display()
{
    for(int i=0;i<v;i++)
    {
        cout<<"\t"<<city[i];
    }
    cout<<"\n";
    
    for(int i=0;i<v;i++)
	{
		cout<<city[i];
		for(int j=0;j<v;j++)
		{
			cout<<"\t"<<adj[i][j];
		
		}
		cout<<"\n";
	}
}

void Node::mst()
{
    int min,u;
    int key[100];
    int parent[100];
    bool visited[100];

    for(i=0;i<v;i++)
    {
        key[i] = 999;
        visited[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int e=0;e<v-1;e++)
    {
        min = 999;
        for(int i=0;i<v;i++)
        {
            if(!visited[i] && min>key[i])
            {
                min = key[i];
                u = i;
            }
        }
        visited[u] = true;

        for(int j=0;j<v;j++)
        {
            if (adj[u][j] && !visited[j] && adj[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = adj[u][j];
            }
        }
    }

    cout << "\nMinimum Spanning Tree is :\n";
   
    for (i=1;i<v;i++)
    {
        cout <<city[parent[i]]<<"\t\t"<<adj[i][parent[i]]<<"\t"<<city[i]<<endl;
    }
}

int main()
{
	int ch;
	do{
		cout<<"\nMain MENU \n"<<endl;
		cout<<"1.Create\n2.Display\n3.Find Minimum Spanning Tree.";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
                    e.create();
			        break;
			case 2:
                    e.display();
			        break;
			case 3:
                    e.mst();
			        break;
		}
	}while(ch!=0);
return 0;
}