

#include "sll.h"


Node* SLL_CreateNode(ElementType data) {
    Node * newNode = malloc(sizeof(Node));

    newNode -> data =data;
    newNode -> next = NULL;

    return newNode;
}

void SLL_DestroyNode(Node* oldNode) {
    free(oldNode);
}

// tail => local variable, so whenever loop allocate tail = tail -> next, local variable 'tail' points same place where tail->next points.
// but tail->next is different, tail -> next is (*tail).next, it actually accesses to the address where tail was pointing to.
void SLL_AppendNode(Node** head, Node*newNode) {
    if ((*head) == NULL) {
        (*head) = newNode;
    }else {
        Node*tail = (*head);
        while (tail-> next!=NULL) {
            tail = tail -> next;
        }
        tail->next = newNode;
    }
}

void SLL_PrintNodes(Node* head) {
    printf("start printing nodes: \n");

    int count = SLL_GetNodesCount(head);

    for (int i=0; i<count; i++) {
        Node * current = SLL_GetNodeAt(head, i);
        printf("List[%d] : %d \n", i , current->data);
    }

    printf("end printing.\n");
}

Node * SLL_GetNodeAt(Node* head, int location) {
    Node * temp = head;

    while (temp!=NULL && --location >= 0) {
        temp = temp -> next;
    }

    return temp;
}

void SLL_RemoveNode(Node**head, Node * targetNode) {
    if (*head == targetNode) {
        (*head)  = (*head) ->next;
        (*head) = NULL; // if it is the head when you're trying to free the memory, make sure it won't lead to dereferencing.
    }else {

        Node* temp = *head;
        while (temp != NULL && temp->next != targetNode) {
            temp = temp -> next;
        }

        if (temp != NULL) temp->next = targetNode -> next;
    }

    SLL_DestroyNode(targetNode);
}

int SLL_GetNodesCount(Node* head) {
    int count = 0;
    Node * currentNode = head;

    while (currentNode!= NULL) {
        currentNode = currentNode -> next;
        count++;
    }

    return count;
}

void SLL_InsertAfter(Node * thisNode, Node * newNode) {
    newNode ->next = thisNode -> next;
    thisNode -> next = newNode;
}

void SLL_InsertNewHead(Node **head, Node * newNode) {
    if (*head == NULL) {
        (*head) = newNode;
    } else {
        newNode->next = (*head);
        (*head) = newNode;
    }
}


void SLL_InsertBefore(Node**head, Node * current, Node* newHead) {
    if (*head == current) {
        newHead -> next = current;
        *head = newHead;
    }else {
        Node * before = *head;
        while (before!=NULL && before->next != current) {
            before = before -> next;
        }

        if (before!=NULL) {
            newHead->next = before-> next;
            before -> next = newHead;
        }
    }

    }

void SLL_DestroyAllNodes(Node ** list) {
    Node * current = *list;

    while (current !=NULL) {
        Node * temp = current;
        current = current -> next;
        SLL_DestroyNode(temp);
    }

    *list = NULL; // if it is head pointer when you're trying to free the memory allocated, make sure it won't lead to dereferencing.
}

int init_sll() {
    int i = 0;
    int count =0;
    Node* list = NULL;
    Node* current = NULL;
    Node * newNode = NULL;

    for (i=0;i<5;i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&list, newNode);
    }

    SLL_PrintNodes(list);

    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&list, newNode);

    newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&list, newNode);

    SLL_PrintNodes(list);

    printf("\nInserting 3000 After [2] ... \n\n");

    current  = SLL_GetNodeAt(list,2);
    newNode = SLL_CreateNode(3000);

    SLL_InsertAfter(current, newNode);

    SLL_PrintNodes(list);

    // printf("\nDestorying list...\n");
    //
    // for (i=0;i<count; i++) {
    //     current = SLL_GetNodeAt(list, 0);
    //
    //     if (current != NULL) {
    //         SLL_RemoveNode(&list, current);
    //         SLL_DestroyNode(current);
    //     }
    // }

    current = SLL_GetNodeAt(list, 7);
    newNode = SLL_CreateNode(19);

    printf("Inserting %d before [%d]\n", newNode->data, 7);
    SLL_InsertBefore(&list, current, newNode);

    SLL_PrintNodes(list);



    SLL_DestroyAllNodes(&list);
    count = SLL_GetNodesCount(list);


    printf("%d -> all nodes left", count);

    return 0;
}