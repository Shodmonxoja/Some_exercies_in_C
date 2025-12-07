#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int following;
    struct Node* next;
}Node;

typedef struct Graph{
    int V;
    Node **adj;
}Graph;

Node* createNode(int dest){
    Node* nNode = malloc(sizeof(Node*));
    if(nNode==NULL){
        printf("Alloc_Fail");
        exit(1);
    }
    nNode->following=dest;
    nNode->next=NULL;
    return nNode;
}

Graph* createGraph(int V){
    Graph* nGraph = malloc(sizeof(Graph*));
    if(nGraph==NULL){
        printf("Alloc_Fail");
        exit(1);
    }
    nGraph->V=V;
    nGraph->adj = malloc(V*sizeof(Node*));
    if(nGraph->adj==NULL){
        printf("Alloc_Fail");
        exit(1);
    }
    for(int i=0;i<V;i++){
        nGraph->adj[i]=NULL;
    }
    return nGraph;
}

void addEdge(Graph* graph, int f, int t){
    Node* nNode = createNode(t);
    nNode->next = graph->adj[f];
    graph->adj[f] = nNode;
}

void printGraph(Graph* graph){
    for(int i=0;i<graph->V;i++){
        printf("User %d follows users with ID:\n", i);
        Node* nNode = graph->adj[i];
        while(nNode!=NULL){
            printf(" %d", nNode->following);
            nNode = nNode->next;
        }
        printf("\n");
    }
}

int isMutual(Graph* graph,int u1, int u2){
    int fo1=0, fo2=0, res;
    Node* temp = graph->adj[u1];
    while(temp!=NULL){
        if(temp->following==u2){
            fo1 = 1;
            break;
        }
    }
    temp = graph->adj[u2];
    while(temp!=NULL){
        if(temp->following==u1){
            fo2 = 1;
            break;
        }
    }
    if(fo1 == 1 && fo2 ==1){
        res = 1;
    }else{
        res = 0;
    }
    return res;
}

int main(){
    int c;
    int num_users;
    printf("Enter the number of users: ");
    scanf("%d", &num_users);
    Graph* graph = createGraph(num_users);
    while(1){
        int rl1, rl2;
        printf("Enter an user-follower relation (u f): ");
        if(scanf("%d", &rl1)==1){
            scanf("%d", &rl2);
            if(rl1<num_users && rl2<num_users){
                addEdge(graph, rl1, rl2);
            }else{
                printf("You exceeded the range. Try again \n");
                continue;
            }
        }else{
            printf("you exited\n");
            while ((c = getchar()) != '\n' && c != EOF) {}
            break;
        }
    }
    while(1){
        int u1, u2;
        printf("Check if the users follow each other (u1 u2): ");
        if(scanf("%d", &u1)==1){
            scanf("%d", &u2);
            if(u1<num_users && u2<num_users){
                int boolshit = isMutual(graph,u1, u2);
                if(boolshit==1){
                    printf("Yes they follow each other\n");
                }else{
                    printf("No they do not follow each other\n");
                }
            }else{
                printf("You exceeded the range. Try again \n");
                continue;
            }
        }else{
            printf("you exited\n");
            while ((c = getchar()) != '\n' && c != EOF) {}
            break;
        }
    }
    printGraph(graph);
    return 0;
}
