//
// Created by gjshj on 2025-01-28.
//

#include "dll.h"


// create & destroy node;

Node* DLL_Create(ElementType newData) {
    Node*newNode = malloc(sizeof(Node));

    newNode->data =newData;
    newNode->prevNode= NULL;
    newNode->nextNode= NULL;

    return newNode;
}

void DLL_Destroy(Node*node) {
    free(node);
}

// operation

void DLL_InsertAfter(Node*current, Node*newNode) {
    newNode -> nextNode = current -> nextNode;
    newNode -> prevNode = current;

    if (current -> nextNode != NULL) {
        current -> nextNode -> prevNode = newNode;
        current -> nextNode = newNode;
    }
}

void DLL_InsertBefore(Node*current, Node*newNode) {

    newNode->nextNode = current;
    newNode->prevNode = current->prevNode;

    if (current->prevNode!=NULL)
            current->prevNode->nextNode = newNode;
    current->prevNode = newNode;
}
void DLL_AppendNode(Node**head, Node*newNode) {
    if (*head == NULL) {
        *head = newNode;
    }else {
        Node * tail = *head;

        while (tail->nextNode !=NULL) {
            tail = tail->nextNode;
        }

        tail->nextNode = newNode;
        newNode -> prevNode = tail; //
    }
}
void DLL_DestroyAllNode(Node**head) {
    Node*current = *head;
    *head = NULL;

    while (current!=NULL) {
        Node*temp = current;
        current = current -> nextNode;
        DLL_Destroy(temp);
    }
}

void DLL_RemoveNode(Node**head, Node*oldNode) {
    if (*head == oldNode) {
        *head = (*head) -> nextNode;

        if (*head!=NULL) {
            (*head) -> prevNode = NULL;
        }

    }else {
        Node * prevNode = oldNode->prevNode;
        Node * nextNode = oldNode->nextNode;

        if (prevNode!=NULL)
            prevNode->nextNode = nextNode;
        if (nextNode!=NULL)
            nextNode->prevNode = prevNode;
    }
    DLL_Destroy(oldNode);
}


int DLL_CountNodes(Node*head) {
    int count = 0;
    while (head!=NULL) {
        head = head->nextNode;
        count++;
    }

    return count;
}
Node *  DLL_GetNodeAt(Node*head, int location) {

    while (head!=NULL && --location >=0) {
        head = head -> nextNode;
    }

    return head;
}

void DLL_PrintNode(Node*head) {
    if (head->prevNode == NULL)
        printf("*Prev : NULL \n");
    else
        printf("Prev : %d\n", head->prevNode->data);

    printf("Current : %d\n", head->data);

    if (head->nextNode ==NULL)
        printf("*Next: NULL\n");

    else
        printf("Next: %d\n", head->nextNode ->data);

    printf("\n");
}

void DLL_PrintAllNodes(Node*head) {
    int count = DLL_CountNodes(head);

    for (int i=0; i<count; i++) {
        printf("Node[%d] : %d\n",i, DLL_GetNodeAt(head, i)->data );
    }
}

void DLL_PrintReverse(Node* head) {
    Node*tail = head;
    while (tail->nextNode != NULL) tail = tail ->nextNode;

    Node * current = tail;
    while (current!=NULL) {
        DLL_PrintNode(current);
        current = current ->prevNode;
    }
}

int init_dll() {

    int count = 0;
    Node* head = NULL;
    Node * newNode = NULL;
    Node * current = NULL;

    for (int i=0;i<5; i++) {
        newNode = DLL_Create(i);
        DLL_AppendNode(&head, newNode);
    }

    DLL_PrintAllNodes(head);

    printf("\n Inserting 3000 after [2]....\"\n");

    current = DLL_GetNodeAt(head, 2);
    newNode = DLL_Create(3000);
    DLL_InsertAfter(current, newNode);


    DLL_PrintAllNodes(head);

    DLL_PrintReverse(head);

    printf("\n Destroying List ... \n");

    count = DLL_CountNodes(head);

    for (int i =0;i<count;i++) {
        current = DLL_GetNodeAt(head, i);

        if (current!=NULL) {
            DLL_RemoveNode(&head, current);
            DLL_Destroy(current);
        }
    }
    return 0;
}
