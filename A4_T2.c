#include <stdio.h>
#include <stdlib.h> 

typedef struct Node{
    char name; 
    struct Node * connections[6]; //This is the columns of the matrix 
    int con_count;
}Node;
struct Node * master[7]; 

typedef struct Edge{
    Node * side1; 
    Node * side2; 
    struct Edge * tot_edge; 
    int weight; 
} edge; 

char abc[7] = {'A','B','C','D','E','F','G'};

void addNode(char name, int index){
    printf("\n");
    struct Node * newNode = (struct Node *) malloc(30*sizeof(struct Node *)); //Initialise node 
    newNode->name = name; //Sside2re the character in the struct 
    master[index] = newNode; //Stores a pointer to ALL nodes 
    newNode->con_count =0;
    for(int i =0;i<7;i++){
        newNode->connections[i] = NULL; 
    }
    
}


Node * getNode(char c){ // RETURNS NODE FOR A GIVEN CHARACTER
    for(int i = 0; i<6; i++){
        if(master[i]->name == c){
            return master[i]; 
        }
    }
}

void addEdge(Node * n1, Node * n2, int weight){ //CONNECTS TWO NODES AND GIVES WEIGHT
   
   
    
    n1->connections[n1->con_count] = n2; 
    n2->connections[n2->con_count] = n1; 
    printf("|%c <-> %c|", n1->name,n2->name);
    n1->con_count = n1->con_count + 1; 
    n2->con_count = n2->con_count + 1; 
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

int main (){
    int A=0, B=1, C=2, D=3, E=4, F=5, G=6; 

    printf(">>Initialised\n");
    printf("Adding nodes = ");
    for(int i = 0; i<7; i++){
        printf("+ %c",abc[i]);
        addNode(abc[i] , i); // ADD ALL THE NODES, UNCONNETED
    }
    printf("Finished Adding\n");
    //A's EDGES 
    addEdge(getNode(abc[A]),getNode(abc[B]), 1);
    addEdge(getNode(abc[A]),getNode(abc[C]), 3);
    addEdge(getNode(abc[A]),getNode(abc[F]), 10);
    //B's EDGES 
    addEdge(getNode(abc[B]),getNode(abc[G]), 2);
    addEdge(getNode(abc[B]),getNode(abc[D]), 7);
    addEdge(getNode(abc[B]),getNode(abc[E]), 5);
    addEdge(getNode(abc[B]),getNode(abc[C]), 1);
    //C 
    addEdge(getNode(abc[C]),getNode(abc[D]), 9);
    addEdge(getNode(abc[C]),getNode(abc[E]), 3);
    //D
    addEdge(getNode(abc[D]),getNode(abc[G]), 12);
    addEdge(getNode(abc[D]),getNode(abc[F]), 1);
    addEdge(getNode(abc[D]),getNode(abc[E]), 2);
    //E
    addEdge(getNode(abc[E]),getNode(abc[F]), 2);
    
    
    


}