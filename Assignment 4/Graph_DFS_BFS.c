#include <stdio.h>
#include <stdlib.h>
#define maxQ 10 

//Use ADJACENCY MATRIX  
// A=0, B=1, C=2, D=3, E=4, F=5 
typedef struct Node{
    char name; 
    struct Node * connections[6]; //This is the columns of the matrix 
    int con_count;
}Node;
struct Node * root[6]; 


//QUEUE SECTION 
typedef struct Qnode {
    char data; 
    struct Qnode * next; 
}Qnode; 

Qnode * front = NULL;
Qnode * back = NULL; 
Qnode * prev = NULL; 

int Qsize = 0; 
void enqueue(char data){
   // printf("Enqueuing...\n");
    struct Qnode * newNode = (struct Qnode *) malloc(12*sizeof(struct Qnode *));
    if(front == NULL){ //This is first in the queue 
        front = newNode; //point front and back at it 
        back = newNode; 
        newNode->data = data; 
        newNode->next = NULL; 
    } else if(front != NULL){
        newNode->data = data; 
        prev->next = newNode; //Point the previous node @ the new one - connect them
        back = newNode; //Point the back at the new one
        newNode->next = NULL; 
    }
    prev = newNode; 
    Qsize++; 
    //printf("%c\n", newNode->data);
}

Qnode * dequeue(){
    //printf("Dequeuing..\n");
    Qnode * hold = front;
    //Get rid of the first node 
    front = front->next;
    Qsize--; 
    return hold;  
}

int empty()
{
    if(front = NULL)
        return 1;
    else
        return 0;
}

void printQ(){
    Qnode * curr = front;
    while(curr != NULL){
        printf("|%c|", curr->data);
        curr = curr->next;
    } 
    printf("\n");
}

//END OF QUEUE SECTION 
 
int DFS_visited[6];
int BFS_visited[6]; 
char abc[6] = {'A','B','C','D','E','F'};

Node * getNode(char c){
    for(int i = 0; i<6; i++){
        if(root[i]->name == c){
            return root[i]; 
        }
    }
}
  
//GRAPH SECTION 
void addNode(char name, int index){
    struct Node * newNode = (struct Node *) malloc(12*sizeof(struct Node *)); //Initialise node 
    newNode->name = name; //Store the character in the struct 
    root[index] = newNode; //Stores a pointer to ALL nodes 
    newNode->con_count =0;
    for(int i =0;i<6;i++){
        newNode->connections[i] = NULL; 
    }
}

void connect(char d1, char d2){
    Node * temp1; 
    Node * temp2; 
    temp1 = getNode(d1);
    temp2 = getNode(d2);
    int sent = 0, i =0; 
     //loop till we find a null connection 
        
    temp1->connections[temp1->con_count] = temp2; 
    printf("|%c -> %c|", d1,d2);
    temp1->con_count = temp1->con_count + 1;       
}


int checkConnection(int i, int j){
    char a = abc[i];
    char b = abc[j]; 
    Node * temp1 = getNode(a);
    Node * temp2 = getNode(b);
    for(int k = 0;k<6;k++){
        if(temp1->connections[k] == temp2){
        //printf("%i and %i are connected\n",i,j);
            return 1; 
        }
    }
    return 0; 
}

 //TRAVERSALS 
void DFS (int i){
    printf("%c ", abc[i]);
    DFS_visited[i] = 1; 
    for(int k =0; k<6; k++){    
        if(DFS_visited[k] == 0 && checkConnection(i,k)==1){
            //printf("%d - %d\n", DFS_visited[k], array[k][i]);
            DFS(k);
        }
    }
} 

void BFS(int i){ 
    
    int amt = 0; 
    enqueue(abc[i]);
    BFS_visited[i] = 2; //Two means it is holding  
    //printf("Entered bfs\n");
    
    while(Qsize > 0){
        
        printf("%c ", front->data);
        dequeue(); 
        //printf("Pop\n");
        BFS_visited[i] = 1; 
        //GET ALL ADJACENT VERTICES OF FQ? 
        for(int k = 0; k<6;k++){
            if(checkConnection(i, k)){   //if FQ has a connection to any other node
                if(BFS_visited[k] == 0){ //If that node is not visited
                    BFS_visited[k] = 2; 
                    amt++; 
                    enqueue(abc[k]);
                }
                
            } 
            
        }
        i++; 
    }
    printf("\n");

}

int main(){
    
    int A=0, B=1, C=2, D=3, E=4, F=5; 
    char cA = 'A',cB = 'B',cC = 'C',cD = 'D',cE = 'E',cF = 'F';
    for(int i =0; i<6;i++){
        DFS_visited[i] = 0; //INITIALISE TO 0 
        BFS_visited[i] = 0; 
    } 
    
    addNode(cA,0); 
    addNode(cB,1);
    addNode(cC,2); 
    addNode(cD,3); 
    addNode(cE,4); 
    addNode(cF,5); 

    printf("\nDisplay Connections:\n");
    connect(cA,cB);
    connect(cA,cD);
    connect(cA,cE);
    printf("\n");
    connect(cB,cD);
    connect(cB, cC); 
    printf("\n");
    connect(cC,cB);
    connect(cC,cD); 
    printf("\n");
    connect(cD,cF); 
    printf("\n");
    connect(cE,cD); 
    printf("\n");
    connect(cF,cC); 
    printf("\n");

    printf(">>Graph succesfully generated\n\n>>DFS Search Results\n");
    DFS(0);
    printf("\n>>BFS Search Results\n");
    BFS(0);


    return 0; 
}
