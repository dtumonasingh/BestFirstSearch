#include<stdio.h>
#include<malloc.h>

void insert(struct node); 
struct node del();
void display();
int empty();

//Structure to save the index and value of a node in the Graph.
struct node
{
int value;
int index;
struct node *next;
}*start=NULL,*q,*temp,*new1;
 
typedef struct node N;

//The main function.

int main()
{
printf("\n\n\n\n");
printf("--------------------------------BEST FIRST SEARCH USING PRIORITY QUEUE-----------------------------------------------");
printf("\n\n");
FILE* file = fopen ("graph", "r");
int i = 0;
int N,s,g;

  fscanf (file, "%d", &i);  
  N=i;
  printf("The Number of Nodes in the Graph is ");
  printf("%d",N);  
  printf("\n\n");


  fscanf (file, "%d", &i);  
  s=i;
  printf("The Source Node in the Graph is ");
  printf("%d",s);  
  printf("\n\n");


  fscanf (file, "%d", &i);  
  g=i;
  printf("The Goal Node in the Graph is ");
  printf("%d",g);  
  printf("\n\n");


  int G[N+1][N+1]; //The G[][] Matrix is used to store the Graph.
  int x,y;
  x=1;y=1;
  int V[N+1]; //The V[] Matrix is used to store the vlaue of each node os the Graph.
  int k=1;
  fscanf (file, "%d", &i); 
  while (!feof(file))  //Taking input form the Input file.
    {
    if(x<N+1){
      G[x][y]=i;
      y++;
      if(y==N+1)
      {
      y=1;
      x++;
      }
      }
  else{
      V[k]=i;
      k++;
     }
  fscanf (file, "%d", &i);      
    }


printf("The Adjacency Matrix");
printf("\n");

for(x=1;x<=N;x++)
  {
   for(y=1;y<=N;y++)
    {
    printf("%d ",G[x][y]);
    }
   printf("\n");
  }

printf("\n");

printf("The Value of each Node");
printf("\n\n");

x=1;
for(x=1;x<=N;x++){
   printf("%d ",V[x]);
}

fclose (file);  


int ch;
struct node m;
struct node n;
 
int I; //for index;
m.index=1;
m.value=V[1];
insert(m);
int Visit[N+1]={0};
Visit[1]=1;
printf("\n\n");

printf("The Path Followed to Reach the Goal is ");
printf("\n\n");

//The Best First Search Implementation.

while(!empty()){
  n=del();
printf("--->");
   printf("%d ",n.index);
  if(n.index==g){
     printf("GOAL REACHED!");
     printf("\n");
     break;
     }
  else{
     for(x=1;x<=N;x++){
        if(G[n.index][x]==1){
           if(Visit[x]==0)
             Visit[x]=1; 

             m.index=x;
             m.value=V[x];
             insert(m);
           
             }
	  
          }
      }


}


}

//Function for pushing in the Priority Queue.
 
void insert(struct node m)
{
int item=m.index,itprio=m.value;
new1=(N*)malloc(sizeof(N));

new1->index=item;
new1->value=itprio;
new1->next=NULL;
if(start==NULL )
{
//new1->next=start;
start=new1;
}
else if(start!=NULL&&itprio<=start->value)
{  new1->next=start;
start=new1;
}
else
{
q=start;
while(q->next != NULL && q->next->value<=itprio)
{q=q->next;}
new1->next=q->next;
q->next=new1;
}
}

//Function for popping from the Priority Queue.
 
struct node del()
{
struct node n;
n.index=-1;
n.value=-1;
if(start==NULL)
{
printf("\nQUEUE UNDERFLOW\n");
 
}
else
{

n.index=start->index;
n.value=start->value;
new1=start;

start=start->next;
}

return n;
}

//Function to determine if the Priority Queue is empty.

int empty(){
if(start==NULL)
return 1;
return 0;
}
 

