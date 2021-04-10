
struct Node {
    int data;
    struct Node *next;
}
Node;
#include <stdio.h>
#include <malloc.h>
void printAllInList(struct Node *node);
struct Node *gotoEndInChain(struct Node *node );

//Den blev ikke helt færdig men jeg har desværre ikke mere tid :)
int main() {

    struct Node *list = NULL;
    struct Node *firstNode= malloc(sizeof(Node));
    struct Node *secondNode= malloc(sizeof(Node));
    struct Node *thirdNode= malloc(sizeof(Node));


    list = firstNode;
    firstNode->data = 1;
    secondNode->data = 2;
    thirdNode->data = 3;

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;


    //printAllInList(list);

    printf("%d\n", gotoEndInChain(list)->data);
    return 0;
}

void printAllInList(struct Node *node){

    if(node != NULL){
        printf("%d",node->data);
        printAllInList(node->next);
    }
}

void addToArray(struct Node *node, struct Node *node2, int number)
{
    if(node != NULL)
    {
        node->data = number;
        if(node2->next != NULL)
            node->next = NULL;
    }
}

struct Node *gotoEndInChain(struct Node *node ){


            if (node->next != NULL)
            {
                gotoEndInChain(node->next);
            }
            else
            {
                printf("gotoEnd: %d", node->data);
                return node;
            }

    return NULL;
}