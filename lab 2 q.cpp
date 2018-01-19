#include <iostream>
using namespace std;
struct node //structure that has variable for data and a pointer for next
{
	int value;
	node *next;
};
class linkedlist //class containing functions that operate on nodes
{
	private:
	 node *head; //two nodes are created called head and tail
	 node *tail;
	public: 
	 linkedlist() //a constructer that will make value of the pointers null
	 {
	 	head=NULL; 
	 	tail=NULL;
	 }
    void insert(int data) //function to insert a node at the end of a linked list
    {
    	node *temp=new node;
    	temp->value=data;
    	temp->next=NULL;
    	if(head==NULL)
    	{
    		head=temp;
    		tail=temp;
    	}
    	else
    	{
    		tail->next=temp;
    		tail=temp;
    	}
    }
    void insertAt(int pos, int data) //function to insert a node at a given position
    {
    	node *prev=new node;
    	node *curr=new node;
    	node *temp=new node;
    	curr=head;
    	temp->value=data;
    	if(pos<=Count())
    	{
    	   for(int i=1;i<pos;i++)
    	   {
    	   	  prev=curr;
    	   	  curr=curr->next;
    	   }
    	   prev->next=temp;
    	   temp->next=curr;
    	}
    	else
    	 cout<<"empty linked list";
    }

    void Delete()      //function to delete the node at the end
    {
    	node *curr=new node;
    	node *prev=new node;
    	curr=head;
    	while(curr->next!=NULL)
        {
        	prev=curr;
        	curr=curr->next;
        }
        tail=prev;
        prev->next=NULL;
        delete curr;
    }
    
    void deleteAt(int pos) //function to delete a particular node
    {
    	node *curr=new node;
    	node *prev=new node;
    	node *after=new node;
    	curr=head;
    	if(pos<=Count())
    	{
    		for(int i=1;i<pos;i++)
    		{
    			prev=curr;
    			curr=curr->next;
    			after=curr->next;
    		}
    		prev->next=after;
    		delete curr;
    	}
    	else
    	 cout<<"empty linked list";
    }
    
    int Count() //count the number of nodes in a linked list
    {
    	int c=0;
    	node *temp=new node;
    	while(temp!=NULL)
    	{
    		temp=temp->next;
    		c++;
    	}
    	return c;
    }
    	
    void display() //display the values of a linked list 
    {
    	node *temp=new node;
    	temp=head;
    	while(temp!=NULL)
    	{
    		cout<<temp->value<<"-";
    		temp=temp->next;
    	}
    }
};  
    
    int main()
    {
    	linkedlist l; //declaring object of class linked list
    	l.insert(10);
    	l.insert(20);
    	l.display();
    	l.insertAt(2,15);
    	l.display();
    	l.Delete();
    	l.display();
    	l.insertAt(2,19);
    	l.display();
    	l.deleteAt(2);
    	l.display();
    	 return 0;
    }
    
