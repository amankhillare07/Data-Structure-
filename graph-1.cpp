#include<iostream>
using namespace std;

int i,j,v;

class Node
{
public:
	int fuel;
	string Cityname[20];
	int adj[100][100];
	
	void accept();
	void display();
	
	Node *next;
	string City;
	
	void create();
	void add();
	void displayAL();
}*head[10],li;

void Node::accept()
{
	cout<<"Enter the number of cities you want to enter:";
    	cin>>v;
    
    	cout<<"Enter the names of "<<v<<" cities:";
    	for(int i=0;i<v;i++)
    	{
    		cout<<"\nEnter the city "<<i+1<<"'s name:";
		cin>>Cityname[i];
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
                		cout<<"\nEnter fuel required to travel from "<<Cityname[i]<<" to "<<Cityname[j]<<" : ";
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
		cout<<"\t"<<Cityname[i];
	}
	cout<<"\n";
    
	for(int i=0;i<v;i++)
	{
		cout<<Cityname[i];
		for(int j=0;j<v;j++)
		{
			cout<<"\t"<<adj[i][j];		
		}
		cout<<"\n";
	}
}

void Node::create()
{
	cout<<"Enter the number of cities you want to enter:";
	cin>>v;
    
	cout<<"\nEnter the names of "<<v<<" cities:";
	for(int i=0;i<v;i++)
	{
		head[i] = new Node;
        
		cout<<"\nEnter the city "<<i+1<<"'s name:";
		cin>>head[i]->City;
		head[i]->next == NULL;
	}
}

void Node::add()
{
	int e;
	string s,d;
	Node *temp,*n1,*n2,*temp1;

	cout<<"Enter the total no of edges:";
	cin>>e;

	for(i=0;i<e;i++)
	{
		cout<<"Enter the source city:";
		cin>>s;
		cout<<"Enter the destination city:";
		cin>>d;

		for(j=0;j<v;j++)
		{
			if(s == head[j]->City)
			{
				break;
			}
		}

		n1 = new Node;
		n1->City = d;
		cout<<"Enter the fuel required:";
		cin>>n1->fuel;
		n1->next = NULL;

		temp = head[j];
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n1;
	
		
		for(j=0;j<v;j++)
		{
			if(d == head[j]->City)
			{
				break;
			}
		}

		n2 = new Node;
		n2->City = s;
		n2->fuel = n1->fuel;
		n2->next = NULL;

		temp1 = head[j];
		while(temp1->next != NULL)
		{
			temp1 = temp->next;
		}
		temp1->next = n2;
	}
}

void Node::displayAL()
{
	Node *temp;

	for(int i=0;i<v;i++)
	{
		temp = head[i];

		while(temp != NULL)
		{
			cout<<temp->fuel<<" -> "<<temp->City<<" -> ";
			temp = temp->next;
		}
		cout<<"NULL\n";
	}
}

int main()
{
	int ch;
	
	do{
		cout<<"\nMain MENU \n"<<endl;
		cout<<"1.Acccept\n2.Display\n3.Create\n4.Add Edge\n5.Display AL\n6.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				li.accept();
				break;
			case 2:
				li.display();
				break;
			case 3:
				li.create();
				break;
			case 4:
				li.add();
				break;
			case 5: 
				li.displayAL();
				break;
		}
	}while(ch!=0);

	return 0;
}
